// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/25/25
// Archivo VehiculoTransporte.h : Declaración de la clase VehiculoTransporte
//        En este fichero se declara la clase VehiculoTransporte
//
// Historial de revisiones
//        03/25/25 - Creación (primera versión) del código
#ifndef C_VehiculoTransporte_H
#define C_VehiculoTransporte_H

#include"../Ruta/Ruta.h"

/**
 * @brief Clase que representa un vehículo de transporte.
 * @details Esta clase se utiliza para la abstracción necesaria para los vehículos de transporte
 */
class VehiculoTransporte {
 public:
  VehiculoTransporte();
 private:
  int id_vehiculo_;
  int id_zona_actual_;
  double tiempo_restante_;
  double capacidad_restante_; 
  vector<int> ruta_actual_;
  double tiempo_regreso_;
};

#endif