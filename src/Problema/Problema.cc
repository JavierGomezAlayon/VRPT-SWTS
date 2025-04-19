// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/25/25
// Archivo Problema.cc: Implementación de Problema
//        En este fichero se implementa las funciones de la clase Problema
//
// Historial de revisiones
//        03/25/25 - Creación (primera versión) del código

#include"Problema.h"

/** Problema::Problema()
  * @brief Crea el objeto de la clase Problema.
  * @return objeto de la clase Problema
  */
Problema::Problema() {
  Algoritmo* voraz1 = new ConstructivoVorazRecoleccion();
  Algoritmo* voraz2 = new ConstructivoVorazTransporte();
  Algoritmo* grasp = new Grasp();
  Algoritmo* vnd = new VND();
  this->algoritmos_ = {voraz1, voraz2, grasp, vnd};
}

/** Problema::Problema(DatosProblema datos_problema)
  * @brief Crea el objeto de la clase Problema.
  * @param datos_problema: Datos del problema
  * @return objeto de la clase Problema
  */
Problema::Problema(DatosProblema datos_problema) {
  this->datos_problema_ = datos_problema;
  Algoritmo* voraz1 = new ConstructivoVorazRecoleccion();
  Algoritmo* voraz2 = new ConstructivoVorazTransporte();
  Algoritmo* grasp = new Grasp();
  Algoritmo* vnd = new VND();
  this->algoritmos_ = {voraz1, voraz2, grasp, vnd};
}

/** Problema::set_datos_problema(DatosProblema datos_problema)
  * @brief Establece los datos del problema.
  * @param datos_problema: Datos del problema
  */
void Problema::set_datos_problema(DatosProblema datos_problema) {
  this->datos_problema_ = datos_problema;
}

/** Problema::solve()
  * @brief Resuelve el problema.
  * @return void
  */
void Problema::solve() {
  // lo resuelvo con el algoritmo constructivo voraz de recolección
  this->algoritmos_[0]->set_datos_problema(this->datos_problema_).set_distancia_zonas(this->datos_problema_.zonas).solve();
  vector<RutaRecoleccion> rutas_recoleccion = dynamic_cast<ConstructivoVorazRecoleccion*>(this->algoritmos_[0])->get_rutas();

  // mejoro la solución con busqueda local
  this->algoritmos_[3]->set_datos_problema(this->datos_problema_).set_distancia_zonas(this->datos_problema_.zonas);
  dynamic_cast<VND*>(this->algoritmos_[3])->set_rutas(rutas_recoleccion).solve();
  rutas_recoleccion = dynamic_cast<VND*>(this->algoritmos_[3])->get_rutas_optimas();
    
  // lo resuelvo con el algoritmo constructivo voraz de transporte
  this->algoritmos_[1]->set_datos_problema(this->datos_problema_).set_distancia_zonas(this->datos_problema_.zonas);
  dynamic_cast<ConstructivoVorazTransporte*>(this->algoritmos_[1])->set_rutas(rutas_recoleccion).solve();
  vector<RutaTransporte> rutas_transporte = dynamic_cast<ConstructivoVorazTransporte*>(this->algoritmos_[1])->get_rutas();

  vector<RutaRecoleccion> mejores_rutas_grasp;
  float mejor_costo = INFINITY;
  int sin_mejora = 0;
  for (int i = 0; i < 10000; i++) {
    this->algoritmos_[2]->set_datos_problema(this->datos_problema_).set_distancia_zonas(this->datos_problema_.zonas).solve();
    this->algoritmos_[3]->set_datos_problema(this->datos_problema_).set_distancia_zonas(this->datos_problema_.zonas);
    if (sin_mejora > 500) { break; }
    // lo resuelvo con el algoritmo GRASP
    this->algoritmos_[2]->solve();
    vector<RutaRecoleccion> rutas_grasp = dynamic_cast<Grasp*>(this->algoritmos_[2])->get_rutas();
    
    // mejoro la solución con busqueda local
    dynamic_cast<VND*>(this->algoritmos_[3])->set_rutas(rutas_grasp).solve();
    rutas_grasp = dynamic_cast<VND*>(this->algoritmos_[3])->get_rutas_optimas();
    float coste_ruta_grasp = this->evaluar_rutas(rutas_grasp);

    if (coste_ruta_grasp < mejor_costo) {
      mejores_rutas_grasp = rutas_grasp;
      mejor_costo = coste_ruta_grasp;
      sin_mejora = 0;
    } else {
      sin_mejora++;
    }
  }
  
  // lo resuelvo con el algoritmo constructivo voraz de transporte
  dynamic_cast<ConstructivoVorazTransporte*>(this->algoritmos_[1])->set_rutas(mejores_rutas_grasp).solve();
  vector<RutaTransporte> rutas_grasp_transporte = dynamic_cast<ConstructivoVorazTransporte*>(this->algoritmos_[1])->get_rutas();

  // imprimo toda la solución
  cout << "Rutas de recolección:" << endl;
  for (const RutaRecoleccion& ruta : mejores_rutas_grasp) {
    if (ruta.factible(this->datos_problema_, this->datos_problema_.zonas)) {
      cout << ruta << endl;
    } else {
      cout << "Ruta no factible" << endl;
    }
  }
  cout << "Coste de la ruta de recolección: " << this->evaluar_rutas(mejores_rutas_grasp) << endl;
  cout << "Rutas de transporte:" << endl;
  for (const RutaTransporte& ruta : rutas_grasp_transporte) {
    cout << ruta << endl;
  }
}



/** Problema::evaluar_rutas(vector<RutaRecoleccion>& rutas)
  * @brief Evalua las rutas.
  * @param rutas: Rutas a evaluar
  * @return double: coste de las rutas
  */
double Problema::evaluar_rutas(const vector<RutaRecoleccion>& rutas) {
  double coste = 0;
  for (int i = 0; i < rutas.size(); i++) {
    coste += rutas[i].get_distancia_total(this->datos_problema_.zonas);
  }
  return coste;
}