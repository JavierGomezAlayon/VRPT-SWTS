// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/05/25
// Archivo Algoritmo.cc: Implementación de Algoritmo
//        En este fichero se implementa las funciones de la clase Algoritmo
//
// Historial de revisiones
//        04/05/25 - Creación (primera versión) del código

#include"Algoritmo.h"

/** Algoritmo::Algoritmo()
  * @brief Crea el objeto de la clase Algoritmo.
  * @param 
  * @return objeto de la clase Algoritmo
  */
Algoritmo::Algoritmo() {

}

/** Algoritmo::obtener_zona(int id_zona)
  * @brief Devuelve la zona con el id dado.
  * @param id_zona: id de la zona
  * @return Zona*: puntero a la zona o nullptr si no existe
  */
Zona* Algoritmo::obtener_zona(int id_zona) const {
for (int i = 0; i < this->datos_problema_.zonas.size(); i++) {
    if (this->datos_problema_.zonas[i]->get_id_zona() == id_zona) {
      return this->datos_problema_.zonas[i];
    }
  }
  return nullptr;
}

/** Algoritmo::set_datos_problema(const DatosProblema& datos_problema)
  * @brief Establece los datos del problema.
  * @param datos_problema: datos del problema
  * @return 
  */
void Algoritmo::set_datos_problema(const DatosProblema& datos_problema) {
  this->datos_problema_ = datos_problema;
}

/** Algoritmo::set_distancia_zonas(const DistanciaZonas& distancia_zonas)
  * @brief Establece la distancia entre zonas.
  * @param distancia_zonas: distancia entre zonas
  * @return 
  */
void Algoritmo::set_distancia_zonas(const DistanciaZonas& distancia_zonas) {
  this->distancia_zonas_ = distancia_zonas;
}
