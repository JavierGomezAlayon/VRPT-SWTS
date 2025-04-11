// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/05/25
// Archivo ConstructivoVorazTransporte.cc: Implementación de ConstructivoVorazTransporte
//        En este fichero se implementa las funciones de la clase ConstructivoVorazTransporte
//
// Historial de revisiones
//        04/05/25 - Creación (primera versión) del código

#include"ConstructivoVorazTransporte.h"

/** ConstructivoVorazTransporte::ConstructivoVorazTransporte()
  * @brief Crea el objeto de la clase ConstructivoVorazTransporte.
  * @param 
  * @return objeto de la clase ConstructivoVorazTransporte
  */
 ConstructivoVorazTransporte::ConstructivoVorazTransporte() {}

/** ConstructivoVorazTransporte::solve()
  * @brief Resuelve el problema de transporte de residuos.
  * @return this Devuelve el propio objeto para permitir la encadenación de llamadas.
  */
 Algoritmo& ConstructivoVorazTransporte::solve() {
  this->CalcularTareas();
  this->CalcularRutasTransporte();
  return *this;
}

/** ConstructivoVorazTransporte::set_rutas(vector<Ruta>& rutas)
  * @brief Establece las rutas del objeto.
  * @param rutas: vector de rutas
  * @return this Devuelve el propio objeto para permitir la encadenación de llamadas.
  */
 Algoritmo& ConstructivoVorazTransporte::set_rutas(vector<RutaRecoleccion> rutas) {
  this->rutas_recoleccion_ = rutas;
  return *this;
}


/** ConstructivoVorazTransporte::CalcularTareas()
  * @brief Calcula las tareas de transporte.
  * @return void
  * @details Esta función se encarga de calcular las tareas de transporte a partir de las rutas de recolección.
  */
void ConstructivoVorazTransporte::CalcularTareas() {
  tareas_.clear();
  for (const RutaRecoleccion& ruta : this->rutas_recoleccion_) {
    double cantidad_residuos = 0;
    double tiempo = 0;
    int indice_nodo_anterior = 0;
    for(int i = 1; i < ruta.size(); i++) {
      int indice_nodo = ruta.get_nodo(i);
      if (indice_nodo < 0) { // Si es una estación de transferencia
        tiempo += this->distancia_zonas_.get_distancia(indice_nodo_anterior, indice_nodo) * 60 / this->datos_problema_.velocidad_vehiculo;
        Tarea tarea({cantidad_residuos, indice_nodo, tiempo});
        tareas_.push_back(tarea);
        cantidad_residuos = 0;
        indice_nodo_anterior = indice_nodo;
      } else if (indice_nodo == 0) {
        // Si es el depósito de residuos
        tiempo += this->distancia_zonas_.get_distancia(indice_nodo_anterior, indice_nodo) * 60 / this->datos_problema_.velocidad_vehiculo;
        if (cantidad_residuos > 0) {
          throw std::runtime_error("Un vehículo se ha llevado residuos al depósito");
        }
        if (tiempo > this->datos_problema_.duracion_maxima_recoleccion) {
          cerr << ruta << endl;
          cerr << "tiempo: " << tiempo << endl;
          throw std::runtime_error("El tiempo de recolección supera el tiempo máximo permitido");
        }
      } else { // Si es una zona
        cantidad_residuos += this->obtener_zona(indice_nodo)->get_demanda();
        if (cantidad_residuos > this->datos_problema_.capacidad_vehiculo_recoleccion) {
          throw std::runtime_error("La cantidad de residuos supera la capacidad del vehículo");
        }
        tiempo += this->distancia_zonas_.get_distancia(indice_nodo_anterior, indice_nodo) * 60 / this->datos_problema_.velocidad_vehiculo;
        tiempo += this->obtener_zona(indice_nodo)->get_tiempo();
        indice_nodo_anterior = indice_nodo;
      }
    }
  }
  return;
}

/** ConstructivoVorazTransporte::CalcularRutasTransporte()
  * @brief Calcula las rutas de transporte.
  * @return void
  * @details Esta función se encarga de calcular las rutas de transporte a partir de las tareas calculadas anteriormente.
  *          Modifica el vector de rutas_ del objeto.
  */
void ConstructivoVorazTransporte::CalcularRutasTransporte() {
  return;
}

