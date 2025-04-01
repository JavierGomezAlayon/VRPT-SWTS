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
    this->distancias_[i][i] = INFINITY; // la distancia a si mismo es infinita
    for (int j = i + 1; j < num_zonas; j++) {
      double distancia = this->zonas_[i].cordenadas.distancia(this->zonas_[j].cordenadas);
      this->distancias_[i][j] = distancia;
      this->distancias_[j][i] = distancia;
    }
  }
}

/**
 * @brief Devuelve la distancia entre dos zonas
 * @param id_nodo_actual id de la zona en la zona en la que estás
 * @param id_nodo_objetivo id de la zona a la que se quiere ir
 * @return double 
 * @throw std::out_of_range si el id de la zona no es válido (tiene que ser desde 1 hasta el número de zonas)
 */
double Zonas::get_distancia(int id_nodo_actual, int id_nodo_objetivo) const {
  if (id_nodo_actual < 1 || id_nodo_actual > this->zonas_.size() || id_nodo_objetivo < 1 || id_nodo_objetivo > this->zonas_.size()) {
    throw std::out_of_range("El id de la zonas " + std::to_string(id_nodo_actual) + "," + std::to_string(id_nodo_objetivo) + " no es válido para pedir la distancia");
  }
  id_nodo_actual--; // restamos uno para que sea el índice
  id_nodo_objetivo--; // restamos uno para que sea el índice
  return this->distancias_[id_nodo_actual][id_nodo_objetivo];
}


/**
 * @brief Devuelve la zona más cercana a la zona id_zona_actual
 * @param id_zona_actual id de la zona en la que estás
 * @param nodos_por_visitar set de zonas que no han sido recogidas
 * @details Si no se pasa el set de zonas, mira todas las zonas
 * @return int id de la zona más cercana
 * @throw std::out_of_range si el id de la zona no es válido (tiene que ser desde 1 hasta el número de zonas)
 */
int Zonas::get_zona_mas_cercana(int id_zona_actual, const set<int>& nodos_por_visitar) const {
  if (id_zona_actual < 1 || id_zona_actual > this->zonas_.size()) {
    throw std::out_of_range("El id de la zona " + to_string(id_zona_actual) + " no es válido");
  }
  id_zona_actual--; // restamos uno para que sea el índice
  double distancia_mas_cercana = INFINITY;
  int zona_mas_cercana;
  for (int j = 0; j < this->zonas_.size(); j++) { // mira todas las zonas
    if (nodos_por_visitar.find(j + 1) != nodos_por_visitar.end() && this->distancias_[id_zona_actual][j] < distancia_mas_cercana) { // si la zona no ha sido recolectada y la distancia es menor que la más cercana
      distancia_mas_cercana = this->distancias_[id_zona_actual][j];
      zona_mas_cercana = j;
    }
  }
  return zona_mas_cercana + 1; // sumamos uno para que sea el id
}

/**
 * @brief Devuelve la zona más cercana a la zona i
 * @param cordenadas_actuales coordenadas de la zona en la que estás
 * @return double 
 */
int Zonas::get_zona_mas_cercana(Cordenadas cordenadas_actuales, const set<int>& nodos_por_visitar) const {
  double distancia_mas_cercana = INFINITY;
  int zona_mas_cercana = -1;
  for (int j = 0; j < this->zonas_.size(); j++) {
    if (nodos_por_visitar.find(j + 1) != nodos_por_visitar.end() && cordenadas_actuales.distancia(this->zonas_[j].cordenadas) < distancia_mas_cercana) {
      distancia_mas_cercana = cordenadas_actuales.distancia(this->zonas_[j].cordenadas);
      zona_mas_cercana = j;
    }
  }
  return zona_mas_cercana + 1; // sumamos uno para que sea el id
}

/**
 * @brief Devuelve la zona i
 * @param id_zona id de la zona
 * @return Zona 
 * @throw std::out_of_range si el id de la zona no es válido (tiene que ser desde 1 hasta el número de zonas)
 */
Zona Zonas::get_zona(int id_zona) const {
  if (id_zona < 1 || id_zona > this->zonas_.size()) {
    throw std::out_of_range("El id de la zona " + to_string(id_zona) + " no es válido");
  }
  return this->zonas_[id_zona - 1]; // restamos uno para que sea el índice
}

/**
 * @brief Devuelve el tamaño del vector de zonas
 * @return int 
 */
int Zonas::size() const {
  return this->zonas_.size();
}
