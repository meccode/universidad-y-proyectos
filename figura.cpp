#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

// -------------------------------------------------------------
// CLASE BASE: Figura
// -------------------------------------------------------------
class Figura {
protected:
    string color;

public:
    Figura(string col) : color(col) {}

    string getColor() const {
        return color;
    }
};

// -------------------------------------------------------------
// CLASE DERIVADA: Circulo
// -------------------------------------------------------------
class Circulo : public Figura {
private:
    double radio;

public:
    Circulo(string col, double rad) : Figura(col), radio(rad) {}

    double calcularArea() const {
        return PI * radio * radio;
    }

    double calcularPerimetro() const {
        return 2 * PI * radio;
    }

    void mostrarDatos() const {
        cout << "\n=== CIRCULO ===" << endl;
        cout << "Color: " << color << endl;
        cout << "Radio: " << radio << endl;
        cout << "Area: " << calcularArea() << endl;
        cout << "Perimetro: " << calcularPerimetro() << endl;
    }
};

// -------------------------------------------------------------
// CLASE DERIVADA: Rectangulo
// -------------------------------------------------------------
class Rectangulo : public Figura {
private:
    double base;
    double altura;

public:
    Rectangulo(string col, double bas, double alt) : Figura(col), base(bas), altura(alt) {}

    double calcularArea() const {
        return base * altura;
    }

    double calcularPerimetro() const {
        return 2 * (base + altura);
    }

    void mostrarDatos() const {
        cout << "\n=== RECTANGULO ===" << endl;
        cout << "Color: " << color << endl;
        cout << "Base: " << base << endl;
        cout << "Altura: " << altura << endl;
        cout << "Area: " << calcularArea() << endl;
        cout << "Perimetro: " << calcularPerimetro() << endl;
    }
};

// -------------------------------------------------------------
// CLASE DERIVADA: Triangulo (con tipo entero y condicionales)
// -------------------------------------------------------------
class Triangulo : public Figura {
private:
    double base;
    double altura;
    int tipo; // 1: Equilátero, 2: Isósceles, 3: Escaleno

public:
    Triangulo(string col, double bas, double alt, int tip) 
        : Figura(col), base(bas), altura(alt), tipo(tip) {}

    double calcularArea() const {
        return (base * altura) / 2.0;
    }

    void mostrarDatos() const {
        cout << "\n=== TRIANGULO ===" << endl;
        cout << "Color: " << color << endl;
        cout << "Base: " << base << endl;
        cout << "Altura: " << altura << endl;
        cout << "Area: " << calcularArea() << endl;
        
        // Verificación del tipo mediante condicionales según el valor entero
        cout << "Tipo de Triangulo: ";
        switch (tipo) {
            case 1:
                cout << "Equilatero (Codigo 1)" << endl;
                break;
            case 2:
                cout << "Isosceles (Codigo 2)" << endl;
                break;
            case 3:
                cout << "Escaleno (Codigo 3)" << endl;
                break;
            default:
                cout << "Personalizado / No especificado (Codigo " << tipo << ")" << endl;
                break;
        }
    }
};

// -------------------------------------------------------------
// FUNCIÓN MAIN
// -------------------------------------------------------------
int main() {
    // Creación de objetos (el triángulo recibe un int en su parámetro 'tipo', por ejemplo, 2 para Isósceles)
    Circulo c("Rojo", 5.0);
    Rectangulo r("Azul", 4.0, 6.0);
    Triangulo t("Verde", 3.0, 8.0, 2);

    // Mostrar características, área y perímetro
    c.mostrarDatos();
    r.mostrarDatos();
    t.mostrarDatos();

    return 0;
}