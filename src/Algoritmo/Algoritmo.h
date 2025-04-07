// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/05/25
// Archivo Algoritmo.h : Declaración de la clase Algoritmo
//        En este fichero se declara la clase Algoritmo
//
// Historial de revisiones
//        04/05/25 - Creación (primera versión) del código
#ifndef C_Algoritmo_H
#define C_Algoritmo_H
#include"../DistanciaZonas/DistanciaZonas.h"
#include"../Estructuras_auxiliares/Datos_problema/Datos_problema.h"


class Algoritmo {
 public:
  Algoritmo();
  void set_datos_problema(const DatosProblema& datos_problema);
  void set_distancia_zonas(const DistanciaZonas& distancia_zonas);
  virtual void solve() = 0;
  protected:
  Zona* obtener_zona(int id_zona) const;
  DatosProblema datos_problema_;
  DistanciaZonas distancia_zonas_;
};

#endif