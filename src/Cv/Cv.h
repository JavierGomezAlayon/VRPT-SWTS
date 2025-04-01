// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/25/25
// Archivo Cv.h : Declaración de la clase Cv
//        En este fichero se declara la clase Cv
//
// Historial de revisiones
//        03/25/25 - Creación (primera versión) del código
#ifndef C_Cv_H
#define C_Cv_H

class Cv {
 public:
  Cv();
 private:
  int id_vehiculo_;
  int id_zona_actual_;
  double tiempo_restante_;
  double capacidad_restante_; 
};

#endif