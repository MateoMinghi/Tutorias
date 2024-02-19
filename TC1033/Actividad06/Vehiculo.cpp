#include "Vehiculo.h"
#include <iostream>

Vehiculo::Vehiculo()
    : nivel(1000), tipo('N'), tripulante(), armadura() {}

Vehiculo::Vehiculo(unsigned int nivel, char tipo, const Guerrero& tripulante, const Armadura& armadura)
    : nivel(nivel), tipo(tipo), tripulante(tripulante), armadura(armadura) {}

unsigned int Vehiculo::getNivel() const {
    return nivel;
}

void Vehiculo::setNivel(unsigned int nuevoNivel) {
    nivel = nuevoNivel;
}

char Vehiculo::getTipo() const {
    return tipo;
}

void Vehiculo::setTipo(char nuevoTipo) {
    tipo = nuevoTipo;
}

const Guerrero& Vehiculo::getTripulante() const {
    return tripulante;
}

void Vehiculo::setTripulante(const Guerrero& nuevoTripulante) {
    tripulante = nuevoTripulante;
}

const Armadura& Vehiculo::getArmadura() const {
    return armadura;
}

void Vehiculo::setArmadura(const Armadura& nuevaArmadura) {
    armadura = nuevaArmadura;
}

void Vehiculo::imprimeVehiculo() const {
    cout << "Nivel del vehiculo: " << nivel << ", Tipo: " << tipo << endl;
    tripulante.imprimeGuerrero();
    armadura.imprimeArmadura();
}

void Vehiculo::atacaVehiculo(Vehiculo& otroVehiculo) {
    Armadura nuevaArmadura(otroVehiculo.getArmadura());

    if (nuevaArmadura.getNivel() > 300) {
        nuevaArmadura.setNivel(nuevaArmadura.getNivel() - 300);
    } else {
        nuevaArmadura.setNivel(0);
    }

    nuevaArmadura.setTipo('N');
    otroVehiculo.setArmadura(nuevaArmadura);

    otroVehiculo.setTipo('N');


    Guerrero nuevoGuerrero = otroVehiculo.getTripulante();
    unsigned int nuevaVida = nuevoGuerrero.getHp() > 40 ? nuevoGuerrero.getHp() - 40 : 0;
    nuevoGuerrero.setHp(nuevaVida);

    unsigned int nuevaNivelArmadura = nuevoGuerrero.getArmour().getNivel() > 60 ? nuevoGuerrero.getArmour().getNivel() - 60 : 0;
    Armadura nuevaArmaduraGuerrero = nuevoGuerrero.getArmour();
    nuevaArmaduraGuerrero.setNivel(nuevaNivelArmadura);
    nuevoGuerrero.setArmour(nuevaArmaduraGuerrero);

    otroVehiculo.setTripulante(nuevoGuerrero);
}
