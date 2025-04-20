// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/14/25
// Archivo VND.cc: Implementación de VND
//        En este fichero se implementa las funciones de la clase VND
//
// Historial de revisiones
//        04/14/25 - Creación (primera versión) del código

#include"VND.h"
#include<thread>

/** VND::VND()
  * @brief Crea el objeto de la clase VND.
  * @param 
  * @return objeto de la clase VND
  */
VND::VND() {

}

/** VND::solve()
  * @brief Resuelve el problema con el algoritmo VND.
  * @return objeto de la clase VND
  * @details Este algoritmo se basa en la búsqueda local de vecindad variable.
  *          Utilizo bitmapping para saber cuales búsquedas me faltan por hacer. 
  *          
  */
Algoritmo& VND::solve() {
  crear_busquedas_locales();
  // cout << "Rutas de recoleccion iniciales" << endl;
  // for (int i = 0; i < this->rutas_.size(); i++) {
  //   cout << this->rutas_[i] << endl;
  // }
  // cout << "Coste inicial: " << this->evaluar_rutas(this->rutas_) << endl;
  // cout << endl;
  // la máscara la pongo a 1 para que todas las búsquedas se ejecuten
  unsigned int bitmask = (1 << this->busquedas_locales_.size()) - 1;
  bool mejora = false;
  int rutas_size = this->rutas_.size();
  while(bitmask > 0) {
    // busco la primera búsqueda que no se ha ejecutado
    int indice_busqueda_local = __builtin_ctz(bitmask);
    bitmask &= ~(1 << indice_busqueda_local); // quito la búsqueda de la máscara
    // cout << "Buscando la búsqueda local " << indice_busqueda_local << endl;
    // cout << "Rutas de recoleccion:" << endl;
    // for (int i = 0; i < this->rutas_.size(); i++) {
    //   cout << this->rutas_[i] << endl;
    // }
    // cout << "B: " << indice_busqueda_local << endl;
    
    // ejecuto la búsqueda local hasta encontrar un óptimo
    BusquedaLocal* busqueda_local = this->busquedas_locales_[indice_busqueda_local]; 
    bool mejorado = false;
    for (int i = 0; i < rutas_size; i++) {
      this->rutas_[i].calcular_circuitos();
    }
    if (busqueda_local->rutas_necesarias() == 1) {
      do {
        // double coste_ruta_inicial = this->evaluar_rutas(this->rutas_);
        double coste_minimo = 0;
        mejora = false;
        coste_minimo = 0;
        double coste = 0;
        RutaRecoleccion ruta_actual;
        RutaRecoleccion mejor_ruta;
        for (int i = 0; i < rutas_size; i++) { // por cada ruta de la solución
          mejor_ruta = this->rutas_[i];
          ruta_actual = this->rutas_[i];
          pair<pair<RutaRecoleccion, RutaRecoleccion>, double> sol_busqueda = busqueda_local->ejecutar(ruta_actual); // me da la mejor ruta de todas los vecinos posibles ante esta combinación de ruta.
          RutaRecoleccion& ruta_optimo_local = sol_busqueda.first.first; // me da la mejor ruta de todas los vecinos posibles ante esta combinación de ruta.
          coste = sol_busqueda.second; // me da el coste de la mejora
          if (std::abs(coste - coste_minimo) > 1e-6 && coste < 0) {
            mejora = true;
            mejorado = true;
            mejor_ruta = ruta_optimo_local;
            // cout << mejor_ruta << endl;
            this->rutas_[i] = mejor_ruta; // actualizo la ruta
            // const double coste_ruta_final = this->evaluar_rutas(this->rutas_);
            // cout << coste_ruta_inicial << coste << " = " << coste_ruta_final << endl;
            // cout << "lo que tendría que ser: " << coste_ruta_inicial + coste << endl;
            // std::this_thread::sleep_for(std::chrono::seconds(1));
            // coste_ruta_inicial = coste_ruta_final;
            // double coste_ruta_final = this->evaluar_rutas(this->rutas_);
            // if (std::abs(coste_ruta_inicial + coste - std::round(coste_ruta_final * 100) / 100) > 1e-2) {
            //   cout << "ERRROOORRRR --------------------------------------------------------------------------------------------------------------" << endl;
            //   cout << "tendría que ser: " << coste_ruta_inicial + coste << endl;
            // }
            // cout << coste_ruta_inicial << coste << " = " << coste_ruta_final << endl;
            // coste_ruta_inicial = coste_ruta_final;
          }
        }
        // cout << "coste_ruta_inicial: " << coste_ruta_inicial << ". coste_ruta_final: " << coste_ruta_final << endl;
        // cout << "siguiente iteracion" << endl;
      } while (mejora == true);
    } else if (busqueda_local->rutas_necesarias() == 2) {
      pair<RutaRecoleccion,RutaRecoleccion> mejor_ruta;
      double coste_minimo = 0;
      do {
        // const double coste_ruta_inicial = this->evaluar_rutas(this->rutas_);
        coste_minimo = 0;
        mejora = false;
        mejor_ruta = {this->rutas_[0], this->rutas_[1]};
        int indice1 = 0;
        int indice2 = 1;
        coste_minimo = 0;
        for (int i = 0; i < rutas_size; i++) { 
          for (int j = i + 1; j < rutas_size; j++) { // Para todas las combinaciones de rutas
            pair<RutaRecoleccion,RutaRecoleccion> rutas_actual = {this->rutas_[i], this->rutas_[j]};
            pair<pair<RutaRecoleccion,RutaRecoleccion>,double> sol_busqueda = busqueda_local->ejecutar(rutas_actual.first, rutas_actual.second); // me da la mejor ruta de todas los vecinos posibles ante esta combinación de ruta. 
            pair<RutaRecoleccion,RutaRecoleccion> rutas_optimo_local = sol_busqueda.first; 
            // Evaluo el coste de la "mejora"
            double coste = sol_busqueda.second; // me da el coste de la mejora
            if (coste < coste_minimo) {
              mejora = true;
              mejorado = true;
              mejor_ruta = rutas_optimo_local;
              indice1 = i;
              indice2 = j;
              coste_minimo = coste;
            }
          }
        }
        this->rutas_[indice1] = mejor_ruta.first; // actualizo la ruta
        this->rutas_[indice2] = mejor_ruta.second; // actualizo la ruta
        // const double coste_ruta_final = this->evaluar_rutas(this->rutas_);
        // cout << coste_ruta_inicial << coste_minimo << " = " << coste_ruta_final << endl;
        // if (std::abs(coste_ruta_inicial + coste_minimo - std::round(coste_ruta_final * 100) / 100) > 1e-2) {
        //   cout << "ERRROOORRRR --------------------------------------------------------------------------------------------------------------" << endl;
        //   cout << "tendría que ser: " << coste_ruta_inicial + coste_minimo << endl;
        // }
        // for (int i = 0; i < this->rutas_.size(); i++) {
        //   cout << this->rutas_[i].get_distancia_total(this->distancia_zonas_) << endl;
        // }
        // std::this_thread::sleep_for(std::chrono::seconds(1));
      } while (mejora == true);
    }
    if (mejorado) {
      // si la búsqueda ha mejorado la solución, vuelvo a poner la máscara a todo a 1 menos la que acabo de hacer.
      // cout << "mejorado" << endl;
      bitmask = (1 << this->busquedas_locales_.size()) - 1;
      bitmask &= ~(1 << indice_busqueda_local);
    }
  }
  // cout << "Rutas de recoleccion finales" << endl;
  // for (int i = 0; i < this->rutas_.size(); i++) {
  //   cout << this->rutas_[i] << endl;    
  // }
  // cout << endl;
  return *this;
}

/**
 * @brief VND::set_rutas
 * @details Establece las rutas del objeto.
 * @param rutas: vector de rutas
 * @return this Devuelve el propio objeto para permitir la encadenación de llamadas.
 * @details Esta función se encarga de establecer las rutas del objeto.
 */
Algoritmo& VND::set_rutas(vector<RutaRecoleccion> rutas) {
  this->rutas_ = rutas;
  return *this;
}

/**
 * @brief VND::get_rutas_optimas
 * @details Devuelve las rutas óptimas.
 * @return vector<RutaRecoleccion>&: vector de rutas óptimas
 * @details Esta función se encarga de devolver las rutas óptimas.
 */
vector<RutaRecoleccion>& VND::get_rutas_optimas() {
  return this->rutas_;
  cout << "Rutas de recolección:" << endl;
  for (const RutaRecoleccion& ruta : this->rutas_) {
    if (ruta.factible(this->datos_problema_, this->distancia_zonas_)) {
      cout << ruta << endl;
    } else {
      cout << "Ruta no factible" << endl;
    }
  }
  cout << "distancia de la ruta: " << this->evaluar_rutas(this->rutas_) << endl;
}


/**
 * @brief VND::crear_busquedas_locales
 * @details Crea las búsquedas locales.
 * @return void
 * @details Esta función se encarga de crear las búsquedas locales.
 */
void VND::crear_busquedas_locales() {
  this->busquedas_locales_.clear();
  this->busquedas_locales_.push_back(&(new AdjentSwap())->set_datos(this->datos_problema_, this->distancia_zonas_));
  this->busquedas_locales_.push_back(&(new Swap())->set_datos(this->datos_problema_, this->distancia_zonas_));
  this->busquedas_locales_.push_back(&(new Swap2vect())->set_datos(this->datos_problema_, this->distancia_zonas_));
  // this->busquedas_locales_.push_back(&(new SubrutaSwap())->set_datos(this->datos_problema_, this->distancia_zonas_));
  this->busquedas_locales_.push_back(&(new Insertion())->set_datos(this->datos_problema_, this->distancia_zonas_));
  // busqueda local de cargarme un vehículo
  // this->busquedas_locales_.push_back(&(new ElimVehiculo())->set_datos(this->datos_problema_, this->distancia_zonas_));
  // Cambio de zona de transferencia
  // this->busquedas_locales_.push_back(&(new TransferenciaSwitch())->set_datos(this->datos_problema_, this->distancia_zonas_));
}

/**
 * @brief VND::evaluar_rutas
 * @details Evalua las rutas.
 * @param rutas: vector de rutas
 * @return double: coste de las rutas
 * @details Esta función se encarga de evaluar las rutas.
 */
double VND::evaluar_rutas(const vector<RutaRecoleccion>& rutas) {
  double coste = 0;
  int rutas_size = rutas.size();
  for (int i = 0; i < rutas_size; i++) {
    coste += rutas[i].get_distancia_total(this->distancia_zonas_);
  }
  return coste;
}
