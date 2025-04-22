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

#include"../Zona/ZonaRecoleccion/ZonaRecoleccion.h"
#include"../Zona/ZonaTransferencia/ZonaTransferencia.h"
#include"../Zona/ZonaDeposito/ZonaDeposito.h"
#include"../Zona/ZonaVertedero/ZonaVertedero.h"
#include"../Ruta/Ruta.h"
#include"../Algoritmo/ConstructivoVorazRecoleccion/ConstructivoVorazRecoleccion.h"
#include"../Algoritmo/ConstructivoVorazTransporte/ConstructivoVorazTransporte.h"
#include"../Algoritmo/Grasp/Grasp.h"
#include"../Algoritmo/VND/VND.h"
#include"../DistanciaZonas/DistanciaZonas.h"
#include"../Estructuras_auxiliares/Datos_problema/Datos_problema.h"
#include"../Estructuras_auxiliares/Tarea/Tarea.h"
#include"../Estructuras_auxiliares/Resultados/Resultados.h"
#include<chrono> // Para medir el tiempo de ejecución
#include<algorithm> // Para sort
#include <iomanip> // Para setw

/**
 * @brief Clase que representa el problema de recolección y transporte de residuos.
 *        Esta clase se va a encargar de elegir como resolver el problema y con qué algoritmos hacerlo.
 *        También encargada de sacar por pantalla todos los resultados de los algoritmos ejecutados.
 */
class Problema {
 public:
  Problema();
  Problema(DatosProblema datos_problema);
  float solve();
  vector<Resultados>& get_resultados();
  void grasp(int candidatos_grasp);
  void vnd(int max_iteraciones ,int intentos_mejora, int candidatos_grasp);
  void voraz();
  void modi(int max_iteraciones, int intentos_mejora, int candidatos_grasp);
  void set_datos_problema(DatosProblema datos_problema);
  void mostrar_resultados();
  void resultados_clear();
 private: 
  double evaluar_rutas(const vector<RutaRecoleccion>& rutas);
  double evaluar_rutas(const vector<RutaTransporte>& rutas);
  void mostrar_resultados_voraz(vector<Resultados>& resultados);
  void mostrar_resultados_grasp(vector<Resultados>& resultados);
  void mostrar_resultados_vnd(vector<Resultados>& resultados);
  DatosProblema datos_problema_;
  vector<Algoritmo*> algoritmos_; // 0: voraz recoleccion, 1: voraz transporte, 2: grasp, 3: vnd
  vector<Resultados> resultados_;
};

// End of header guard
#endif  // C_Problema_H