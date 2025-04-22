// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/14/25
// Archivo VND.h : Declaración de la clase VND
//        En este fichero se declara la clase VND
//
// Historial de revisiones
//        04/14/25 - Creación (primera versión) del código
#ifndef C_VND_H
#define C_VND_H

#include<vector>
#include"../Algoritmo.h"
#include"../../BusquedaLocal/Swap/Swap.h"
#include"../../BusquedaLocal/AdjentSwap/AdjentSwap.h"
#include"../../BusquedaLocal/Insertion/Insertion.h"
#include"../../BusquedaLocal/SubrutaSwap/SubrutaSwap.h"
#include"../../BusquedaLocal/Swap2vect/Swap2vect.h"


/**
 * @brief Clase VND
 * @details Esta clase implementa el algoritmo VND (Variable Neighborhood Descent) para resolver el problema de transporte de residuos.
 *          Es decir se va a encargar de hacer las búsquedas locales para mejorar la solución obtenida por el algoritmo constructivo.
 */
class VND : public Algoritmo {
 public:
  VND();
  Algoritmo& solve() override;
  Algoritmo& set_rutas(vector<RutaRecoleccion> rutas);
  vector<RutaRecoleccion>& get_rutas_optimas();
  void set_busquedas_locales(vector<bool> busquedas_locales);
 private:
  void crear_busquedas_locales();
  double evaluar_rutas(const vector<RutaRecoleccion>& rutas);
  vector<BusquedaLocal*> busquedas_locales_;
  vector<RutaRecoleccion> rutas_;
  vector<bool> busquedas_locales_a_hacer_;
};

#endif