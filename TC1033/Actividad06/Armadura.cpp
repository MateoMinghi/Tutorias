#include "Armadura.h"
#include <iostream>
using namespace std;

Armadura::Armadura() : nivel(100), tipo('G') {}

Armadura::Armadura(unsigned int lvl, char t) : nivel(lvl), tipo(t) {}

void Armadura::imprimeArmadura() const{
    cout << "Nivel de armdura: " << nivel << ", Tipo " << tipo << endl;
}

unsigned int Armadura::getNivel() const {
    return nivel;
}

void Armadura::setNivel(unsigned int newlvl) {
    nivel = newlvl;
}

char Armadura::getTipo() const {
    return tipo;
}

void Armadura::setTipo(char newt){
    tipo = newt;
}

