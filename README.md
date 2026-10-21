# Comparación Experimental y Teórica: MergeSort vs. QuickSort

Repositorio para la evaluación de rendimiento de algoritmos de ordenamiento logarítmico en C++ en el marco del curso de **Programación Avanzada** (Universidad Nacional Jorge Basadre Grohmann).

## 🛠️ Especificaciones Técnicas del Entorno
- **Sistema Operativo:** [Ej. Ubuntu 22.04 LTS / Windows 11]
- **Procesador (CPU):** [Ej. Intel Core i5-11400H @ 2.70GHz]
- **Memoria RAM:** [Ej. 16 GB DDR4]
- **Compilador:** g++ (GCC) con estándar C++11 o superior.
- **Semilla Pseudoaleatoria:** 42 (para garantizar reproducibilidad).

## ⚙️ Instrucciones de Compilación y Ejecución
Para compilar y ejecutar el benchmark de pruebas y generar los registros en `.csv`:
```bash
cd src
g++ -std=c++11 -O3 main.cpp -o benchmark
./benchmark

📁 Estructura del Repositorio
src/: Código fuente de las pruebas experimentales.

include/: Cabeceras con la implementación de los algoritmos.

results/: Archivos de salida crudos en formato CSV.

docs/: Manuscrito final en PDF del artículo científico.

## 4. Control de Versiones (Commits Iniciales)

Para demostrar el avance documentado ante el docente, realiza los siguientes commits secuenciales en tu terminal[cite: 1]:

1. `git init`
2. `git add .` -> `git commit -m "feat: estructura inicial del repositorio y carpetas obligatorias"`
3. `git add include/ src/` -> `git commit -m "refactor: implementacion de algoritmos MergeSort y QuickSort con std::chrono"`
4. `git add README.md` -> `git commit -m "docs: redaccion del README con especificaciones tecnicas y de compilacion"`

---

