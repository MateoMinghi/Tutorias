#ifndef VEHICULO_H
#define VEHICULO_H

#include "Guerrero.h"

class Vehiculo {
private:
    unsigned int nivel;
    char tipo;
    Guerrero tripulante;
    Armadura armadura;

public:
    Vehiculo();
    Vehiculo(unsigned int nivel, char tipo, const Guerrero& tripulante, const Armadura& armadura);

    unsigned int getNivel() const;
    void setNivel(unsigned int nuevoNivel);

    char getTipo() const;
    void setTipo(char nuevoTipo);

    const Guerrero& getTripulante() const;
    void setTripulante(const Guerrero& nuevoTripulante);

    const Armadura& getArmadura() const;
    void setArmadura(const Armadura& nuevaArmadura);

    void imprimeVehiculo() const;
    void atacaVehiculo(Vehiculo& otroVehiculo);
};

#endif // VEHICULO_H
