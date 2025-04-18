// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/14/25
// Archivo Insertion.cc: Implementación de Insertion
//        En este fichero se implementa las funciones de la clase Insertion
//
// Historial de revisiones
//        04/14/25 - Creación (primera versión) del código

#include"Insertion.h"

/** Insertion::Insertion()
  * @brief Crea el objeto de la clase Insertion.
  * @param 
  * @return objeto de la clase Insertion
  */
Insertion::Insertion() {

}

/**
 * @brief Insertion::ejecutar
 * @param ruta1: Ruta de recolección
 * @param ruta2: Ruta de transporte
 * @return pair<pair<RutaRecoleccion, RutaRecoleccion>, double>: par de rutas modificadas y el coste de la mejora
 */
pair<pair<RutaRecoleccion, RutaRecoleccion>, double> Insertion::ejecutar(const RutaRecoleccion& ruta1, const RutaRecoleccion& ruta2) {
  RutaRecoleccion ruta_actual11 = ruta1;
  RutaRecoleccion ruta_actual21 = ruta2;
  RutaRecoleccion ruta_actual12 = ruta1;
  RutaRecoleccion ruta_actual22 = ruta2;
  RutaRecoleccion mejor_ruta1 = ruta1;
  RutaRecoleccion mejor_ruta2 = ruta2;
  double mejor_coste = 0;
  for (int i = 1; i < ruta_actual11.size() - 2; i++) {
    for (int j = 1; j < ruta_actual21.size() - 2; j++) {
      ruta_actual11 = ruta1;
      ruta_actual21 = ruta2;
      ruta_actual12 = ruta1;
      ruta_actual22 = ruta2;
      // Inserto el nodo de la ruta 2 en la ruta 1
      int nodo2 = ruta_actual21.get_nodo(j);
      ruta_actual11.anadir_parada(nodo2, i);
      ruta_actual21.quitar_parada(j);
      
      // Comprobar si la ruta es factible
      if (ruta_actual11.factible(this->datos_problema_, this->distancia_zonas_) && ruta_actual21.factible(this->datos_problema_, this->distancia_zonas_)) { 
        double distancia_quitada1 = this->distancia_zonas_.get_distancia(ruta1.get_nodo(i-1), ruta1.get_nodo(i));
        double distancia_quitada2 = this->distancia_zonas_.get_distancia(ruta2.get_nodo(j-1), ruta2.get_nodo(j)) + this->distancia_zonas_.get_distancia(ruta2.get_nodo(j+1), ruta2.get_nodo(j));
        double distancia_anadida1 = this->distancia_zonas_.get_distancia(ruta_actual11.get_nodo(i-1), ruta_actual11.get_nodo(i)) + this->distancia_zonas_.get_distancia(ruta_actual11.get_nodo(i), ruta_actual11.get_nodo(i+1));
        double distancia_anadida2 = this->distancia_zonas_.get_distancia(ruta_actual21.get_nodo(j-1), ruta_actual21.get_nodo(j));
        double coste = (distancia_anadida1 + distancia_anadida2) - (distancia_quitada1 + distancia_quitada2);
        if (coste < mejor_coste) {
          mejor_coste = coste;
          mejor_ruta1 = ruta_actual11;
          mejor_ruta2 = ruta_actual21;
        }
      } // si no es factible, no lo tengo en cuenta
      // Calcular coste 


      // Inserto el nodo de la ruta 1 en la ruta 2
      int nodo1 = ruta_actual11.get_nodo(i);
      ruta_actual12.quitar_parada(i);
      ruta_actual22.anadir_parada(nodo1, j);

      // Comprobar si la ruta es factible
      if (!ruta_actual12.factible(this->datos_problema_, this->distancia_zonas_) || !ruta_actual22.factible(this->datos_problema_, this->distancia_zonas_)) { continue; } // si no es factible, no lo tengo en cuenta
      // Calcular coste
      double distancia_quitada1 = this->distancia_zonas_.get_distancia(ruta1.get_nodo(i-1), ruta1.get_nodo(i)) + this->distancia_zonas_.get_distancia(ruta1.get_nodo(i+1), ruta1.get_nodo(i));
      double distancia_quitada2 = this->distancia_zonas_.get_distancia(ruta2.get_nodo(j-1), ruta2.get_nodo(j));
      double distancia_anadida1 = this->distancia_zonas_.get_distancia(ruta_actual12.get_nodo(i-1), ruta_actual12.get_nodo(i));
      double distancia_anadida2 = this->distancia_zonas_.get_distancia(ruta_actual22.get_nodo(j-1), ruta_actual22.get_nodo(j)) + this->distancia_zonas_.get_distancia(ruta_actual22.get_nodo(j), ruta_actual22.get_nodo(j+1));
      double coste = (distancia_anadida1 + distancia_anadida2) - (distancia_quitada1 + distancia_quitada2);
      if (coste < mejor_coste) {
        mejor_coste = coste;
        mejor_ruta1 = ruta_actual12;
        mejor_ruta2 = ruta_actual22;
      }
    }
  }
  return {{mejor_ruta1, mejor_ruta2}, mejor_coste};
}

/**
 * @brief Insertion::calcular_coste
 * @param ruta1: Ruta de recolección
 * @param ruta_optima1: Ruta óptima de recolección
 * @param ruta2: Ruta de transporte
 * @param ruta_optima2: Ruta óptima de transporte
 * @return double: coste de la mejora
 */
double Insertion::calcular_coste(const RutaRecoleccion& ruta1, const RutaRecoleccion& ruta_optima1, const RutaRecoleccion& ruta2, const RutaRecoleccion& ruta_optima2) {
  // double coste = 0;
  // // Calculo el coste de la mejora
  // for (int i = 0; i < ruta1.size(); i++) {
  //   coste += this->distancia_zonas_.get_distancia(ruta1.get_nodo(i), ruta_optima1.get_nodo(i));
  // }
  return 0;
}