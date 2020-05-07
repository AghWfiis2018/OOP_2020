/* Celem zadania jest napisanie klasy, będącej przykładem sprytnego wskaźnika.
 * Jest to klasa opakowująca wskaźnik w sposób, w którym liczona jest ilość
 * referencji do tego wkaźnika. 
 * 
 * Podczas konstruowania takiego sprytnego wskaźnika przekazujemy do niego
 * wskaźnik do obiektu stworzonego operatorem new i startujemy licznik.
 * Każdy następny sprytny wskaźnik pokazujący na ten obiekt (stworzony z 
 * innego sprytnego wskaźnika) zwiększa ten licznik, a każde zniszczenie 
 * sprytnego wskaźnika (np przez wyjście poza zakres) zmniejsza licznik. 
 * Gdy licznik dochodzi do zera, pamięć należy zwolnić. 
 * 
 * Kluczową sprawą jest zapewnienie współdzielenia licznika pomiędzy różnymi
 * instancjami klasy sprytnego licznika (static nie jest rozwiązaniem).
 * 
 * Sprytny wskaźnik ma obslugiwać banalną klasę InfoClass, która nic nie 
 * robi, tylko dużo mówi (głośny konstruktor/destruktor, metoda info()).
 * 
 * Można korzystać ze wszelkich dobrodziejstw biblioteki standardowej.
 * Zamiana liczby na std::string: std::to_string(int).
 */

#include "InfoSmartPtr.h"
#include "InfoClass.h"
#include <iostream>

void printInfo(const InfoClass& info)
{
	std::cout << "** printInfo: " << info.info() << std::endl;
}

int main()
{
	// -------------------------
	{
		InfoClass info("InfoAAA");
		printInfo(info);
	}
	std::cout << std::endl;
	
	// -------------------------
	{
		InfoSmartPtr info( new InfoClass("InfoBBB") );
		printInfo(*info);
	}
	std::cout << std::endl;
	
	// -------------------------
	InfoSmartPtr infoOne( new InfoClass("InfoCCC") );
	InfoSmartPtr infoTwo( new InfoClass("InfoDDD") );
	infoTwo = infoOne;                           // Kasowanie InfoDDD!!!
	std::cout << std::endl;
	
	// -------------------------
	infoTwo->info("InfoXXX");
	std::cout << "== " << infoOne->info() << std::endl;
	std::cout << "== " << infoTwo->info() << std::endl;
	std::cout << std::endl;	
	
	// -------------------------
	{
		const InfoSmartPtr infoThree = infoTwo;
		printInfo(*infoThree);		
		std::cout << "== " << infoThree->info() << std::endl;
	}
	std::cout << "== " << infoTwo->info() << std::endl;
	std::cout << std::endl;
		
	// -------------------------
	InfoSmartPtr infoFour( new InfoSuperClass("InfoSSS", 2019) );
	infoOne = infoFour;
	std::cout << "== " << infoOne->info() << std::endl;
	std::cout << "== " << infoTwo->info() << std::endl;
	std::cout << "== " << infoFour->info() << std::endl;
	std::cout << std::endl;	
	
	return 0;
}

/* wynik działania programu:
++ Tworze obiekt InfoClass: info = InfoAAA
** printInfo: info = InfoAAA
++ Usuwam obiekt InfoClass: info = InfoAAA

++ Tworze obiekt InfoClass: info = InfoBBB
** printInfo: info = InfoBBB
++ Usuwam obiekt InfoClass: info = InfoBBB

++ Tworze obiekt InfoClass: info = InfoCCC
++ Tworze obiekt InfoClass: info = InfoDDD
++ Usuwam obiekt InfoClass: info = InfoDDD

== info = InfoXXX
== info = InfoXXX

** printInfo: info = InfoXXX
== info = InfoXXX
== info = InfoXXX

++ Tworze obiekt InfoClass: info = InfoSSS
== info = InfoSSS, num = 2019
== info = InfoXXX
== info = InfoSSS, num = 2019

++ Usuwam obiekt InfoClass: info = InfoXXX
++ Usuwam obiekt InfoClass: info = InfoSSS
*/
