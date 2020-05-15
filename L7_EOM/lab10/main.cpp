 /* Celem zadania jest przećwiczenie podstawowych operacji na kontenerach,
    stosowania iteratorów oraz algorytmów STL.
    Dana jest klasa Person, reprezentująca studenta i jego oceny
    oraz klasa Data, reprezentująca bazę danych studentów. 
    Można w nich wykonywać proste operacje edytorskie, wyszukiwać, 
    zliczać sumy, średnie i sortować ją na różne sposoby.
	Funkcje należy wywnioskować z kodu oraz dołączonych komentarzy. 
	Należy wykorzystać wszystkie możliwe algorytmy STL,
	napisanie funkcji "na piechotę" znacznie obniża ocenę kodu.
    UWAGA!
    Zadanie należy wykonać bez żadnych tradycyjnych pętli ze standardowego C (nawet w print),
    lecz z pomocą tych dedykowanych kontenerom STL oraz iteratorów.
	For dla kontenerów jest OK, ale proszę choć raz skorzystać z for_each.
    Dla urozmaicenia, w klasie Person można zastosować std::vector, a w klasie Data std::array.
	Można korzystać z dokumentacji STL.
	W razie wątypliwości, jestem jak zawsze dostępna na chacie i służę pomocą.
*/

#include "main.h"
#include <iostream>

using namespace std;

int main(){
	vector<double> val {2, 4.5, 5, 3.5};
	const Person stud("Student1", val);
	stud.print(); //wykorzystać std::setw(n) z biblioteki iomanip (n=5)
	cout << "Suma ocen: " << stud.getSum() << endl;
	cout << "Srednia: " << averageScore(stud) << endl;
 	auto result = stud.notIntScores(); // znajduje pierwszą niecałkowitą ocenę
	cout << "Znaleziono ocene niecalkowita: " << *result << endl; //zadanie dodatkowe na później: znajdź wszystkie wystąpienia. zwracając je w postaci wektora
	int neg = count_if(val.begin(), val.end(), badScores()); // badScores zlicza wszystkie oceny negatywne
    cout << "Liczba ocen negatywnych: " << neg << endl; // 2.5 jest oceną negatywną
	cout << "Liczba ocen pozytywnych: " << stud.countGoodScores() << endl << endl; // od 3.0 w górę

	cout << "************  Baza danych  *************" << endl;
 	Data tab;
	tab += stud;
	tab += Person("Student2", {3, 3, 2,3,2});
	tab += Person("Student3", {3.5, 2, 2.5, 3, 3.5});

	tab.fullprint();  //wykorzystać std::setw(n) z biblioteki iomanip (n=4)
	cout << "Liczba ocen pozytywnych dla Student2: " << tab[1].countGoodScores() << endl;
	// dodajemy na koniec nową ocenę dla Student2
	tab[1].addScore(3.5);
	cout << "Liczba ocen pozytywnych dla Student2: " << tab[1].countGoodScores() << endl;
	cout << "Nowa srednia dla Student2: " << averageScore(tab[1]) << endl;

	cout << "\n******* sortowanie po kolumnie 2 *******" << endl;
	tab.sort(1).print(); 

	cout << "******* sortowanie po kolumnie 3 *******" << endl;
	tab.sort(2).print(); 
	// usuwamy ocenę o wartości 2 (pierwsze znalezione wystąpienie)
	tab[2].removeScore(2);
	tab.sort(3); 		// uwaga, niekompletna kolumna, indeks spoza zakresu
	// dodajemy na koniec nową ocenę, tab[2] to aktualnie Student2
	tab[2].addScore(5);
	cout << "Nowa srednia dla Student1: " << averageScore(tab[2]) << endl;
	tab.sort(4); 		// uwaga, indeks spoza zakresu
	cout << "\n********* sortowanie po sredniej *********" << endl;
	// sortujemy po sredniej ocen, malejąco, greaterAverage to funkcja porównująca
    tab.sortBy(greaterAverage).print();
}

/* wynik działania programu:
Student1:      2   4.5     5   3.5
Suma ocen: 15
Srednia: 3.75
Znaleziono ocene niecalkowita: 4.5
Liczba ocen negatywnych: 1
Liczba ocen pozytywnych: 3


************  Baza danych  *************
Student1 srednia: 3.75 suma:   15 oceny:      2   4.5     5   3.5
Student2 srednia:  2.6 suma:   13 oceny:      3     3     2     3     2
Student3 srednia:  2.9 suma: 14.5 oceny:    3.5     2   2.5     3   3.5

Liczba ocen pozytywnych dla Student2: 3
Liczba ocen pozytywnych dla Student2: 4
Nowa srednia dla Student2: 2.75

******* sortowanie po kolumnie 2 *******
Student3:    3.5     2   2.5     3   3.5
Student2:      3     3     2     3     2   3.5
Student1:      2   4.5     5   3.5

******* sortowanie po kolumnie 3 *******
Student2:      3     3     2     3     2   3.5
Student3:    3.5     2   2.5     3   3.5
Student1:      2   4.5     5   3.5

Indeks 3 nieprawidlowy!
Nowa srednia dla Student1: 3.25
Indeks 4 nieprawidlowy!

********* sortowanie po sredniej *********
Student1:    4.5     5   3.5
Student3:    3.5     2   2.5     3   3.5     5
Student2:      3     3     2     3     2   3.5
*/
