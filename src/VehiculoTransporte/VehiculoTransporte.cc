// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/25/25
// Archivo VehiculoTransporte.cc: Implementación de VehiculoTransporte
//        En este fichero se implementa las funciones de la clase VehiculoTransporte
//
// Historial de revisiones
//        03/25/25 - Creación (primera versión) del código

#include"VehiculoTransporte.h"

// Inicialización de los miembros estáticos
int VehiculoTransporte::id_vehiculo_inicial_ = 0;

/** VehiculoTransporte::crear_vehiculo(double capacidad_restante, int zona_actual, double tiempo_en_ruta)
  * @brief Crea el objeto de la clase VehiculoTransporte.
  * @param capacidad_restante: capacidad restante
  * @param id_zona_actual: id de la zona actual
  * @param tiempo_en_ruta: tiempo restante
  * @return objeto de la clase VehiculoTransporte
  */
VehiculoTransporte VehiculoTransporte::crear_vehiculo(double capacidad_restante, int zona_actual, double tiempo_en_ruta) {
  int id_vehiculo = VehiculoTransporte::id_vehiculo_inicial_++;
  return VehiculoTransporte(id_vehiculo, zona_actual, capacidad_restante);
}

/** VehiculoTransporte::VehiculoTransporte(int id_vehiculo, int id_zona_actual, double tiempo_en_ruta, double capacidad_restante)
  * @brief Crea el objeto de la clase VehiculoTransporte.
  * @param id_vehiculo: id del vehículo
  * @param id_zona_actual: id de la zona actual
  * @param tiempo_en_ruta: tiempo restante
  * @param capacidad_restante: capacidad restante
  * @return objeto de la clase VehiculoTransporte
  */
VehiculoTransporte::VehiculoTransporte(int id_vehiculo, int id_zona_actual, double capacidad_restante, double tiempo_en_ruta) {
  this->id_vehiculo_ = id_vehiculo;
  this->id_zona_actual_ = id_zona_actual;
  this->tiempo_actual_ = tiempo_en_ruta;
  this->capacidad_restante_ = capacidad_restante;
  this->ruta_actual_ = {id_zona_actual};
}

/** VehiculoTransporte::get_ruta() const
  * @brief Devuelve la ruta del vehículo.
  * @return vector<int> ruta del vehículo
  */
vector<int> VehiculoTransporte::get_ruta() const {
  return this->ruta_actual_;
}

/** VehiculoTransporte::asignar_tarea(Tarea& tarea)
  * @brief Asigna una tarea al vehículo.
  * @param tarea: tarea a asignar
  * @return void
  */
void VehiculoTransporte::asignar_tarea(Tarea& tarea, double tiempo_inicial) {
  if (this->ruta_actual_.size() < 2) { // si lo acaban de crear le pongo el tiempo inicial.
    if (tiempo_inicial == std::numeric_limits<double>::infinity()) {
      throw std::invalid_argument("El tiempo inicial no puede ser infinito");
    }
    this->tiempo_inicial_ = tiempo_inicial;
  }
  this->capacidad_restante_ -= tarea.cantidad_residuos;
  this->tiempo_en_ruta_ = (tarea.tiempo - this->tiempo_inicial_);
  this->tiempo_actual_ = tarea.tiempo;
  this->ruta_actual_.push_back(tarea.estacion_transferencia);
  this->id_zona_actual_ = tarea.estacion_transferencia;
}

/** VehiculoTransporte::agregar_destino_vertedero()
  * @brief Vacia el vehículo.
  * @return void
  */
void VehiculoTransporte::agregar_destino_vertedero(int capacidad_vechiculo, double tiempo_al_deposito) {
  this->capacidad_restante_ = capacidad_vechiculo;
  this->tiempo_actual_ += tiempo_al_deposito;
  this->tiempo_en_ruta_ += tiempo_al_deposito;
  this->ruta_actual_.push_back(0);
}

/**
 * 
 */
int VehiculoTransporte::getZonaActual() {
  return this->id_zona_actual_;
}

double VehiculoTransporte::get_tiempo_actual() const {
  return this->tiempo_actual_;
}

double VehiculoTransporte::get_capacidad_restante() const {
  double devolver = this->capacidad_restante_;
  return devolver; // me da error aquí no sé porqué, alomejor es por el const??
}

double VehiculoTransporte::get_tiempo_en_ruta() const {
  return this->tiempo_en_ruta_;
}

void VehiculoTransporte::resetIdVehiculo() {
  VehiculoTransporte::id_vehiculo_inicial_ = 0;
}
