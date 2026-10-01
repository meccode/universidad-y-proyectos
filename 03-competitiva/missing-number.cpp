#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long suma_total = (n * (n + 1)) / 2;
    long long suma_actual = 0;

    cout << "Introduce los " << n - 1 << " numeros:\n";
    for (int i = 0; i < n - 1; i++)
    {
        long long numero;
        cin >> numero;
        suma_actual += numero;
    }

    cout << suma_total - suma_actual << endl;

    return 0;
}
