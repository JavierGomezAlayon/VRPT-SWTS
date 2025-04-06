// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/05/25
// Archivo ZonaTransferencia.h : Declaración de la clase ZonaTransferencia
//        En este fichero se declara la clase ZonaTransferencia
//
// Historial de revisiones
//        04/05/25 - Creación (primera versión) del código
#ifndef C_ZonaTransferencia_H
#define C_ZonaTransferencia_H
#include"../../Cordenadas/Cordenadas.h"
#include"../Zona.h"
/**
 * @brief Clase que representa una zona de transferencia.
 * @details Su id es negativo (menor que 0).
 */
class ZonaTransferencia : public Zona {
 public:
  ZonaTransferencia();
  ZonaTransferencia(int id_zona, Cordenadas& cordenadas);
 private:
  
};

#endif