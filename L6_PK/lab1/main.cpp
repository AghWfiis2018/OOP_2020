/// \file main.cpp
/// \mainpage
///
/// \n\n
///
//  ----------------------------------------------------------------------------------
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
//  --------------------------------------------------------------------------------- 
///
///    \n\n


#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


// -------------------------------------------------------------------------------
//
/// *** Klasa QuantumWire ***
///
/// 1) Klasa implementuje cząstki (lub 'kwanty' cząstek) umieszczone na 'drucie' o długości L.
///    Każda cząstka może być w stanie 0 lub 1. 
/// 
///    Klasa MUSI mieć przynajmniej następujące pola:
///	-- długość drutu (typ double)
///	-- dynamiczna tablica cząstek na drucie (typ bool* )
//
///    Klasa musi mieć (jako minimum) następujące konstruktory:
///	-- konstruktor tworzący cząstki na drucie o zadanej długości;
///	   Stan cząstki (0 lub 1) jest losowany fcją rand()
///	-- Konstruktor domyślny, który co najwyżej zeruje pola i wskaźniki.
///	-- Konstruktor kopiujący i przenoszący.
///
///    Należy przeładować następujące operatory (szczegóły implementacji
///    trzeba odczytać z fcji main i wyjścia z pliku output.txt):
///	-- przypisania kopiującego i przenoszącego
///	-- operator =* dla mnożenia drutu przez liczbę double x.
///	   W wyniku powiększamy długość drutu x razy.
///	-- operator * dla mnożenia drutu przez double x z lewej bądź prawej strony.
///	   Efekt taki sam jak dla =*.
///	-- Operator !.
///	   Operator ten zmienia stan wszystkich cząstek na przeciwny,
///	   tj. 0 na 1, 1 na 0. (ale nie zmienia oryginału);
///	-- Operator []
///	   Pozwala na wyświetlenie stanu i-tej cząstki   
///	-- Operator konwersji do int
///	   Konwersja obiektu zwraca liczbe kwantów.
///	-- Operator ()
///	   Operator ten ma realizować predykat, który porównuje długości dwóch drutów.
///	   Predykat to fcja zwracająca bool, i borąca jako argumenty dwa obiekty danej klasy.
///	   (oprócz wskaźnika this, jeśli jest fcją składową).
///	-- Operator << drukujący obiekt QuantumWire std-out
///	   Format wydruku widoczny jest w pliku output.txt.
///        
#include "wire.h"
// -----------------------------------------------------------------------------




// =======================================================================
int main() {

	srand(1343375771);// seed dla generatora liczb pseudolosowych
	std::cout << "\n";

	// Tworzymy 3 druty kwantowe o podanych długościach
	// i podanej liczbie kwantów.
	
	  QuantumWire qw1(10.,5), qw2(40.,8), qw3 (1.,2);

	  cout << qw1 << "\n" << qw2 << "\n" << qw3 << endl;



	cout << "\n-------------------------------------------------------------\n" << endl;

	// Testujmey operatory =  *= , *, !, []

	  QuantumWire qw4 = 6.28*(!qw3);

	  cout << (qw1*=2.) << "\n" << 3.*qw2 << "\n" << qw2*3. << "\n" 
	  << !qw1 << "\n" << !qw2 << "\n" << qw4 << "\n"  << endl;

	  for (int k=0;k<qw2;k++)	cout << qw2[k] << " ";
	  

	cout << "\n\n-------------------------------------------------------------\n" << endl;

	// Tworzymy STL wektor drutów kwantowych i sortujemy malejąco używając predykatu,
	// danego jako obiekt klasy QuantumWire.
	
  	  vector<QuantumWire> wires;
	  wires.push_back(qw1);
	  wires.push_back(qw2);
	  wires.push_back(qw3);
	  wires.push_back(qw4);

	  QuantumWire pred; 

	  sort(wires.begin(),wires.end(), pred );

	  vector<QuantumWire>::iterator it = wires.begin();
	  while (it!=wires.end()) { 
	  	cout << *it << endl;
		it++;
	  } 

	
	std::cout << "\n";

return 0;}
/// =======================================================================


