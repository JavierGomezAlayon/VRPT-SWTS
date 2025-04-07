// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/05/25
// Archivo ConstructivoVorazRecoleccion.cc: Implementación de ConstructivoVorazRecoleccion
//        En este fichero se implementa las funciones de la clase ConstructivoVorazRecoleccion
//
// Historial de revisiones
//        04/05/25 - Creación (primera versión) del código

#include"ConstructivoVorazRecoleccion.h"

/** ConstructivoVorazRecoleccion::ConstructivoVorazRecoleccion()
  * @brief Crea el objeto de la clase ConstructivoVorazRecoleccion.
  * @param 
  * @return objeto de la clase ConstructivoVorazRecoleccion
  */
ConstructivoVorazRecoleccion::ConstructivoVorazRecoleccion() {

}

/** ConstructivoVorazRecoleccion::solve()
  * @brief Resuelve el problema de recolección de residuos.
  * @return void
  * @details Este algoritmo proporciona una solución guardada en su atributo rutas_ y también en el atributo Tareas_.
  */
void ConstructivoVorazRecoleccion::solve() {
  

}

/** ConstructivoVorazRecoleccion::get_rutas()
  * @brief Devuelve las rutas de recolección.
  * @return vector<Ruta>&: vector de rutas
  */
vector<Ruta>& ConstructivoVorazRecoleccion::get_rutas() {
  return this->rutas_;
}

/** ConstructivoVorazRecoleccion::get_tareas()
  * @brief Devuelve las tareas de recolección.
  * @return vector<Tarea>&: vector de tareas
  */
vector<Tarea>& ConstructivoVorazRecoleccion::get_tareas() {
  return this->Tareas_;
}


