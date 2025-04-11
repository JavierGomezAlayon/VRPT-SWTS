// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/05/25
// Archivo Grasp.h : Declaración de la clase Grasp
//        En este fichero se declara la clase Grasp
//
// Historial de revisiones
//        04/05/25 - Creación (primera versión) del código
#ifndef C_Grasp_H
#define C_Grasp_H
#include"../Algoritmo.h"
#include"../../Ruta/Ruta.h"
#include"../../Estructuras_auxiliares/Tarea/Tarea.h"
#include<ctime>
#include<cstdlib>
#include<algorithm>

class Grasp : public Algoritmo {
 public:
  Grasp();
  void solve() override;
  vector<Ruta>& get_rutas();
  void set_amplitud_lista_random(int amplitud_lista_random);
 private:
  pair<int, double> obtener_zona_mas_cercana(int id_zona, int numero_de_zonas, char tipo_zona = 'R', const set<int>& zonas_visitadas = {}) const;
  vector<Ruta> rutas_;
  int amplitud_lista_random_ = 10; // número de zonas más cercanas que se van a considerar
};

#endif