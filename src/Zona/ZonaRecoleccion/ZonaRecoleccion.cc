// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/05/25
// Archivo ZonaRecoleccion.cc: Implementación de ZonaRecoleccion
//        En este fichero se implementa las funciones de la clase ZonaRecoleccion
//
// Historial de revisiones
//        04/05/25 - Creación (primera versión) del código

#include"ZonaRecoleccion.h"

/** ZonaRecoleccion::ZonaRecoleccion()
  * @brief Crea el objeto de la clase ZonaRecoleccion.
  * @param 
  * @return objeto de la clase ZonaRecoleccion
  */
ZonaRecoleccion::ZonaRecoleccion() {

}

/** ZonaRecoleccion::ZonaRecoleccion(int id_zona, Cordenadas cordenadas, double tiempo, double demanda)
  * @brief Crea el objeto de la clase ZonaRecoleccion.
  * @param id_zona: id de la zona
  * @param cordenadas: coordenadas de la zona
  * @param tiempo: tiempo de recolección
  * @param demanda: demanda de residuos
  * @return objeto de la clase ZonaRecoleccion
  */
ZonaRecoleccion::ZonaRecoleccion(int id_zona, Cordenadas cordenadas, double tiempo, double demanda) {  
  this->id_zona_ = id_zona;
  this->cordenadas_ = cordenadas;
  this->tipo_zona_ = 'R';
  this->tiempo_procesado_ = tiempo;
  this->demanda_ = demanda;
}

/** ZonaRecoleccion::get_tiempo()
  * @brief Devuelve el tiempo de recolección.
  * @return double: tiempo de recolección
  */
double ZonaRecoleccion::get_tiempo() const {
  return tiempo_procesado_;
}

/** ZonaRecoleccion::get_demanda()
  * @brief Devuelve la demanda de residuos.
  * @return double: demanda de residuos
  */
double ZonaRecoleccion::get_demanda() const {
  return demanda_;
}