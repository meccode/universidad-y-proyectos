#include <iostream>
using namespace std;

int main() {
    long long n;
    cout << "Introduce el valor de n: ";
    cin >> n;

    long long suma_total = (n * (n + 1)) / 2;
    long long suma_actual = 0;

    cout << "Introduce los " << n - 1 << " numeros:\n";
    for (int i = 0; i < n - 1; i++) {
        long long numero;
        cin >> numero;
        suma_actual += numero;
    }

    cout << "El numero faltante es: " << suma_total - suma_actual << endl;

    // --- SISTEMA DE PAUSA ---
    cout << "\nPresiona Enter para salir...";
    cin.ignore(); 
    cin.get();    

    return 0;
}
