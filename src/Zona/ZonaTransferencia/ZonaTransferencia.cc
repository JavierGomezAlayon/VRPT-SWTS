// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/05/25
// Archivo ZonaTransferencia.cc: Implementación de ZonaTransferencia
//        En este fichero se implementa las funciones de la clase ZonaTransferencia
//
// Historial de revisiones
//        04/05/25 - Creación (primera versión) del código

#include"ZonaTransferencia.h"

/** ZonaTransferencia::ZonaTransferencia()
  * @brief Crea el objeto de la clase ZonaTransferencia.
  * @param 
  * @return objeto de la clase ZonaTransferencia
  */
ZonaTransferencia::ZonaTransferencia() {

}

/** ZonaTransferencia::ZonaTransferencia(Cordenadas cordenadas)
  * @brief Crea el objeto de la clase ZonaTransferencia.
  * @param cordenadas: Coordenadas de la zona
  * @return objeto de la clase ZonaTransferencia
  */
ZonaTransferencia::ZonaTransferencia(int id_zona, Cordenadas cordenadas) {
  this->cordenadas_ = cordenadas;
  this->tipo_zona_ = 'T';
  this->id_zona_ = -id_zona; 
}
