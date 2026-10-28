#ifndef SORTING_HPP
#define SORTING_HPP

#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// --- MERGESORT ---
void merge(vector<int>& arr, int left, int mid, int right, long long& comparisons) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, k = left, j = 0;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right, long long& comparisons) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, comparisons);
        mergeSort(arr, mid + 1, right, comparisons);
        merge(arr, left, mid, right, comparisons);
    }
}

// --- QUICKSORT CON PIVOTE ALEATORIO ---
int partition(vector<int>& arr, int low, int high, long long& comparisons) {
    // Generador local para elegir un índice pivote aleatorio y evitar el peor caso O(n^2)
    static mt19937 rng_qs(1337);
    uniform_int_distribution<int> dist(low, high);
    int random_idx = dist(rng_qs);
    
    // Intercambiar el elemento aleatorio con el último elemento para usarlo como pivote
    swap(arr[random_idx], arr[high]);

    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high, long long& comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
}

#endif