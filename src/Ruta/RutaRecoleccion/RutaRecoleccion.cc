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

/** RutaRecoleccion::swap(int indice1, int indice2)
  * @brief Intercambia dos nodos de la rutaRecoleccion.
  * @param indice1: índice del primer nodo
  * @param indice2: índice del segundo nodo
  * @return void
  */
void RutaRecoleccion::swap(int indice1, int indice2) {
  if (indice1 < 0 || indice1 >= this->paradas_.size() || indice2 < 0 || indice2 >= this->paradas_.size()) {
    throw std::out_of_range("Índice fuera de rango");
  }
  indice1++;
  indice2++;
  int temp = this->paradas_[indice1];
  this->paradas_[indice1] = this->paradas_[indice2];
  this->paradas_[indice2] = temp;
  return;
}

/** RutaRecoleccion::factible(DatosProblema& datos_problema, DistanciaZonas& distancia_zonas)
  * @brief Comprueba si la rutaRecoleccion es factible.
  * @param datos_problema: datos del problema
  * @param distancia_zonas: distancias entre zonas
  * @return true si es factible, false en caso contrario
  */
bool RutaRecoleccion::factible(DatosProblema& datos_problema, DistanciaZonas& distancia_zonas) {
  double tiempo_total = 0;
  double cantidad_residuos = 0;
  int paradas_size = this->paradas_.size();
  for(int i = 2; i < paradas_size; i++) { // recorro los nodos sin contar el número de circuitos
    int indice_nodo = this->paradas_[i];
    tiempo_total += distancia_zonas.get_distancia(this->paradas_[i - 1], indice_nodo) * 60 / datos_problema.velocidad_vehiculo; // calculo el tiempo entre el nodo anterior y el nodo actual
    if (indice_nodo < 0) { // Si es una estación de transferencia
      if (cantidad_residuos > datos_problema.capacidad_vehiculo_recoleccion) {
        return false; // La cantidad de residuos supera la capacidad del vehículo
      }
      cantidad_residuos = 0; // Reseteo la cantidad de residuos
    } else if (indice_nodo == 0) { // Si es el depósito
      if (cantidad_residuos > 0) {
        return false; // No se puede llevar residuos al depósito
      }
      if (tiempo_total > datos_problema.duracion_maxima_recoleccion) {
        return false; // el tiempo total supera el máximo
      }
    } else { // Si es una zona
      cantidad_residuos += datos_problema.obtener_zona(indice_nodo)->get_demanda();
      tiempo_total += datos_problema.obtener_zona(indice_nodo)->get_tiempo();
    }
  } 
  return true;
}


