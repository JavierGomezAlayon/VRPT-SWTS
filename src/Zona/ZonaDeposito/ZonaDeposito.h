// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/05/25
// Archivo ZonaDeposito.h : Declaración de la clase ZonaDeposito
//        En este fichero se declara la clase ZonaDeposito
//
// Historial de revisiones
//        04/05/25 - Creación (primera versión) del código
#ifndef C_ZonaDeposito_H
#define C_ZonaDeposito_H
#include"../../Cordenadas/Cordenadas.h"
#include"../Zona.h"

/**
 * @brief Clase que representa una zona de depósito.
 *        Se supone que solo habrá un depósito en el problema. con lo cual se podría hacer una clase singleton.
 * @details Su id es 0 siempre (solo hay un depósito)
 */
class ZonaDeposito : public Zona {
 public:
  ZonaDeposito();
  ZonaDeposito(Cordenadas& cordenadas);
 private:
};

#endif