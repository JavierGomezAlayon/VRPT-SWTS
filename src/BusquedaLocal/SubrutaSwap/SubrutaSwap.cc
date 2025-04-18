// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/14/25
// Archivo SubrutaSwap.cc: Implementación de SubrutaSwap
//        En este fichero se implementa las funciones de la clase SubrutaSwap
//
// Historial de revisiones
//        04/14/25 - Creación (primera versión) del código

#include"SubrutaSwap.h"

/** SubrutaSwap::SubrutaSwap()
  * @brief Crea el objeto de la clase SubrutaSwap.
  * @param 
  * @return objeto de la clase SubrutaSwap
  */
SubrutaSwap::SubrutaSwap() {

}


/**
 * @brief SubrutaSwap::ejecutar
 * @param ruta1: Ruta de recolección
 * @param ruta2: Ruta de transporte
 * @return pair<pair<RutaRecoleccion, RutaRecoleccion>, double>: par de rutas modificadas y el coste de la mejora
 * @details Esta función se encarga de ejecutar la búsqueda local SubrutaSwap.
 * No mejora en nada la ruta de recolección.
 */
pair<pair<RutaRecoleccion, RutaRecoleccion>, double> SubrutaSwap::ejecutar(const RutaRecoleccion& ruta1, const RutaRecoleccion& ruta2) {
  RutaRecoleccion ruta_actual1 = ruta1;
  RutaRecoleccion ruta_actual2 = ruta2;
  RutaRecoleccion mejor_ruta1 = ruta1;
  RutaRecoleccion mejor_ruta2 = ruta2;
  double mejor_coste = 0;
  int subrutas1 = ruta_actual1.get_circuitos();
  int subrutas2 = ruta_actual2.get_circuitos();
  for (int i = 1; i <= subrutas1; i++) {
    for (int j = 1; j <= subrutas2; j++) {
      ruta_actual1 = ruta1;
      ruta_actual2 = ruta2;
      // detecto la subruta y sus nodos
      vector<int> subruta1 = ruta_actual1.get_subruta(i);
      vector<int> subruta2 = ruta_actual2.get_subruta(j);
      // el primer número de la subruta es el índice inicial
      int indice_subruta1 = subruta1[0];
      int indice_subruta2 = subruta2[0];
      // elimino el primer número de la subruta
      subruta1.erase(subruta1.begin());
      subruta2.erase(subruta2.begin());

      int subruta1_size = subruta1.size();
      int subruta2_size = subruta2.size();
      // Intercambiar los nodos
      if (subruta1_size == subruta2_size) {
        for (int k = 0; k < subruta1_size; k++) {
          ruta_actual1.intercambiar_parada(subruta2[k], k + indice_subruta1);
          ruta_actual2.intercambiar_parada(subruta1[k], k + indice_subruta2);
        }
      } else {
        int diferencia = subruta1_size - subruta2_size;
        if (diferencia > 0) { // la subruta 1 es más larga
          // Intercambiar los nodos de la subruta más corta
          for (int k = 0; k < subruta2_size; k++) {
            ruta_actual1.intercambiar_parada(subruta2[k], k + indice_subruta1);
          }
          for (int k = 0; k < diferencia; k++) {
            ruta_actual1.quitar_parada(k + indice_subruta1 + subruta2_size);
          }
          // Intercambiar los nodos de la subruta más larga
          for (int k = 0; k < subruta2_size; k++) {
            ruta_actual2.intercambiar_parada(subruta1[k], k + indice_subruta2);
          }
          for (int k = 0; k < diferencia; k++) {
            ruta_actual2.anadir_parada(subruta1[k + subruta2_size], k + indice_subruta2 + subruta2_size);
          }
        } else { // la subruta 2 es más larga
          // Intercambiar los nodos de la subruta más corta
          for (int k = 0; k < subruta1_size; k++) {
            ruta_actual2.intercambiar_parada(subruta1[k], k + indice_subruta2);
          }
          for (int k = 0; k < -diferencia; k++) {
            ruta_actual2.quitar_parada(k + indice_subruta2 + subruta1_size);
          }
          // Intercambiar los nodos de la subruta más larga
          for (int k = 0; k < subruta1_size; k++) {
            ruta_actual1.intercambiar_parada(subruta2[k], k + indice_subruta1);
          }
          for (int k = 0; k < -diferencia; k++) {
            ruta_actual1.anadir_parada(subruta2[k + subruta1_size], k + indice_subruta1 + subruta1_size);
          }
        }
      }
      if (!ruta_actual1.factible(this->datos_problema_, this->distancia_zonas_) || !ruta_actual2.factible(this->datos_problema_, this->distancia_zonas_)) { continue; } // si no es factible, no lo tengo en cuenta
      // Calcular coste 
      // puedo poner un if para ver si ha cambiado en algo las distancias de las rutas (si los extremos de las subrutas son los mismos)
      double distancia_quitada1 = this->distancia_zonas_.get_distancia(ruta1.get_nodo(indice_subruta1 - 1), ruta1.get_nodo(indice_subruta1)) + this->distancia_zonas_.get_distancia(ruta1.get_nodo(indice_subruta1 + subruta1_size - 1), ruta1.get_nodo(indice_subruta1 + subruta1_size));
      double distancia_quitada2 = this->distancia_zonas_.get_distancia(ruta2.get_nodo(indice_subruta2 - 1), ruta2.get_nodo(indice_subruta2)) + this->distancia_zonas_.get_distancia(ruta2.get_nodo(indice_subruta2 + subruta2_size - 1), ruta2.get_nodo(indice_subruta2 + subruta2_size));
      double distancia_anadida1 = this->distancia_zonas_.get_distancia(ruta_actual1.get_nodo(indice_subruta1 - 1), ruta1.get_nodo(indice_subruta1)) + this->distancia_zonas_.get_distancia(ruta1.get_nodo(indice_subruta1 + subruta1_size - 1), ruta_actual1.get_nodo(indice_subruta1 + subruta1_size));
      double distancia_anadida2 = this->distancia_zonas_.get_distancia(ruta_actual2.get_nodo(indice_subruta2 - 1), ruta2.get_nodo(indice_subruta2)) + this->distancia_zonas_.get_distancia(ruta2.get_nodo(indice_subruta2 + subruta2_size - 1), ruta_actual2.get_nodo(indice_subruta2 + subruta2_size));
      double coste = (distancia_anadida1 + distancia_anadida2) - (distancia_quitada1 + distancia_quitada2);
      if (coste < mejor_coste) {
        mejor_coste = coste;
        mejor_ruta1 = ruta_actual1;
        mejor_ruta2 = ruta_actual2;
        cout << "MEJORAAA-------------------------------------------------------------------------------------------" << endl;
      }
    }
  }
  return {{mejor_ruta1, mejor_ruta2}, mejor_coste};
}

/**
  * @brief SubrutaSwap::calcular_coste
  * @param ruta1: Ruta de recolección
  * @param ruta_optima1: Ruta óptima de recolección
  * @param ruta2: Ruta de transporte
  * @param ruta_optima2: Ruta óptima de transporte
  * @return double: coste de la mejora
  */
double SubrutaSwap::calcular_coste(const RutaRecoleccion& ruta1, const RutaRecoleccion& ruta_optima1, const RutaRecoleccion& ruta2, const RutaRecoleccion& ruta_optima2) {
  // double coste = 0;
  // // Calculo el coste de la mejora
  // for (int i = 0; i < ruta1.size(); i++) {
  //   coste += this->distancia_zonas_.get_distancia(ruta1.get_nodo(i), ruta_optima1.get_nodo(i));
  // }
  return 0;
}