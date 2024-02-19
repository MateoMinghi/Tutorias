#ifndef ARMADURA_H
#define ARMADURA_H

class Armadura {
private:
  unsigned int nivel;
  char tipo;
public:
    Armadura();
    Armadura(unsigned int lvl, char t);

    void imprimeArmadura() const;

    unsigned int getNivel() const;
    char getTipo() const;

    void setNivel(unsigned int newlvl);    
    void setTipo(char newt);
};

#endif
