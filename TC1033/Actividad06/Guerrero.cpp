#include "Guerrero.h"
#include <iostream>

Guerrero::Guerrero() : vida(100), nombre("X"), armadura() {}

Guerrero::Guerrero(unsigned int hp, const string& name, const Armadura& armour):
vida(hp), nombre(name), armadura(armour) {}

unsigned int Guerrero::getHp() const{
    return vida;
}

void Guerrero::setHp(unsigned int nuevaVida){
    vida=nuevaVida;
}

const string& Guerrero::getName() const{
    return nombre;
}

void Guerrero::setName(const string& nuevoNombre){
    nombre = nuevoNombre;
}

const Armadura& Guerrero::getArmour() const{
    return armadura;
}

void Guerrero::setArmour(const Armadura& nuevaArmadura){
    armadura = nuevaArmadura;
}

void Guerrero::imprimeGuerrero() const{
    cout << "Nombre: " << nombre << ", Vida " << vida << endl;
    armadura.imprimeArmadura();
}