// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/14/25
// Archivo Swap.h : Declaración de la clase Swap
//        En este fichero se declara la clase Swap
//
// Historial de revisiones
//        04/14/25 - Creación (primera versión) del código
#ifndef C_Swap_H
#define C_Swap_H

#include"../BusquedaLocal.h"
/**
 * @brief Clase Swap
 * @details Esta clase es una implementación de la búsqueda local Swap.
 *          Se basa en el intercambio de dos rutas para mejorar la solución.
 */
class Swap : public BusquedaLocal {
 public:
  Swap();
  pair<pair<RutaRecoleccion, RutaRecoleccion>, double> ejecutar(const RutaRecoleccion& ruta1, const RutaRecoleccion& ruta2) override;
  double calcular_coste(const RutaRecoleccion& ruta1, const RutaRecoleccion& ruta_optima1, const RutaRecoleccion& ruta2 = ruta_default, const RutaRecoleccion& ruta_optima2 = ruta_default) override;
  int rutas_necesarias() override;
 private:
 
};

#endif