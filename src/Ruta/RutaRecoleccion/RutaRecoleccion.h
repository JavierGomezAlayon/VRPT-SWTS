// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/29/25
// Archivo RutaRecoleccion.h : Declaración de la clase RutaRecoleccion
//        En este fichero se declara la clase RutaRecoleccion
//
// Historial de revisiones
//        03/29/25 - Creación (primera versión) del código
#ifndef C_RutaRecoleccion_H
#define C_RutaRecoleccion_H

#include"../Ruta.h"
#include "../../Estructuras_auxiliares/Datos_problema/Datos_problema.h"
#include"../../DistanciaZonas/DistanciaZonas.h"

/**
 * @brief Clase que representa una rutaRecoleccion de un vehículo de recolección.
 * @details Esta clase se utiliza para representar la solución del problema de recolección.
 *          Está compuesta por un vector de enteros que representan las paradas de la rutaRecoleccion.
 *          En donde el 0 representa el depósito, los elementos negativos representan las estaciones de transferencia,
 *          y los elementos positivos representan las zonas.
 *          El primer número representa cuántos circuitos se han realizado en dicha rutaRecoleccion.
 */
class RutaRecoleccion : public Ruta {
 public:
  RutaRecoleccion();  
  RutaRecoleccion(vector<int> paradas);
  void calcular_circuitos();
  int get_nodo(int id) const override;
  int size() const override;
  int get_circuitos() const;
  void swap(int indice1, int indice2);
  int intercambiar_parada(int parada, int indice);
  vector<int> get_subruta(int id) const;
  void quitar_parada(int indice);
  void anadir_parada(int parada, int indice);
  double get_distancia_total(const DistanciaZonas& distancia_zonas) const override;
  bool factible(const DatosProblema& datos_problema, const DistanciaZonas& distancia_zonas) const override;
  // double get_distancia() const;

  friend ostream& operator<<(ostream& os, const RutaRecoleccion& rutaRecoleccion) ;
};

#endif