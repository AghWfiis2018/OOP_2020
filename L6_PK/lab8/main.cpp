// *** Nie wolno modyfikować tego pliku ***

/*==========================================================================
***  Terroryści i ich Proxy ***

Tym razem panikę w mieście sieją terroryści, uzbrojeni po zęby w noże, 
maczety i bomby. Czy systemy bezpieczeństwa i tym razem zawiodą?

W tym prostym zadaniu należy napisać 3 klasy wykorzystując dziedziczenie 
wielokrotne. Cały kod nie powinien być dłuższy niż około 40 linijek 
i powienien znajdować się w całości w pliku 'myclass.h'.
Trudność zadania polega na przeanalizowaniu danego kodu i napisaniu 
wymaganych klas zachowując zasady podane niżej.

Następujące klasy są dane:

A) klasa Weapon oraz klasy pochodne ('weapon.h')

Implementują różne 'bronie'. Dla ułatwienia, nie użyto tutaj wirtualności, 
która przy wielokrotnym dziedziczeniu skomplikowałaby sprawę. 
Działanie klas jest oczywiste -- patrz kod.

B) klasa Terrorist ('terrorist.h')

Klasa abstrakcyjna, implemetuje pierwowzór terrorysty -- patrz kod.


Należy napisać następujące klasy:

1. klasa Terrorist1 oraz Terrorist2

Sa to dwie różne implementacje klasy Terrorist. Klasy te muszą także 
dziedziczyć odpowiednie klasy broni (z pliku 'weapon.h') tak aby fcja 
attack() zwracała odpowiednie wyjście (patrz fcja main).
UWAGA: 
-- Nie wolno implementować żadnych dodatkowych metod, konstruktorów, składników,
   poza wirtualnymi.
-- Klasa nie może używać żadnych fcji drukujących na ekran. Fcje drukujące 
   konieczne do uzyskania prawidłowego wyjścia są już zaimplementowane 
   (pliki weapon.h i terrorist.h).
-- Złamanie tych zasad jest traktowane jak błąd kompilacji.

2. klasa Safety

Musi to być klasa pochodna klasy Terrorist. 
Jest to klasa typu 'proxy' tzn. przechowuje wskaźnik (zwykły) do obiektu 
klasy Terrorist i wykonuje jego metody.
Dodatkowo, klasa zawiera metodę apply_safety_measures(), która unieszkodliwia 
terrorystę. Konstruktory powinny radzić sobie zarówno ze zwykłym wskaźnikiem 
do Terrorist jak i z mądrym wskaźnikiem.

*///==========================================================================


#include <iostream>
#include <memory>

#include "myclass.h"

using namespace std;





// =======================================================================
int main() {

	std::cout << "\n";

	// Tworzymy dwóch terrorystów, używających różnych zestawów broni
       	Terrorist* terrorist1 = new Terrorist1("Katschynski");
	std::unique_ptr<Terrorist> terrorist2( dynamic_cast<Terrorist*>( new Terrorist2("Mason") ) );

	terrorist1->what();   // wydruk
	terrorist1->attack(); // atak terrorysty
	
	std::cout << "\n";

	terrorist2->what();   // wydruk
	terrorist2->attack(); // atak terrorysty


	// ---------------------------------------------------------------	
	std::cout << "\n";

	// Tworzymy 'proxy' terrorystów 
	Safety terr1(terrorist1);
	Safety terr2(terrorist2);

	terr1.what();
	terr1.attack();

	std::cout << "\n";

	terr2.what();
	terr2.apply_safety_measures(); // uniemożliwienie ataku
	terr2.attack();


	std::cout << "\n";

	delete terrorist1;

return 0;}
/// =======================================================================

/* *** Spodziewane wyjście ***

This is Katschynski carrying: Knife, Rifle.
Slash!
Ratatatata!

This is Mason carrying: Axe, Bomb.
Chop!
Kaaaa-booooom!

This is Katschynski carrying: Knife, Rifle.
Slash!
Ratatatata!

This is Mason carrying: Axe, Bomb.

*/
