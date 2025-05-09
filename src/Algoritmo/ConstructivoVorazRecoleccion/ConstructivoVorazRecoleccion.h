// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/05/25
// Archivo ConstructivoVorazRecoleccion.h : Declaración de la clase ConstructivoVorazRecoleccion
//        En este fichero se declara la clase ConstructivoVorazRecoleccion
//
// Historial de revisiones
//        04/05/25 - Creación (primera versión) del código
#ifndef C_ConstructivoVorazRecoleccion_H
#define C_ConstructivoVorazRecoleccion_H
#include"../Algoritmo.h"
#include"../../Ruta/RutaRecoleccion/RutaRecoleccion.h"
#include"../../Estructuras_auxiliares/Tarea/Tarea.h"

class ConstructivoVorazRecoleccion : public Algoritmo {
 public:
  ConstructivoVorazRecoleccion();
  Algoritmo& solve() override;
  vector<RutaRecoleccion>& get_rutas();
 private:
  vector<RutaRecoleccion> rutas_;
};

#endif