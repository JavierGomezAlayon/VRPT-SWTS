// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/25/25
// Archivo funciones_main.cc: Implementación de las funciones del main
//        En este fichero se implementa las funciones utilizadas en el main
//
// Historial de revisiones
//        03/25/25 - Creación (primera versión) del código

#include"funciones_main.h" 


/**
 * @brief Recoge los parámetros que se han enviado por linea del comando. Comprobando si los parámetros son correctos.
 * @param numero_argumentos 
 * @param argv 
 * @return retorna un booleano que indica si se ha recogido correctamente los parámetros (true si es correcto, false si no)
 * @throw std::invalid_argument si no se han introducido los argumentos necesarios
 * @throw std::invalid_argument si se han introducido demasiados argumentos
 */
Dato recoger_parametro(int numero_argumentos, char *argv[]) {
  Dato datos;
  const std::string kHelp = "--help";
  const std::string kH = "-h";
  switch (numero_argumentos) {
    case 1:
      mostrar_ayuda_resumida();
      throw std::invalid_argument("No se han introducido los argumentos necesarios");
    case 2:
      if (argv[1] == kHelp || argv[1] == kH) {
        mostrar_ayuda();
        datos.correcto = true;
      } else {
        datos.fichero = argv[1];
        datos.correcto = true;
      }
      return datos;
    default:
      throw std::invalid_argument("Demasiados argumentos");
  }
}
/**
 * @brief Muestra una ayuda detallada del programa
 */
void mostrar_ayuda() {
  std::cout << "\nEste programa se encarga de realizar una serie de algoritmos que resuelven el problema VRPT-SWTS " << std::endl;
  std::cout << "El programa recibe como argumentos el nombre del fichero que contiene todos los datos necesarios para el problema. Consulta en docs la explicación de cadda instancia." << std::endl;
  std::cout << "Usage: ./programa data/instance1 " << std::endl;
}

/**
 * @brief Muestra una ayuda resumida del programa
 */
void mostrar_ayuda_resumida() {
  std::cout << "\nUsage: ./programa data/instance1 " << std::endl;
  std::cout << "Usa el parámetro -h para más información" << std::endl;
}

void mostrar_ayuda_menu() {
  std::cout << "Introduce una de las siguientes opciones: " << std::endl;
  std::cout << "0. Salir" << std::endl;
  std::cout << "1. Mostrar ayuda" << std::endl;
  std::cout << "2. indicar nodo inicial y nodo final" << std::endl;
}

/**
 * @brief implementación del menú del programa
 */
void menu() { 
  mostrar_ayuda_menu();
  int opcion;
  while (true) {
    std::cout << std::endl;
    std::cout << "Introduzca una opción: ";
    std::cin >> opcion;
    switch (opcion) {
      case 1:
        mostrar_ayuda_menu();
        break;
      case 0:
        return;
        break;
      default:
        std::cerr << "Error: Opción no válida" << std::endl;
        break;
    }
  }
}

/**
 * @brief Lee el fichero de entrada y devuelve los datos del problema
 * @param fichero nombre del fichero sin ninguna ruta adicional y con la extensión
 * @return DatosProblema un struct hecho para llevar los datos del problema
 * @throw std::invalid_argument si no se ha podido abrir el fichero
 */
DatosProblema leer_fichero(std::string fichero) {
  std::ifstream file("/home/javichu401/clases/DAA/VRPT-SWTS/data/" + fichero);
  if (!file.is_open()) {
    throw std::invalid_argument("No se ha podido abrir el fichero");
  }
  DatosProblema datos_problema;
  std::string linea = "";
  while (std::getline(file, linea)) {
    if (linea == "" ) continue; 
    std::istringstream sslinea(linea); // hace un stream de la linea
    actualizar_datos(datos_problema, sslinea);
  }
  file.close();
  return datos_problema;
}


void actualizar_datos(DatosProblema &datos_problema, std::istringstream &sslinea) {
  std::string palabra;
  sslinea >> palabra;
  palabra = lowercase(palabra);
  if (palabra == "l1") {
    sslinea >> datos_problema.duracion_maxima_recoleccion;
  } else if (palabra == "l2") {
    sslinea >> datos_problema.duracion_maxima_transporte;
  } else if (palabra == "num_vehicles") {
    sslinea >> datos_problema.num_vehiculos;
  } else if (palabra == "num_zones") {
    sslinea >> datos_problema.num_zonas_recoleccion;
  } else if (palabra == "lx") {
    sslinea >> datos_problema.lx;
  } else if (palabra == "ly") {
    sslinea >> datos_problema.ly;
  } else if (palabra == "q1") {
    sslinea >> datos_problema.capacidad_vehiculo_recoleccion;
  } else if (palabra == "q2") {
    sslinea >> datos_problema.capacidad_vehiculo_transporte;
  } else if (palabra == "v") {
    sslinea >> datos_problema.velocidad_vehiculo;
  } else if (palabra == "depot") {
    double x, y;
    sslinea >> x >> y;
    Zona* nueva_zona = new ZonaDeposito(Cordenadas(x, y));
    datos_problema.zonas.push_back(nueva_zona);
  } else if (palabra == "dumpsite") {
    double x, y;
    sslinea >> x >> y;
    Zona* nueva_zona = new ZonaVertedero(Cordenadas(x, y));
    datos_problema.zonas.push_back(nueva_zona);
  } else if (regex_search(palabra, regex("if([0-9]+)?"))) { // para detectar cualquier estación de transferencia
    double x, y;
    sslinea >> x >> y;
    string numero_id = palabra.substr(2); // le quito el if
    if (numero_id == "" ) { numero_id = "0"; } // si no hay número, le pongo 1
    int id = std::stoi(numero_id) + 1;
    Zona* nueva_zona = new ZonaTransferencia(id, Cordenadas(x, y));
    datos_problema.zonas.push_back(nueva_zona);
  } else if (regex_search(palabra, regex("[0-9]+"))) { // para detectar cualquier zona de recolección
    int id = std::stoi(palabra);
    double x, y;
    sslinea >> x >> y;
    double d1, d2;
    sslinea >> d1 >> d2;
    Zona* nueva_zona = new ZonaRecoleccion(id, Cordenadas(x, y), d1, d2);
    datos_problema.zonas.push_back(nueva_zona);
  } 
}

std::string lowercase(std::string str) {
  std::transform(str.begin(), str.end(), str.begin(), ::tolower);
  return str;
}