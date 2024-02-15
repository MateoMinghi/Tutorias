#include "Triangulo.h"
#include <cmath>
#include <iomanip>

Triangulo::Triangulo() : p0{0,0,"A"}, p1{1,1,"B"}, p2{2,0,"C"}, etiqueta{"T"} {
  calculaArea();
  calculaPerimetro();
}
Triangulo::Triangulo(const Punto& a, const Punto& b, const Punto& c, string e) : p0{a}, p1{b}, p2{c}, etiqueta {e} {
  calculaArea();
  calculaPerimetro();
}

bool Triangulo::esValido() {
  calculaArea();
  if (area > 0)
    return true;
  else
    return false;
}
void Triangulo::calculaPerimetro() {
  perimetro = p0.distancia(p1) + p0.distancia(p2) + p1.distancia(p2); 
}
void Triangulo::calculaArea() {
  double a{p0.distancia(p1)}, b{p0.distancia(p2)}, c{p1.distancia(p2)};
  double s{(a+b+c)/2.0};
  area = sqrt(s*(s-a)*(s-b)*(s-c));
}
void Triangulo::imprimeTriangulo() {
  cout << etiqueta << " ";
  p0.imprimePunto(); 
  cout << " ";
  p1.imprimePunto();
  cout << " ";
  p2.imprimePunto();
  cout << "\nPerímetro: " << perimetro << " Area: " << area << endl;
}


Punto Triangulo::getp0()const{
  return p0;
}

Punto Triangulo::getp1()const{
  return p1;
}

Punto Triangulo::getp2()const{
  return p2;
}

string Triangulo::getE()const{
  return etiqueta;
}

void Triangulo::setp0(Punto P0){
  p0 = P0;
}

void Triangulo::setp1(Punto P1){
  p1 = P1;
}

void Triangulo::setp2(Punto P2){
  p2 = P2;
}

void Triangulo::setE(string E){
  etiqueta = E;
}