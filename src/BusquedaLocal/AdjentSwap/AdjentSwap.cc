// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/14/25
// Archivo AdjentSwap.cc: Implementación de AdjentSwap
//        En este fichero se implementa las funciones de la clase AdjentSwap
//
// Historial de revisiones
//        04/14/25 - Creación (primera versión) del código

#include"AdjentSwap.h"

/** AdjentSwap::AdjentSwap()
  * @brief Crea el objeto de la clase AdjentSwap.
  * @param 
  * @return objeto de la clase AdjentSwap
  */
 AdjentSwap::AdjentSwap() {}

/**
  * @brief AdjentSwap::ejecutar
  * @param ruta1: Ruta de recolección
  * @param ruta2: Ruta de transporte
  * @return pair<pair<RutaRecoleccion, RutaRecoleccion>, double>: par de rutas modificadas y el coste de la mejora
  * @details Esta función se encarga de ejecutar la búsqueda local AdjentSwap.
  */
pair<pair<RutaRecoleccion, RutaRecoleccion>, double> AdjentSwap::ejecutar(const RutaRecoleccion& ruta1, const RutaRecoleccion& ruta2) {
  RutaRecoleccion ruta_actual = ruta1;
  RutaRecoleccion mejor_ruta = ruta1;
  double mejor_coste = 0;
  for (int i = 1; i < ruta_actual.size() - 3; i++) { // quiero que intercambie entre el primer nodo de recolección y el último. (sin contar estaciones de transferencia)
    ruta_actual = ruta1;
    ruta_actual.swap(i, i + 1);
    // Comprobar si la ruta es factible
    if (!ruta_actual.factible(this->datos_problema_, this->distancia_zonas_)) { continue; } // si no es factible, no lo tengo en cuenta
    // Calcular coste 
    double distancia_quitada = this->distancia_zonas_.get_distancia(ruta1.get_nodo(i-1), ruta1.get_nodo(i)) + this->distancia_zonas_.get_distancia(ruta1.get_nodo(i + 2), ruta1.get_nodo(i + 1));
    double distancia_anadida = this->distancia_zonas_.get_distancia(ruta1.get_nodo(i-1), ruta1.get_nodo(i + 1)) + this->distancia_zonas_.get_distancia(ruta1.get_nodo(i), ruta1.get_nodo(i + 2));
    double coste = distancia_anadida - distancia_quitada;
    if (coste < mejor_coste) {
      mejor_coste = coste;
      mejor_ruta = ruta_actual;
    }
  }
  return {{mejor_ruta, ruta2}, mejor_coste};
}


/**
 * @brief indica cuantas rutas necesita la búsqueda local
 * @return int: número de rutas necesarias
 * @details Esta función se encarga de indicar cuantas rutas necesita la búsqueda local.
 */
int AdjentSwap::rutas_necesarias() {
  return 1;
}

/**
 * @brief AdjentSwap::calcular_coste
 * @param ruta1: Ruta de recolección
 * @param ruta_optima1: Ruta óptima de recolección
 * @param ruta2: Ruta de transporte
 * @param ruta_optima2: Ruta óptima de transporte
 * @return double: coste de la mejora
 */
double AdjentSwap::calcular_coste(const RutaRecoleccion& ruta1, const RutaRecoleccion& ruta_optima1, const RutaRecoleccion& ruta2, const RutaRecoleccion& ruta_optima2) {
  double coste = 0;
  return 0;
}