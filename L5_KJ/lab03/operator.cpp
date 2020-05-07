/* Przeladowanie operatora new i delete.
* Czesto alokacja malych obiektow moze byc przyczyna niewydajnosci programow.
* W zadaniu mamy do czynienia z taka mala klasa: Malenstwo, ktorej obiekty
* bedziemy chcieli alokowac w duzej ilosci. Jedynym skladnikiem klasy Malenstwo
* ma byc pojedynczy integer.
* 
* Nalezy odpowiednio przeladowac operatory new i delete, tak aby alokowac
* od razu 100 obiektow, a potem wykorzystywac zaalokowana pamiec. 
* 
* Do zarzadzania pamiecia warto przygotowac pomocnicza klase, ktora bedzie 
* dbala o alokowanie pamieci i jej zwalnianie gdy przystanie byc potrzebna.
* 
* Kolejnym rozszerzeniem zadania bedzie zadbanie o wykorzystywanie wolnej
* pamieci, rozszerzania w razie potrzeby etc. Na razie mozna zalozyc ze 
* w programie nie pojawia sie duzo obiektow, ale sa alokowane/dealokowane 
* bardzo czesto, i to rzedem (najpierw alokacja, potem zwalnianie wszystkiego,
* potem nowe alokacje etc).
* 
* Druga pomocna (acz trywialna klasa do napisania) jest MalenstwoSamoSprzatacz
* dostarczajacy semantyki wskaznika, ale dbajacy o usuniecie pamieci
* przy wyjsciu z zakresu (ulomny sprytny wskaznik).
* 
* Kompilacja do plitu atest z flagami -Wall -g
*/

#include "Malenstwo.h"
#include <iostream>

int main()
{
	/////////////////////////////////////////
	// podstawowe alokowanie obiektow 
	Malenstwo* x1 = new Malenstwo(12);
	std::cout << x1->wartosc() << std::endl;
	Malenstwo* x2 = new Malenstwo(13);
	std::cout << x2->wartosc() << std::endl;
	Malenstwo* x3 = new Malenstwo(34);
	Malenstwo* x4 = new Malenstwo(7);
	
	std::cout << "cos o ulozeniu w pamieci" << std::endl;
	x3->wartosc() = 9;
	x4->wartosc() = 7;
	std::cout << "x3 " << (x3)->wartosc() << std::endl;
	// normalnie ponizszej operacji nie powinnismy wykonywac!!!
	std::cout << "x3++ " << (x3+1)->wartosc() << std::endl; 
	
	/////////////////////////////////////////
	// operacje na tablicy
	std::cout << "alokujemy tablice" << std::endl;
	Malenstwo* tab = new Malenstwo[5];
	tab[0] = 10;
	tab[1].wartosc() = 5;
	std::cout << "tab[0] = " << tab[0].wartosc() << std::endl;
	std::cout << "tab[1] = " << tab[1].wartosc() << std::endl;
	std::cout << "tab[2] = " << tab[2].wartosc() << std::endl;
	delete[] tab;
	
	/////////////////////////////////////////
	// potworek...
	delete new Malenstwo(3);
	
	/////////////////////////////////////////
	// ulomny ale sprytny wskaznik
	x1 = new Malenstwo(99); 
	{
		MalenstwoSamoSprzatacz sm(new Malenstwo(51));
		std::cout << "sm : " << sm->wartosc() << std::endl;
		sm->wartosc() ++;
		std::cout << "sm : " << sm->wartosc() << std::endl;
	}
	delete x1;  
	
	return 0;
}

/* output:
Alokuje jeden obiekt: 1 (4 bajtow)
Pierwszy obiekt na stercie - prealokuje skladowisko na 100 elementow
Konstrukcja Malenstwa: wart = 12
12
Alokuje jeden obiekt: 1 (4 bajtow)
Konstrukcja Malenstwa: wart = 13
13
Alokuje jeden obiekt: 1 (4 bajtow)
Konstrukcja Malenstwa: wart = 34
Alokuje jeden obiekt: 1 (4 bajtow)
Konstrukcja Malenstwa: wart = 7
cos o ulozeniu w pamieci
x3 9
x3++ 7
alokujemy tablice
Alokuje tablice [] o rozmiarze5 (28 bajtow)
Konstrukcja Malenstwa: wart = 10
tab[0] = 10
tab[1] = 5
tab[2] = 0
Zwalniam tablice [] o rozmiarze5 (28 bajtow)
Alokuje jeden obiekt: 1 (4 bajtow)
Konstrukcja Malenstwa: wart = 3
Zwalniam jeden obiekt: 1 (4 bajtow)
Alokuje jeden obiekt: 1 (4 bajtow)
Konstrukcja Malenstwa: wart = 99
Alokuje jeden obiekt: 1 (4 bajtow)
Konstrukcja Malenstwa: wart = 51
sm : 51
sm : 52
Zwalniam jeden obiekt: 1 (4 bajtow)
Zwalniam jeden obiekt: 1 (4 bajtow)
*/
