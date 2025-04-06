// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/05/25
// Archivo Zona.cc: Implementación de Zona
//        En este fichero se implementa las funciones de la clase Zona
//
// Historial de revisiones
//        04/05/25 - Creación (primera versión) del código

#include"Zona.h"

/** Zona::Zona()
  * @brief Crea el objeto de la clase Zona.
  * @param 
  * @return objeto de la clase Zona
  */
Zona::Zona() {

}

/** Zona::get_id_zona()
  * @brief Devuelve el id de la zona.
  * @return int: id de la zona
  */
int Zona::get_id_zona() const {
  return id_zona_;
}

/** Zona::get_cordenadas()
  * @brief Devuelve las cordenadas de la zona.
  * @return Cordenadas: cordenadas de la zona
  */
Cordenadas Zona::get_cordenadas() const {
  return cordenadas_;
}

/** Zona::get_tipo_zona()
  * @brief Devuelve el tipo de la zona.
  * @return char: tipo de la zona
  * @details D = Deposito
  *          R = Recoleccion
  *          T = Transferencia
  *          V = Vertedero
  */
char Zona::get_tipo_zona() const {
  return tipo_zona_;
}


