// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/05/25
// Archivo ZonaRecoleccion.h : Declaración de la clase ZonaRecoleccion
//        En este fichero se declara la clase ZonaRecoleccion
//
// Historial de revisiones
//        04/05/25 - Creación (primera versión) del código
#ifndef C_ZonaRecoleccion_H
#define C_ZonaRecoleccion_H
#include"../../Cordenadas/Cordenadas.h"
#include"../Zona.h"

/**
 * @brief Clase que representa una zona de recolección.
 * @details Su id es positivo y mayor que 0.
 * 
 */	
class ZonaRecoleccion : public Zona {
 public:
  ZonaRecoleccion();
  ZonaRecoleccion(int id_zona, Cordenadas cordenadas, double tiempo, double demanda);
  // Getters
  double get_tiempo() const override;
  double get_demanda() const override;
 private:
  double tiempo_procesado_;
  double demanda_;
};

#endif