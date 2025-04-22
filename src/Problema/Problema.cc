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
  * @return float: coste de la mejor solución
  */
float Problema::solve() {
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
  this->algoritmos_[2]->set_datos_problema(this->datos_problema_).set_distancia_zonas(this->datos_problema_.zonas).solve();
  this->algoritmos_[3]->set_datos_problema(this->datos_problema_).set_distancia_zonas(this->datos_problema_.zonas);

  for (int i = 0; i < 1000; i++) {
    if (sin_mejora > 500) { break; }
    // lo resuelvo con el algoritmo GRASP
    this->algoritmos_[2]->solve();
    vector<RutaRecoleccion> rutas_grasp = dynamic_cast<Grasp*>(this->algoritmos_[2])->get_rutas();
    
    // mejoro la solución con busqueda local
    dynamic_cast<VND*>(this->algoritmos_[3])->set_rutas(rutas_grasp).solve();
    rutas_grasp = dynamic_cast<VND*>(this->algoritmos_[3])->get_rutas_optimas();
    float coste_ruta_grasp = this->evaluar_rutas(rutas_grasp);
    if (rutas_grasp.size() < mejores_rutas_grasp.size() || mejores_rutas_grasp.size() == 0) {
      mejores_rutas_grasp = rutas_grasp;
      mejor_costo = coste_ruta_grasp;
      sin_mejora = 0;
    } else if (coste_ruta_grasp < mejor_costo && rutas_grasp.size() == mejores_rutas_grasp.size()) {
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

  // Coste de la ruta de recolección
  double coste_ruta_recoleccion = this->evaluar_rutas(mejores_rutas_grasp);
  // imprimo toda la solución
  cout << "Rutas de recolección:" << endl;
  for (const RutaRecoleccion& ruta : mejores_rutas_grasp) {
    cout << ruta << endl;
  }
  cout << "Coste de la ruta de recolección: " << coste_ruta_recoleccion << endl;
  cout << "Rutas de transporte:" << endl;
  for (const RutaTransporte& ruta : rutas_grasp_transporte) {
    cout << ruta << endl;
  }
  return coste_ruta_recoleccion;
}



/** Problema::evaluar_rutas(vector<RutaRecoleccion>& rutas)
  * @brief Evalua las rutas.
  * @param rutas: Rutas a evaluar
  * @return double: coste de las rutas
  */
double Problema::evaluar_rutas(const vector<RutaRecoleccion>& rutas) {
  double coste = 0;
  int rutas_size = rutas.size();
  for (int i = 0; i < rutas_size; i++) {
    coste += rutas[i].get_distancia_total(this->datos_problema_.zonas);
  }
  return coste;
}

/** double evaluar_rutas() 
 * @brief Evalua las rutas.
 * @param rutas: Rutas a evaluar
 * @return double: coste de las rutas
 * @details Esta función se encarga de evaluar las rutas.
 */
double Problema::evaluar_rutas(const vector<RutaTransporte>& rutas) {
  double coste = 0;
  int rutas_size = rutas.size();
  for (int i = 0; i < rutas_size; i++) {
    coste += rutas[i].get_distancia_total(this->datos_problema_.zonas);
  }
  return coste;
}

/** Problema::get_resultados()
  * @brief Devuelve los resultados.
  * @return vector<Resultados>&: Resultados
  */
vector<Resultados>& Problema::get_resultados() {
  return this->resultados_;
}

/** Problema::grasp()
  * @brief Resuelve el problema con el algoritmo GRASP.
  * @return void
  */
void Problema::grasp(int candidatos_grasp) {
  if (candidatos_grasp < 1) {
    throw std::invalid_argument("El número de candidatos para el algoritmo GRASP debe ser mayor que 0");
  }
  this->algoritmos_[2]->set_datos_problema(this->datos_problema_).set_distancia_zonas(this->datos_problema_.zonas);
  this->algoritmos_[3]->set_datos_problema(this->datos_problema_).set_distancia_zonas(this->datos_problema_.zonas);
  auto start = chrono::high_resolution_clock::now();
  dynamic_cast<Grasp*>(this->algoritmos_[2])->set_amplitud_lista_random(candidatos_grasp).solve();
  vector<RutaRecoleccion> rutas_grasp = dynamic_cast<Grasp*>(this->algoritmos_[2])->get_rutas();
    
  // mejoro la solución con busqueda local
  dynamic_cast<VND*>(this->algoritmos_[3])->set_rutas(rutas_grasp).solve();
  rutas_grasp = dynamic_cast<VND*>(this->algoritmos_[3])->get_rutas_optimas();
  auto end = chrono::high_resolution_clock::now();
  // hago las rutas de transporte
  this->algoritmos_[1]->set_datos_problema(this->datos_problema_).set_distancia_zonas(this->datos_problema_.zonas);
  dynamic_cast<ConstructivoVorazTransporte*>(this->algoritmos_[1])->set_rutas(rutas_grasp).solve();
  // Calculo el tiempo transcurrido
  chrono::duration<double> tiempo = end - start;

  // Hago los resultados
  Resultados resultado;
  resultado.nombre_fichero_ = this->datos_problema_.nombre_fichero;
  resultado.rutas_recoleccion_ = rutas_grasp;
  resultado.rutas_transporte_ = dynamic_cast<ConstructivoVorazTransporte*>(this->algoritmos_[1])->get_rutas();
  resultado.coste_rutas_recoleccion_ = this->evaluar_rutas(rutas_grasp);
  resultado.coste_rutas_transporte_ = this->evaluar_rutas(resultado.rutas_transporte_);
  resultado.coste_total_ = resultado.coste_rutas_recoleccion_ + resultado.coste_rutas_transporte_;
  resultado.tiempo_ejecucion_ = tiempo.count();
  resultado.num_zonas_ = this->datos_problema_.num_zonas_recoleccion;
  resultado.num_candidatos_grasp_ = candidatos_grasp;
  resultado.type_ = 1; // 0: voraz, 1: grasp, 2: vnd
  this->resultados_.push_back(resultado);
}


/** Problema::vnd()
  * @brief Resuelve el problema con el algoritmo VND.
  * @return void
  */
void Problema::vnd(int max_iteraciones ,int intentos_mejora, int candidatos_grasp) {
  if (candidatos_grasp < 1) {
    throw std::invalid_argument("El número de candidatos para el algoritmo GRASP debe ser mayor que 0");
  }
  if (intentos_mejora < 1) {
    throw std::invalid_argument("El número de intentos de mejora debe ser mayor que 0");
  }
  if (max_iteraciones < 1) {
    throw std::invalid_argument("El número de iteraciones debe ser mayor que 0");
  }
  vector<RutaRecoleccion> mejores_rutas_grasp;
  float mejor_costo = INFINITY;
  int sin_mejora = 0;
  this->algoritmos_[2]->set_datos_problema(this->datos_problema_).set_distancia_zonas(this->datos_problema_.zonas);
  this->algoritmos_[3]->set_datos_problema(this->datos_problema_).set_distancia_zonas(this->datos_problema_.zonas);
  dynamic_cast<Grasp*>(this->algoritmos_[2])->set_amplitud_lista_random(candidatos_grasp);
  // registro el tiempo
  auto start = chrono::high_resolution_clock::now();
  for (int i = 0; i < max_iteraciones; i++) {
    if (sin_mejora > intentos_mejora) { break; }
    // lo resuelvo con el algoritmo GRASP
    this->algoritmos_[2]->solve();
    vector<RutaRecoleccion> rutas_grasp = dynamic_cast<Grasp*>(this->algoritmos_[2])->get_rutas();
    
    // mejoro la solución con busqueda local
    dynamic_cast<VND*>(this->algoritmos_[3])->set_rutas(rutas_grasp).solve();
    rutas_grasp = dynamic_cast<VND*>(this->algoritmos_[3])->get_rutas_optimas();
    float coste_ruta_grasp = this->evaluar_rutas(rutas_grasp);
    if ((rutas_grasp.size() < mejores_rutas_grasp.size() || mejores_rutas_grasp.size() == 0) || (coste_ruta_grasp < mejor_costo && rutas_grasp.size() == mejores_rutas_grasp.size())) {
      mejores_rutas_grasp = rutas_grasp;
      mejor_costo = coste_ruta_grasp;
      sin_mejora = 0;
    } else {
      sin_mejora++;
    }
  }
  // hago las rutas de transporte
  this->algoritmos_[1]->set_datos_problema(this->datos_problema_).set_distancia_zonas(this->datos_problema_.zonas);
  dynamic_cast<ConstructivoVorazTransporte*>(this->algoritmos_[1])->set_rutas(mejores_rutas_grasp).solve();
  // Calculo el tiempo transcurrido
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> tiempo = end - start;

  // Hago los resultados
  Resultados resultado;
  resultado.nombre_fichero_ = this->datos_problema_.nombre_fichero;
  resultado.rutas_recoleccion_ = mejores_rutas_grasp;
  resultado.rutas_transporte_ = dynamic_cast<ConstructivoVorazTransporte*>(this->algoritmos_[1])->get_rutas();
  resultado.coste_rutas_recoleccion_ = this->evaluar_rutas(mejores_rutas_grasp);
  resultado.coste_rutas_transporte_ = this->evaluar_rutas(resultado.rutas_transporte_);
  resultado.coste_total_ = resultado.coste_rutas_recoleccion_;
  resultado.tiempo_ejecucion_ = tiempo.count();
  resultado.num_zonas_ = this->datos_problema_.num_zonas_recoleccion;
  resultado.num_candidatos_grasp_ = candidatos_grasp;
  resultado.type_ = 2; // 0: voraz, 1: grasp, 2: vnd
  this->resultados_.push_back(resultado);
}

/** Problema::voraz()
  * @brief Resuelve el problema con el algoritmo voraz.
  * @return void
  */
void Problema::voraz() {

  // Mido el tiempo de ejecución
  auto start = chrono::high_resolution_clock::now();

  // lo resuelvo con el algoritmo constructivo voraz de recolección
  this->algoritmos_[0]->set_datos_problema(this->datos_problema_).set_distancia_zonas(this->datos_problema_.zonas).solve();
  vector<RutaRecoleccion> rutas_recoleccion = dynamic_cast<ConstructivoVorazRecoleccion*>(this->algoritmos_[0])->get_rutas();
    
  // lo resuelvo con el algoritmo constructivo voraz de transporte
  this->algoritmos_[1]->set_datos_problema(this->datos_problema_).set_distancia_zonas(this->datos_problema_.zonas);
  dynamic_cast<ConstructivoVorazTransporte*>(this->algoritmos_[1])->set_rutas(rutas_recoleccion).solve();
  vector<RutaTransporte> rutas_transporte = dynamic_cast<ConstructivoVorazTransporte*>(this->algoritmos_[1])->get_rutas();

  // Calculo el tiempo transcurrido
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> tiempo = end - start;
  //cout << "Tiempo de ejecución: " << tiempo.count() << " segundos" << endl;

  // Hago los resultados
  Resultados resultado;
  resultado.nombre_fichero_ = this->datos_problema_.nombre_fichero;
  resultado.rutas_recoleccion_ = rutas_recoleccion;
  resultado.rutas_transporte_ = rutas_transporte;
  resultado.coste_rutas_recoleccion_ = this->evaluar_rutas(rutas_recoleccion);
  resultado.coste_rutas_transporte_ = this->evaluar_rutas(rutas_transporte);
  resultado.coste_total_ = resultado.coste_rutas_recoleccion_ + resultado.coste_rutas_transporte_;
  resultado.tiempo_ejecucion_ = tiempo.count();
  resultado.num_zonas_ = this->datos_problema_.num_zonas_recoleccion;
  resultado.type_ = tiempo.count();
  this->resultados_.push_back(resultado);
}


/** Problema::mostrar_resultados()
  * @brief Muestra los resultados.
  * @return void
  */
void Problema::mostrar_resultados() {
  cout << "Resultados:" << endl;
  // ordeno el vector de resultados por el tipo de algoritmo
  sort(this->resultados_.begin(), this->resultados_.end(), [](const Resultados& a, const Resultados& b) {
    return a.type_ < b.type_;
  });
  // diferencio los resultados por el tipo de algoritmo
  vector<int> counts(3, 0); // Para contar la cantidad de cada tipo (0: voraz, 1: grasp, 2: vnd)
  for (const auto& resultado : this->resultados_) {
    counts[resultado.type_]++;
  }
  // divido el vector de resultados en 3 partes
  vector<Resultados> resultados_voraz(this->resultados_.begin(), this->resultados_.begin() + counts[0]);
  vector<Resultados> resultados_grasp(this->resultados_.begin() + counts[0], this->resultados_.begin() + counts[0] + counts[1]);
  vector<Resultados> resultados_vnd(this->resultados_.begin() + counts[0] + counts[1], this->resultados_.end());
  // muestro los resultados de cada algoritmo
  if (resultados_voraz.size() > 0) {
    // ordeno los resultados por el nombre del fichero
    sort(resultados_voraz.begin(), resultados_voraz.end(), [](const Resultados& a, const Resultados& b) {
      return stoi(a.nombre_fichero_.substr(8)) < stoi(b.nombre_fichero_.substr(8)); // cojo solo el número del nombre del fichero y lo comparo
    });
    this->mostrar_resultados_voraz(resultados_voraz);
  }
  if (resultados_grasp.size() > 0) {
    sort(resultados_grasp.begin(), resultados_grasp.end(), [](const Resultados& a, const Resultados& b) {
      if (stoi(a.nombre_fichero_.substr(8)) == stoi(b.nombre_fichero_.substr(8))) {
        return a.num_candidatos_grasp_ < b.num_candidatos_grasp_; // si el número es el mismo, comparo por LRC
      }
      return stoi(a.nombre_fichero_.substr(8)) < stoi(b.nombre_fichero_.substr(8)); // cojo solo el número del nombre del fichero y lo comparo
    });
    this->mostrar_resultados_grasp(resultados_grasp);
  }
  if (resultados_vnd.size() > 0) {
    sort(resultados_vnd.begin(), resultados_vnd.end(), [](const Resultados& a, const Resultados& b) {
      if (stoi(a.nombre_fichero_.substr(8)) == stoi(b.nombre_fichero_.substr(8))) {
        return a.num_candidatos_grasp_ < b.num_candidatos_grasp_; // si el número es el mismo, comparo por LRC
      }
      return stoi(a.nombre_fichero_.substr(8)) < stoi(b.nombre_fichero_.substr(8)); // cojo solo el número del nombre del fichero y lo comparo
    });
    this->mostrar_resultados_vnd(resultados_vnd);
  }
}

/** Problema::mostrar_resultados_voraz()
  * @brief Muestra los resultados del algoritmo voraz.
  * @return void
  */
void Problema::mostrar_resultados_voraz(vector<Resultados>& resultados) {
  int resultados_size = resultados.size();
  const string separador = "-------------------------------------------------------------";
  // Cabecera
  cout << endl;
  cout << separador << endl;
  cout << "Resultados del algoritmo voraz:" << endl;
  cout << separador << endl;
  cout << fixed << setprecision(4);
  cout << left 
  << setw(15) << "Instancia" 
  << setw(8) << "#Zonas" 
  << setw(6) << "#CV" 
  << setw(6) << "#TV" 
  << setw(12) << "Tiempo CPU" 
  << setw(12) << "Coste Total"
  << endl;
  cout << separador << endl;

  double mediaZonas = 0.0, mediaCV = 0.0, mediaTV = 0.0, mediaCPU = 0.0, mediaCoste = 0.0;
  // Itero sobre los datos
  for (int i = 0; i < resultados_size; i++) {
    cout << fixed << setprecision(4);
    cout << left 
    << setw(15) << resultados[i].nombre_fichero_
    << setw(8) << resultados[i].num_zonas_
    << setw(6) << resultados[i].rutas_recoleccion_.size()
    << setw(6) << resultados[i].rutas_transporte_.size()
    << setw(12) << resultados[i].tiempo_ejecucion_
    << setw(12) << resultados[i].coste_total_ * 60 / this->datos_problema_.velocidad_vehiculo
    << endl;
    mediaZonas += resultados[i].num_zonas_;
    mediaCV += resultados[i].rutas_recoleccion_.size();
    mediaTV += resultados[i].rutas_transporte_.size();
    mediaCPU += resultados[i].tiempo_ejecucion_;
    mediaCoste += resultados[i].coste_total_ * 60 / this->datos_problema_.velocidad_vehiculo;
  }
  // Medias
  cout << separador << endl;
  mediaZonas /= resultados.size();
  mediaCV /= resultados.size();
  mediaTV /= resultados.size();
  mediaCPU /= resultados.size();
  mediaCoste /= resultados.size();
  cout << fixed << setprecision(2);
  cout << left 
  << setw(15) << "Averages" 
  << setw(8) << mediaZonas
  << setw(6) << mediaCV
  << setw(6) << mediaTV
  << setw(12) << mediaCPU
  << setw(12) << mediaCoste
  << endl;
  cout << separador << endl;
  cout << "Fin de la tabla voraz" << endl;
}

/** Problema::mostrar_resultados_grasp()
  * @brief Muestra los resultados del algoritmo GRASP.
  * @return void
  */
void Problema::mostrar_resultados_grasp(vector<Resultados>& resultados) {
  int resultados_size = resultados.size();
  const string separador = "-------------------------------------------------------------";
  // Cabecera
  cout << endl;
  cout << separador << endl;
  cout << "Resultados del algoritmo GRASP:" << endl;
  cout << separador << endl;
  cout << fixed << setprecision(4);
  cout << left 
  << setw(15) << "Instancia" 
  << setw(8) << "#Zonas" 
  << setw(6) << "|LRC|"
  << setw(6) << "#CV" 
  << setw(6) << "#TV" 
  << setw(12) << "Tiempo CPU" 
  << setw(12) << "Coste Total"
  << endl;
  cout << separador << endl;

  double mediaZonas = 0.0, mediaCV = 0.0, mediaTV = 0.0, mediaCPU = 0.0, mediaLRC = 0.0, mediaCoste = 0.0;
  // Itero sobre los datos
  for (int i = 0; i < resultados_size; i++) {
    cout << fixed << setprecision(4);
    cout << left 
    << setw(15) << resultados[i].nombre_fichero_
    << setw(8) << resultados[i].num_zonas_
    << setw(6) << resultados[i].num_candidatos_grasp_
    << setw(6) << resultados[i].rutas_recoleccion_.size()
    << setw(6) << resultados[i].rutas_transporte_.size()
    << setw(12) << resultados[i].tiempo_ejecucion_
    << setw(12) << resultados[i].coste_total_ * 60 / this->datos_problema_.velocidad_vehiculo
    << endl;
    mediaZonas += resultados[i].num_zonas_;
    mediaLRC += resultados[i].num_candidatos_grasp_;
    mediaCV += resultados[i].rutas_recoleccion_.size();
    mediaTV += resultados[i].rutas_transporte_.size();
    mediaCPU += resultados[i].tiempo_ejecucion_;
    mediaCoste += resultados[i].coste_total_ * 60 / this->datos_problema_.velocidad_vehiculo;
  }
  // Medias
  cout << separador << endl;
  mediaZonas /= resultados.size();
  mediaLRC /= resultados.size();
  mediaCV /= resultados.size();
  mediaTV /= resultados.size();
  mediaCPU /= resultados.size();
  mediaCoste /= resultados.size();
  cout << fixed << setprecision(2);
  cout << left 
  << setw(15) << "Averages" 
  << setw(8) << int(mediaZonas)
  << setw(6) << int(mediaLRC)
  << setw(6) << mediaCV
  << setw(6) << mediaTV
  << setw(12) << mediaCPU
  << setw(12) << mediaCoste
  << endl;
  cout << separador << endl;
  cout << "Fin de la tabla GRASP" << endl;
}

/** Problema::mostrar_resultados_vnd()
  * @brief Muestra los resultados del algoritmo VND.
  * @return void
  */
void Problema::mostrar_resultados_vnd(vector<Resultados>& resultados) {
  int resultados_size = resultados.size();
  const string separador = "-------------------------------------------------------------";
  // Cabecera
  cout << endl;
  cout << separador << endl;
  cout << "Resultados del algoritmo GVNS:" << endl;
  cout << separador << endl;
  cout << fixed << setprecision(4);
  cout << left 
  << setw(15) << "Instancia" 
  << setw(8) << "#Zonas" 
  << setw(6) << "Kmax"
  << setw(6) << "#CV" 
  << setw(6) << "#TV" 
  << setw(12) << "Tiempo CPU" 
  << setw(12) << "Coste Total"
  << endl;
  cout << separador << endl;

  double mediaZonas = 0.0, mediaCV = 0.0, mediaTV = 0.0, mediaCPU = 0.0, mediaKmax = 0.0, mediaCoste = 0.0;
  // Itero sobre los datos
  for (int i = 0; i < resultados_size; i++) {
    // cout << fixed << setprecision(4);
    // cout << left 
    // << setw(15) << resultados[i].nombre_fichero_
    // << setw(8) << resultados[i].num_zonas_
    // << setw(6) << resultados[i].num_candidatos_grasp_
    // << setw(6) << resultados[i].rutas_recoleccion_.size()
    // << setw(6) << resultados[i].rutas_transporte_.size()
    // << setw(12) << resultados[i].tiempo_ejecucion_
    // << setw(12) << resultados[i].coste_total_ * 60 / this->datos_problema_.velocidad_vehiculo
    // << endl;
    mediaZonas += resultados[i].num_zonas_;
    mediaKmax += resultados[i].num_candidatos_grasp_;
    mediaCV += resultados[i].rutas_recoleccion_.size();
    mediaTV += resultados[i].rutas_transporte_.size();
    mediaCPU += resultados[i].tiempo_ejecucion_;
    mediaCoste += resultados[i].coste_total_ * 60 / this->datos_problema_.velocidad_vehiculo;
  }
  // Medias
  cout << separador << endl;
  mediaZonas /= resultados.size();
  mediaKmax /= resultados.size();
  mediaCV /= resultados.size();
  mediaTV /= resultados.size();
  mediaCPU /= resultados.size();
  mediaCoste /= resultados.size();
  cout << fixed << setprecision(2);
  cout << left 
  << setw(15) << "Averages" 
  << setw(8) << int(mediaZonas)
  << setw(6) << int(mediaKmax)
  << setw(6) << mediaCV
  << setw(6) << mediaTV
  << setw(12) << mediaCPU
  << setw(12) << mediaCoste
  << endl;
  cout << separador << endl;
  cout << "Fin de la tabla GVNS" << endl;
}


/** Problema::resultados_clear()
  * @brief Limpia los resultados.
  * @return void
  */
void Problema::resultados_clear() {
  this->resultados_.clear();
}