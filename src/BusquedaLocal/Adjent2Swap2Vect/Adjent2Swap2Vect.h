// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/14/25
// Archivo Adjent2Swap2Vect.h : Declaración de la clase Adjent2Swap2Vect
//        En este fichero se declara la clase Adjent2Swap2Vect
//
// Historial de revisiones
//        04/14/25 - Creación (primera versión) del código
#ifndef C_Adjent2Swap2Vect_H
#define C_Adjent2Swap2Vect_H
#include"../BusquedaLocal.h"


class Adjent2Swap2Vect : public BusquedaLocal {
 public:
  Adjent2Swap2Vect();
  pair<pair<RutaRecoleccion, RutaRecoleccion>, double> ejecutar(const RutaRecoleccion& ruta1, const RutaRecoleccion& ruta2) override;
  double calcular_coste(const RutaRecoleccion& ruta1, const RutaRecoleccion& ruta_optima1, const RutaRecoleccion& ruta2 = ruta_default, const RutaRecoleccion& ruta_optima2 = ruta_default) override;
 private:
 
};

#endif