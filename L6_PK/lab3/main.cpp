/// \file main.cpp
/// \mainpage
///
/// \n\n
///
/// **********************************************************************************
/// 
/// Zadanie polega na zaimplementowaniu klasy matrix, która reprezentuje macierze
/// liczb całkowitych.
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

// Klasa vector z Lab2
#include "vector.h"

using namespace std;


/// -------------------------------------------------------------------------------
///
/// *** Klasa matrix *** 
/// 
/// Implementuje macierze NxM (N - liczba kolumn, M - l. wierszy) liczb int oraz interfejs.
/// 
///  Klasa MUSI posiadać (jako minium):
///  -- dynamiczną tablicę typu vector**, tj. wiersze macierzy są przechowywane jako wektory
///     (UWAGA: należy użyć własnej klasy vector z Lab2)
///  -- odpowiednie konstruktory (kopiujący,przenoszący),
///  -- operator [] zwracający n-ty wiersz jako obiekt vector,
///  -- operator przypisania = (kopiujący, przenoszący),
///  -- operator drukowania do std-out <<,
///  -- metodę fill wypełniającą macierz przy pomocy tablicy vector[],
///  -- operator dodawania i mnożenia macierzy
//
/// UWAGA: klasę vector należy doposażyć w konstruktor przenoszący i operator = przenoszący,
///         oraz inne ewentualnie potrzebne operatory/fcje.
///         
///  Proszę starać się napisać możliwie kompaktowy kod.       
///        
// -----------------------------------------------------------------------------
#include "matrix.h"


/// Fcja pomocnicza, do sprawdzania konstruktora przenoszącego.
/// Nie należy się ją przejmować.
template<class T> T _copy_(T org) {
	return org; }


// =======================================================================
int main() {

	std::cout << "\n";

	// -------------------------------------------
	// konstrukcja pustych macierzy
	
	const auto Nx1=4;
	const auto Ny1=5;
	MyStuff::matrix m1(Nx1,Ny1);
       
	const auto Nx2=5;
	const auto Ny2=2;
	MyStuff::matrix m2(Nx2,Ny2);

	cout << m1 << m2 << endl;
	// -------------------------------------------
	
	std::cout << "\n";


	// -------------------------------------------
	// wypełnienie macierzy jakimiś liczbami (na dwa sposoby)
	
	int fill_m1[][Nx1] {{0,1,0,1},{1,0,1,0},{0,0,1,1},{1,1,0,0},{1,0,0,1}};
	for (auto k=0;k<Ny1;++k) {
		auto l=0;
		for (auto x: fill_m1[k])
			m1[k][l++] = x; }	

	MyStuff::vector fill_m2[Ny2];
        for (int l=0;l<Nx2;++l) 
		fill_m2[0].push_back(l+1);
	fill_m2[1] = m1[0]+fill_m2[0];


	// -------------------------------------------
	// testowanie operatorów i przenoszenia
	
	using MyStuff::matrix; 
	m2.fill(fill_m2,Ny2);
	matrix m3 = matrix() = matrix(_copy_(m1+m2));
	matrix m4 = m2*m1;
	
	cout << m1 << m2 << m3 << m4;
	
	// -------------------------------------------

return 0;}
/// =======================================================================


