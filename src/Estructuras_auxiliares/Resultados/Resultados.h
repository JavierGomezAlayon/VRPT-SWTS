// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/19/25
// Archivo Resultados.h : Declaración de la clase Resultados
//        En este fichero se declara la clase Resultados
//
// Historial de revisiones
//        04/19/25 - Creación (primera versión) del código
#ifndef C_Resultados_H
#define C_Resultados_H
#include"../../Ruta/RutaRecoleccion/RutaRecoleccion.h"
#include"../../Ruta/RutaTransporte/RutaTransporte.h"

struct Resultados {
  vector<RutaRecoleccion> rutas_recoleccion_;
  vector<RutaTransporte> rutas_transporte_;
  double coste_rutas_recoleccion_;
  double coste_rutas_transporte_;
  double coste_total_;
  double tiempo_ejecucion_;
  int num_zonas_;
  int num_candidatos_grasp_;
  int type_; // 0: voraz, 1: grasp, 2: vnd
};

#endif