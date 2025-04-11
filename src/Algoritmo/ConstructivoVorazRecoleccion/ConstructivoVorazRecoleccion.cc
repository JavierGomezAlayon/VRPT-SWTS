// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/05/25
// Archivo ConstructivoVorazRecoleccion.cc: Implementación de ConstructivoVorazRecoleccion
//        En este fichero se implementa las funciones de la clase ConstructivoVorazRecoleccion
//
// Historial de revisiones
//        04/05/25 - Creación (primera versión) del código
#pragma GCC diagnostic ignored "-Wsign-compare"  
#include"ConstructivoVorazRecoleccion.h"

/** ConstructivoVorazRecoleccion::ConstructivoVorazRecoleccion()
  * @brief Crea el objeto de la clase ConstructivoVorazRecoleccion.
  * @param 
  * @return objeto de la clase ConstructivoVorazRecoleccion
  */
ConstructivoVorazRecoleccion::ConstructivoVorazRecoleccion() {

}

/** ConstructivoVorazRecoleccion::solve()
  * @brief Resuelve el problema de recolección de residuos.
  * @return this Devuelve el propio objeto para permitir la encadenación de llamadas.
  * @details Este algoritmo proporciona una solución guardada en su atributo rutas_ y también en el atributo Tareas_.
  */
 Algoritmo& ConstructivoVorazRecoleccion::solve() {
  const int DEPOSITO = 0;
  set<int> zonas_visitadas;
  this->rutas_.clear();
  while(zonas_visitadas.size() < this->datos_problema_.num_zonas_recoleccion) { // mientras haya zonas no visitadas
    if (this->rutas_.size() > this->datos_problema_.num_vehiculos) {
      cout << "Se han superado el número de vehículos de recolección" << endl;
      break;
    }
    int id_zona_actual = DEPOSITO;
    // Inicializo la ruta y las variables necesarias para el nuevo vehículo
    vector<int> ruta_actual = {DEPOSITO};
    double capacidad_restante = datos_problema_.capacidad_vehiculo_recoleccion;
    double tiempo_restante = datos_problema_.duracion_maxima_recoleccion;
    pair<int, double> zona_mas_cercana;
    while(zonas_visitadas.size() < this->datos_problema_.num_zonas_recoleccion) {
      zona_mas_cercana = this->distancia_zonas_.get_zona_mas_cercana(id_zona_actual, 'R', zonas_visitadas);

      // tiempo que tarda en ir a la zona de transferencia más cercana, al sitio de transferencia más cercano y volver al depósito
      double tiempo_hasta_zona = (zona_mas_cercana.second * 60 / datos_problema_.velocidad_vehiculo);  // llego a la zona nueva
      tiempo_hasta_zona += this->obtener_zona(zona_mas_cercana.first)->get_tiempo();                   // la recojo

      pair<int,double> id_zona_transferencia = this->distancia_zonas_.get_zona_mas_cercana(zona_mas_cercana.first, 'T');   // obtengo la zona de transferencia más cercana
      double distancia_regreso = id_zona_transferencia.second + this->distancia_zonas_.get_distancia(id_zona_transferencia.first, DEPOSITO); // calculo la distancia de vuelta al depósito pasando por la zona de transferencia
      double tiempo_regreso = tiempo_hasta_zona + (distancia_regreso * 60) / this->datos_problema_.velocidad_vehiculo; // tiempo hasta la zona más cercana de transferencia  más el tiempo de ir a la transferencia y volver al depósito

      // y la capacidad necesaria
      double capacidad_necesaria = this->obtener_zona(zona_mas_cercana.first)->get_demanda();
      if (capacidad_restante > capacidad_necesaria && tiempo_restante > tiempo_regreso) { // Si la capacidad y el tiempo son suficientes
        // Actualizo todo lo necesario
        ruta_actual.push_back(zona_mas_cercana.first);
        zonas_visitadas.emplace(zona_mas_cercana.first);
        capacidad_restante -= capacidad_necesaria;
        tiempo_restante -= tiempo_hasta_zona; // lo pongo en km/h
        id_zona_actual = zona_mas_cercana.first;
      } else if (tiempo_restante > tiempo_regreso) { // si el tiempo es suficiente pero la capacidad no
        pair<int, double> zona_transferencia_mas_cercana = this->distancia_zonas_.get_zona_mas_cercana(id_zona_actual, 'T');
        // voy a la zona de tranferencia
        ruta_actual.push_back(zona_transferencia_mas_cercana.first);
        id_zona_actual = zona_transferencia_mas_cercana.first;
        // Actualizo la capacidad y el tiempo
        tiempo_restante -= zona_transferencia_mas_cercana.second * 60 / datos_problema_.velocidad_vehiculo; // lo pongo en km/h
        capacidad_restante = this->datos_problema_.capacidad_vehiculo_recoleccion;
      } else {
        break;
      }
    }
    if (id_zona_actual > 0) { // si no ha ido a una estación de transferencia
      // busco la zona de transferencia más cercana
      pair<int, double> zona_transferencia_mas_cercana = this->distancia_zonas_.get_zona_mas_cercana(id_zona_actual, 'T');
      // voy a la zona de tranferencia
      ruta_actual.push_back(zona_transferencia_mas_cercana.first);
    } else { // si ha ido a una estación de transferencia
      id_zona_actual = 0; // lo pongo en positivo de nuevo
    }
    RutaRecoleccion ruta (ruta_actual);
    ruta.set_nueva_parada(0); // añado la parada de vuelta al depósito
    ruta.calcular_circuitos();
    // cout << "Ruta: " << ruta << endl;
    this->rutas_.push_back(ruta);
  }
  // cout << "Se han visitado " << zonas_visitadas.size() << " zonas de recolección, con " << rutas_.size() << " vehículos" << endl;
  return *this;
}

/** ConstructivoVorazRecoleccion::get_rutas()
  * @brief Devuelve las rutas de recolección.
  * @return vector<Ruta>&: vector de rutas
  */
vector<RutaRecoleccion>& ConstructivoVorazRecoleccion::get_rutas() {
  return this->rutas_;
}


