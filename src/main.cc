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
  for (int i = 1; i <= 20; i++) {
    datos.fichero = "instance" + std::to_string(i) + ".txt";
    try {
      //datos = recoger_parametro(argc, argv);
      datos_problema = leer_fichero(datos.fichero);
      ordenar_zonas(datos_problema.zonas);
    } catch (std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
      return 1;
    }
    Problema problema(datos_problema);

    cout << "\nINSTANCIA " << i << endl;
    cout << endl;
    try {
      problema.solve();
    } catch (std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
      return 1;
    }
  }
  cout << "Fin del programa" << endl;
  return 0;
}