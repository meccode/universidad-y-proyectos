

#include <iostream>
using namespace std;
class int main() {
  
  


    return 0;
} 

class Display(){
    private:
    string tipo;
    public:
    Display(string );
    getTipo();
};
Display::Display(string t) {
    tipo = t;
}
string Display::getTipo() {
    return tipo;
}

class Hora(){
    private:
    int hora;
    int minutos;
    int segundos;
    public:
    Hora(int, int, int);
    getHora();
    getMinuto();
    getSegundo();
};
Hora::Hora(int h, int m, int s) {
    hora = h;
    minutos = m;
    segundos = s;
}

class Reloj(){
    private:
    Display *pDisplay;
    Hora *pHora;
    public:
    Reloj(int h, int m, int s);
    asignarDisplay(Display *pD);
    getHora();
};

Reloj::Reloj(int h, int m, int s) {
    pHora = new Hora(h, m, s);
}



