// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/05/25
// Archivo DistanciaZonas.h : Declaración de la clase DistanciaZonas
//        En este fichero se declara la clase DistanciaZonas
//
// Historial de revisiones
//        04/05/25 - Creación (primera versión) del código
#ifndef C_DistanciaZonas_H
#define C_DistanciaZonas_H
#include <vector>

using namespace std;

/**
 * @brief Clase que representa la distancia entre zonas de todo tipo
 * @details Esta clase pretende ser un abstracción para las distancias entre zonas
 *          de recogida, transferencia y el vertedero.
 *          Permite habiendo dado un vector de zonas, calcular la distancia entre ellas
 *          y guardarlas en un vector de distancias.
 *          Gestionando todas las peticiones de distancia entre cualquier zona
 */
class DistanciaZonas {
 public:
  DistanciaZonas();
  DistanciaZonas();
 private:
  vector<double> distancia_zonas_;
 
};

#endif