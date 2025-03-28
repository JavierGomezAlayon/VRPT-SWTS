// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/25/25
// Archivo Zonas.cc: Implementación de Zonas
//        En este fichero se implementa las funciones de la clase Zonas
//
// Historial de revisiones
//        03/25/25 - Creación (primera versión) del código

#include"Zonas.h"


/**
 * @brief Constructor por defecto de la clase Zonas
 */
Zonas::Zonas() {
  this->zonas_ = {};
}

/**
 * @brief Constructor de la clase Zonas
 * @param zonas 
 */
Zonas::Zonas(std::vector<Zona> zonas) {
  this->zonas_ = zonas;
}

/**
 * @brief Añade una zona a la lista de zonas
 * @param zona 
 */
void Zonas::add_zona(Zona zona) {
  this->zonas_.push_back(zona);
}

/**
 * @brief Calcula las distancias entre las zonas
 */
void Zonas::calcular_distancias() {
  const int num_zonas = this->zonas_.size();
  this->distancias_.resize(num_zonas);
  for (int i = 0; i < num_zonas; i++) {
    this->distancias_[i].resize(num_zonas);
  }
  for (int i = 0; i < num_zonas; i++) {
    for (int j = i + 1; j < num_zonas; j++) {
      float distancia = this->zonas_[i].cordenadas.distancia(this->zonas_[j].cordenadas);
      this->distancias_[i][j] = distancia;
      this->distancias_[j][i] = distancia;
    }
  }
}

/**
 * @brief Devuelve la distancia entre dos zonas
 * @param i id de la zona en la zona en la que estás
 * @param j id de la zona a la que se quiere ir
 * @return float 
 */
float Zonas::get_distancia(int i, int j) const {
  return this->distancias_[i][j];
}
