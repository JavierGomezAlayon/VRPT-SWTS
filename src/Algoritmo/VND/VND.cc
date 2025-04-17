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
  cout << "Rutas de recoleccion iniciales" << endl;
  for (int i = 0; i < this->rutas_.size(); i++) {
    cout << this->rutas_[i] << endl;
  }
  cout << endl;
  // la máscara la pongo a 1 para que todas las búsquedas se ejecuten
  unsigned int bitmask = (1 << this->busquedas_locales_.size()) - 1;
  bool mejora = false;
  int rutas_size = this->rutas_.size();
  while(bitmask > 0) {
    // busco la primera búsqueda que no se ha ejecutado
    int indice_busqueda_local = __builtin_ctz(bitmask);
    bitmask &= ~(1 << indice_busqueda_local); // quito la búsqueda de la máscara
    
    // ejecuto la búsqueda local hasta encontrar un óptimo
    BusquedaLocal* busqueda_local = this->busquedas_locales_[indice_busqueda_local]; 
    bool mejorado = false;
    if (busqueda_local->rutas_necesarias() == 1) {
      do {
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
          if (coste < coste_minimo) {
            mejora = true;
            mejorado = true;
            mejor_ruta = ruta_optimo_local;
          }
          this->rutas_[i] = mejor_ruta; // actualizo la ruta
          cout << mejor_ruta << endl;
        }
        cout << "siguiente iteracion" << endl;
      } while (mejora == true);
    } else if (busqueda_local->rutas_necesarias() == 2) {
      pair<RutaRecoleccion,RutaRecoleccion> mejor_ruta;
      double coste_minimo = 0;
      do {
        mejora = false;
        coste_minimo = 0;
        for (int i = 0; i < rutas_size; i++) { 
          for (int j = 0; j < rutas_size; j++) { // Para todas las combinaciones de rutas
            
            pair<RutaRecoleccion,RutaRecoleccion> rutas_actual = {this->rutas_[i], this->rutas_[j]};
            pair<RutaRecoleccion,RutaRecoleccion> rutas_optimo_local = busqueda_local->ejecutar(rutas_actual.first, rutas_actual.second).first; // me da la mejor ruta de todas los vecinos posibles ante esta combinación de ruta.
            // Evaluo el coste de la "mejora"
            double coste = busqueda_local->calcular_coste(rutas_actual.first, rutas_optimo_local.first, rutas_actual.second, rutas_optimo_local.second);
            if (coste < coste_minimo) {
              mejora = true;
              mejorado = true;
              this->rutas_[i] = rutas_optimo_local.first; // actualizo la ruta
              this->rutas_[j] = rutas_optimo_local.second; // actualizo la ruta
            }
          }
        }
      } while (mejora == true);
    }
    if (mejorado) {
      // si la búsqueda ha mejorado la solución, vuelvo a poner la máscara a todo a 1 menos la que acabo de hacer.
      bitmask = (1 << this->busquedas_locales_.size()) - 1;
      bitmask &= ~(1 << indice_busqueda_local);
    }
  }
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
  // this->busquedas_locales_.push_back(&(new AdjentSwap())->set_datos(this->datos_problema_, this->distancia_zonas_));
  // this->busquedas_locales_.push_back(&(new Swap2vect())->set_datos(this->datos_problema_, this->distancia_zonas_));
  // this->busquedas_locales_.push_back(&(new Adjent2Swap2Vect())->set_datos(this->datos_problema_, this->distancia_zonas_));
  // this->busquedas_locales_.push_back(&(new SubrutaSwap())->set_datos(this->datos_problema_, this->distancia_zonas_));
  // this->busquedas_locales_.push_back(&(new Insertion())->set_datos(this->datos_problema_, this->distancia_zonas_));
}


