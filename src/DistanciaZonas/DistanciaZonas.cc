// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/05/25
// Archivo DistanciaZonas.cc: Implementación de DistanciaZonas
//        En este fichero se implementa las funciones de la clase DistanciaZonas
//
// Historial de revisiones
//        04/05/25 - Creación (primera versión) del código

#include"DistanciaZonas.h"

/** DistanciaZonas::DistanciaZonas()
  * @brief Crea el objeto de la clase DistanciaZonas.
  * @param 
  * @return objeto de la clase DistanciaZonas
  */
DistanciaZonas::DistanciaZonas() {

}

/** DistanciaZonas::DistanciaZonas(vector<Zona*> zonas)
  * @brief Crea el objeto de la clase DistanciaZonas.
  * @param zonas: vector de zonas
  * @return objeto de la clase DistanciaZonas
  */
DistanciaZonas::DistanciaZonas(vector<Zona*>& zonas) {
  this->num_zonas_transferencia_ = 0;
  this->num_zonas_recoleccion_ = 0;
  int zonas_size = zonas.size();
  // Inicializo el vector de distancias
  this->distancia_zonas_.resize(zonas_size);
  for (int i = 0; i < zonas_size; i++) {
    // Cuento las zonas de transferencia y recolección
    if (zonas[i]->get_tipo_zona() == 'T') {
      num_zonas_transferencia_++;
    } else if (zonas[i]->get_tipo_zona() == 'R') {
      num_zonas_recoleccion_++;
    }
    // Calculo las distancias
    for (int j = 0; j < zonas_size; j++) {
      if (i != j) {
        double distancia = zonas[i]->get_cordenadas().distancia(zonas[j]->get_cordenadas()); // distancia entre las dos cordenadas
        distancia_zonas_[i].push_back(distancia);
      } else {
        double distancia = INFINITY; // distancia a si mismo
        distancia_zonas_[i].push_back(distancia); // la distancia a si mismo es infinita
      }
    }
  }
}

/** DistanciaZonas::get_distancia(int id_zona_a, int id_zona_b)
  * @brief Devuelve la distancia entre dos zonas.
  * @param id_zona_a: id de la zona a
  * @param id_zona_b: id de la zona b
  * @details Las zonas se enumeran de la siguiente manera:
  *          Zona de recolección: 1... num_zonas_recoleccion_
  *          Zona de transferencia: -1, -2, ... -num_zonas_transferencia_
  *          Zona de vertedero: INFINITY
  *          Zona de depósito: 0
  * @return double: distancia entre las zonas
  */
double DistanciaZonas::get_distancia(int id_zona_a, int id_zona_b) const {
  if (id_zona_a == id_zona_b) {
    return INFINITY;
  }
  if (id_zona_a == INFINITY || id_zona_b == INFINITY) {
    id_zona_a = id_zona_a == INFINITY ? num_zonas_recoleccion_ + 1 : id_zona_a; // si es el vertedero, lo cambio por el último elemento del vector
    id_zona_b = id_zona_b == INFINITY ? num_zonas_recoleccion_ + 1 : id_zona_b; // si es el vertedero, lo cambio por el último elemento del vector
  }
  /* Combierto los id de las zonas a índices.
   Le sumo el número de zonas de transferencia para que sea el índice ya que el id más negativo es el número de zonas de 
   transferencia pero en negativo, entonces al sumarle ese número se tiene el índice empezando en 0 */
  int index_a = id_zona_a + num_zonas_transferencia_;
  int index_b = id_zona_b + num_zonas_transferencia_;
  return distancia_zonas_[index_a][index_b]; // devuelvo la distancia entre las dos zonas
}

/** DistanciaZonas::get_zona_mas_cercana(int id_zona_actual, const set<int>& nodos_por_visitar)
  * @brief Devuelve la zona más cercana a la zona actual.
  * @param id_zona_actual: id de la zona actual
  * @param tipo_zona_necesaria: tipo de zona que se necesita (R, T, V o D)
  * @param nodos_por_visitar: set de zonas que no han sido recogidas
  * @details Si no se pasa el set de zonas, mira todas las zonas
  * @return pair<int, double>: par con el id de la zona más cercana y la distancia a ella
  */
pair<int, double> DistanciaZonas::get_zona_mas_cercana(int id_zona_actual, const char tipo_zona_necesaria, const set<int>& nodos_por_visitar) const {
  double distancia_mas_cercana = INFINITY;
  int id_zona_mas_cercana = -1;
  int indice_inicial = 0;
  int indice_final = 0;
  int id_zona_objetivo = 0;
  switch (tipo_zona_necesaria) {
    case 'R':
      indice_inicial = this->num_zonas_transferencia_ + 1; // esto situaría el índice en la primera zona de recolección
      indice_final = this->num_zonas_transferencia_ + this->num_zonas_recoleccion_ + 1; // esto situaría el índice en la última zona de recolección
      for (int i = indice_inicial; i < indice_final; i++) {
        id_zona_objetivo++;
        double distancia_actual = this->distancia_zonas_[id_zona_actual][i];
        if (distancia_actual < distancia_mas_cercana && nodos_por_visitar.find(id_zona_objetivo) != nodos_por_visitar.end()) { // si la zona no ha sido recolectada y la distancia es menor que la más cercana
          distancia_mas_cercana = distancia_actual;
          id_zona_mas_cercana = id_zona_objetivo;
        }
      }
      break;
    case 'T':
      indice_inicial = 0; // esto situaría el índice en la primera zona de transferencia
      indice_final = this->num_zonas_transferencia_; // esto situaría el índice en la última zona de transferencia
      for (int i = indice_inicial; i < indice_final; i++) {
        id_zona_objetivo--;
        double distancia_actual = this->distancia_zonas_[id_zona_actual][i];
        if (distancia_actual < distancia_mas_cercana) { // si la zona no ha sido recolectada y la distancia es menor que la más cercana
          distancia_mas_cercana = distancia_actual;
          id_zona_mas_cercana = id_zona_objetivo;
        }
      }
      break;
    case 'V':
      return {INFINITY, this->distancia_zonas_[id_zona_actual][this->distancia_zonas_.size() - 1]}; // si es el vertedero, no hay que mirar nada
    case 'D':
      return {0, this->distancia_zonas_[id_zona_actual][this->num_zonas_transferencia_]}; // si es el depósito
    default:
      break;
  }
  return {id_zona_mas_cercana, distancia_mas_cercana};
}


