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

struct DatosProblema {
  int duracion_maxima_recoleccion;
  int duracion_maxima_transporte;
  int num_vehiculos;
  int num_zonas;
  int lx;                     // tamaño del mapa en x
  int ly;                     // tamaño del mapa en y
  int capacidad_vehiculo_recoleccion;
  int capacidad_vehiculo_transporte;
  int velocidad_vehiculo;
  Cordenadas cord_deposito;
  std::vector<Cordenadas> cord_estaciones_transferencia;
  Cordenadas cord_vertedero;
  Zonas zonas;
};

class Problema {
 public:
  Problema();
  Problema(DatosProblema datos_problema);
  void solve();
  void set_datos_problema(DatosProblema datos_problema);
 private:
  DatosProblema datos_problema_;
  // atributos vector para la distancia entre las zonas y el depósito
  // atributo vector para la distancia entre las zonas y las estaciones de transferencia (solo a la más cercana)
};

#endif