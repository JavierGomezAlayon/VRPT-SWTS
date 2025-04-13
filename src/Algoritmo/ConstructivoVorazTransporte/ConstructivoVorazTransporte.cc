// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/05/25
// Archivo ConstructivoVorazTransporte.cc: Implementación de ConstructivoVorazTransporte
//        En este fichero se implementa las funciones de la clase ConstructivoVorazTransporte
//
// Historial de revisiones
//        04/05/25 - Creación (primera versión) del código
#pragma GCC diagnostic ignored "-Woverflow"  
#include"ConstructivoVorazTransporte.h"

/** ConstructivoVorazTransporte::ConstructivoVorazTransporte()
  * @brief Crea el objeto de la clase ConstructivoVorazTransporte.
  * @param 
  * @return objeto de la clase ConstructivoVorazTransporte
  */
 ConstructivoVorazTransporte::ConstructivoVorazTransporte() {}

/** ConstructivoVorazTransporte::solve()
  * @brief Resuelve el problema de transporte de residuos.
  * @return this Devuelve el propio objeto para permitir la encadenación de llamadas.
  */
 Algoritmo& ConstructivoVorazTransporte::solve() {
  this->CalcularTareas();
  this->CalcularRutasTransporte();
  return *this;
}

/** ConstructivoVorazTransporte::set_rutas(vector<Ruta>& rutas)
  * @brief Establece las rutas del objeto.
  * @param rutas: vector de rutas
  * @return this Devuelve el propio objeto para permitir la encadenación de llamadas.
  */
 Algoritmo& ConstructivoVorazTransporte::set_rutas(vector<RutaRecoleccion> rutas) {
  this->rutas_recoleccion_ = rutas;
  return *this;
}


/** ConstructivoVorazTransporte::CalcularTareas()
  * @brief Calcula las tareas de transporte.
  * @return void
  * @details Esta función se encarga de calcular las tareas de transporte a partir de las rutas de recolección.
  */
void ConstructivoVorazTransporte::CalcularTareas() {
  this->tareas_.clear();
  this->rutas_transporte_.clear();
  this->vehiculos_transporte_.clear();
  for (const RutaRecoleccion& ruta : this->rutas_recoleccion_) {
    double cantidad_residuos = 0;
    double tiempo = 0;
    int indice_nodo_anterior = 0;
    for(int i = 1; i < ruta.size(); i++) {
      int indice_nodo = ruta.get_nodo(i);
      if (indice_nodo < 0) { // Si es una estación de transferencia
        tiempo += this->distancia_zonas_.get_distancia(indice_nodo_anterior, indice_nodo) * 60 / this->datos_problema_.velocidad_vehiculo;
        Tarea tarea({cantidad_residuos, indice_nodo, tiempo});
        tareas_.push_back(tarea);
        cantidad_residuos = 0;
        indice_nodo_anterior = indice_nodo;
      } else if (indice_nodo == 0) {
        // Si es el depósito de residuos
        tiempo += this->distancia_zonas_.get_distancia(indice_nodo_anterior, indice_nodo) * 60 / this->datos_problema_.velocidad_vehiculo;
        if (cantidad_residuos > 0) {
          throw std::runtime_error("Un vehículo se ha llevado residuos al depósito");
        }
        if (tiempo > this->datos_problema_.duracion_maxima_recoleccion) {
          cerr << ruta << endl;
          cerr << "tiempo: " << tiempo << endl;
          throw std::runtime_error("El tiempo de recolección supera el tiempo máximo permitido");
        }
      } else { // Si es una zona
        cantidad_residuos += this->obtener_zona(indice_nodo)->get_demanda();
        if (cantidad_residuos > this->datos_problema_.capacidad_vehiculo_recoleccion) {
          throw std::runtime_error("La cantidad de residuos supera la capacidad del vehículo");
        }
        tiempo += this->distancia_zonas_.get_distancia(indice_nodo_anterior, indice_nodo) * 60 / this->datos_problema_.velocidad_vehiculo;
        tiempo += this->obtener_zona(indice_nodo)->get_tiempo();
        indice_nodo_anterior = indice_nodo;
      }
    }
  }
  return;
}

/** ConstructivoVorazTransporte::CalcularRutasTransporte()
  * @brief Calcula las rutas de transporte.
  * @return void
  * @details Esta función se encarga de calcular las rutas de transporte a partir de las tareas calculadas anteriormente.
  *          Modifica el vector de rutas_ del objeto.
  */
void ConstructivoVorazTransporte::CalcularRutasTransporte() {
  const int VERTEDERO = std::numeric_limits<int>::max();
  // Ordeno las rutas de tareas
  sort(tareas_.begin(), tareas_.end(), [](const Tarea& a, const Tarea& b) {
    return a.tiempo < b.tiempo;
  });
  // bucle de asignación de tareas a vehículos
  Tarea tarea_actual;
  VehiculoTransporte* vehiculo_seleccionado = nullptr;
  const double minimun_waste = BuscarMinimoWaste();
  while (!tareas_.empty()) {
    tarea_actual = tareas_.front();
    tareas_.erase(tareas_.begin());
    // Buscar el vehículo que minimice el costo de inserción cumpliendo las restricciones (a)-(c)
    vehiculo_seleccionado = this->ElegirVehiculoTransporte(tarea_actual);
    // Si no hay un vehículo disponible, crear uno nuevo
    if (vehiculo_seleccionado == nullptr) {
      this->vehiculos_transporte_.push_back(VehiculoTransporte::crear_vehiculo(this->datos_problema_.capacidad_vehiculo_transporte));
      // Asignar la tarea al nuevo vehículo
      vehiculo_seleccionado = &this->vehiculos_transporte_.back();
      vehiculo_seleccionado->asignar_tarea(tarea_actual, tarea_actual.tiempo - this->distancia_zonas_.get_distancia(VERTEDERO, tarea_actual.estacion_transferencia) * 60 / this->datos_problema_.velocidad_vehiculo);
    } else {
      // Asignar la tarea al vehículo seleccionado
      vehiculo_seleccionado->asignar_tarea(tarea_actual);
    }


    // Verificar si la capacidad restante cae por debajo del umbral mínimo
    if (vehiculo_seleccionado->get_capacidad_restante() < minimun_waste) {
      vehiculo_seleccionado->agregar_destino_vertedero(this->datos_problema_.capacidad_vehiculo_transporte, this->distancia_zonas_.get_distancia(vehiculo_seleccionado->getZonaActual(), VERTEDERO));
    }
  }
  // Asegurar que todas las rutas terminan en el vertedero
  for (VehiculoTransporte& vehiculo : this->vehiculos_transporte_) {
    if (!vehiculo.get_ruta().back() == 0) {
      vehiculo.agregar_destino_vertedero(this->datos_problema_.capacidad_vehiculo_transporte, this->distancia_zonas_.get_distancia(vehiculo.getZonaActual(), VERTEDERO));
    }
  }
  // Actualizar las rutas del objeto
  rutas_recoleccion_.clear();
  for (const VehiculoTransporte& vehiculo : this->vehiculos_transporte_) {
    this->rutas_transporte_.push_back(RutaTransporte(vehiculo.get_ruta()));
  }

  // imprimo por pantalla las rutas de transporte
  cout << "Rutas de transporte:" << endl;
  for (const RutaTransporte& ruta : this->rutas_transporte_) {
    cout << ruta << endl;
  }
  // imprimo por pantalla los vehículos de transporte
  cout << "Vehículos de transporte:" << this->vehiculos_transporte_.size() << endl;
  VehiculoTransporte::resetIdVehiculo();
  return;
}



/** ConstructivoVorazTransporte::get_rutas()
  * @brief Devuelve las rutas del objeto.
  * @return vector<RutaTransporte>: vector de rutas
  */
vector<RutaTransporte>& ConstructivoVorazTransporte::get_rutas() {
  return this->rutas_transporte_;
}

/** ConstructivoVorazTransporte::ElegirVehiculoTransporte()
  * @brief Elige el vehículo de transporte que minimiza el coste de inserción.
  * @param tarea: tarea a asignar
  * @return VehiculoTransporte*: puntero al vehículo seleccionado
  * @details Esta función se encarga de elegir el vehículo de transporte que minimiza el coste de inserción cumpliendo las restricciones (a)-(c).
  */
VehiculoTransporte* ConstructivoVorazTransporte::ElegirVehiculoTransporte(Tarea& tarea) {
  VehiculoTransporte* vehiculo_seleccionado = nullptr;
  double coste_minimo = std::numeric_limits<double>::max();
  for (VehiculoTransporte& vehiculo : this->vehiculos_transporte_) {
    double coste_insercion = this->CalcularCosteInsercion(tarea, vehiculo);
    if (coste_insercion < coste_minimo) {
      coste_minimo = coste_insercion;
      vehiculo_seleccionado = &vehiculo;
    }
  }
  return vehiculo_seleccionado;
}

/** ConstructivoVorazTransporte::CalcularCosteInsercion()
  * @brief Calcula el coste de inserción de una tarea en un vehículo.
  * @param tarea: tarea a asignar
  * @param vehiculo: vehículo al que se le va a asignar la tarea
  * @return double: coste de inserción
  */
double ConstructivoVorazTransporte::CalcularCosteInsercion(Tarea& tarea, VehiculoTransporte& vehiculo) {
  const double VERTEDERO = INFINITY;
  double coste_insercion = std::numeric_limits<double>::max();
  // confirmar que el vehículo puede realizar la tarea
  double tiempo_viaje;
  if (!vehiculo.get_ruta().empty()) {
    const int ultima_zona = vehiculo.getZonaActual();
    double distancia_viaje = this->distancia_zonas_.get_distancia(ultima_zona, tarea.estacion_transferencia);
    tiempo_viaje = (distancia_viaje == INFINITY? 0 : distancia_viaje) * 60 / this->datos_problema_.velocidad_vehiculo;
    if (tiempo_viaje > (tarea.tiempo - vehiculo.get_tiempo_actual())) {
      return std::numeric_limits<double>::max(); // Restricción (a) no cumplida
    }
  }

  if (vehiculo.get_capacidad_restante() < tarea.cantidad_residuos) {
    return std::numeric_limits<double>::max(); // Restricción (b) no cumplida
  }
  // solo para debug.
  // double duracion_viaje = vehiculo.get_tiempo_en_ruta();
  // duracion_viaje += tiempo_viaje;
  // duracion_viaje += (this->distancia_zonas_.get_distancia(tarea.estacion_transferencia, VERTEDERO) * 60 / this->datos_problema_.velocidad_vehiculo);
  double duracion_total = vehiculo.get_tiempo_en_ruta() + tiempo_viaje + (this->distancia_zonas_.get_distancia(tarea.estacion_transferencia, VERTEDERO) * 60 / this->datos_problema_.velocidad_vehiculo);
  if (duracion_total > this->datos_problema_.duracion_maxima_transporte) {
    return std::numeric_limits<double>::max(); // Restricción (c) no cumplida
  }
  // calcular el coste de inserción
  coste_insercion = tiempo_viaje;
  return coste_insercion;
}


/** ConstructivoVorazTransporte::BuscarMinimoWaste()
  * @brief Busca el mínimo waste de los vehículos de transporte.
  * @return double: mínimo waste
  */
double ConstructivoVorazTransporte::BuscarMinimoWaste() {
  double minimo_waste = std::numeric_limits<double>::max();
  for (const Tarea& tarea : this->tareas_) {
    double waste = tarea.cantidad_residuos;
    if (waste < minimo_waste) {
      minimo_waste = waste;
    }
  }
  return minimo_waste;
}