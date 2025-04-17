// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/14/25
// Archivo Adjent2Swap2Vect.cc: Implementación de Adjent2Swap2Vect
//        En este fichero se implementa las funciones de la clase Adjent2Swap2Vect
//
// Historial de revisiones
//        04/14/25 - Creación (primera versión) del código

#include"Adjent2Swap2Vect.h"

/** Adjent2Swap2Vect::Adjent2Swap2Vect()
  * @brief Crea el objeto de la clase Adjent2Swap2Vect.
  * @param 
  * @return objeto de la clase Adjent2Swap2Vect
  */
Adjent2Swap2Vect::Adjent2Swap2Vect() {

}

/**
  * @brief Adjent2Swap2Vect::ejecutar
  * @param ruta1: Ruta de recolección
  * @param ruta2: Ruta de transporte
  * @return pair<pair<RutaRecoleccion, RutaRecoleccion>, double>: par de rutas modificadas y el coste de la mejora
  * @details Esta función se encarga de ejecutar la búsqueda local Adjent2Swap2Vect.
  */
pair<pair<RutaRecoleccion, RutaRecoleccion>, double> Adjent2Swap2Vect::ejecutar(const RutaRecoleccion& ruta1, const RutaRecoleccion& ruta2) {
  return {{ruta1, ruta2}, 0};
}

/**
  * @brief Adjent2Swap2Vect::calcular_coste
  * @param ruta1: Ruta de recolección
  * @param ruta_optima1: Ruta óptima de recolección
  * @param ruta2: Ruta de transporte
  * @param ruta_optima2: Ruta óptima de transporte
  * @return double: coste de la mejora
  */
double Adjent2Swap2Vect::calcular_coste(const RutaRecoleccion& ruta1, const RutaRecoleccion& ruta_optima1, const RutaRecoleccion& ruta2, const RutaRecoleccion& ruta_optima2) {
  // double coste = 0;
  // // Calculo el coste de la mejora
  // for (int i = 0; i < ruta1.size(); i++) {
  //   coste += this->distancia_zonas_.get_distancia(ruta1.get_nodo(i), ruta_optima1.get_nodo(i));
  // }
  return 0;
}
