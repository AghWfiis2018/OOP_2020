// *** Nie wolno modyfikować tego pliku ***

/*==========================================================================

*** Czarne Dziury ***

Olbrzymi radioteleskop zbudowany na Marsie podczas poprzedniej misji umożliwia obserwację odległych obiektów z niespotykaną dotąd dokładnością, w tym czarnych dziur. Agencja Kosmiczna zleca Ci napisanie prostego oprogramowania zarządzającego katalogiem zaobserwowanych czarnych dziur.

Należy napisać następujące klasy:

1. BlackHole (blackhole.h)

Klasa przechowuje następujące informacje dot. czarnych dziur:
-- nazwa
-- masa w masach słońca (typ double)
-- promień Schwarzschilda (czyli promień horyzontu zdarzeń)
   Jest on wyliczany podczas tworzenia obiektu ze wzoru Rh=2*G*M/c^2, gdzie:
   G - stała grawitacji Newtona (6.67*10^-11 m^3/ks/s^2)
   M - masa czarnej dziury w kg (przyjąć masę słońca równą 2*10^30 kg)
   c - prędkość światła (3*10^8 m/s)
-- odległość czarnej dziury od Ziemi
Należy napisać odpowiednie gettery oraz konstruktory -- patrz fcja main.
Należy zdefiniować operator<< drukujący dane czarnej dziury (patrz wyjście fcji main) oraz operator< porządkujący czarne dziury według masy.

2. BHCatalogue (bhcat.h)

Klasa implementuje katalog czarnych dziur wraz z kilkoma metodami.
Należy przyjąć następujące założenia:
-- Katalog może przechowywać co najwyżej 5 pozycji.
-- Katalog musi przechowywać czarne dziury przy użyciu std::map, gdzie kluczem jest liczebnik rzymski "I.","II.","III.","IV.","V." (typ std::string), zaś wartością klasa BlackHole. 
-- Należy zdefiniować fcję 'add', która pobiera pojednyńczą czarną dziurę lub listę inicjalizacyjną, i dodaje do katalogu. Każda nowa pozycja uzyskuje nowy kolejny rzymski numer-klucz. Najłatwiej to zrealizować używając drugiej mapy std::map<int,std::string>, mapującej int na rzymskie literały.
-- Próba dodania więcej czarnych dziur niż 5 kończy się komunikatem ostrzegającym (patrz main).
-- Należy zdefiniwać fcję 'get(std::string)' zwracającą obiekt czarnej dziury odpowiadający argumentowi, będącemu rzymskim liczebnikiem.
-- Należy zdefiniować fcję 'get_ordered_by_mass', która zwraca wektor czarnych dziur uporządkowany od najlżejszej.
-- Neleży zdefiniować fcję 'get_map' zwracającą cały obiekt std::map;
-- [Praca domowa obowiązkowa] Należy zdefiniować fcję 'get_custom', która zwraca wektor czarnych dziur spełniających przesłany warunek. Poprawne wykonanie tego punktu podczas zajęć dodaje +2 punkty do oceny, lecz nie więcej niż łącznie 11 punktów. Należy odkomentować stosowne linijki w fcji main i sprawdzić działanie, a potem spowrotem zakomentować. Proszę poinformować mnie o wykonaniu tej części.

UWAGA:
Przy ocenianiu będzie brane pod uwagę (oprócz oczywiście poprawnego działania) rozsądne użycie const, typedef oraz przejrzystość i kompaktowość kodu gwarantowaną użyciem biblioteki STL. 

*///==========================================================================


#include <ostream>
#include <vector>

#include "blackhole.h"
#include "bhcat.h"

using namespace std;


// =======================================================================
int main() {

	std::cout << "\n";
       
       	// Tworzymy obiekt czarnej dziury o podanych kolejno:
	// nazwie, masie w masach słońca, odległości od Ziemi w parsekach (pc).
	// Jest to czarna dziura w centrum naszej galaktyki.	
	BlackHole bh1("Sagittarius A*",4.1e6,8178);
	cout << bh1; // wydruk

	// ---------------------------------------------------------------

	// Tworzymy nowy pusty katalog czarnych dziur.
	BHCatalogue catalogue;

	// Dodajemy naszą czarną dziurę
	catalogue.add(bh1);

	// Dodajemy inne istniejące czarne dziury
	catalogue.add( {
			 BlackHole("M87*",6.5e9,16.4e8),
			 BlackHole("Cygnus X-1",15,1900),
			 BlackHole("V404 Cygni",9,2390),
			 BlackHole("GRO J1655-40",5.31,3700),
			 BlackHole("Gargantua",1e8,3e8) // ta jest z filmu Interstellar
			 } ); 

	// Wydobywamy z katalogu czarne dziury o podanych rzymskich numerach i drukujemy:
	cout << catalogue.get("II.");
	cout << catalogue.get("III.");
	cout << catalogue.get("IV.");
	
	// Tutaj sprawdzam czy została użyta std::map
	map< string, BlackHole > map = catalogue.get_map();
	cout << map.at("V.");

	// ---------------------------------------------------------------

	std::cout << "\n";

	// Zwracamy wektor czarnych dziur uporządkowany według mas:
	vector<BlackHole> tmp = catalogue.get_ordered_by_mass();
	for (auto l : tmp) cout << l; // wydruk
	
	std::cout << "\n";
	
	
	// ---------------------------------------------------------------
	// ** Praca domowa obowiązkowa (lub bonus punktowy)
	/*
	// Wyświetlamy czarne dziury o masie powyżej 100 mas słońca
	const double M=100;
	tmp = catalogue.get_custom( 
			[M]( const BlackHole& bh_ ) {
		       		return (bh_.get_mass() > M); }
			);			
	for (auto l : tmp) cout << l;

	std::cout << "\n";

	// Wyświetlamy czarne dziury o promieniu horyzontu zdarzeń poniżej 50km podanych w pc
	const double R=1.62e-12_pc; // 50km in parsecs (1 pc = 3.1e13 km)
	tmp = catalogue.get_custom(
			[R]( const BlackHole& bh_ ) {
				return (bh_.get_Rh() < R); }
			);
	for (auto l : tmp) cout << l;
	*/

	std::cout << "\n";


return 0;}
/// =======================================================================

/* *** Spodziewane wyjście ***

Sagittarius A* : M=4.1e+06 solar mass, Rh=1.21542e+07 km, dist=8178 pc
>> Catalogue full. "Gargantua" not added. 
M87* : M=6.5e+09 solar mass, Rh=1.92689e+10 km, dist=1.64e+09 pc
Cygnus X-1 : M=15 solar mass, Rh=44.4667 km, dist=1900 pc
V404 Cygni : M=9 solar mass, Rh=26.68 km, dist=2390 pc
GRO J1655-40 : M=5.31 solar mass, Rh=15.7412 km, dist=3700 pc

GRO J1655-40 : M=5.31 solar mass, Rh=15.7412 km, dist=3700 pc
V404 Cygni : M=9 solar mass, Rh=26.68 km, dist=2390 pc
Cygnus X-1 : M=15 solar mass, Rh=44.4667 km, dist=1900 pc
Sagittarius A* : M=4.1e+06 solar mass, Rh=1.21542e+07 km, dist=8178 pc
M87* : M=6.5e+09 solar mass, Rh=1.92689e+10 km, dist=1.64e+09 pc

*/
/* *** Wyjście z bonusem *** 

Sagittarius A* : M=4.1e+06 solar mass, Rh=1.21542e+07 km, dist=8178 pc
>> Catalogue full. "Gargantua" not added. 
M87* : M=6.5e+09 solar mass, Rh=1.92689e+10 km, dist=1.64e+09 pc
Cygnus X-1 : M=15 solar mass, Rh=44.4667 km, dist=1900 pc
V404 Cygni : M=9 solar mass, Rh=26.68 km, dist=2390 pc
GRO J1655-40 : M=5.31 solar mass, Rh=15.7412 km, dist=3700 pc

GRO J1655-40 : M=5.31 solar mass, Rh=15.7412 km, dist=3700 pc
V404 Cygni : M=9 solar mass, Rh=26.68 km, dist=2390 pc
Cygnus X-1 : M=15 solar mass, Rh=44.4667 km, dist=1900 pc
Sagittarius A* : M=4.1e+06 solar mass, Rh=1.21542e+07 km, dist=8178 pc
M87* : M=6.5e+09 solar mass, Rh=1.92689e+10 km, dist=1.64e+09 pc

Sagittarius A* : M=4.1e+06 solar mass, Rh=1.21542e+07 km, dist=8178 pc
M87* : M=6.5e+09 solar mass, Rh=1.92689e+10 km, dist=1.64e+09 pc

Cygnus X-1 : M=15 solar mass, Rh=44.4667 km, dist=1900 pc
V404 Cygni : M=9 solar mass, Rh=26.68 km, dist=2390 pc
GRO J1655-40 : M=5.31 solar mass, Rh=15.7412 km, dist=3700 pc

*/