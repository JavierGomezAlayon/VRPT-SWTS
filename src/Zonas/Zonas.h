// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/25/25
// Archivo Zonas.h : Declaración de la clase Zonas
//        En este fichero se declara la clase Zonas
//
// Historial de revisiones
//        03/25/25 - Creación (primera versión) del código
#ifndef C_Zonas_H
#define C_Zonas_H

#include<vector>
#include"../Cordenadas/Cordenadas.h"

using namespace std;

struct Zona {
  int id;
  Cordenadas cordenadas;
  float d1;                 // Representa el hueco de la zona
  float d2;                 // Representa la capacidad de la zona
  float demanda;            // d2 - d1
};

class Zonas {
 public:
  Zonas();
  Zonas(vector<Zona> zonas);
  void add_zona(Zona zona);
  void calcular_distancias();
  float get_distancia(int i, int j) const;
  int size() const;
 private:
  vector<Zona> zonas_;
  vector<vector<float>> distancias_;
};

#endif