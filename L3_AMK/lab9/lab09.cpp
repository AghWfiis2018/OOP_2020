/* Celem zadania jest przećwiczenie dziedziczenia wielokrotnego. 
  W tym celu stworzymy hierarchię klas reprezentujących obiekty
  w grze (6 klas).

  Proszę na podstawie wyniku wywnioskować, jaka jest hierarchia klas
  oraz dopisać niezbędne funkcje.
  W dokumentacji proszę uzasadnić hierarchnię. Bez tego dokumentacja nieważna.
   
 */

#include <iostream>
#include "Main.h"

void printPtr(const void* p) {
  if (p)
    std::cout << "valid ptr" << std::endl;
  else
    std::cout << "null ptr" << std::endl;
}

void printGameObj(const GameObj* p) {
  std::cout << "=== === === " << std::endl;
  if (p){
    std::cout << "Info o obiekcie: " << (*p) << "\n";
    std::cout << "ID: " << p->id() << std::endl;
  }
  else
    std::cout << "Obiekt nierozpoznany" << std::endl;
}

int main() {
  // HP - health points
  Player* s2= new Player(HP(50), "Mario", "id1"); // gracz ma 50 hp
  printGameObj(s2);
  printPtr(dynamic_cast<Character*>(s2));
  printPtr(dynamic_cast<Hurting*>(s2));
    
  Bomb* d2= new Bomb(HP(10), "id2"); // odbiera graczowi 10 hp
  printGameObj(d2);
  printPtr(dynamic_cast<Hurting*>(d2));
  printPtr(dynamic_cast<Character*>(d2));
  
  GameObj* p =  new Boss(HP(100), "Wario", HP(20), "id3"); // ma 100 hp, uderzenie odbiera graczowi 20 hp
  const Character *d = dynamic_cast<Character*>(p);
  const Hurting *k = dynamic_cast<Hurting*>(p);  
  const Bomb *s = dynamic_cast<Bomb*>(p); 
  printGameObj(d);
  printPtr(d);
  if(d) std::cout << "Character hp: " << d->hp() << "\n";

  printGameObj(k);
  printPtr(k);
  if(k) std::cout << "Odbiera hp: " << k->hp() << "\n";

  printGameObj(s);
  printPtr(s);
  
  delete s2;
  delete d2;
  delete p;
}
/* wynik

=== === === 
Info o obiekcie: Player Mario, ma: [50 HP]
ID: id1
valid ptr
null ptr
=== === === 
Info o obiekcie: Jego uderzenie odbiera: [10 HP]
ID: id2
valid ptr
null ptr
=== === === 
Info o obiekcie: Bad guy: Wario, ma: [100 HP]
Jego uderzenie odbiera: [20 HP]
ID: id3
valid ptr
Character hp: [100 HP]
=== === === 
Info o obiekcie: Bad guy: Wario, ma: [100 HP]
Jego uderzenie odbiera: [20 HP]
ID: id3
valid ptr
Odbiera hp: [20 HP]
=== === === 
Obiekt nierozpoznany
null ptr

 */
