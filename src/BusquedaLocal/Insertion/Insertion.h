// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/14/25
// Archivo Insertion.h : Declaración de la clase Insertion
//        En este fichero se declara la clase Insertion
//
// Historial de revisiones
//        04/14/25 - Creación (primera versión) del código
#ifndef C_Insertion_H
#define C_Insertion_H
#include"../BusquedaLocal.h"


class Insertion : public BusquedaLocal {
 public:
  Insertion();
  pair<pair<RutaRecoleccion, RutaRecoleccion>, double> ejecutar(const RutaRecoleccion& ruta1, const RutaRecoleccion& ruta2) override;
  double calcular_coste(const RutaRecoleccion& ruta1, const RutaRecoleccion& ruta_optima1, const RutaRecoleccion& ruta2 = ruta_default, const RutaRecoleccion& ruta_optima2 = ruta_default) override;
 private:
 
};

#endif