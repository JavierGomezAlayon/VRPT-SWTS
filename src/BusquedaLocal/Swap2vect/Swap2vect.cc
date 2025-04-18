// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/14/25
// Archivo Swap2vect.cc: Implementación de Swap2vect
//        En este fichero se implementa las funciones de la clase Swap2vect
//
// Historial de revisiones
//        04/14/25 - Creación (primera versión) del código

#include"Swap2vect.h"

/** Swap2vect::Swap2vect()
  * @brief Crea el objeto de la clase Swap2vect.
  * @param 
  * @return objeto de la clase Swap2vect
  */
Swap2vect::Swap2vect() {

}

/**
  * @brief Swap2vect::ejecutar
  * @param ruta1: Ruta de recolección
  * @param ruta2: Ruta de transporte
  * @return pair<pair<RutaRecoleccion, RutaRecoleccion>, double>: par de rutas modificadas y el coste de la mejora
  */
pair<pair<RutaRecoleccion, RutaRecoleccion>, double> Swap2vect::ejecutar(const RutaRecoleccion& ruta1, const RutaRecoleccion& ruta2) {
  RutaRecoleccion ruta_actual1 = ruta1;
  RutaRecoleccion ruta_actual2 = ruta2;
  RutaRecoleccion mejor_ruta1 = ruta1;
  RutaRecoleccion mejor_ruta2 = ruta2;
  double mejor_coste = 0;
  for (int i = 1; i < ruta_actual1.size() - 2; i++) {
    for (int j = 1; j < ruta_actual2.size() - 2; j++) {
      ruta_actual1 = ruta1;
      ruta_actual2 = ruta2;
      // Intercambiar los nodos
      int nodo1 = ruta_actual1.get_nodo(i);
      int nodo2 = ruta_actual2.get_nodo(j);
      ruta_actual1.intercambiar_parada(nodo2, i);
      ruta_actual2.intercambiar_parada(nodo1, j);
      // Comprobar si la ruta es factible
      if (!ruta_actual1.factible(this->datos_problema_, this->distancia_zonas_) || !ruta_actual2.factible(this->datos_problema_, this->distancia_zonas_)) { continue; } // si no es factible, no lo tengo en cuenta
      // Calcular coste 
      double distancia_quitada1 = this->distancia_zonas_.get_distancia(ruta1.get_nodo(i-1), ruta1.get_nodo(i)) + this->distancia_zonas_.get_distancia(ruta1.get_nodo(i+1), ruta1.get_nodo(i));
      double distancia_quitada2 = this->distancia_zonas_.get_distancia(ruta2.get_nodo(j-1), ruta2.get_nodo(j)) + this->distancia_zonas_.get_distancia(ruta2.get_nodo(j+1), ruta2.get_nodo(j));
      double distancia_anadida1 = this->distancia_zonas_.get_distancia(ruta_actual1.get_nodo(i-1), ruta_actual1.get_nodo(i)) + this->distancia_zonas_.get_distancia(ruta_actual1.get_nodo(i), ruta_actual1.get_nodo(i+1));
      double distancia_anadida2 = this->distancia_zonas_.get_distancia(ruta_actual2.get_nodo(j-1), ruta_actual2.get_nodo(j)) + this->distancia_zonas_.get_distancia(ruta_actual2.get_nodo(j), ruta_actual2.get_nodo(j+1));
      double coste = (distancia_anadida1 + distancia_anadida2) - (distancia_quitada1 + distancia_quitada2);
      if (coste < mejor_coste) {
        mejor_coste = coste;
        mejor_ruta1 = ruta_actual1;
        mejor_ruta2 = ruta_actual2;
      }
    }
  }
  return {{mejor_ruta1, mejor_ruta2}, mejor_coste};
}

/**
  * @brief Swap2vect::calcular_coste
  * @param ruta1: Ruta de recolección
  * @param ruta_optima1: Ruta óptima de recolección
  * @param ruta2: Ruta de transporte
  * @param ruta_optima2: Ruta óptima de transporte
  * @return double: coste de la mejora
  */
double Swap2vect::calcular_coste(const RutaRecoleccion& ruta1, const RutaRecoleccion& ruta_optima1, const RutaRecoleccion& ruta2, const RutaRecoleccion& ruta_optima2) {
  // double coste = 0;
  // // Calculo el coste de la mejora
  // for (int i = 0; i < ruta1.size(); i++) {
  //   coste += this->distancia_zonas_.get_distancia(ruta1.get_nodo(i), ruta_optima1.get_nodo(i));
  // }
  return 0;
}
