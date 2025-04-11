// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/05/25
// Archivo ConstructivoVorazTransporte.h : Declaración de la clase ConstructivoVorazTransporte
//        En este fichero se declara la clase ConstructivoVorazTransporte
//
// Historial de revisiones
//        04/05/25 - Creación (primera versión) del código
#ifndef C_ConstructivoVorazTransporte_H
#define C_ConstructivoVorazTransporte_H
#include"../Algoritmo.h"
#include"../../Ruta/RutaRecoleccion/RutaRecoleccion.h"
#include"../../Ruta/RutaTransporte/RutaTransporte.h"
#include"../../Estructuras_auxiliares/Tarea/Tarea.h"

class ConstructivoVorazTransporte : public Algoritmo {
 public:
  ConstructivoVorazTransporte();
  Algoritmo& solve() override;
  Algoritmo& set_rutas(vector<RutaRecoleccion> rutas);
 private:
  void CalcularTareas();
  void CalcularRutasTransporte();
  vector<Tarea> tareas_;
  vector<RutaTransporte> rutas_transporte_;
  vector<RutaRecoleccion> rutas_recoleccion_;
};

#endif