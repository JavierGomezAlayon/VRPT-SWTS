// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/14/25
// Archivo AdjentSwap.h : Declaración de la clase AdjentSwap
//        En este fichero se declara la clase AdjentSwap
//
// Historial de revisiones
//        04/14/25 - Creación (primera versión) del código
#ifndef C_AdjentSwap_H
#define C_AdjentSwap_H
#include"../BusquedaLocal.h"

/**
 * @brief Clase AdjentSwap
 * @details Esta clase es una implementación de la búsqueda local AdjentSwap.
 *          Se basa en el intercambio de dos rutas adyacentes para mejorar la solución.
 */
class AdjentSwap : public BusquedaLocal {
 public:
  AdjentSwap();
  pair<pair<RutaRecoleccion, RutaRecoleccion>, double> ejecutar(const RutaRecoleccion& ruta1, const RutaRecoleccion& ruta2) override;
  double calcular_coste(const RutaRecoleccion& ruta1, const RutaRecoleccion& ruta_optima1, const RutaRecoleccion& ruta2 = ruta_default, const RutaRecoleccion& ruta_optima2 = ruta_default) override;
  int rutas_necesarias() override;

 private:
 
};

#endif