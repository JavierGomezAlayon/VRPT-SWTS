// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 04/14/25
// Archivo BusquedaLocal.h : Declaración de la clase BusquedaLocal
//        En este fichero se declara la clase BusquedaLocal
//
// Historial de revisiones
//        04/14/25 - Creación (primera versión) del código
#ifndef C_BusquedaLocal_H
#define C_BusquedaLocal_H
#include<vector>
#include"../Ruta/RutaRecoleccion/RutaRecoleccion.h"
#include"../Estructuras_auxiliares/Datos_problema/Datos_problema.h"
#include"../DistanciaZonas/DistanciaZonas.h"

extern RutaRecoleccion ruta_default;
/**
 * @brief Clase BusquedaLocal
 * @details Esta clase será la clase base para las búsquedas locales que se van a implementar.
 */
class BusquedaLocal {
 public:
  BusquedaLocal();
  BusquedaLocal(const DatosProblema& datos_problema, const DistanciaZonas& distancia_zonas);
  virtual pair<pair<RutaRecoleccion, RutaRecoleccion>, double> ejecutar(const RutaRecoleccion& ruta1, const RutaRecoleccion& ruta2 = ruta_default) = 0;
  virtual int rutas_necesarias() { return 2; }
  virtual double calcular_coste(const RutaRecoleccion& ruta1, const RutaRecoleccion& ruta_optima1, const RutaRecoleccion& ruta2 = ruta_default, const RutaRecoleccion& ruta_optima2 = ruta_default) = 0;
  virtual BusquedaLocal& set_datos(const DatosProblema& datos_problema, const DistanciaZonas& distancia_zonas);

 protected:
  DatosProblema datos_problema_;
  DistanciaZonas distancia_zonas_;
};

#endif