#ifndef GUERRERO_H
#define GUERRERO_H

#include <string>
#include "Armadura.h"
using namespace std;

class Guerrero {
private:
  unsigned int vida;
  string nombre;
  Armadura armadura;
public:
  Guerrero();
  Guerrero(unsigned int hp, const string& name, const Armadura& armour);

  void imprimeGuerrero() const;

  unsigned int getHp() const;
  const string& getName() const;
  const Armadura& getArmour() const;

  void setHp(unsigned int nuevaVida);
  void setName(const string& nuevoNombre);
  void setArmour(const Armadura& nuevaArmadura);
};

#endif 
