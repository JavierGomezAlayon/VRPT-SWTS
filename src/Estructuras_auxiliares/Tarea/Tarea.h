// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/07/25
// Archivo Tarea.h : Declaración de la clase Tarea
//        En este fichero se declara la clase Tarea
//
// Historial de revisiones
//        04/07/25 - Creación (primera versión) del código
#ifndef C_Tarea_H
#define C_Tarea_H

/**
 * @brief Estructura que representa una tarea de recolección de residuos.
 * @param cantidad_residuos: cantidad de residuos a recoger.
 * @param estacion_transferencia: id de la estación de transferencia.
 * @param tiempo: tiempo que tarda en recoger la tarea.
 */
struct Tarea {
  double cantidad_residuos; // cantidad de residuos a recoger
  int estacion_transferencia; // id de la estación de transferencia
  double tiempo; // tiempo que tarda en recoger la tarea
};

#endif