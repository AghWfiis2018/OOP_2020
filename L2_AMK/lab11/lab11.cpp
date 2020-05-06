/*
 Celem zadania jest napisanie polimorficznego kontenera 
 ze zwięrzętami na łące (klasa Meadow). Są to różne zwierzęta:
 stworzymy klasy Sheep, Cow i Horse. Wszystkie zwierzęta mają imię,
 a ich destruktory wypisują komunikat. 

 Spośród zwierząt obecnych na łące tylko owce można strzyc. 
 Proszę dopisać niezbędne metody, tak by poniższy program
 działał poprawnie.

 Uwaga: Plik Animal.h jest udostępniony na UPeLu. Nie należy go
 modyfikować.

 Hints:
 - do zliczania wystąpień może być pomocny pewien kontener STL.
 - można korzystać z dokumentacji, np. http://www.cplusplus.com/reference/

 */

#include "Meadow.h"
#include "Animals.h"
#include "Animal.h"
#include <iostream>
#include <vector>

int main() {
  Sheep littleSheep("Beata");
  littleSheep.print();
  std::cout << std::endl;

  Meadow meadow;
  meadow.add(std::make_unique<Sheep>("Bernadeta"));
  meadow.add(std::make_unique<Cow>("Mucka"));
  meadow.add(std::make_unique<Cow>("Krasula"));
  meadow.add(std::make_unique<Horse>("Rafal"));
  meadow.add(std::make_unique<Sheep>("Beata"));
  meadow.add(std::make_unique<Cow>("Mucka"));
  meadow.add(std::make_unique<Sheep>(littleSheep));
  meadow.print("Zwierzeta na lace");

  std::cout << "== Ile wystapien imion == " << std::endl;
  meadow.countNames(); // wypisanie ile razy występuje każde imię, alfabetycznie

  std::cout << "===== Stado owieczek ===== " << std::endl;
  std::vector<Sheep*> herd = meadow.getSheepHerd();
  for(const auto &v: herd){
  	std::cout << v->name() << std::endl;
  	v->shear();
  }
  meadow.print("Po strzyzeniu owiec");
  std::cout << "====== Koniec wypasu ====== " << std::endl;
}
/* wynik

- Owca Beata nieostrzyzona
=== Zwierzeta na lace ===
- Owca Bernadeta nieostrzyzona
- Krowa Mucka
- Krowa Krasula
- Kon Rafal
- Owca Beata nieostrzyzona
- Krowa Mucka
- Owca Beata nieostrzyzona
== Ile wystapien imion == 
Beata: 2
Bernadeta: 1
Krasula: 1
Mucka: 2
Rafal: 1
===== Stado owieczek ===== 
Bernadeta
Beata
Beata
=== Po strzyzeniu owiec ===
- Owca Bernadeta ostrzyzona
- Krowa Mucka
- Krowa Krasula
- Kon Rafal
- Owca Beata ostrzyzona
- Krowa Mucka
- Owca Beata ostrzyzona
====== Koniec wypasu ====== 
- Owca Bernadeta ostrzyzona wraca do zagrody
- Krowa Mucka wraca do obory
- Krowa Krasula wraca do obory
- Kon Rafal wraca do stajni
- Owca Beata ostrzyzona wraca do zagrody
- Krowa Mucka wraca do obory
- Owca Beata ostrzyzona wraca do zagrody
- Owca Beata nieostrzyzona wraca do zagrody

 */
