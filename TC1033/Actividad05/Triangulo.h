#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Punto.h"
using namespace std;

class Triangulo {
private:
  Punto p0{}, p1{}, p2{};
  string etiqueta{};
  double area{}, perimetro{};

public:
  Triangulo();
  Triangulo(const Punto&, const Punto&, const Punto&, string);
  bool esValido();
  void calculaPerimetro();
  void calculaArea();
  void imprimeTriangulo();

  Punto getp0()const;
  Punto getp1()const;
  Punto getp2()const;
  string getE()const;

  void setp0(Punto P0);
  void setp1(Punto P1);
  void setp2(Punto P2);
  void setE(string E);
};

#endif