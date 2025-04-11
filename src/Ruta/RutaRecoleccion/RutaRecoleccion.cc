// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/29/25
// Archivo RutaRecoleccion.cc: Implementación de RutaRecoleccion
//        En este fichero se implementa las funciones de la clase RutaRecoleccion
//
// Historial de revisiones
//        03/29/25 - Creación (primera versión) del código

#include"RutaRecoleccion.h"

/** RutaRecoleccion::RutaRecoleccion()
  * @brief Crea el objeto de la clase RutaRecoleccion.
  * @param 
  * @return objeto de la clase RutaRecoleccion
  */
RutaRecoleccion::RutaRecoleccion() {
  this->paradas_ = {0};
}

/** RutaRecoleccion::RutaRecoleccion(vector<int> paradas)
  * @brief Crea el objeto de la clase RutaRecoleccion.
  * @param paradas: vector de enteros que representan las paradas SIN EL NÚMERO DE CIRCUITOS
  * @return objeto de la clase RutaRecoleccion
  */
RutaRecoleccion::RutaRecoleccion(vector<int> paradas) {
  this->paradas_ = paradas;
  if (this->paradas_.empty()) {
    this->paradas_.push_back(0); // Asegura que siempre haya un elemento inicial
  } else {
    this->paradas_.insert(this->paradas_.begin(), 0); // Inserta el número de circuitos al principio
  }
}

/** RutaRecoleccion::calcular_circuitos()
  * @brief Calcula el número de circuitos de la rutaRecoleccion.
  * @return void
  */
void RutaRecoleccion::calcular_circuitos() {
  if (this->paradas_.empty()) {
    throw std::runtime_error("El vector de paradas está vacío en calcular_circuitos");
  }

  int circuitos = 0;
  int paradas_size = this->paradas_.size();
  for (int i = 1; i < paradas_size; i++) {
    if (this->paradas_[i] < 0) { // cada vez que pasa por una estación de transferencia
      circuitos++;
    }
  }
  this->paradas_[0] = circuitos;
}


/** RutaRecoleccion::operator<<
  * @brief Sobrecarga del operador << para imprimir la rutaRecoleccion.
  * @param os: flujo de salida
  * @param rutaRecoleccion: rutaRecoleccion a imprimir
  * @return flujo de salida
  */
ostream& operator<<(ostream& os, const RutaRecoleccion& rutaRecoleccion) {
  os << "RutaRecoleccion: ";
  int paradas_size = rutaRecoleccion.paradas_.size();
  for (int i = 0; i < paradas_size; i++) {
    os << rutaRecoleccion.paradas_[i] << " ";
  }
  return os;
}

/** RutaRecoleccion::get_nodo(int posicion) const
  * @brief Devuelve el nodo de la rutaRecoleccion en la posición posicion.
  * @param posicion: posición del nodo
  * @return entero de la rutaRecoleccion en la posición dada
  */
int RutaRecoleccion::get_nodo(int posicion) const {
  int paradas_size = this->paradas_.size();
  if (posicion == 0 || posicion == paradas_size - 2) {
    return 0; // el depósito
  }
  int indice = posicion + 1; // para quitar el primer elemento que es el número de circuitos
  return Ruta::get_nodo(indice);
}

/** RutaRecoleccion::size() const
  * @brief Devuelve el tamaño de la rutaRecoleccion.
  * @return tamaño de la rutaRecoleccion
  */
int RutaRecoleccion::size() const {
  return this->paradas_.size() - 1; // para quitar el primer elemento que es el número de circuitos
}

/** RutaRecoleccion::get_circuitos() const
  * @brief Devuelve el número de circuitos de la rutaRecoleccion.
  * @return número de circuitos de la rutaRecoleccion
  */
int RutaRecoleccion::get_circuitos() const {
  return this->paradas_[0];
}

