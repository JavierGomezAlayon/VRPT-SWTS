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
 * @details Esta clase se utiliza como clase padre para la representación de las soluciones de los distintos algoritmos.
 *          Está compuesta por un vector de enteros que representan las paradas de la ruta.
 */
class Ruta {
 public:
  Ruta();  
  virtual void set_nueva_parada(int parada);
  virtual int get_nodo(int id) const;
  virtual int size() const = 0;
 protected:
  vector<int> paradas_;
};

#endif