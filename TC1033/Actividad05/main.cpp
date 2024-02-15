#include <iostream>
#include <cmath>
#include "Triangulo.h"
#include "Punto.h"
using namespace std;

int main() {
  Triangulo T1{Punto{3,2,"A"}, Punto{-8,4,"B"}, Punto{5,6,"C"}, "T1"};
  Triangulo T2{Punto{1,6,"A"}, Punto{6,7,"B"}, Punto{7,4,"C"}, "T2"};
  Triangulo T3{Punto{2,9,"A"}, Punto{-2,7,"B"}, Punto{-2,1,"C"}, "T3"};

  
  Triangulo aTri[3]{T1, T2, T3};
  for (int i{0}; i<3; i++)
    aTri[i].imprimeTriangulo();
  
  return 0;

}
