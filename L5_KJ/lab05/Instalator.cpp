/* Celem zadania jest zaimplementowanie prostej maszyny stanów. 
 * W naszym wypadku bedzie odpowiadała ona za okno instalatora,
 * ktory zbierze podstawowe informacje i uruchomi instalacje.
 * Mozna sie w nim przesuwac w przód i w tył (zmiany stanów).
 * Służyć do tego będą operatory: ++ i --. 
 * 
 * Bieżący stan można (zwrócić) za pomocą operatora (). 
 * Stan aktywuje się własnym operatorem (). 
 * 
 * Dodawanie stanów do maszyny będzie odbywać się za pomocą operatora +=.
 * 
 * W pliku BaseStates.hpp znajdują się przygotowane dwa stany, inne dwa stany
 * nalezy przygotowac samemu. 
 * 
 * Operacje na wektorach stringów mogą być męczące dla komputera... Dlatego
 * do przechowania listy systemów należy stworzyć klasę, która zapewni
 * korzystanie z mechanizmu przenoszenia. To czy mechanizm zaimplementowano
 * poprawnie mozna sprawdzić odkomentowując komendę ListaString::rob_halas(true).
 * 
 * Proszę zadbać o prawidłowe zarządzanie pamięcią.
 */
 
#include "ListaString.h"
#include "MaszynaStanow.h"
#include "StanyBazowe.h"
#include <iostream>

int main()
{
	ListaString::rob_halas(true);
		
	ListaString systems;
	systems << "Windows";
	
	std::cout << "Na liscie sa systemy:" << std::endl
	          << systems << "Malo? To dodajmy kolejne." << std::endl;
	
	systems << "Linux" << "OS X";	
	
	std::cout << std::endl << std::endl;
	
	MaszynaStanow m;
	m += new DostepneSystemy(systems);
	m += new ZbieranieDanych("Adres email");
	// Ten stan powinien zebrac inforacje o adresie email i zapisac go
	// Prosze o "zamockowanie" tej sytuacji, tj przyjac ze zostaje wpisany adres Nowak@mail.com
	// std::cint >> adres;    ----->     adres = "Nowak@mail.com";		
	m += new Podsumowanie();
	// W tym stanie wyswietlamy informacje o zebranych danych (np. adres email)
	
	m.start();	
	m()();
	std::cout << std::endl;
	//-------
	++m;
	std::cout << "Po pierwszej inkrementacji: \n" << "m = " << m << std::endl;
	m()();
	std::cout << std::endl;
	//-------
	++m;
	std::cout << "Po drugiej inkrementacji: \n" << "m = " << m << std::endl;
	m()();
	std::cout << std::endl;
	//-------
	--m;
	std::cout << "Po pierwszej dekrementacji: \n" << "m = " << m << std::endl;
	m()();
	std::cout << std::endl;
	//-------
	++m;
	m()();
	std::cout << std::endl;
	//-------
	m += new Instalacja();
	++m;
	std::cout << "Na koncu: \n" << "m = " << (const MaszynaStanow&)m << std::endl;
	m()();
	
	return 0;
}

/* wynik działania programu:
Na liscie sa systemy:
   1. Windows
Malo? To dodajmy kolejne.


Rozpoczynamy dzialanie maszyny stanow!
Program mozna uruchomic na nastepujacych systemach: 
   1. Windows
   2. Linux
   3. OS X
wybrano 'Linux'

Po pierwszej inkrementacji: 
m = DostepneSystemy >ZbieranieDanych< Podsumowanie 
Prosze podac dana: Adres email = ?, podano 'Nowak@mail.com'

Po drugiej inkrementacji: 
m = DostepneSystemy ZbieranieDanych >Podsumowanie< 
Podsumowanie: 
 * Wybrano system: 'Linux'
 * Adres email = Nowak@mail.com

Po pierwszej dekrementacji: 
m = DostepneSystemy >ZbieranieDanych< Podsumowanie 
Prosze podac dana: Adres email = ?, podano 'Nowak@mail.com'

Podsumowanie: 
 * Wybrano system: 'Linux'
 * Adres email = Nowak@mail.com

Na koncu: 
m = DostepneSystemy ZbieranieDanych Podsumowanie >Instalacja< 
Instalacja w toku... 
OK!
*/

/* wynik działania programu z glosnymi konstruktorami:
 (list-def-ctor) 
Na liscie sa systemy:
   1. Windows
Malo? To dodajmy kolejne.


 (list-copy-ctor) 
 (list-move-ctor) 
 (list-dtor) 
Rozpoczynamy dzialanie maszyny stanow!
Program mozna uruchomic na nastepujacych systemach: 
   1. Windows
   2. Linux
   3. OS X
wybrano 'Linux'

Po pierwszej inkrementacji: 
m = DostepneSystemy >ZbieranieDanych< Podsumowanie 
Prosze podac dana: Adres email = ?, podano 'Nowak@mail.com'

Po drugiej inkrementacji: 
m = DostepneSystemy ZbieranieDanych >Podsumowanie< 
Podsumowanie: 
 * Wybrano system: 'Linux'
 * Adres email = Nowak@mail.com

Po pierwszej dekrementacji: 
m = DostepneSystemy >ZbieranieDanych< Podsumowanie 
Prosze podac dana: Adres email = ?, podano 'Nowak@mail.com'

Podsumowanie: 
 * Wybrano system: 'Linux'
 * Adres email = Nowak@mail.com

Na koncu: 
m = DostepneSystemy ZbieranieDanych Podsumowanie >Instalacja< 
Instalacja w toku... 
OK!
 (list-dtor) 
 (list-dtor) 
*/
