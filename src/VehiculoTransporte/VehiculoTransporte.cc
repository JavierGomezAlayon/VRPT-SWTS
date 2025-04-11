// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/25/25
// Archivo VehiculoTransporte.cc: Implementación de VehiculoTransporte
//        En este fichero se implementa las funciones de la clase VehiculoTransporte
//
// Historial de revisiones
//        03/25/25 - Creación (primera versión) del código

#include"VehiculoTransporte.h"

/** VehiculoTransporte::VehiculoTransporte()
  * @brief Crea el objeto de la clase VehiculoTransporte.
  * @param 
  * @return objeto de la clase VehiculoTransporte
  */
VehiculoTransporte::VehiculoTransporte() {}

/** VehiculoTransporte::VehiculoTransporte(int id_vehiculo, int id_zona_actual, double tiempo_restante, double capacidad_restante)
  * @brief Crea el objeto de la clase VehiculoTransporte.
  * @param id_vehiculo: id del vehículo
  * @param id_zona_actual: id de la zona actual
  * @param tiempo_restante: tiempo restante
  * @param capacidad_restante: capacidad restante
  * @return objeto de la clase VehiculoTransporte
  */
VehiculoTransporte::VehiculoTransporte(int id_vehiculo, int id_zona_actual, double tiempo_restante, double capacidad_restante) {
  this->id_vehiculo_ = id_vehiculo;
  this->id_zona_actual_ = id_zona_actual;
  this->tiempo_restante_ = tiempo_restante;
  this->capacidad_restante_ = capacidad_restante;
  this->ruta_actual_ = {id_zona_actual};
}

