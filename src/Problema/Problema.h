// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/25/25
// Archivo Problema.h : Declaración de la clase Problema
//        En este fichero se declara la clase Problema
//
// Historial de revisiones
//        03/25/25 - Creación (primera versión) del código
#ifndef C_Problema_H
#define C_Problema_H

#include"../Zonas/Zonas.h"
#include"../Ruta/Ruta.h"
#include"../Algoritmo/Algoritmo.h"
#include<set>

struct DatosProblema {
  int duracion_maxima_recoleccion;
  int duracion_maxima_transporte;
  int num_vehiculos;
  int num_zonas;
  int lx;                     // tamaño del mapa en x
  int ly;                     // tamaño del mapa en y
  int capacidad_vehiculo_recoleccion;
  int capacidad_vehiculo_transporte;
  int velocidad_vehiculo;
  Cordenadas cord_deposito;
  vector<Cordenadas> cord_estaciones_transferencia;
  Cordenadas cord_vertedero;
  Zonas zonas;
};

struct Tarea {
  int cantidad_residuos;
  int estacion_transferencia;
  int tiempo;
};


/**
 * @brief Clase que representa el problema de recolección y transporte de residuos.
 *        Esta clase se va a encargar de elegir como resolver el problema y con qué algoritmos hacerlo.
 *        También encargada de sacar por pantalla todos los resultados de los algoritmos ejecutados.
 */
class Problema {
 public:
  Problema();
  Problema(DatosProblema datos_problema);
 //  void solve();
 //  void set_datos_problema(DatosProblema datos_problema);
 private:
 //  
 //  vector<Ruta> algoritmo_constructivo_recoleccion();
 //  vector<Tarea> generacion_tareas(vector<Ruta>& rutas_recoleccion);
 //  void calcular_distancias();
 //  pair<int,double> zona_mas_cercana(const int id_zona_actual,const set<int>& zonas_recogidas, bool zona_transferencia = false);
 //  double distancia(int id_sitio_actual, int id_sitio_objetivo);
 //  double tiempo_regreso(int id_zona_actual);
 //  
  DatosProblema datos_problema_;
  vector<Tarea> tareas_generadas_;
  vector<Algoritmo*> algoritmos_;
 //  vector<double> distancias_deposito_zonas_;
 //  vector<vector<double>> distancias_zonas_estaciones_trasnferencia_;
 //  vector<double> distancias_deposito_zonas_transferencia_;
};

#endif