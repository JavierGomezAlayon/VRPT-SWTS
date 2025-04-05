// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/05/25
// Archivo ZonaVertedero.h : Declaración de la clase ZonaVertedero
//        En este fichero se declara la clase ZonaVertedero
//
// Historial de revisiones
//        04/05/25 - Creación (primera versión) del código
#ifndef C_ZonaVertedero_H
#define C_ZonaVertedero_H
#include"../../Cordenadas/Cordenadas.h"
#include"../Zona.h"

/**
 * @brief Clase que representa una zona de vertedero.
 * @details Directamente no tiene id, ya que se supone que solo hay un vertedero. 
 */
class ZonaVertedero : public Zona {
 public:
  ZonaVertedero();
  ZonaVertedero(Cordenadas cordenadas);
  int get_id_zona() const;
 private:
 
};

#endif