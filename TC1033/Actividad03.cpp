#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Triangulo {
public:
    double x0{}, y0{}, x1{}, y1{}, x2{}, y2{};
    double area{};
    string etiqueta{};

    Triangulo();
    void imprimeTriangulo();
    double distanciaLado(double xA, double yA, double xB, double yB);
    bool esValido();
    void calculaArea();
};

Triangulo::Triangulo() {
    cout << "Elige un nombre para el triángulo: ";
    cin >> etiqueta;
    cout << "Ingrese las coordenadas x0, y0, x1, y1, x2, y2: " << endl;
    cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
    calculaArea();
}

void Triangulo::imprimeTriangulo() {
    cout << etiqueta << ":";
    cout << "(" << x0 << "," << y0 << "), ";
    cout << "(" << x1 << "," << y1 << "), ";
    cout << "(" << x2 << "," << y2 << ") " << endl;

    if (esValido()) {
        cout << fixed << setprecision(2) << "El triángulo es válido, su área es de " << area << endl;
    } else {
        cout << "El triángulo no es válido, no tiene área" << endl;
    }
}

double Triangulo::distanciaLado(double xA, double yA, double xB, double yB) {
    return sqrt(pow(xB - xA, 2) + pow(yB - yA, 2));
}

bool Triangulo::esValido() {
    if (x0 == x1 && x2 == x1 || y0 == y1 && y2 == y1) {
        return false;
    }
    double ladoA = distanciaLado(x1, y1, x2, y2);
    double ladoB = distanciaLado(x0, y0, x2, y2);
    double ladoC = distanciaLado(x0, y0, x1, y1);

    if (ladoA + ladoB <= ladoC || ladoA + ladoC <= ladoB || ladoB + ladoC <= ladoA) {
        return false;
    }
    return true;
}

void Triangulo::calculaArea() {
    double ladoA = distanciaLado(x1, y1, x2, y2);
    double ladoB = distanciaLado(x0, y0, x2, y2);
    double ladoC = distanciaLado(x0, y0, x1, y1);

    double Perimetro = ladoA + ladoB + ladoC;
    double S = Perimetro / 2.00; // semi-perímetro
    area = sqrt(S * (S - ladoA) * (S - ladoB) * (S - ladoC));
}

int main() {
  Triangulo t1{};
  t1.imprimeTriangulo();
    
  Triangulo t2{};
  t2.imprimeTriangulo();

  Triangulo t3{};
  t3.imprimeTriangulo();
  
  return 0;  }
