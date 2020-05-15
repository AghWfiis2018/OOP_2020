/*
 Dziedziczenie wielokrotne z polimorfizmem + wykorzystanie  dynamic_cast.
 Ponieważ ostatnim razem właściwa hierarchia klas pozostawiała sporo do życzenia,
 jeszcze raz ją przećwiczymy, tym razem z klasami polimorficznymi.
 
 Należy stworzyć hierarchię klas reprezentujących obiekty graficzne w układzie współrzędnych XY:
 koło, odcinek, deltoid (przypominam, że to taki czworokąt, którego przekątne przecinają się pod kątem prostym).

 Każdy z obiektów graficznych ma swoje własności (można je np. rysować, wyliczyć długość/obwód,  
 przesuwać, obliczać pole, jeśli kształt jest zamknięty), 
 ale tylko jeśli dziedziczą po odpowiednich klasach. 

 Proszę na podstawie wyniku wywnioskować hierarchię klas oraz napisać niezbędne funkcje.
 W ramach dokumentacji w pliku main.h proszę uzasadnić zastosowaną hierarchię oraz dołączyć utworzone
 przez siebie pliki z klasami. Proszę nie tworzyć osobnych plików dla każdej z klas, 
 tylko je pogrupować tematycznie (np wirtualne osobno, obiekty graficzne osobno).
 */

#include <iostream>
#include "main.h"

int main() {
	const Point p(1.5, 3.0);
	std::cout << "Punkt " << p << std::endl;
	// Koło o promieniu 3 i srodku p
	Circle kolo(p, 3); 					
	// Odcinek od punktu (1, 1) do (-3, 5)	
	Section ab(Point(0, 1), Point(-3, 5));
//	std::cout << "Dlugosc odcinka: " << ab.length() << std::endl;
	// Definiujemy przekątne diag1 i diag2 dla deltoidu (przekątne przecinają cię pod kątem prostym)
	Section diag1 (Point(0.5, 1.0), Point(5.0, 1.0)), 
	        diag2 (Point(2, 0), Point(2, 2));
	Deltoid delt1 (diag1, diag2); 			
	// Deltoid inicjowany za pomocą wierzchołków - punkty podawane sa po kolei zgodnie z rysowaniem
    Deltoid delt2(Point(0, 0), Point(2.5, 0), Point(2.5, 2.5), Point(0, 2.5));
	// Tablica obiektów do narysowania
	unsigned numObj = 4;
	Drawable *list[]{&kolo, &ab, &delt1, &delt2};
	for (unsigned i = 0; i < numObj; ++i){
		std::cout << "\n*** Obiekt " << i+1 << " ***\n";
		draw(list[i]); 
		std::cout << "Dlugosc/Obwod = " << list[i]->length() << std::endl;
		// Przesuwamy figury o wektor [1,1]
		Transformable *t = dynamic_cast<Transformable*>(list[i]);
		if(t) t->shift(1.0, 1.0);
		draw(list[i]); 
		// tylko koło i deltoid, bez odcinka (pole rombu liczymy z przekątnych)
		const ClosedShape *shape = dynamic_cast<const ClosedShape*>(list[i]);
		if(shape) std::cout << "Pole = " << shape->area() << std::endl;
	}
	Transformable *t = &delt2;
	t->shift(2.0, 2.0);
	draw(&delt2);

	#ifdef ERROR1
	Drawable* d = t; // ma powodować błąd komilacji: "cannot convert ..."
	#endif
	#ifdef ERROR2
	Transformable* t2 = list[0]; // ma powodować błąd komilacji: "cannot convert ..."
	#endif
}

/* wynik 
Punkt (1.5, 3)

*** Obiekt 1 ***
Rysujemy kolo o srodku (1.5, 3) i promieniu 3
Dlugosc/Obwod = 18.8496
Rysujemy kolo o srodku (2.5, 4) i promieniu 3
Pole = 28.2743

*** Obiekt 2 ***
Rysujemy odcinek od (0, 1) do (-3, 5)
Dlugosc/Obwod = 5
Rysujemy odcinek od (1, 2) do (-2, 6)

*** Obiekt 3 ***
Rysujemy deltoid o wierzcholkach (0.5, 1), (2, 0), (5, 1), (2, 2)
Dlugosc/Obwod = 9.93011
Rysujemy deltoid o wierzcholkach (1.5, 2), (3, 1), (6, 2), (3, 3)
Pole = 9

*** Obiekt 4 ***
Rysujemy deltoid o wierzcholkach (0, 0), (2.5, 0), (2.5, 2.5), (0, 2.5)
Dlugosc/Obwod = 10
Rysujemy deltoid o wierzcholkach (1, 1), (3.5, 1), (3.5, 3.5), (1, 3.5)
Pole = 12.5
Rysujemy deltoid o wierzcholkach (3, 3), (5.5, 3), (5.5, 5.5), (3, 5.5)
 */
