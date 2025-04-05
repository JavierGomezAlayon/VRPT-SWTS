// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/25/25
// Archivo Zonas.h : Declaración de la clase Zonas
//        En este fichero se declara la clase Zonas
//
// Historial de revisiones
//        03/25/25 - Creación (primera versión) del código
#ifndef C_Zonas_H
#define C_Zonas_H

#include<vector>
#include"../Cordenadas/Cordenadas.h"
#include<set>

using namespace std;

struct Zona {
  int id;
  Cordenadas cordenadas;
  double tiempo;            // d1
  double demanda;           // d2
};

// ESTO TENGO QUE QUITARLO

/**
 * Con esta clase se trabaja con los indices desde 1 hasta size()
 */
class Zonas {
 public:
  Zonas();
  Zonas(vector<Zona> zonas);
  void add_zona(Zona zona);
  void calcular_distancias();
  double get_distancia(const int id_noco_actual, const int id_nodo_objetivo) const;
  int get_zona_mas_cercana(const int id_nodo_actual, const set<int>& nodos_por_visitar = {}) const;
  int get_zona_mas_cercana(Cordenadas cordenadas_actuales, const set<int>& nodos_por_visitar = {}) const;
  Zona get_zona(int id_noco_actual) const;
  int size() const;
 private:
  vector<Zona> zonas_;
  vector<vector<double>> distancias_;
};

#endif