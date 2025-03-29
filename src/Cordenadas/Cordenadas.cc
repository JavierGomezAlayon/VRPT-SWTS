// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/25/25
// Archivo Cordenadas.cc: Implementación de Cordenadas
//        En este fichero se implementa las funciones de la clase Cordenadas
//
// Historial de revisiones
//        03/25/25 - Creación (primera versión) del código

#include"Cordenadas.h"






/**
 * @brief Constructor de la clase Cordenadas
 * @param x 
 * @param y 
 */
Cordenadas::Cordenadas(int x, int y) {
  if (x < 0 || y < 0) {
    throw std::invalid_argument("Los valores de x e y no pueden ser negativos");
  }
  this->x_ = x;
  this->y_ = y;
}

/**
 * @brief Devuelve el valor de x
 * @return int 
 */
int Cordenadas::get_x() const {
  return x_;
}

/**
 * @brief Devuelve el valor de y
 * @return int 
 */
int Cordenadas::get_y() const {
  return y_;
}

/**
 * @brief Calcula la distancia euclidiana entre dos cordenadas
 * @param cordenadas 
 * @return float 
 */
float Cordenadas::distancia(const Cordenadas &cordenadas) const {
  return sqrt(pow(this->x_ - cordenadas.x_, 2) + pow(this->y_ - cordenadas.y_, 2));
}

/**
 * @brief Sobrecarga del operador << para imprimir las cordenadas
 * @param os 
 * @param cordenadas 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &os, const Cordenadas &cordenadas) {
  os << "(" << cordenadas.x_ << ", " << cordenadas.y_ << ")";
  return os;
}

/**
 * @brief Sobrecarga del operador == para comparar dos cordenadas
 * @param cordenadas 
 * @return true 
 * @return false 
 */
bool Cordenadas::operator==(const Cordenadas &cordenadas) const {
  return (this->x_ == cordenadas.x_ && this->y_ == cordenadas.y_);
}

/**
 * @brief Sobrecarga del operador < para comparar dos cordenadas
 * @param cordenadas 
 * @return true 
 * @return false 
 */
bool Cordenadas::operator<(const Cordenadas &cordenadas) const {
  if (this->x_ < cordenadas.x_) {
    return true;
  } else if (this->x_ == cordenadas.x_) {
    return this->y_ < cordenadas.y_;
  }
  return false;
}

/**
 * @brief Sobrecarga del operador > para comparar dos cordenadas
 * @param cordenadas 
 * @return true 
 * @return false 
 */
bool Cordenadas::operator>(const Cordenadas &cordenadas) const {
  if (this->x_ > cordenadas.x_) {
    return true;
  } else if (this->x_ == cordenadas.x_) {
    return this->y_ > cordenadas.y_;
  }
  return false;
}

