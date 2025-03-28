// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/25/25
// Archivo Cordenadas.h : Declaración de la clase Cordenadas
//        En este fichero se declara la clase Cordenadas
//
// Historial de revisiones
//        03/25/25 - Creación (primera versión) del código
#ifndef C_Cordenadas_H
#define C_Cordenadas_H

#include<iostream>
#include<cmath>

class Cordenadas {
 public:
  Cordenadas(int x = 0, int y = 0);
  int get_x() const;
  int get_y() const;
  float distancia(const Cordenadas &cordenadas) const;
  // sobrecarga de operadores
  bool operator==(const Cordenadas &cordenadas) const;
  bool operator<(const Cordenadas &cordenadas) const;
  bool operator>(const Cordenadas &cordenadas) const;
  friend std::ostream& operator<<(std::ostream &os, const Cordenadas &cordenadas);

 private:
  int x_;
  int y_;
 
};

#endif