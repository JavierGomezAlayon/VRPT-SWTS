// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/14/25
// Archivo BusquedaLocal.cc: Implementación de BusquedaLocal
//        En este fichero se implementa las funciones de la clase BusquedaLocal
//
// Historial de revisiones
//        04/14/25 - Creación (primera versión) del código

#include"BusquedaLocal.h"

RutaRecoleccion ruta_default;

/**
 * @brief Constructor de la clase BusquedaLocal
 * @return objeto de la clase BusquedaLocal
 * @details Este constructor inicializa los datos del problema y la distancia entre zonas.
 */
BusquedaLocal::BusquedaLocal() {}

/**
 * @brief Constructor de la clase BusquedaLocal
 * @param datos_problema: Datos del problema
 * @param distancia_zonas: Distancia entre zonas
 * @return objeto de la clase BusquedaLocal
 */
BusquedaLocal::BusquedaLocal(const DatosProblema& datos_problema, const DistanciaZonas& distancia_zonas)
    : datos_problema_(datos_problema), distancia_zonas_(distancia_zonas) {}
    


/**
 * @brief Establece los datos del problema y la distancia entre zonas.
 * @param datos_problema: Datos del problema
 * @param distancia_zonas: Distancia entre zonas
 * @return void
 */
BusquedaLocal& BusquedaLocal::set_datos(const DatosProblema& datos_problema, const DistanciaZonas& distancia_zonas) {
  this->datos_problema_ = datos_problema;
  this->distancia_zonas_ = distancia_zonas;
  return *this;
}
