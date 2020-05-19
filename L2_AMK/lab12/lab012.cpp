/*
 Celem zadania jest napisanie klasy, która zachowuje się jak 
 tablica 2-wymiarowa o zmiennym kształcie. Czyli np. tablicę a x b = 4 x 5 
 można przekształcić na c x d = 10 x 2, ale nie można, gdy a x b != c x d.

 Taką tablicę najwygodniej zapisać w tablicy 1D. 
 Trzeba tylko odpowiednio mapować indeksy z 2d na indeks w 1d,
 czyli indeksy (i, j) -> na indeks n

 Dostęp do tablicy jest na dwa sposoby. 
 - Bez sprawdzania poprawności indeksów -- przez operator[]. 
 - Ze sprawdzaniem poprawności indeksów -- przez metodę: at.

 Wyjątki są rzucane przy:
 - wyjściu poza zakres w którymś z wymiarów,
 - jeśli żądany w reshape nowy kształt jest niemożliwy do otrzymania, tzn. a x b != c x d.

 Wskazówki:
 - zmiana kształtu tablicy jest trywialna.
 - zamiana liczby na string: std::to_string(liczba)
 - konkatenacja stringów: string1 + string2
 - wyrzucamy obiekt napisanej przez siebie klasy lub standardowy wyjątek 
   (proszę dodać odpowiedni include w którymś z plików).
 */

// to ma uniemożliwić użycie std::vector
namespace std {struct vector {};}

#include "BadDimsException.h"
#include "Array2D.h"
#include <iostream>
#include <string>

int main() {
	Array2D arr(3, 4); // konstruktor wypelnia tablicę od 1 do 12 (czyli 3*4)
	std::cout << arr << "\n";

	try{
		arr.reshape(2, 6);
		std::cout << arr << std::endl;

		arr.reshape(3,5);
		std::cout << "Ooops!" << std::endl;
	}
	catch(BadDimsException &e){
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try{
		arr[1][3] = -99; // co tu trzeba zwrócić?
		std::cout << arr << std::endl;
		std::cout << "value at (1,2): " << arr.at(1,2) << std::endl; // w at sprawdzamy czy indeksy i,j są prawidłowe
		arr.at(2, 5) = 0;
		std::cout << "Something wrong!" << std::endl;
	}
	catch(std::out_of_range &e){
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try{
		const Array2D arr2(2,3);
		std::cout << "value at (1,2): " << arr2.at(1,2) << std::endl; 
		std::cout << arr2.at(1,3) << std::endl; 
	}
	catch(std::out_of_range &e){
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	Array2D arr2(1,2);
	arr2 = arr; // jak napisać, żeby było super bezpieczne. 
	std::cout << arr2;
// do zastanowienia: co zrobić, żeby at sprawdzała wychodzenie poza zakres
// w obu wersjach: const i nie-const, ale nie pisać dwa razy tego samego kodu?
}

/* wynik

1	2	3	4	
5	6	7	8	
9	10	11	12	

1	2	3	4	5	6	
7	8	9	10	11	12	

Exception caught: dimensions 3 and 5 do not conform with 2 and 6
1	2	3	4	5	6	
7	8	9	-99	11	12	

value at (1,2): 9
Exception caught: out of range at i=2
value at (1,2): 6
Exception caught: out of range at j=3
1	2	3	4	5	6	
7	8	9	-99	11	12	

 */