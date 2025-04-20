// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/07/25
// Archivo Datos_problema.h : Declaración de la clase Datos_problema
//        En este fichero se declara la clase Datos_problema
//
// Historial de revisiones
//        04/07/25 - Creación (primera versión) del código
#ifndef C_Datos_problema_H
#define C_Datos_problema_H

#include "../../Zona/Zona.h"
#include <vector>

/**
 * @brief Estructura que contiene los datos del problema.
 *       Se utiliza para almacenar los datos del problema y pasarlos a los algoritmos.
 */
struct DatosProblema {
  int duracion_maxima_recoleccion; // en minutos
  int duracion_maxima_transporte;  // en minutos
  int num_vehiculos;
  int num_zonas_recoleccion;
  int lx;                     // tamaño del mapa (recolección) en x
  int ly;                     // tamaño del mapa (recolección) en y
  int capacidad_vehiculo_recoleccion;
  int capacidad_vehiculo_transporte;
  int velocidad_vehiculo;
  string nombre_fichero;
  vector<Zona*> zonas;
  /**
   * @brief Función que devuelve la zona con el id dado.
   * @param id_zona: id de la zona a buscar
   * @return Zona*: puntero a la zona con el id dado.
   */
  Zona* obtener_zona(int id_zona) const {
    for (const auto& zona : zonas) {
      if (zona->get_id_zona() == id_zona) {
        return zona;
      }
    }
    return nullptr;
  }
  // Cordenadas cord_deposito;
  // vector<Cordenadas> cord_estaciones_transferencia;
  // Cordenadas cord_Deposito;
  // Zonas zonas;
};
#endif