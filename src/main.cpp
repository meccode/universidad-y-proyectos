#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <fstream>
#include "../include/sorting.hpp"

using namespace std;

// Generador de patrones de entrada
vector<int> generatePattern(int n, int type, mt19937& rng) {
    vector<int> arr(n);
    if (type == 1) { // Aleatorio uniforme
        uniform_int_distribution<int> dist(1, n * 10);
        for (int i = 0; i < n; i++) arr[i] = dist(rng);
    } else if (type == 2) { // Ordenado ascendente
        for (int i = 0; i < n; i++) arr[i] = i;
    } else if (type == 3) { // Ordenado descendente
        for (int i = 0; i < n; i++) arr[i] = n - i;
    } else if (type == 4) { // Casi ordenado (~5% permutado)
        for (int i = 0; i < n; i++) arr[i] = i;
        int swaps = max(1, (int)(n * 0.05));
        uniform_int_distribution<int> dist(0, n - 1);
        for (int s = 0; s < swaps; s++) {
            int idx1 = dist(rng);
            int idx2 = dist(rng);
            swap(arr[idx1], arr[idx2]);
        }
    } else if (type == 5) { // Con duplicados (10-20 valores únicos)
        uniform_int_distribution<int> dist(1, 15);
        for (int i = 0; i < n; i++) arr[i] = dist(rng);
    }
    return arr;
}

int main() {
    int runs = 30; // Mínimo de ejecuciones requeridas
    vector<int> sizes = {1000, 10000, 100000};
    mt19937 rng(42); // Semilla fija para reproducibilidad

    ofstream csv("results/benchmark_results.csv");
    csv << "Algorithm,Pattern,Size,Run,Time_ms,Comparisons\n";

    for (int n : sizes) {
        for (int pattern = 1; pattern <= 5; pattern++) {
            for (int r = 1; r <= runs; r++) {
                
                // --- PRUEBA MERGESORT ---
                vector<int> originalArr = generatePattern(n, pattern, rng);
                vector<int> arr1 = originalArr;
                long long compsMerge = 0;

                auto start1 = chrono::steady_clock::now();
                mergeSort(arr1, 0, n - 1, compsMerge);
                auto end1 = chrono::steady_clock::now();
                double durationMerge = chrono::duration<double, milli>(end1 - start1).count();

                csv << "MergeSort," << pattern << "," << n << "," << r << "," << durationMerge << "," << compsMerge << "\n";

                // --- PRUEBA QUICKSORT ---
                vector<int> arr2 = originalArr;
                long long compsQuick = 0;

                auto start2 = chrono::steady_clock::now();
                quickSort(arr2, 0, n - 1, compsQuick);
                auto end2 = chrono::steady_clock::now();
                double durationQuick = chrono::duration<double, milli>(end2 - start2).count();

                csv << "QuickSort," << pattern << "," << n << "," << r << "," << durationQuick << "," << compsQuick << "\n";
            }
        }
    }
    csv.close();
    cout << "¡Benchmark ejecutado con exito! Datos guardados en results/benchmark_results.csv" << endl;
    return 0;
}