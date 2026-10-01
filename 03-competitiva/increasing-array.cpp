#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Introduce el tamaño del arreglo (n): ";
    cin >> n;

    long long movimientos = 0;
    long long anterior;

    cout << "Introduce los numeros separados por espacios:\n";
    cin >> anterior;

    for (int i = 1; i < n; i++)
    {
        long long actual;
        cin >> actual;

        if (actual < anterior)
        {
            movimientos += (anterior - actual);
        }
        else
        {
            anterior = actual;
        }
    }

    cout << "Minimo de movimientos requeridos: " << movimientos << endl;

    return 0;
}
