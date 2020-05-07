/// \file main.cpp
/// \mainpage
///
/// \n\n
///
/// **********************************************************************************
/// 
/// Zadanie polega na zaimplementowaniu klasy vector, która jest udoskonaloną tablicą
/// przechowującą liczby typu int (podobną do vector<int>).
/// Klasa udostępnia metody i operatory opisane w dokumentacji klasy poniżej.
///
/// ----------------------------------------------------------------------------------
///
/// UWAGI OGÓLNE: 
///
/// Należy utworzyć brakujące pliki 
/// i utworzyć w nich odpowiedni kod, tak aby 
/// program się kompilowal BEZ OSTRZEŻEŃ i poprawnie wykonywał,
/// dając DOKŁADNIE wynik podany w pliku output.txt. 
/// (Należy użyć komendy diff -- 'diff output.txt <( ./exec )').
///  \n\n
/// 
/// Ponadto:
/// a) Należy użyc ***  CMake *** do przygotowania programu
/// -- pliki źrodłowe muszą być w podkatalogu 'src'
/// -- pliki nagłówkowe muszą być w podkatalogu 'include' 
/// -- kod musi się kompilować w nowym podkatalogu (np. 'build')
///    poleceniem 'cmake .. && make' 
/// b) program musi się kompilować z flagami '-Wall -g', jako minimum.
/// c) Jako rozwiązanie, proszę przeslać spakowany katalog źrodlowy, 
///    WŁĄCZAJĄC plik main.cpp, ale BEZ katalogu 'build'. 
/// d) Nie wolno modyfikować pliku main.cpp.
/// e) Proszę nazwać program wykonywalny 'exec'.
///
/// --------------------------------------------------------------------------------- 
///
///    \n\n


#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


/// -------------------------------------------------------------------------------
///
/// *** Klasa vector *** 
/// 
/// Implementuje tablicę liczb int oraz interfejs.
/// 
///  Klasa MUSI posiadać (jako minium):
///  -- dynamiczną tablicę typu int jako składnik, przechowującą dane,
///  -- odpowiednie konstruktory (użyty w fcji main, oraz kopiujący),
///  -- operator [] pozwalający na nadanie wartości oraz odczyt i-tego elementu,
///  -- operator przypisania =,
///  -- operator drukowania do std-in <<,
///  -- metodę push_back(int m) umieszczającą liczbę m na końcu wektora,
///  -- metodę pop_back(int k) usuwającą k ostatnich elementów wektora
///  -- metodę size() zwracającą wymiar wektora
///        
#include "vector.h"
// -----------------------------------------------------------------------------




// =======================================================================
int main() {

	std::cout << "\n";

	// tworzymy wektor 4-elementowy, wypełniony zerami
	MyStuff::vector v1(4); 

	// wpisujemy nowe wartości na pozycje 0 i 1
	v1[0]=1; v1[1]=2;

	// drukujemy wektor i jego wymiar 
	cout << v1 << "\tsize: " << v1.size() << endl;

	// dodajemy nowe elementy na koniec wektora
	v1.push_back(5);
	v1.push_back(8);

	// drukujemy
	cout << v1 << "\tsize: " << v1.size() << endl;

	// tworzymy nowy wektor
	MyStuff::vector v2(10);

	// usuwamy ostatni element wektora v1
	v1.pop_back();

	// tworzymy nowy wektor v3 oraz nadajemy mu, oraz wektorowi v2, zawartość v1
	MyStuff::vector v3 = v2 = v1;

	// wydruk
	cout << v2 << "\t" << v3 << endl;

	
	std::cout << "\n";

return 0;}
/// =======================================================================


