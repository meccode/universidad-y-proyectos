#include <iostream>

using namespace std;

class Calculadora
{
private:
    float primero;
    float segundo;

    bool comprobar() const
    {
        return segundo != 0.0f;
    }

public:
    Calculadora()
    {
        primero = 0.0f;
        segundo = 0.0f;
    }

    void setNumeros(float a, float b)
    {
        primero = a;
        segundo = b;
    }

    float getPrimero() const
    {
        return primero;
    }

    float getSegundo() const
    {
        return segundo;
    }

    // Métodos que imprimen directamente el resultado (tipo void)
    void sumar() const
    {
        cout << "\nResultado de la suma: " << (primero + segundo) << endl;
    }

    void restar() const
    {
        cout << "\nResultado de la resta: " << (primero - segundo) << endl;
    }

    void multiplicar() const
    {
        cout << "\nResultado de la multiplicacion: " << (primero * segundo) << endl;
    }

    void dividir() const
    {
        if (comprobar())
        {
            cout << "\nResultado de la division: " << (primero / segundo) << endl;
        }
        else
        {
            cout << "\nError: No se puede dividir entre cero (el segundo numero es 0)." << endl;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Calculadora casio;
    float n1, n2;
    int opcion = 0;

    cout << "=== INGRESO DE DATOS ===" << endl;
    cout << "Ingrese el primer numero: " << flush;
    cin >> n1;
    cout << "Ingrese el segundo numero: " << flush;
    cin >> n2;
    casio.setNumeros(n1, n2);

    do
    {
        cout << "\n=================================" << endl;
        cout << "       MENU DE OPERACIONES       " << endl;
        cout << "=================================" << endl;
        cout << "1. Sumar" << endl;
        cout << "2. Restar" << endl;
        cout << "3. Multiplicar" << endl;
        cout << "4. Dividir" << endl;
        cout << "5. Consultar numeros almacenados" << endl;
        cout << "6. Cambiar numeros" << endl;
        cout << "7. Salir" << endl;
        cout << "Elija una opcion: " << flush;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            casio.sumar();
            break;

        case 2:
            casio.restar();
            break;

        case 3:
            casio.multiplicar();
            break;

        case 4:
            casio.dividir();
            break;

        case 5:
            cout << "\nPrimer numero:  " << casio.getPrimero() << endl;
            cout << "Segundo numero: " << casio.getSegundo() << endl;
            break;

        case 6:
            cout << "\nIngrese el nuevo primer numero: " << flush;
            cin >> n1;
            cout << "Ingrese el nuevo segundo numero: " << flush;
            cin >> n2;
            casio.setNumeros(n1, n2);
            cout << "Numeros actualizados correctamente." << endl;
            break;

        case 7:
            cout << "\nSaliendo del programa..." << endl;
            break;

        default:
            cout << "\nOpcion no valida. Intente de nuevo." << endl;
            break;
        }

    } while (opcion != 7);

    return 0;
}