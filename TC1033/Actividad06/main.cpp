#include "Vehiculo.h"
#include <iostream>
using namespace std;

int main(){
    Armadura armadura1(400,'G'),armadura2(450, 'V');
    Guerrero guerrero1(100,"Guerrero1",armadura1), guerrero2(150, "Guerrero2", armadura2);
  
    Vehiculo vehiculo1(1500, 'E', guerrero1, armadura1), vehiculo2(1000, 'N', guerrero2, armadura2);

    cout << "Vehiculo1:" << endl;
    vehiculo1.imprimeVehiculo();
    cout << "" << endl;
    cout << "Vehiculo2:" << endl;
    vehiculo2.imprimeVehiculo();

    vehiculo1.atacaVehiculo(vehiculo2);
    cout << "" << endl;
    cout << "Vehiculo1 despues del ataque:" << endl;
    vehiculo1.imprimeVehiculo();
    cout << "" << endl;
    cout << "Vehiculo2 despues del ataque:" << endl;
    vehiculo2.imprimeVehiculo();

    vehiculo2.atacaVehiculo(vehiculo1);
    cout << "" << endl;
    cout << "Vehiculo1 despues del contraataque:" << endl;
    vehiculo1.imprimeVehiculo();
    cout << "" << endl;
    cout << "Vehiculo2 despues del contraataque:" << endl;
    vehiculo2.imprimeVehiculo();

    return 0;
}