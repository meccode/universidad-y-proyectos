#include <iostream>
#include <string>

using namespace std;

// -------------------------------------------------------------
// CLASE BASE: Vehiculo
// -------------------------------------------------------------
class Vehiculo {
protected:
    string numeroPlaca;
    string color;
    string marca;
    double velocimetro;

public:
    // Constructor
    Vehiculo(string placa, string col, string mar, double vel)
        : numeroPlaca(placa), color(col), marca(mar), velocimetro(vel) {}

    void mostrarDatos() const {
        cout << "Placa: " << numeroPlaca << endl;
        cout << "Color: " << color << endl;
        cout << "Marca: " << marca << endl;
        cout << "Velocidad: " << velocimetro << " km/h" << endl;
    }

    void cambiarVelocidad(double nuevaVelocidad) {
        velocimetro = nuevaVelocidad;
        cout << "[->] Velocidad actualizada a: " << velocimetro << " km/h" << endl;
    }
};

// -------------------------------------------------------------
// CLASE DERIVADA: Automovil
// -------------------------------------------------------------
class Automovil : public Vehiculo {
private:
    int cantidadPuertas;
    int cantidadPasajeros;

public:
    // Lista de inicialización que invoca al constructor de la clase base
    Automovil(string placa, string col, string mar, double vel, int puertas, int pasajeros)
        : Vehiculo(placa, col, mar, vel), cantidadPuertas(puertas), cantidadPasajeros(pasajeros) {}

    void mostrarAutomovil() const {
        cout << "\n=== DATOS DEL AUTOMOVIL ===" << endl;
        mostrarDatos(); // Heredado de Vehiculo
        cout << "Cantidad de puertas: " << cantidadPuertas << endl;
        cout << "Cantidad de pasajeros: " << cantidadPasajeros << endl;
    }

    void subirPasajeros(int cantidad) {
        cantidadPasajeros += cantidad;
        cout << "[+] Subieron " << cantidad << " pasajeros. Total actual: " << cantidadPasajeros << endl;
    }

    void bajarPasajeros(int cantidad) {
        if (cantidad <= cantidadPasajeros) {
            cantidadPasajeros -= cantidad;
            cout << "[-] Bajaron " << cantidad << " pasajeros. Total actual: " << cantidadPasajeros << endl;
        } else {
            cout << "[!] Error: No se pueden bajar mas pasajeros de los existentes." << endl;
        }
    }
};

// -------------------------------------------------------------
// CLASE DERIVADA: Camion
// -------------------------------------------------------------
class Camion : public Vehiculo {
private:
    double carga; // Carga en toneladas/kg

public:
    // Lista de inicialización que invoca al constructor de la clase base
    Camion(string placa, string col, string mar, double vel, double cargaInicial)
        : Vehiculo(placa, col, mar, vel), carga(cargaInicial) {}

    void mostrarCamion() const {
        cout << "\n=== DATOS DEL CAMION ===" << endl;
        mostrarDatos(); // Heredado de Vehiculo
        cout << "Carga actual: " << carga << " toneladas" << endl;
    }

    void cambiarCarga(double nuevaCarga) {
        carga = nuevaCarga;
        cout << "[->] Carga actualizada a: " << carga << " toneladas" << endl;
    }
};

// -------------------------------------------------------------
// FUNCIÓN MAIN
// -------------------------------------------------------------
int main() {
    // 1. Instanciación de Objetos
    Automovil auto1("ABC-123", "Rojo", "Toyota", 0.0, 4, 2);
    Camion camion1("XYZ-987", "Azul", "Volvo", 0.0, 15.5);

    // 2. Mostrar estado inicial
    auto1.mostrarAutomovil();
    camion1.mostrarCamion();

    cout << "\n--------------------------------------------------" << endl;
    cout << "MODIFICANDO ATRIBUTOS MEDIANTE METODOS..." << endl;
    cout << "--------------------------------------------------" << endl;

    // 3. Modificación de atributos del Automóvil
    cout << "\n> Operaciones en Automovil:" << endl;
    auto1.cambiarVelocidad(80.5);
    auto1.subirPasajeros(2);
    auto1.bajarPasajeros(1);

    // 4. Modificación de atributos del Camión
    cout << "\n> Operaciones en Camion:" << endl;
    camion1.cambiarVelocidad(60.0);
    camion1.cambiarCarga(22.0);

    // 5. Mostrar resultados actualizados
    cout << "\n--------------------------------------------------" << endl;
    cout << "ESTADO FINAL DE LOS VEHICULOS" << endl;
    cout << "--------------------------------------------------" << endl;
    auto1.mostrarAutomovil();
    camion1.mostrarCamion();

    return 0;
}