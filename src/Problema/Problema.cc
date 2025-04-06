// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/25/25
// Archivo Problema.cc: Implementación de Problema
//        En este fichero se implementa las funciones de la clase Problema
//
// Historial de revisiones
//        03/25/25 - Creación (primera versión) del código

#include"Problema.h"

/** Problema::Problema()
  * @brief Crea el objeto de la clase Problema.
  * @return objeto de la clase Problema
  */
Problema::Problema() {

}

/** Problema::Problema(DatosProblema datos_problema)
  * @brief Crea el objeto de la clase Problema.
  * @param datos_problema: Datos del problema
  * @return objeto de la clase Problema
  */
Problema::Problema(DatosProblema datos_problema) {
  datos_problema_ = datos_problema;
}

/** Problema::set_datos_problema(DatosProblema datos_problema)
  * @brief Establece los datos del problema.
  * @param datos_problema: Datos del problema
  */
// void Problema::set_datos_problema(DatosProblema datos_problema) {
//   datos_problema_ = datos_problema;
// }
// 
// /** Problema::solve()
//   * @brief Resuelve el problema.
//   * @return void
//   */
// void Problema::solve() {
//   // Para resolver el problema primero debemos hacer una primera parte en la que resolvemos el problema de la recolección
//   // y después la parte de transporte.
//   vector<Ruta> rutas_recoleccion = algoritmo_constructivo_recoleccion();
//   // algoritmo_constructivo_transporte();
//   cout << "vehículos de la ruta: " << rutas_recoleccion.size() << endl << endl;
// }


/** Problema::algoritmo_constructivo_recoleccion()
  * @brief Resuelve el problema de la recolección.
  * @return vector<Ruta>: Devuelve un vector con las rutas de recolección
  */
 // vector<Ruta> Problema::algoritmo_constructivo_recoleccion() {
 // calcular_distancias();
 // const int DEPOSITO = 0;
 // vector<Ruta> ruta_recoleccion;
 // set<int> zonas_no_visitadas;
 // // inicializo el vector de zonas no visitadas
 // for (int i = 0; i < datos_problema_.num_zonas; i++) {                 // ESTO TENGO QUE HACERLO AL REVÉS (EMPEZAR SIN ZONAS E IR AÑADIENDO)
 //   zonas_no_visitadas.insert(i + 1); // las zonas empiezan en 1
 // }
 // while(zonas_no_visitadas.size() > 0) { // mientras haya zonas no visitadas
 //   int id_zona_actual = DEPOSITO;
 //   // Inicializo la ruta y las variables necesarias para el nuevo vehículo
 //   vector<int> ruta_actual = {DEPOSITO};
 //   double capacidad_restante = datos_problema_.capacidad_vehiculo_recoleccion;
 //   double tiempo_restante = datos_problema_.duracion_maxima_recoleccion;
 //   // busco la zona más cercana a la zona de inicio
 //   pair<int, double> zona_mas_cercana;
 //   while(zonas_no_visitadas.size() > 0) {
 //     zona_mas_cercana = this->zona_mas_cercana(id_zona_actual, zonas_no_visitadas);
 //     // tiempo que tarda en ir a la zona de transferencia más cercana y volver al depósito
 //     double tiempo_regreso = this->datos_problema_.zonas.get_zona(zona_mas_cercana.first).tiempo + this->tiempo_regreso(zona_mas_cercana.first);
 //     double capacidad_necesaria = this->datos_problema_.zonas.get_zona(zona_mas_cercana.first).demanda;
 //     // compruebo que el tiempo y la capacidad son suficientes
 //     if (capacidad_restante > capacidad_necesaria && tiempo_restante > tiempo_regreso) { // Si la capacidad y el tiempo son suficientes
 //       // Actualizo todo lo necesario
 //       ruta_actual.push_back(zona_mas_cercana.first);
 //       zonas_no_visitadas.erase(zona_mas_cercana.first);
 //       capacidad_restante -= capacidad_necesaria;
 //       tiempo_restante -= (zona_mas_cercana.second * 60 / datos_problema_.velocidad_vehiculo) + this->datos_problema_.zonas.get_zona(zona_mas_cercana.first).tiempo; // lo pongo en km/h
 //       id_zona_actual = zona_mas_cercana.first;
 //     } else if (tiempo_regreso <= tiempo_restante) { // si el tiempo es suficiente pero la capacidad no
 //       pair<int, double> zona_transferencia_mas_cercana = this->zona_mas_cercana(id_zona_actual, zonas_no_visitadas, true);
 //       // voy a la zona de tranferencia
 //       ruta_actual.push_back(zona_transferencia_mas_cercana.first);
 //       id_zona_actual = zona_transferencia_mas_cercana.first;
 //       // Actualizo la capacidad y el tiempo
 //       tiempo_restante -= zona_transferencia_mas_cercana.second * 60 / datos_problema_.velocidad_vehiculo; // lo pongo en km/h
 //       capacidad_restante = this->datos_problema_.capacidad_vehiculo_recoleccion;
 //     } else {
 //       break;
 //     }
 //   }
 //   if (id_zona_actual > 0) { // si no ha ido a una estación de transferencia
 //     // busco la zona de transferencia más cercana
 //     pair<int, double> zona_transferencia_mas_cercana = this->zona_mas_cercana(id_zona_actual, zonas_no_visitadas, true);
 //     // voy a la zona de tranferencia
 //     ruta_actual.push_back(zona_transferencia_mas_cercana.first);
 //     // CREO UNA TAREA CON LA ZONA DE TRANSFERENCIA
 //   } else { // si ha ido a una estación de transferencia
 //     id_zona_actual = 0; // lo pongo en positivo de nuevo
 //   }
 //   Ruta ruta (ruta_actual);
 //   ruta.set_nueva_parada(0); // añado la parada de vuelta al depósito
 //   ruta.calcular_circuitos();
 //   cout << ruta << endl;
 //   ruta_recoleccion.push_back(ruta);
 // }
 // return ruta_recoleccion;
 // }


/** Problema::calcular_distancias()
  * @brief Calcula las distancias entre las zonas y el depósito y entre las zonas y las estaciones de transferencia.
  * @return void
  * @details sigue las especificaciones de las Rutas (en cuanto saber que tipo de zona es)
  */
// void Problema::calcular_distancias() {
//   int num_zonas = this->datos_problema_.zonas.size();
//   Cordenadas cord_deposito = this->datos_problema_.cord_deposito;
//   Zonas zonas = this->datos_problema_.zonas;
//   // Relleno el vector de distancias entre el depósito y las zonas
//   distancias_deposito_zonas_.resize(num_zonas);
//   for (int i = 0; i < num_zonas; i++) {
//     distancias_deposito_zonas_[i] = cord_deposito.distancia(zonas.get_zona(i + 1).cordenadas);
//   }
//   // Relleno la matriz de distancias entre estaciones de transferencia y zonas
//   int num_estaciones_transferencia = this->datos_problema_.cord_estaciones_transferencia.size();
//   distancias_zonas_estaciones_trasnferencia_.resize(num_estaciones_transferencia);
//   for (int i = 0; i < num_estaciones_transferencia ; i++) {
//     distancias_zonas_estaciones_trasnferencia_[i].resize(num_zonas);
//     for (int j = 0; j < num_zonas; j++) {
//       distancias_zonas_estaciones_trasnferencia_[i][j] = zonas.get_zona(j + 1).cordenadas.distancia(this->datos_problema_.cord_estaciones_transferencia[i]);
//     }
//   }
//   // Relleno la matriz de distancias entre estaciones de transferencia y deposito
//   this->distancias_deposito_zonas_transferencia_.resize(num_estaciones_transferencia);
//   for (int i = 0; i < num_estaciones_transferencia; i++) {
//     this->distancias_deposito_zonas_transferencia_[i] = cord_deposito.distancia(this->datos_problema_.cord_estaciones_transferencia[i]);
//   }
// }
// 
// /**
//  * @brief Devuelve la distancia entre dos zonas
//  * @param id_zona id de la zona actual
//  * @param zonas_no_recogidas set de zonas que faltan por recoger
//  * @param zona_transferencia si es true, devuelve la distancia a la zona de transferencia más cercana
//  * @return pair<int, double> un par con el id de la zona más cercana y la distancia a ella.
//  * @details Tengo que añadir un bitmapping de las zonas que han sido visitadas
//  */
// pair<int, double> Problema::zona_mas_cercana(const int id_zona_actual,const set<int>& zonas_no_recogidas, bool zona_transferencia) {
//   int id_zona_mas_cercana;
//   if (id_zona_actual == 0) { 
//     id_zona_mas_cercana = this->datos_problema_.zonas.get_zona_mas_cercana(this->datos_problema_.cord_deposito, zonas_no_recogidas);
//   } else if (zona_transferencia) { // si es una zona de transferencia, busco la zona de recogida más cercana
//     double distancia_mas_cercana = INFINITY;
//     int zonas_transferencia_size = this->datos_problema_.cord_estaciones_transferencia.size();
//     for (int i = 0; i < zonas_transferencia_size; i++) {
//       double distancia_actual = this->distancias_zonas_estaciones_trasnferencia_[i][id_zona_actual - 1]; // le resto uno para que sea el índice
//       if (distancia_actual < distancia_mas_cercana) {
//         id_zona_mas_cercana =  (i + 1) * -1; // lo pongo en negativo para que sea la estación de transferencia y le sumo uno para que sea el índice
//         distancia_mas_cercana = distancia_actual;
//       }
//     }
//   } else if (id_zona_actual < 0) { // si es una estación de transferencia, busco la zona de recogida más cercana
//     int estacion_transferencia_actual = -id_zona_actual - 1; // lo pongo en positivo de nuevo y le resto uno para que sea el índice
//     double distancia_mas_cercana = INFINITY;
//     id_zona_mas_cercana = 0; // inicializo la zona más cercana a 0
//     for (int i = 0; i < this->datos_problema_.num_zonas; i++) { // lo recorro siendo el índice de la zona
//       double distancia_actual = this->distancias_zonas_estaciones_trasnferencia_[estacion_transferencia_actual][i];
//       if (distancia_actual < distancia_mas_cercana && zonas_no_recogidas.find(i + 1) != zonas_no_recogidas.end()) {
//         id_zona_mas_cercana = i + 1; // le sumo uno para que sea el índice
//         distancia_mas_cercana = distancia_actual;
//       }
//     }
// 
//   } else { // si es una zona de recogida, busco la zona de transferencia más cercana
//     id_zona_mas_cercana = this->datos_problema_.zonas.get_zona_mas_cercana(id_zona_actual, zonas_no_recogidas);
//   }
//   if (id_zona_mas_cercana > this->datos_problema_.num_zonas) {
//     throw std::invalid_argument("La zona " + to_string(id_zona_mas_cercana) + " no es una zona más cercana válida");
//   }
//   double distancia = this->distancia(id_zona_actual, id_zona_mas_cercana);
//   return {id_zona_mas_cercana, distancia};
// }
// 
// /**
//  * @brief Devuelve la distancia entre dos zonas
//  * @param id_zona1 id de la zona 1
//  * @param id_zona2 id de la zona 2
//  * @return double 
//  * @details Se utiliza el convenio de que el depósito es la zona 0 y las estaciones de transferencia son zonas negativas
//  *          y las zonas de recogida son positivas
//  */
// double Problema::distancia(int id_zona1, int id_zona2) {
//   if (id_zona1 == id_zona2 || id_zona1 > this->datos_problema_.num_zonas || id_zona2 > this->datos_problema_.num_zonas) {
//     throw std::invalid_argument("La distancia de " + std::to_string(id_zona1) + " a " + std::to_string(id_zona2) + " no es válida");
//   }
//   if (id_zona1 == 0 || id_zona2 == 0) { // si alguno de los dos es el depósito
//     int otra_zona = (id_zona1 == 0) ? id_zona1 : id_zona2;
//     int zona_recoleccion = (id_zona1 == 0) ? id_zona2 : id_zona1;
//     if (zona_recoleccion < 0) { // si la otra zona es una estación de transferencia
// 
//       return this->distancias_deposito_zonas_transferencia_[(-zona_recoleccion) - 1];
//     }
//     return this->distancias_deposito_zonas_[zona_recoleccion - 1]; // le resto uno para que sea el índice
//   }
//   if (id_zona1 < 0 || id_zona2 < 0) { // si alguno de los dos es una estación de transferencia
//     int estacion = (id_zona1 < 0) ? -id_zona1 - 1 : -id_zona2 - 1; // lo pongo en positivo de nuevo y le resto uno para que sea el índice
//     int zona = (id_zona1 < 0) ? id_zona2 : id_zona1;
//     return this->distancias_zonas_estaciones_trasnferencia_[estacion][zona - 1]; // le resto uno para que sea el índice
//   }
//   // Si los dos son zonas de recogida, devuelvo la distancia entre ellas
//   return this->datos_problema_.zonas.get_distancia(id_zona1, id_zona2);
// }
// 
// /**
//  * @brief Devuelve el tiempo de regreso a la zona de recogida 
//  * @param id_zona_actual id de la zona actual
//  * @return double 
//  * @throw std::invalid_argument si la zona es menor que 1
//  * @details De la zona actual a la zona de transferencia más cercana y de ahí al depósito
//  */
// double Problema::tiempo_regreso(int id_zona_actual) {
//   if (id_zona_actual < 1) {
//     throw std::invalid_argument("La zona actual no puede ser menor que 1");
//   }
//   set<int> zonas_recogidas = {};// esto da igual para este caso
//   pair<int, double> zona_transferencia_mas_cercana = this->zona_mas_cercana(id_zona_actual, zonas_recogidas, true);
//   double distancia = zona_transferencia_mas_cercana.second + this->distancia(zona_transferencia_mas_cercana.first, 0);
//   double tiempo = (distancia * 60) / this->datos_problema_.velocidad_vehiculo; // lo paso a km/h poniendole 60.
//   return tiempo;
// }