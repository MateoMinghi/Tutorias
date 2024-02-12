#include "Triangulo.h"
#include <cmath>
#include <iomanip>

Triangulo::Triangulo() : p0{}, p1{}, p2{}{
 cin >> etiqueta;
 area = 0.0;
 perimetro = 0.0;
 calculaPerimetro();
 calculaArea();
}

Triangulo::Triangulo(string e, double a, double p, Punto punto0, Punto punto1, Punto punto2): p0(punto0), p1(punto1), p2(punto2), etiqueta(e), area(a), perimetro(p){
etiqueta = e;
area = a;
perimetro = p;
calculaPerimetro();
calculaArea();
}

double Triangulo::distanciaLado(Punto &pA, Punto &pB) {
  return sqrt(pow(pB.x - pA.x, 2) + pow(pB.y - pA.y, 2));
}

bool Triangulo::esValido() {
    if (p1.x == p2.x && p1.x == p2.x || p1.y == p2.y && p1.y == p2.y) {
        return false;
    }
    double ladoA = distanciaLado(p1, p2);
    double ladoB = distanciaLado(p0, p2);
    double ladoC = distanciaLado(p0, p1);

    if (ladoA + ladoB <= ladoC || ladoA + ladoC <= ladoB || ladoB + ladoC <= ladoA) {
        return false;
    }
    return true;
}

void Triangulo::calculaPerimetro(){
  double ladoA = distanciaLado(p1, p2);
  double ladoB = distanciaLado(p0, p2);
  double ladoC = distanciaLado(p0, p1);
  perimetro = ladoA + ladoB + ladoC;
}

void Triangulo::calculaArea(){
  double ladoA = distanciaLado(p1, p2);
  double ladoB = distanciaLado(p0, p2);
  double ladoC = distanciaLado(p0, p1);
  double S = perimetro / 2.00; 
  area = sqrt(S * (S - ladoA) * (S - ladoB) * (S - ladoC));
}

void Triangulo::imprimeTriangulo(){
  cout << "El triángulo " << etiqueta << endl;
  p0.imprimePunto(), p1.imprimePunto(), p2.imprimePunto();

  if (esValido()) {
      cout << fixed << setprecision(2) << "Es un triángulo válido con área de " << area << " y perímetro de " << perimetro << endl;
      cout << "" << endl;
  } else {
      cout << "No es un triángulo válido." << endl;
      cout << "" << endl;
  }
}
