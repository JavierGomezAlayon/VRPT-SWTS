// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/19/25
// Archivo Resultados.h : Declaración de la clase Resultados
//        En este fichero se declara la clase Resultados
//
// Historial de revisiones
//        04/19/25 - Creación (primera versión) del código
#ifndef C_Resultados_H
#define C_Resultados_H
#include"../Ruta/RutaRecoleccion/RutaRecoleccion.h"
#include"../Ruta/RutaTransporte/RutaTransporte.h"
#include"../Estructuras_auxiliares/Datos_problema/Datos_problema.h"
#include"../Estructuras_auxiliares/Tarea/Tarea.h"
#include<map>

class Resultados {
 public:
  Resultados();
 private:
  map<int, vector<RutaRecoleccion>> rutas_recoleccion_;
  map<int, vector<RutaTransporte>> rutas_transporte_;
  map<int, double> coste_rutas_recoleccion_;
  map<int, double> coste_rutas_transporte_;
  map<int, double> coste_total_;
  map<int, double> tiempo_ejecucion_;
 
};

#endif