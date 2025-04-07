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
  paradas_ = {0};
}

/** Ruta::Ruta(vector<int> paradas)
  * @brief Crea el objeto de la clase Ruta.
  * @param paradas: vector de enteros que representan las paradas SIN EL NÚMERO DE CIRCUITOS
  * @return objeto de la clase Ruta
  */
Ruta::Ruta(vector<int> paradas) {
  int paradas_size = paradas.size();
  paradas_.resize(paradas_size + 1);
  for (int i = 0; i < paradas_size; i++) { // meto todas las paradas pero desplazadas una posición
    paradas_[i + 1] = paradas[i];
  }
}

/** Ruta::set_nueva_parada(int parada)
  * @brief Añade una nueva parada a la ruta.
  * @param parada: parada a añadir
  * @return void
  */
void Ruta::set_nueva_parada(int parada) {
  paradas_.push_back(parada);
}

/** Ruta::calcular_circuitos()
  * @brief Calcula el número de circuitos de la ruta.
  * @return void
  */
void Ruta::calcular_circuitos() {
  int circuitos = 0;
  int paradas_size = paradas_.size();
  for (int i = 1; i < paradas_size; i++) {
    if (paradas_[i] < 0) { // cada vez que pasa por una estación de transferencia
      circuitos++;
    }
  }
  paradas_[0] = circuitos;
}


/** Ruta::operator<<
  * @brief Sobrecarga del operador << para imprimir la ruta.
  * @param os: flujo de salida
  * @param ruta: ruta a imprimir
  * @return flujo de salida
  */
ostream& operator<<(ostream& os, const Ruta& ruta) {
  os << "Ruta: ";
  int paradas_size = ruta.paradas_.size();
  for (int i = 0; i < paradas_size; i++) {
    os << ruta.paradas_[i] << " ";
  }
  return os;
}

/** Ruta::get_nodo(int posicion) const
  * @brief Devuelve el nodo de la ruta en la posición posicion.
  * @param posicion: posición del nodo
  * @return nodo de la ruta en la posición posicion
  */
int Ruta::get_nodo(int posicion) const {
  if (posicion < 0 || posicion > paradas_.size() - 1) {
    throw invalid_argument("posición fuera de rango");
  }
  if (posicion == 0 || posicion == paradas_.size() - 1) {
    return 0; // el depósito
  }
  int indice = posicion + 1; // para quitar el primer elemento que es el número de circuitos
  return paradas_[indice];
}

/** Ruta::size() const
  * @brief Devuelve el tamaño de la ruta.
  * @return tamaño de la ruta
  */
int Ruta::size() const {
  return paradas_.size() - 1; // para quitar el primer elemento que es el número de circuitos
}

/** Ruta::get_circuitos() const
  * @brief Devuelve el número de circuitos de la ruta.
  * @return número de circuitos de la ruta
  */
int Ruta::get_circuitos() const {
  return paradas_[0];
}

