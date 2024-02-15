#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>
using namespace std;

class Punto {
private:
  double x{}, y{}, angulo{};
  string 	etiqueta{}, cuadrante{};

public:
  Punto();
  Punto(double, double, string);
  void imprimePunto()const;
  void calculaAngulo();
  void determinaCuadrante();
  void imprimeInfo()const;
  double distancia(const Punto&);

  void setX(double X);
  double getX()const;
  void setY(double Y);
  double getY()const;
  void setE(const string& E);
  string getE()const;
};

#endif