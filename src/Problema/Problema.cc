// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/25/25
// Archivo Problema.cc: Implementación de Problema
//        En este fichero se implementa las funciones de la clase Problema
//
// Historial de revisiones
//        03/25/25 - Creación (primera versión) del código

#include"Problema.h"

/** Problema::Problema()
  * @brief Crea el objeto de la clase Problema.
  * @return objeto de la clase Problema
  */
Problema::Problema() {

}

/** Problema::Problema(DatosProblema datos_problema)
  * @brief Crea el objeto de la clase Problema.
  * @param datos_problema: Datos del problema
  * @return objeto de la clase Problema
  */
Problema::Problema(DatosProblema datos_problema) {
  datos_problema_ = datos_problema;
}

/** Problema::set_datos_problema(DatosProblema datos_problema)
  * @brief Establece los datos del problema.
  * @param datos_problema: Datos del problema
  */
void Problema::set_datos_problema(DatosProblema datos_problema) {
  datos_problema_ = datos_problema;
}

/** Problema::solve()
  * @brief Resuelve el problema.
  * @return void
  */
void Problema::solve() {

}

