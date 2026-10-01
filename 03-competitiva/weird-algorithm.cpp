#include <iostream> // 1. Librería para entrada y salida de datos
using namespace std;
int main()
{ // 2. Función principal (aquí inicia el programa)
    int n;
    cin >> n;
    cout << n << " ";
    while (n != 1)
    {
        int r = n % 2;
        if (r == 0)
        {
            n = n / 2;

            cout << n << " ";
        }
        else
        {
            n = (n * 3) + 1;
            cout << n << " ";
        }
    }
    cout << endl;
    // --- AGREGA ESTO AQUÍ ---
    cout << "\nPresiona Enter para salir...";
    cin.ignore(); // Limpia el buffer del teclado
    cin.get();    // Espera a que presiones Enter
                  // -------------------------
    return 0;     // 4. Indica que el programa terminó correctamente
}
