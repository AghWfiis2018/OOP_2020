 // Celem zadania jest przećwiczenie podstawowych algorytmów STL.
 // Stworzymy klasę reprezentującą tabelkę wydatków. Można ją sortować na różne 
 // sposoby.
 
 // UWAGA
 // Zadanie należy wykonać bez żadnych tradycyjnych pętli (nawet w print), 
 // lecz z użyciem algorytmów STL.

 // Tips:
 // - wypisanie równej liczby znaków: std::cout<<std::setw(liczba) -- nagłówek iomanip 
 // - można korzystać z dokumentacji: np. http://www.cplusplus.com/reference/

#include "Expense.h"
#include "Table.h"
#include <iostream>

int main(){
	const Expense day1("Sobota", {8.6, 2, 3.2});
	day1.print();
	std::cout << "srednia wydatkow z soboty: " << day1.mean() << std::endl;

	std::cout << "   ============= Table =============" << std::endl;
 	Table table;
	table += day1;
	table += Expense("Wtorek", {3, 2.5, 13, 2});
	table += Expense("Piatek", {1, 3.5, 1.3, 1.5, 12.3});

	table.print();
	std::cout << "======= sortowanie po kolumnie 3 =======" << std::endl;
	table.sort(2).print(); 

	std::cout << "======= sortowanie po kolumnie 2 =======" << std::endl;
	table.sort(1).print(); 

	table.sort(3); // uwaga, tutaj niedozwolony indeks kolumny 
	std::cout << "========= sortowanie po srednich =========" << std::endl;
	table.sortByMean().print(); // sortowanie po sredniej z kolumn, rosnąco
}

/* wynik działania programu:

Sobota:    8.6     2   3.2
srednia wydatkow z soboty: 4.6
   ============= Table =============
Sobota:    8.6     2   3.2
Wtorek:      3   2.5    13     2
Piatek:      1   3.5   1.3   1.5  12.3

======= sortowanie po kolumnie 3 =======
Piatek:      1   3.5   1.3   1.5  12.3
Sobota:    8.6     2   3.2
Wtorek:      3   2.5    13     2

======= sortowanie po kolumnie 2 =======
Sobota:    8.6     2   3.2
Wtorek:      3   2.5    13     2
Piatek:      1   3.5   1.3   1.5  12.3

Indeks 3 nieprawidlowy! 
========= sortowanie po srednich =========
Piatek:      1   3.5   1.3   1.5  12.3
Sobota:    8.6     2   3.2
Wtorek:      3   2.5    13     2

*/
