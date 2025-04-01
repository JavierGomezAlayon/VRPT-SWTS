// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/25/25
// Archivo VehiculoRecoleccion.h : Declaración de la clase VehiculoRecoleccion
//        En este fichero se declara la clase VehiculoRecoleccion
//
// Historial de revisiones
//        03/25/25 - Creación (primera versión) del código
#ifndef C_VehiculoRecoleccion_H
#define C_VehiculoRecoleccion_H

#include"../Ruta/Ruta.h"

class VehiculoRecoleccion {
 public:
  VehiculoRecoleccion();
 private:
  int id_vehiculo_;
  int id_zona_actual_;
  double tiempo_restante_;
  double capacidad_restante_; 
  Ruta ruta_actual_;
  double tiempo_regreso_;
};

#endif