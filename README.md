## 🎥 Video de Demostración (YouTube)

En cumplimiento con los requerimientos de la evaluación final, se ha grabado un video de demostración individual que detalla el funcionamiento del proyecto.

- **Enlace del Video (No listado):** [PEGA_AQUI_TU_ENLACE_DE_YOUTUBE]
- **Duración:** 6 a 10 minutos

### **Contenido Estructurado de la Exposición:**
1. **Presentación (1 min):** Identificación del estudiante, algoritmos seleccionados (MergeSort y QuickSort) y objetivos de la comparación
2. **Explicación del Código C++ (1-2 min):** Revisión de la implementación en C++11, funciones principales, lógica algorítmica y el uso de `std::chrono`
3. **Demostración Práctica (2-3 min):** Compilación, ejecución del programa y visualización de resultados experimentales con diversos tamaños y patrones de entrada[cite: 5, 6].
4. **Análisis de Resultados (1-2 min):** Revisión de los archivos de estadísticas, tablas y gráficos (`figura1` y `figura2`), discutiendo el impacto de los duplicados en QuickSort[cite: 5, 6].
5. **Conclusiones (1 min):** Hallazgos principales relacionados con la complejidad computacional teórica y empírica

# Comparación Experimental y Teórica: MergeSort vs. QuickSort

Repositorio para la evaluación de rendimiento y análisis estadístico de algoritmos de ordenamiento logarítmico en C++ en el marco del curso de Programación Avanzada (Universidad Nacional Jorge Basadre Grohmann).



======================================================================

1. ESPECIFICACIONES TÉCNICAS DEL ENTORNO

======================================================================

- Sistema Operativo: Microsoft Windows 11 Home (64-bit)

- Procesador (CPU): Intel(R) Core(TM) i5-7400 CPU @ 3.00 GHz (4 núcleos, 4 hilos)

- Memoria RAM: 16 GB DDR4 a 2400 MHz (Doble canal)

- Compilador: GCC (g++ versión 11.2.0 MinGW-w64) con estándar C++11 y optimización -O2.

- Semilla Pseudoaleatoria: 42 (std::mt19937) para garantizar la total reproducibilidad de las muestras.



======================================================================

2. PASO A PASO PARA LA EJECUCIÓN Y GENERACIÓN DE ARCHIVOS CLAVE

======================================================================



Sigue este orden secuencial para compilar las pruebas, procesar la estadística y generar las figuras del artículo científico:



Paso 1: Compilar y ejecutar el Benchmark en C++

--------------------------------------------------

Genera los datos crudos de las 900 ejecuciones experimentales (guardándose en results/benchmark_results.csv):



cd src

g++ -std=c++11 -O2 main.cpp -o benchmark

./benchmark

cd ..



Paso 2: Instalar dependencias de Python

--------------------------------------------------

Asegúrate de tener instaladas las librerías necesarias para el análisis de datos y graficación:



python -m pip install --user pandas matplotlib seaborn



Paso 3: Procesar los datos y generar gráficos automáticamente

--------------------------------------------------

Ejecuta el script de procesamiento estadístico que leerá los resultados crudos y generará las tablas de resumen junto con las figuras clave en formato de alta resolución:



python src/process_results.py



Este paso generará automáticamente:

- results/summary_statistics.csv (Estadísticas descriptivas de media, mediana, desviación estándar y comparaciones).

- results/figures/figura1_n_vs_tiempo.png (Curva de escalabilidad asintótica).

- results/figures/figura2_boxplot_100k.png (Diagrama de cajas para n = 100,000).



======================================================================

3. ESTRUCTURA DEL REPOSITORIO

======================================================================

- src/: Código fuente en C++ de las pruebas y script de procesamiento en Python (process_results.py).

- include/: Cabeceras con la implementación algorítmica de MergeSort y QuickSort.

- results/: Almacena los resultados tabulares en CSV y la subcarpeta figures/ con las gráficas del paper.

- docs/: Manuscrito final en formato LaTeX / PDF del artículo científico (main.tex y carátula con logo institucional).

