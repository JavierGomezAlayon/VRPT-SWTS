// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/05/25
// Archivo ZonaVertedero.cc: Implementación de ZonaVertedero
//        En este fichero se implementa las funciones de la clase ZonaVertedero
//
// Historial de revisiones
//        04/05/25 - Creación (primera versión) del código

#include"ZonaVertedero.h"

/** ZonaVertedero::ZonaVertedero()
  * @brief Crea el objeto de la clase ZonaVertedero.
  * @param 
  * @return objeto de la clase ZonaVertedero
  */
ZonaVertedero::ZonaVertedero() {

}

/** ZonaVertedero::ZonaVertedero(Cordenadas cordenadas)
  * @brief Crea el objeto de la clase ZonaVertedero.
  * @param cordenadas: Coordenadas de la zona
  * @return objeto de la clase ZonaVertedero
  */
ZonaVertedero::ZonaVertedero(Cordenadas cordenadas) {
  this->cordenadas_ = cordenadas;
  this->id_zona_ = INFINITY; // id = INFINITY para el vertedero
  this->tipo_zona_ = 'V';
}

