#include <iostream>
using namespace std;

class Armour{
public:
  string armourClass{};
  int level{};
  Armour(){
    armourClass = "Green";
    level = 100;
  }

  Armour(string aC, int lvl){
    armourClass = aC;
    level = lvl;
    
  }

  void printArmour(){
    cout << "Armour" << armourClass << " " << level << endl; 
  }
};

class Warrior{
public:
  string name{};
  int hp{};
  Armour armour;

  Warrior() : armour{}{ //aquí se inicializa a armour
    name = "Mr. X ";
    hp = 100;
  }

  Warrior(string n, int h, string aC, int lvl) :armour{aC, lvl} {
    name = n;
    hp = h;
  }

  void printWarrior(){
    cout << name << "health: " << hp << endl;
    armour.printArmour();
  }


  void attack(Warrior &attacked){
    printWarrior();
    cout << "Attacks ";
    
    attacked.hp -= 30;
    attacked.armour.level -= 50;
    //eficiencia de memoria
  }

/* Warrior attack(Warrior attacked){
  attacked.hp -=30;
  attacked.armour.lvl -= 50;
  return attacked;}

en el main se pone w2 = w1.attack(w2)  
*/



};


int main() {
  Warrior w1{}, w2{"Humberto", 500, "Blue", 80};
  w1.printWarrior();
  cout << endl;
  w2.printWarrior();
  cout << endl;
  w1.attack(w2);
  cout << endl;
  cout << "After the attack, the stats are: " << endl;
  w2.printWarrior();

  return 0;
}





