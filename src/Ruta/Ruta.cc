// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/29/25
// Archivo Ruta.cc: Implementación de Ruta
//        En este fichero se implementa las funciones de la clase Ruta
//
// Historial de revisiones
//        03/29/25 - Creación (primera versión) del código

#include"Ruta.h"

/** Ruta::Ruta()
  * @brief Crea el objeto de la clase Ruta.
  * @param 
  * @return objeto de la clase Ruta
  */
Ruta::Ruta() {
  this->paradas_ = {};
}

/** Ruta::set_nueva_parada(int parada)
  * @brief Añade una nueva parada a la ruta.
  * @param parada: parada a añadir
  * @return void
  */
void Ruta::set_nueva_parada(int parada) {
  this->paradas_.push_back(parada);
}

/** Ruta::get_nodo(int posicion) const
  * @brief Devuelve el nodo de la ruta en la posición posicion.
  * @param posicion: posición del nodo
  * @return nodo de la ruta en la posición posicion
  */
int Ruta::get_nodo(int posicion) const {
  int paradas_size = this->paradas_.size();
  if (posicion < 0 || posicion > paradas_size - 1) {
    throw invalid_argument("posición " + to_string(posicion) + " fuera de rango");
  }
  return this->paradas_[posicion];
}

/** Ruta::size() const
  * @brief Devuelve el tamaño de la ruta.
  * @return tamaño de la ruta
  */
int Ruta::size() const {
  return this->paradas_.size() ; // para quitar el primer elemento que es el número de circuitos
}

