 // Celem zadania jest stworzenie klasy UniquePtr będącej sprytnym wskaźnikem. 
 // Jest to klasa opakowująca wskaźnik na Point tak, aby w danej chwili
 // tylko 1 obiekt UniquePtr mógł wskazywać na 1 obiekt. 
 
 // - Nie jest możliwe kopiowanie lub przypisanie kopiujące wskaźnika.
 //	- Możliwe jest przenoszenie (konstruktor i przenoszący operator przypisania).
  
 // Sprytny wskaźnik ma obslugiwać proste klasy 
 // Point 		 - punkt o współrzędnych x, y,
 // LabeledPoint - j.w., pochodna Point, ale z etykietą (nazwą),
 // które mają głośny konstruktor i destruktor, metodę info() zwracającą dane i settery.
 
 // Proszę przeczytać zadanie do końca.
 // UniquePtr zadziała automatycznie dla klasy pochodnej: LabeledPoint,
 // ale trzeba dopisać własną funkcję globalną setName do zmiany etykiety obiektu.

 // UWAGA
 // Gotowy plik Point.h jest do pobrania z UPeLa. Nie można go modyfikować.

 // Tips:
 // - można użyć std::string. Konkatenacja string1 + string2
 // - zamiana liczby na string: std::to_string(liczba) 
 
#include "UniquePtr.h"
#include "Point.h"
#include "LabeledPoint.h"
#include <iostream>

void printInfo(const Point& info){
	std::cout << "   printInfo: " << info.info() << std::endl;
}

void printPtr(const UniquePtr& sp){
	std::cout << "   pointer: " << sp.get();
	if(sp) std::cout << ", info: " << sp->info() << std::endl;
	else std::cout << std::endl;
}

int main(){
	{
		Point point1(1, 2);
		printInfo(point1);
	}
	std::cout << "==============" << std::endl;

 	UniquePtr smart1( new Point(2, 3) );
	printPtr(smart1);

 	{
		UniquePtr smart2 = std::move(smart1);
		printPtr(smart2);
	    
	    UniquePtr smart3( new Point(3, 4) );
		printPtr(smart3);

		smart3 = std::move(smart2);
		printPtr(smart3);
		printPtr(smart2);
	}
	
	std::cout << "==============" << std::endl;
	UniquePtr smart4( new LabeledPoint("platan", 4, 5) );
	printInfo(*smart4);
	setName(smart4.get(), "brzoza");
	printInfo(*smart4);
	Point *rawPtr = smart4.release();
	delete rawPtr;

	// do wymyślenia w domu: 
	// jakiekolwiek porównania nie powinny być możliwe (jak najkrócej to zapewnić?)
	// if(smart1 != smart2 ) std::cout<< "=== Nie powinno sie skompilowac === " << "\n";
}

/* wynik działania programu:

++ Tworze punkt (1, 2)
   printInfo: pkt 1, 2
-- Usuwam punkt (1, 2)
==============
++ Tworze punkt (2, 3)
   pointer: 0x5641f6c3c280, info: pkt 2, 3
   pointer: 0x5641f6c3c280, info: pkt 2, 3
++ Tworze punkt (3, 4)
   pointer: 0x5641f6c3c2a0, info: pkt 3, 4
-- Usuwam punkt (3, 4)
   pointer: 0x5641f6c3c280, info: pkt 2, 3
   pointer: 0
-- Usuwam punkt (2, 3)
==============
++ Tworze punkt (4, 5)
++ Tworze punkt o nazwie: platan
   printInfo: pkt 4, 5 -- platan
   printInfo: pkt 4, 5 -- brzoza
-- Usuwam punkt o nazwie: brzoza
-- Usuwam punkt (4, 5)

*/
