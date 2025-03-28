// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/25/25
// Archivo Problema.h : Declaración de la clase Problema
//        En este fichero se declara la clase Problema
//
// Historial de revisiones
//        03/25/25 - Creación (primera versión) del código
#ifndef C_Problema_H
#define C_Problema_H

#include"../Zonas/Zonas.h"


class Problema {
 public:
  Problema();
  //void Algoritmo1();
 private:
  Zonas zonas_;
  // atributos vector para la distancia entre las zonas y el depósito
  // atributo vector para la distancia entre las zonas y las estaciones de transferencia (solo a la más cercana)
};

#endif