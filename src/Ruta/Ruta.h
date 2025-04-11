// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/29/25
// Archivo Ruta.h : Declaración de la clase Ruta
//        En este fichero se declara la clase Ruta
//
// Historial de revisiones
//        03/29/25 - Creación (primera versión) del código
#ifndef C_Ruta_H
#define C_Ruta_H

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Clase que representa una ruta de un vehículo de recolección.
 * @details Esta clase se utiliza para representar la solución del problema de recolección.
 *          Está compuesta por un vector de enteros que representan las paradas de la ruta.
 *          En donde el 0 representa el depósito, los elementos negativos representan las estaciones de transferencia,
 *          y los elementos positivos representan las zonas.
 *          El primer número representa cuántos circuitos se han realizado en dicha ruta.
 */
class Ruta {
 public:
  Ruta();  
  Ruta(vector<int> paradas);
  void set_nueva_parada(int parada);
  void calcular_circuitos();
  int get_nodo(int id) const;
  int size() const;
  int get_circuitos() const;

  friend ostream& operator<<(ostream& os, const Ruta& ruta) ;
 private:
  vector<int> paradas_;
};

#endif