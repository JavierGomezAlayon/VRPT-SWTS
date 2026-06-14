# VRPT-SWTS: Resolución del Problema de Enrutamiento de Vehículos

Este repositorio contiene la implementación y el entorno de ejecución para resolver el VRPT (Vehicle Routing Problem) mediante el algoritmo SWTS. El proyecto está diseñado para proporcionar soluciones óptimas o subóptimas de alta calidad a problemas complejos de logística y distribución, minimizando distancias y optimizando la asignación de rutas.

## Descripción General

El Problema de Enrutamiento de Vehículos (VRP) es un problema clásico de optimización combinatoria. Esta variante en particular (VRPT) aborda restricciones específicas del dominio de la logística. 

Para abordar la complejidad computacional (NP-hard) de este problema, este proyecto implementa el enfoque SWTS. Este método permite explorar el espacio de soluciones de manera eficiente, evitando óptimos locales y convergiendo hacia soluciones robustas en tiempos de ejecución razonables. La arquitectura del código prioriza el rendimiento, la escalabilidad y la facilidad de mantenimiento.

## Estructura del Proyecto

El código está organizado de forma modular para separar la lógica del dominio, la lectura de datos, el motor de optimización y la generación de resultados:

* `src/`: Contiene todo el código fuente de la aplicación.
  * `model/`: Definición de las estructuras de datos principales (nodos, vehículos, rutas).
  * `algorithm/`: Implementación del núcleo del algoritmo SWTS y sus heurísticas asociadas.
  * `utils/`: Herramientas para el procesamiento de archivos y parseo de datos de entrada.
* `instances/`: Directorio destinado a almacenar los conjuntos de datos (datasets) o problemas de prueba a resolver.
* `output/`: Directorio donde se generan los reportes y las soluciones calculadas.
* `Makefile`: Archivo de configuración para la compilación automatizada del proyecto.

## Requisitos del Sistema

Para compilar y ejecutar este proyecto, es necesario disponer del siguiente entorno:

* Sistema operativo basado en UNIX (Linux o macOS) o entorno WSL en Windows.
* Compilador de C++ con soporte para el estándar C++11 o superior (ej. `g++` o `clang++`).
* Herramienta de compilación GNU `make`.

## Compilación y Ejecución

**1. Compilación del código**
Para compilar el proyecto y generar el archivo ejecutable, sitúese en la raíz del repositorio y ejecute:
```bash
make
