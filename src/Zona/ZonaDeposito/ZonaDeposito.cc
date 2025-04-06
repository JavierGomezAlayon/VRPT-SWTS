// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/05/25
// Archivo ZonaDeposito.cc: Implementación de ZonaDeposito
//        En este fichero se implementa las funciones de la clase ZonaDeposito
//
// Historial de revisiones
//        04/05/25 - Creación (primera versión) del código

#include"ZonaDeposito.h"

/** ZonaDeposito::ZonaDeposito()
  * @brief Crea el objeto de la clase ZonaDeposito.
  * @param 
  * @return objeto de la clase ZonaDeposito
  */
ZonaDeposito::ZonaDeposito() {

}

/** ZonaDeposito::ZonaDeposito(Cordenadas cordenadas)
  * @brief Crea el objeto de la clase ZonaDeposito.
  * @param cordenadas: Coordenadas de la zona
  * @return objeto de la clase ZonaDeposito
  */
ZonaDeposito::ZonaDeposito(Cordenadas cordenadas) {
  this->cordenadas_ = cordenadas;
  this->id_zona_ = 0; // id = 0 para el depósito
  this->tipo_zona_ = 'D';
}

