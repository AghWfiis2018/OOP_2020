/* 
 * Celem zadania jest napisanie klasy opakowujacej tablice bitow BitArray.
 * Bity maja byc zlozone w tablicy "unsigned char" o odpowienim rozmiarze zaalokowanym przy konstrukcji, tak duzym aby sie one wszystkie bity tam sie zmiescily.
 * Tablica ta musi byc alokowana dynamicznie (mozna uzyc kontnerow z biblioteki standardowej).
 * Klasa BitArray posiada wygodny interfejs pozwalajacy sprawdzic i ustawic wartosci bitow w zadanych pozycjach.
 *
 * UWAGA: Ta alokacja musi byc optymalna. np. Dla 7 bitow, powinna byc alokowana tablica zlozona z jedenego elementu
 * dla 20 bitow, z 3 elementow
 * UWAGA: Rozwiazanie take ze do przechowani informacji i pojedynczym bicie uzywany jest jeden bajt jest zadaniem nie na temat, punktowanym na 0
 * 
 * Kopiowanie bajtow z tablicy do tablicy mozna wykonac z uzyciem funkcji z biblioteki cstring:
 * 		std::memcpy( cel, zrodlo, ilosc_bajtow );
 */

#include "BitArray.h"
#include <iostream>

int main() {
	BitArray ba(35);              // miejsce na 35 bitow indeksowanych od 0 do 34, wszystkie sa ustawione na 0 (false)
	BitArray bb(35, true);        // jw tylko ze wszystkie sa 1 (true)

	// // zmiana wartosci bitow
	ba[3] = true;                 // UWAGA: tu nie mozna zwrocic ref do wartosci bool a trzeba
	bb[3] = false;                // pewien obiekt, ktory jakos wskazuje na pozycje w tablicy
	// 							  // bitow i przeladowuje operatory = i bool

	bool v1 = ba[3];
	bool v2 = ba[4];
	std::cout << "Bity: " << v1 << " " << v2<< std::endl;

	std::cout << "ba:"  << std::endl;
	ba.print();
	std::cout  << std::endl;

	std::cout << "bb:" << std::endl;
	bb.print();
	std::cout << std::endl << std::endl;

	bb[7] = false;
	bb.print();
	std::cout << std::endl << std::endl;

	bb[8] = false;
	bb.print();
	std::cout << std::endl << std::endl;

	// Test na duzym obiekcie:
	BitArray large(128);
	large[12] = true;
	large[13] = true;
	large[64] = true;
	std::cout << std::endl << "large: " << std::endl;
	large.print();
	std::cout << std::endl << std::endl;

	// Test na stalym obiekcie:
	const BitArray cb(4, true);
	cb.print();
	std::cout << "\npojedyncze bity: " << std::boolalpha; 
	for( int i = 3; i>=0 ; --i){
		std::cout << cb[i] << ",";
	}
	std::cout << std::noboolalpha << std::endl << std::endl;

	// Kopiowanie
	ba = bb;	
	std::cout << "ba:"  << std::endl;
	ba.print();
	std::cout << std::endl;
	std::cout << "bb:" << std::endl;
	bb.print();
	std::cout << std::endl;
 
}

/* Oczekiwany wynik dzialania programu:
Bity: 1 0
ba:
000 <-32 00000000 <-24 00000000 <-16 00000000 <-8 00001000 <-0 
bb:
111 <-32 11111111 <-24 11111111 <-16 11111111 <-8 11110111 <-0 

111 <-32 11111111 <-24 11111111 <-16 11111111 <-8 01110111 <-0 

111 <-32 11111111 <-24 11111111 <-16 11111110 <-8 01110111 <-0 


large: 
00000000 <-120 00000000 <-112 00000000 <-104 00000000 <-96 00000000 <-88 00000000 <-80 00000000 <-72 00000001 <-64 00000000 <-56 00000000 <-48 00000000 <-40 00000000 <-32 00000000 <-24 00000000 <-16 00110000 <-8 00000000 <-0 

1111 <-0 
pojedyncze bity: true,true,true,true,

ba:
111 <-32 11111111 <-24 11111111 <-16 11111110 <-8 01110111 <-0 
bb:
111 <-32 11111111 <-24 11111111 <-16 11111110 <-8 01110111 <-0 
*/
