// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/11/25
// Archivo RutaTransporte.cc: Implementación de RutaTransporte
//        En este fichero se implementa las funciones de la clase RutaTransporte
//
// Historial de revisiones
//        04/11/25 - Creación (primera versión) del código

#include"RutaTransporte.h"

/** RutaTransporte::RutaTransporte()
  * @brief Crea el objeto de la clase RutaTransporte.
  * @param 
  * @return objeto de la clase RutaTransporte
  */
RutaTransporte::RutaTransporte() {
  this->paradas_ = {0};
}

/** RutaTransporte::RutaTransporte(vector<int> paradas)
  * @brief Crea el objeto de la clase RutaTransporte.
  * @param paradas: vector de enteros que representan las paradas SIN EL NÚMERO DE CIRCUITOS
  * @return objeto de la clase RutaTransporte
  */
RutaTransporte::RutaTransporte(const vector<int>& paradas) {
  this->paradas_ = paradas;
}

/** RutaTransporte::operator<<
  * @brief Sobrecarga del operador << para imprimir la ruta.
  * @param os: flujo de salida
  * @param ruta: ruta a imprimir
  * @return flujo de salida
  */
ostream& operator<<(ostream& os, const RutaTransporte& ruta) {
  int ruta_size = ruta.paradas_.size();
  for (int i = 0; i < ruta_size; i++) {
    os << ruta.paradas_[i] << " ";
  }
  return os;
}

/** RutaTransporte::get_distancia_total
  * @brief Devuelve la distancia total de la ruta.
  * @param distancia_zonas: objeto de la clase DistanciaZonas
  * @return distancia total de la ruta
  */
double RutaTransporte::get_distancia_total(const DistanciaZonas& distancia_zonas) const {
  double distancia_total = 0;
  int ruta_size = this->paradas_.size();
  int anterior = 0;
  for (int i = 1; i < ruta_size - 1; i++) {
    if (anterior == this->paradas_[i]) {
      continue;
    }
    distancia_total += distancia_zonas.get_distancia(anterior, this->paradas_[i]);
    anterior = this->paradas_[i];
  }
  return distancia_total;
}
/** RutaTransporte::factible
  * @brief Devuelve si la ruta es factible.
  * @param datos_problema: objeto de la clase DatosProblema
  * @param distancia_zonas: objeto de la clase DistanciaZonas
  * @return true si la ruta es factible, false en caso contrario
  */
bool RutaTransporte::factible(const DatosProblema& datos_problema, const DistanciaZonas& distancia_zonas) const {
  if (this->get_distancia_total(distancia_zonas) * 60 / datos_problema.velocidad_vehiculo > datos_problema.duracion_maxima_transporte) {
    return false;
  }
  return true;
}
