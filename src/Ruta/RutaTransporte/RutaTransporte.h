// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/11/25
// Archivo RutaTransporte.h : Declaración de la clase RutaTransporte
//        En este fichero se declara la clase RutaTransporte
//
// Historial de revisiones
//        04/11/25 - Creación (primera versión) del código
#ifndef C_RutaTransporte_H
#define C_RutaTransporte_H

#include"../Ruta.h"

/**
 * @brief Clase que representa una ruta de transporte de un vehículo de transporte.
 * @details Esta clase se utiliza para representar la solución del problema de transporte.
 *          Está compuesta por un vector de enteros que representan las paradas de la ruta.
 *          En donde el 0 representa el dumpsite y los enteron positivos representan las estaciones de transferencia.
 */
class RutaTransporte : public Ruta {
 public:
  RutaTransporte();
  RutaTransporte(const vector<int>& paradas);

};

#endif