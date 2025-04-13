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

#include<iostream>
#include<vector>
#include<limits>
#include"../Estructuras_auxiliares/Tarea/Tarea.h"

using namespace std;

/**
 * @brief Clase que representa un vehículo de transporte.
 * @details Esta clase se utiliza para la abstracción necesaria para los vehículos de transporte
 *          Además se encarga de la creación de los vehículos de transporte.
 */
class VehiculoTransporte {
 public:
  static VehiculoTransporte crear_vehiculo(double capacidad_restante, int zona_actual = 0, double tiempo_en_ruta = 0);
  vector<int> get_ruta() const;
  void asignar_tarea(Tarea& tarea, double tiempo_inicial = std::numeric_limits<double>::infinity());
  double get_tiempo_actual() const;
  double get_capacidad_restante() const;
  double get_tiempo_en_ruta() const;
  void agregar_destino_vertedero(int capacidad_vehiculo, double distancia_hasta_deposito);
  int getZonaActual();
  static void resetIdVehiculo();
 private:
  VehiculoTransporte(int id_vehiculo, int id_zona_actual, double capacidad_restante, double tiempo_restante = 0);
  int id_vehiculo_;
  int id_zona_actual_;
  double tiempo_en_ruta_;
  double tiempo_actual_;
  double tiempo_inicial_;
  double capacidad_restante_; 
  vector<int> ruta_actual_;
  static int id_vehiculo_inicial_;
};

#endif