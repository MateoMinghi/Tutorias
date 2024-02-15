#include "Punto.h"
#include <cmath>
#include <iomanip>

Punto::Punto() : x{0.0}, y{0.0}, etiqueta{"X"} {
  calculaAngulo();
  determinaCuadrante();
}
Punto::Punto(double x, double y, string e) : x{x}, y{y}, etiqueta{e} {
  calculaAngulo();
  determinaCuadrante();
}

void Punto::imprimePunto()const {
  cout << etiqueta << "(" << x << "," << y << ")";
}

void Punto::calculaAngulo() {
  angulo = atan2(y,x)*180.0/M_PI;
}

void Punto::determinaCuadrante() {
  if (x > 0 && y > 0)
    cuadrante = "I";
  else if (x < 0 && y > 0)
    cuadrante = "II";
  else if (x < 0 && y < 0)
    cuadrante = "III";
  else if (x > 0 && y < 0)
    cuadrante = "IV";
  else 
    cuadrante = "A";
}

void Punto::imprimeInfo()const {
  cout << "Cuadrante: " << cuadrante << "Ángulo: " << angulo << endl;
}

double Punto::distancia(const Punto& p) {
  return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}

double Punto::getX() const{
  return x;
}

double Punto::getY() const{
  return y;
}

string Punto::getE() const{
  return etiqueta;
}


void Punto::setX(double X){
  x = X;
}

void Punto::setY(double Y){
  y = Y;
}

void Punto::setE(const string& E){
  etiqueta = E;
}