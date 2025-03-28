// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/25/25
// Archivo funciones_main.h: Declaración de las funciones del main
//        En este fichero se declara las funciones que se utilizan en el main.cc
//
// Historial de revisiones
//        03/25/25 - Creación (primera versión) del código
#ifndef C_funciones_main_H
#define C_funciones_main_H

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<regex>

#include"../Cordenadas/Cordenadas.h"
#include"../Zonas/Zonas.h"

struct Dato {
  bool correcto;
  std::string fichero;
};

struct DatosProblema {
  int duracion_maxima_recoleccion;
  int duracion_maxima_transporte;
  int num_vehiculos;
  int num_zonas;
  int lx;                     // ?
  int ly;                     // ?
  int capacidad_vehiculo_recoleccion;
  int capacidad_vehiculo_transporte;
  int velocidad_vehiculo;
  Cordenadas cord_deposito;
  std::vector<Cordenadas> cord_estaciones_transferencia;
  Cordenadas cord_vertedero;
  Zonas zonas;
};

Dato recoger_parametro(int argc, char *argv[]);
void mostrar_ayuda();
void mostrar_ayuda_resumida();
void menu();
void mostrar_ayuda_menu();
DatosProblema leer_fichero(std::string fichero);
void actualizar_datos(DatosProblema &datos_problema, std::istringstream &sslinea);
void coger_zonas(std::ifstream &file, DatosProblema &datos_problema);
string lowercase(string str);

#endif