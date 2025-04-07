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
#include"../../Ruta/Ruta.h"
#include"../../Estructuras_auxiliares/Tarea/Tarea.h"

class ConstructivoVorazTransporte : public Algoritmo {
 public:
  ConstructivoVorazTransporte();
  void solve() override;
  void set_rutas(vector<Ruta>& rutas);
 private:
  void CalcularTareas();
  vector<Tarea> tareas_;
  vector<Ruta> rutas_;
};

#endif