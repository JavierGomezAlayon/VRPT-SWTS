// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/05/25
// Archivo Zona.h : Declaración de la clase Zona
//        En este fichero se declara la clase Zona
//
// Historial de revisiones
//        04/05/25 - Creación (primera versión) del código
#ifndef C_Zona_H
#define C_Zona_H
#include"../Cordenadas/Cordenadas.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

/**
 * @brief Clase que representa una zona de recogida, transferencia, vertedero o depósito.
 * @details Esta clase se encarga de representar la clase padre de las zonas de recogida, transferencia y vertedero.
 *          Más que nada son contenedores de información sin casi funcionalidades añadidas.
 */
class Zona {
 public:
  Zona();
  // Getters
  int get_id_zona() const;
  Cordenadas get_cordenadas() const;
  char get_tipo_zona() const;
  virtual double get_tiempo() const;
  virtual double get_demanda() const;
 protected:
  char tipo_zona_;
  int id_zona_;
  Cordenadas cordenadas_;

};


void ordenar_zonas(vector<Zona*>& zonas);

#endif