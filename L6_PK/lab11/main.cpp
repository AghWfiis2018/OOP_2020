// *** Nie wolno modyfikować tego pliku ***

/*==========================================================================


*** Clone Experiment ***

Państwa sukcesy w dotychczasowych zadaniach Agencji Kosmicznej
skutkują kolejnym zleceniem.
Dalsza intensywna eksploracja kosmosu wymaga badania efektów 
Ogólnej i Szczególnej Teorii Względności na ludziach.
Nie bacząc na etykę, naukowcy postanawiają zklonować grupę ludzi i wysłać
dwie grupy klonów w podróż kosmiczną statkiem. Jedna grupa będzie doświadczać 
spowolnienia czasu ze względu na podróż z bardzo dużą prędkością, zaś druga
doświadczy spowolnienia czasu orbitując w pobliżu najbliższej czarnej dziury.
Wiek klonów zostanie porównany z wiekiem ludzi-oryginałów na Ziemi.

Zlecenie składa się z następujących etapów:


1. Obsługa czasu (human.h)

Należy zaimplementować format czasu w postaci (lata,dni,godziny,minuty,sekundy).
Format ten będziemy niżej nazywać 'human-readable'.
W tym celu należy użyć kontenera std::tuple<int,int,int,int,int> oraz przeładować
następujące globalne operatory oraz fcje:
a) << 
   Drukowanie czasu w formacie #y:#d:#h:#m:#s (gdzie znak # oznacza jakąś liczbę).
b) +
   Dodawanie dwóch czasów.
c) to_sec
   Fcja konwertująca czas human-readable na sekundy.
d) from_sec
   Fcja konwertująca czas w sekundach na human-readable.
e) _yrs
   Konwersja literału liczby oznaczającej lata do formatu human-readable.
   Np. 12_yrs to 12y:0d:0h:0m:0s.
f) _sec
   Konwersja literału liczby oznaczającej sekundy do formatu human readable.


2. Klasa Human (human.h)

Klasa przechowująca nazwisko oraz wiek człowieka (w formacie human-readble). 
Oprócz potrzebnych konstruktorów oraz getterów, powinna zawierać funkcję update_time,
której argumentem jest czas human-readable o który należy zwiększyć wiek człowieka.


3. Klasa Clone (human.h)

Klasa pochodna klasy Human, która służy do produkcji klonów.
a) Klon tworzony jest na podstawie obiektu Human.
b) Nazwa każdego kolejnego klona musi zawierać przyrostek "_X", 
   gdzie X to numer klona. Przyrostek ten obliczany oraz dodawany
   jest AUTOMATYCZNIE. Poprawne wykonanie tej części nie może używać
   żadnych globalnych obiektów.


4. Klasa Spacecraft (spacecraft.h)

Klasa przechowuje załogę (o typie polimorficznym Human) w postaci dowolnego 
kontenera (ale najwygodniejszy rodzaj jest do odczytania z fcji main).
Oprócz odpowiedniego konstruktora klasa musi zawierać fcję update_time, która
przyjmuje dwa argumenty: i) obiekt fcyjny lub wyr. lambda, ii) czas w formacie 
human-readble. Zadaniem obiektu fcjynego jest obliczenie nowego czasu na 
podstawie czasu podanego w argumencie ii stosując przesłaną przez użytkowanika 
fcję. Następnie fcja update_time uaktualnia wiek załogi. Sczegóły znajdują się
w main. Proszę pytać w razie wątpliwości.
 

UWAGI:
-- koniecznie należy stosować odpowiednie typedef'y
-- proszę stosować kontenery i algorytmy STL
-- zwracamy uwagę na poprawne deklaracje stałych; nie można używać makr C

*///==========================================================================


#include <iostream>
#include <vector>
#include <cmath>

#include "human.h"
#include "spacecraft.h"

// -----------------------------------------------------------------------
void print_human(const Human& h) {
	std::cout << h.get_name() << "  (" << h.get_age() << ")" << std::endl;
}


// =======================================================================
int main() {

	std::cout << "\n-----------------------------------------\n\n";

	// ** Testy implementacji czasu **

	// czas implementowany jako std::tuple, kolejno: lata,dni,godziny,minuty,sekundy
	const std::tuple<int,int,int,int,int> some_time {2,32,44,5,54};

	// wydruk z użyciem przeładowanych operatorów << oraz +
	std::cout << some_time << "\t" << some_time+some_time << std::endl;

	// test konwersji literałów (używam decltype zamiast typedef w celu demonstracji)
	decltype(some_time) other_time = 8733298031_sec; // konwersja sekundy do tuple (lata,dni,...)
	decltype(some_time) only_years = 65_yrs; // konwersja lata -> tuple
	std::cout << other_time << "\t" << only_years << std::endl;


	std::cout << "\n-----------------------------------------\n\n";

	// ** Testy implementacji klas Human i Clone **

	// Tworzymy niewielką populację ludzi o zadanym wieku:
	std::vector< Human > population;
	population.push_back( Human("Rogers",26_yrs) );
	population.push_back( Human("Martinez",36_yrs) );
	for (auto p : population) 
		print_human(p); // wydruk

	// Klonujemy ludzi z populacji aby poddać ich eksperymentowi. 
	// Każdy klon istniejącego człowieka dostaje automatycznie 
	// suffix '_X', gdzie X to numer klonu.
	std::vector< Human* > clones1;
	std::vector< Human* > clones2;
	for (auto p : population) {
		clones1.push_back(new Clone(p));
		clones2.push_back(new Clone(p));
	}
	for ( auto l : {clones1,clones2} )
		for (auto k : l)
			print_human(*k); // wydruk

	std::cout << "\n-----------------------------------------\n\n";

	// ** Eksperyment na klonach **

	// 

	// czas trwania eksperymentu na Ziemi
	const auto t = 5_yrs; 

	// starzejemy populację na Ziemi
	for (auto &l : population)
		l.update_time(t);

	// --- Klony 1 wysłano w podróż kosmiczną z dużą prędkością.
	Spacecraft ship1(clones1);
	const double v = 500.; // prędkość podróży rakietą [km/s]
	ship1.update_time([v]( 
				// fcja zwraca czas w układzie poruszającym się
				const decltype(1_yrs)& time) { 
					const double c = 3e8; // prędkość światła w [m/s]
					const double igamma=sqrt(1.-pow(v*1000./c,2)); // czynnik Lorentza^-1
					return from_sec(igamma*to_sec(time)); } // skrócenie czasu;
			  , t);

	// klony powinny być młodsze niż ludzie na Ziemi
	print_human( population.at(1) );
	print_human( ship1["Martinez_1"] );


	// --- Klony 2 wysłano w sąsiedztwo najbliższej czarnej dziury Cygnus X-1 
	Spacecraft ship2(clones2);
	const double r = 100; // odległość od centrum czarnej dziury Sagittarius A* [km]
	const double M = 15;   // Masa czarnej dziury (masy słońca)
	ship2.update_time([M,r]( 
				// fcja zwraca czas w układzie znajdującym sie w odl. r od masy M
				const decltype(1_yrs)& time) { 
					const double c = 3e8; // prędkość światła w [m/s]
					const double G = 6.67e-11; // stała grawitacji [m^3/kg/s^2]
					const double Msun=2e30; // masa słońca [kg] 
					const double lam=sqrt(1.-2.*G*M*Msun/r/c/c/1000.); 
					return from_sec(lam*to_sec(time)); } // skrócenie czasu;
			  , t);

	// klony powinny być starsze niż ludzie na Ziemi
	print_human( ship2["Martinez_2"] );

	std::cout << "\n-----------------------------------------\n\n";


	for ( auto l : {clones1,clones2} )
		for (auto k : l) delete k;

return 0;}
/// =======================================================================

/* *** Spodziewane wyjście ***


-----------------------------------------

2y:32d:44h:5m:54s	4y:64d:88h:10m:108s
276y:339d:20h:7m:11s	65y:0d:0h:0m:0s

-----------------------------------------

Rogers  (26y:0d:0h:0m:0s)
Martinez  (36y:0d:0h:0m:0s)
Rogers_1  (26y:0d:0h:0m:0s)
Martinez_1  (36y:0d:0h:0m:0s)
Rogers_2  (26y:0d:0h:0m:0s)
Martinez_2  (36y:0d:0h:0m:0s)

-----------------------------------------

Martinez  (41y:0d:0h:0m:0s)
Martinez_1  (40y:364d:23h:56m:20s)
Martinez_2  (39y:265d:0h:3m:44s)

-----------------------------------------



*/