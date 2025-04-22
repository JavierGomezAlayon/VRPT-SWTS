// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 05 : VRPT-SWTS
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/25/25
// Archivo main.cc: Implementación del programa cliente
//        En este fichero se implementa la función del main
//
// Historial de revisiones
//        03/25/25 - Creación (primera versión) del código
#include"funciones_main/funciones_main.h"
#include<iostream>

int main(int argc, char *argv[]) {
  srand(time(0));
  //Compruebo si se han introducido los argumentos necesarios
  Dato datos;
  DatosProblema datos_problema;
  Problema problema;
  for (int j = 2; j <= 15; j++) { // para ver la variabilidad de los resultados según el |LRC|
  for (int i = 1; i <= 20; i++) {
    datos.fichero = "instance" + std::to_string(i);
    try {
      //datos = recoger_parametro(argc, argv);
      datos_problema = leer_fichero(datos.fichero);
      ordenar_zonas(datos_problema.zonas);
    } catch (std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
      return 1;
    }

    problema.set_datos_problema(datos_problema);
    try {
      
        // problema.vnd(1000, 400, 2);
        // problema.vnd(1000, 400, 2);
        // problema.vnd(1000, 400, 2);
        // problema.vnd(1000, 400, 3);
        // problema.vnd(1000, 400, 3);
        problema.vnd(200, 50, j);
        //problema.voraz();
        // problema.grasp(j);
        // problema.grasp(j);
        // problema.grasp(j);
    } catch (std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
      return 1;
    }
  }
  problema.mostrar_resultados();
  problema.resultados_clear();
  }
  //problema.mostrar_resultados();
  cout << "Fin del programa" << endl;
  return 0;
}