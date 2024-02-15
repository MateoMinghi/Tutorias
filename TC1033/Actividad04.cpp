#include <iostream>
#include <iomanip>
#include <cmath> 
using namespace std;

//cuando las funciones reciban objetos, usar referencias


class Punto{
public:
  double x{}, y{};
  double angulo_radianes{}, angulo{};
  string etiqueta{}, cuadrante{};

  Punto();
  Punto(double X, double Y, string e);

  void determinaCuadrante();
  void calculaAngulo();
  void imprimePunto();
  void imprimeInfo(); 
};

Punto::Punto(){
  cout << "ingrese la coordenada en x: ";
  cin >> x;
  cout << "ingrese la coordenada en y: ";
  cin >> y;
  cout << "ingrese el nombre de la etiqueta: ";
  cin >> etiqueta;
  determinaCuadrante();
  calculaAngulo();
}

Punto::Punto(double X, double Y, string e){
  x = X;
  y = Y;
  etiqueta = e;
  determinaCuadrante();
  calculaAngulo();
}

void Punto::determinaCuadrante() {
if (x >= 0 && y >= 0) {
    cuadrante = "1";
} else if (x < 0 && y >= 0) {
    cuadrante = "2";
} else if (x < 0 && y < 0) {
    cuadrante = "3";
} else if (x >= 0 && y < 0) {
    cuadrante = "4";}
}

void Punto::calculaAngulo(){
  angulo_radianes = atan(y/x);
  if (cuadrante == "1") {
    angulo = angulo_radianes * (180/M_PI);
  } 
  else if (cuadrante == "2") {
    angulo = 180 + (angulo_radianes * (180/M_PI));
  }
  else if (cuadrante == "3") {
    angulo = 180 + (angulo_radianes * (180/M_PI));
  } 
  else if (cuadrante == "4") {
    angulo = 360 + (angulo_radianes * (180/M_PI));
  }
}

void Punto::imprimePunto(){
  cout << etiqueta << "(" << x << ", " << y << ")" << endl;
}

void Punto::imprimeInfo(){
  cout << "El punto " << etiqueta << " se encuentra en el cuadrante " << cuadrante << ", con un ángulo de " << angulo << endl;
}



class Triangulo{
public:
  Punto p0, p1, p2;
  string etiqueta;
  double area, perimetro;

  Triangulo();
  Triangulo(string e, double a, double p, Punto punto0, Punto punto1, Punto punto2);

  double distanciaLado(Punto &pA, Punto &pB);
  bool esValido();
  void calculaPerimetro();
  void calculaArea();
  void imprimeTriangulo();
  
};

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

int main() {
  Punto p1{3, 2, "A"}, p2{-8, 7, "B"}, p3{2, 6, "C"};
  Punto p4{1, 1, "A"}, p5{2, 2, "B"}, p6{3, 3, "C"};
  /*p1.imprimePunto();
  p1.imprimeInfo();          
  p2.imprimePunto();
  p2.imprimeInfo();
  p3.imprimePunto();
  p3.imprimeInfo();*/
  Triangulo t1{"ABC", 0.0, 0.0, p1, p2, p3};
  Triangulo t2{"ABC", 0.0, 0.0, p4, p5, p6};
  t1.imprimeTriangulo();
  t2.imprimeTriangulo();
return 0;}
