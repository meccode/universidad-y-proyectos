#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Pelicula
{
private:
    string titulo;
    int duracion;
    float precio;

public:
    Pelicula();
    void setTitulo(const std::string &);
    void setDuracion(int);
    void setPrecio(float);
    string getTitulo();
    int getDuracion();
    float getPrecio();
    void mostrarInformacion();
};
Pelicula::Pelicula()
{
    titulo = "(Sin titulo)";
    duracion = 0;
    precio = 0.0;
};

void Pelicula::setTitulo(const std::string &nuevoTitulo)
{
    titulo = nuevoTitulo;
}
void Pelicula::setDuracion(int nuevaDuracion)
{
    duracion = nuevaDuracion;
}
void Pelicula::setPrecio(float nuevoPrecio)
{
    precio = nuevoPrecio;
}
string Pelicula::getTitulo()
{
    return titulo;
}

int Pelicula::getDuracion()
{
    return duracion;
}

float Pelicula::getPrecio()
{
    return precio;
}
void Pelicula::mostrarInformacion()
{

    cout << "DATOS DE LA PELICULA\n";
    cout << "Titulo: " << titulo << "\n";
    cout << "Duracion: " << duracion << " min" << "\n";
    cout << "Precio: S/ " << precio << "\n";
}

int main()
{
    Pelicula pelicula1; // pelicula1 es una instancia de Película
    pelicula1.mostrarInformacion();
    string titulo;
    int duracion;
    float precio;
    cout << "escribe el titulo del  nuevo libro";
    getline(cin, titulo);
    cout << "escribe la duracion del libro";
    cin >> duracion;
    cout << "escribe el precio del libro";
    cin >> precio;

    pelicula1.setTitulo(titulo);
    pelicula1.setDuracion(duracion);
    pelicula1.setPrecio(precio);

    cout << "\nDespues del registro:\n";
    pelicula1.mostrarInformacion();

    cout << "\nConsultando mediante un getter:\n";
    cout << pelicula1.getTitulo() << "\n";

    return 0;
}
