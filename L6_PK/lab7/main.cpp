// *** Nie wolno modyfikować tego pliku ***

/*==========================================================================

***  Kształty i mądre wskaźniki ***

Zadanie polega na napisaniu prostej chierarchii klas
implementującej kształty oraz klasy implementującej
'sprytny wskaźnik' podobny do unique_ptr z biblioteki STL.

-------------------------------------------------------------------------
1. Klasy kształtów

A) klasa Shape

Jest to abstrakcyjna klasa implementująca dowolny (zamknięty) kształt,
który jest charakteryzowany:

i) nazwą
ii) zbiorem parametrów typu zmiennoprzecinkowego (najlepiej użyć std::vector)

Dodatkowo, dla każdego kształtu może zostać wyliczone: 

iii) pole powierzchni (metoda 'area()'),
iv)  obwód (metoda 'circumference()').

B) klasa Circle

Jest to klasa pochodna klasy Shape implementująca koło o zadanym promieniu.
Należy przyjąć pi=3.14.

C) klasa Rectangle

Klasa pochodna klasy Shape implementująca prostokąt o zadanych bokach.


UWAGI:
-- cały kod może się znaleźć w jednym pliku shape.h
-- należy użyć jak najmniej kodu implementując powyższe klasy
-- nie należy implementować zbędnych konstruktorów, fcji. itp
-- PUNKTY KARNE: 
   za deklaracje jakiegokolwiek konstruktora w klasach Circle i Rectangle
   przyznawane jest minus 1 punkt (za każdy konstruktor).

-------------------------------------------------------------------------
2. klasa Shape_ptr

Jest to klasa implementująca sprytny wskaźnik do obiektów Shape.
Ma to być wskaźnik typu unique_ptr, czyli w danym momencie tylko 
jeden wskaźnik może pokazywać na obiekt Shape. 

Należy przeładować odpowiednie operatory, utworzyć konwersje, tak
aby można było używać obiektów Shape_ptr jak zwykłych wskaźników.

W szczególności, proszę pamiętać o cechach sprytnych wskaźników:
-- operatorów ->, * (dereferencja) używa się tak jak dla zwykłych wskaźników
-- likwidacja mądrego wskaźnika likwiduje pokazywany obiekt
-- przypisanie do mądrego wskaźnika innego istniejącego zwykłego lub mądrego wskaźnika 
   likwiduje pokazywany przez niego obiekt
-- sprytny wskaźnik nie może być kopiowany

UWAGI:
-- program nie może mieć wycieków pamięci: 
   jakikowiek wyciek to ZERO PUNKTÓW ZA WYJŚCIE


*///==========================================================================


#include <iostream>
#include <iomanip>


#include "shape.h"
#include "shape_ptr.h"

using namespace std;



// drukuje kształt: jego nadaną nazwę, pole powierzchni i obwód
void print_shape(const Shape& shape) {
	const string area("  area: ");
	const string circumf("  circumference: ");
	cout << fixed << setprecision(5) << shape << " >>"
	<< area << shape.area() << circumf << shape.circumference() << "\n";
}



// =======================================================================
int main() {

	std::cout << "\n";


	// Tworzymy kształt: koło o zadanym promieniu
	Shape *circ1 = new Circle("circle1",{5.14});

	// Tworzymy kształt: prostokąt o zadanych bokach
	Shape *rect1 { new Rectangle("rectangle1",{4.22,6.45})};
	
	// wypisujemy nasze kształty
	print_shape(*circ1);
	print_shape(*rect1);


	// ---------------------------------------------------------------

	// Tworzymy kolejny prostokąt; tym razem używamy mądrego wskaźnika
	Shape_ptr rect2 { new Rectangle("rectangle2",{1.14,2.33})};
	
	// wydruk
	print_shape(*rect2);



	// Utworzenie nowych mądrych wskaźników:
	Shape_ptr rect1a;
	Shape_ptr rect2a; 
	
	// przypisanie do nich istniejących wskaźników:
	rect1a = rect1;
	rect2a = rect2;

        // wydruk
	print_shape(*rect2a);
	if (rect2)
        	print_shape(*rect2);
	if (rect1)
        	print_shape(*rect1);


	// Poniższe instrukcje powinny wyrzucić błąd kompilacji,
	// ponieważ nie można kopiować mądrego wskaźnika
	//   Shape_ptr rect2a = rect2 ;
	//   Shape_ptr rect2a { rect2 };


	// Usuwamy obiekty pokazywane zwykłymi wskaźnikami
	delete circ1;
	// proszę pamiętać, że delete nie ma efektu jeśli wskaźnik=nullptr
	delete rect1;

	std::cout << "\n";

return 0;}
/// =======================================================================

/* *** Spodziewane wyjście ***

circle1 >>  area: 82.95754  circumference: 32.27920
rectangle1 >>  area: 27.21900  circumference: 21.34000
rectangle2 >>  area: 2.65620  circumference: 6.94000
rectangle2 >>  area: 2.65620  circumference: 6.94000

*/
