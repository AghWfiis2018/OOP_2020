// *** Nie wolno modyfikować tego pliku ***

/*==========================================================================
*** Exploracja Marsa ***

Tym razem Agencja Kosmiczna zleciła Ci napisanie oprogramowania do 
sterowania łazikiem, który będzie odkrywał tajemnice czerwonej planety.

Należy napisać następujące klasy:

1. klasa Coordinates (plik utils.h)

Jest to prosta klasa implementująca współrzędne geograficzne na Marsie
 (długość i szerokość). Dla uproszczenia zakładamy, że będziemy poruszać
 się łazikiem w zakresie małych długości i szerokości, dlatego NIE TRZEBA
 ograniczać i kontrolować zakresu zmiennych.

Klasa powinna posiadać jako minimum:
-- odpowiednie konstruktory, w tym jeden pobierający std::vector
-- operatory +=, -= oraz - dla dodawania/odejmowania współrzędnych
-- operator wypisywania współrzędnych << (patrz wyjście)

2. klasa Rover (plik rover.h)

Jest to klasa implementująca łazik o zadanej nazwie, znajdujący się pod
 pewnymi współrzędnymi. Łazik może się poruszać oraz wykonywać akcje
 przesłane obiektami funkcyjnymi.

Oprócz odpowiendiego konstruktora, klasa powinna posiadać:
-- składnik przechowujący nazwę oraz aktualne współrzędne łazika 
   (typ Coordinates)
-- flagę informującą czy łazik podłączony jest do interfejsu sterowania
-- funkcje get_name i get_coordinate
-- funckję execute, która przyjmuje i wykonuje dowolny obiekt wykonywalny,
   bezargumentowy, zwracający void
-- funkcję drive, która przyjmuje zbiór obiektów wykonywalnych, bezargumentowych,
   zwracających std::vector<double>, które zmieniają współrzędne o ten wektor.
   Zakładamy, że wynik funkcji jest w stopniach (ale patrz praca domowa w fcji main).
-- funkcje execute i drive nie mogą być wykonane, jeśli łazik nie jest 
   podłączony do interfejsu. Należy wtedy wyświetlić napis:
   "ERROR: Rover not linked to an interface."


3. funkcje sterujące łazikiem (plik utils.h)

Należy napisać dwie funckje sterujące łazikiem:
-- route1
-- go_to
zwracające odpowiedni typ, tak aby łazik poruszał się tak jak pokazuje wyjście. 
Funkcje te muszą być zamnkięte w odpowiedniej przestrzeni nazw.


4. DANA jest klasa RoverIface (plik rover_iface.h), która jest klasą typu proxy.
 Przeanalizowanie tej klasy będzie pomocne w konstrukcji klasy Rover.

UWAGI:
-- ze względu na długie typy pojawiające sie w programie, należy używać typedef
   w celu zwiększenia przejrzystości i skrócenia kodu
-- nie należy implementować niepotrzebnych fcji
-- proszę zadbać o kompaktowy, czytelny kod i użycie ułatwień c++11

*///==========================================================================


#include <iostream>

#include "utils.h"
#include "rover.h"
#include "rover_iface.h"

using namespace std;

/// przezwisko typu dla skrócenia zapisu
typedef vector<double> vec;

/// przykładowa akcja wykonywana przez łazik...
void say_hello() {
	cout << "Hello!\n"; }

/// wydruk nazwy oraz pozycji łazika
void report_position(RoverIface* rover) {
	const std::string pos_msg(">> current position: ");
	cout << rover->get_name() << pos_msg << rover->get_coordinates() << endl; }


// =======================================================================
int main() {

	std::cout << "\n";

	// współrzędne bazy na Marsie
	const Coordinates base(30.0112,121.3456);

	// współrzędne interesującej jaskini
	const Coordinates cave(31.5343,119.0522);

	// tworzymy nowy łazik o nazwie "Opportunity"
	Rover* opportunity = new Rover("Opportunity");

	// próba przesłania instrukcji do łazika...
	opportunity->execute( say_hello ); // błąd, trzeba użyć interfejsu

	// tworzymy nowy interfejs do łazika i sprzęgamy z łazikiem
	RoverIface rover(opportunity, "MikeIface");

	// kalibrujemy współrzędne łazika, aby jego współrzędne odpowiadały bazie
	rover.calibrate(base);
	
	// wydruk pozycji
	report_position(&rover);

	// przesyłamy zbiór instrukcji sterujących jazdą łazika
	rover.drive( {
			// przesuń o podaną liczbę stopni
			[](){ return vec{-0.6443,0.8131}; }, // odcinek 1
			[](){ return vec{1.2311,-0.3432}; },  // odcinek 2
			// powrót do jaskini
			// (uwaga na typy argumentów operatora odejmowania poniżej)
			[cave,&rover](){ return (cave - rover.get_coordinates()); } 	
			} );

	// znajdujemy się przy jaskini; wydruk pozycji
	report_position(&rover);
	
	// wykonujemy jakąś operację
	rover.execute( []() { cout << "Collecting samples...\n"; } ); 

	// przemieszczamy łazik; używamy przygotowanych tras
	rover.drive( MarsRoutes::route1() );
	
	// wykonujmey akcję
	rover.execute( []() { cout << "Drilling surface...\n"; } ); 

	// wracamy do bazy używając przygotowanej fcji sterującej
	rover.drive( MarsRoutes::go_to(rover.get_coordinates(),base) );

	// raportujemy pozycję łazika
	report_position(&rover);

	std::cout << "\n";


	/* --- Praca domowa ---

	Proszę zastąpić linijki 115-116 następującym kodem:

		[](){ return vec{-38.1714_km,48.1720_km}; },
		[](){ return vec{72.9363_km,-20.3328_km}; },
			
	Należy napisać odpowiedni operator konwertujący powyższe stałe dosłowne 
        oznaczające odległości w kilometrach, do stopni w radianach. Zakładamy
        pi=3.14 oraz promień Marsa = 3396.2 km.
	Wyjście musi pozostać identyczne do oryginału.
        
        */

return 0;}
/// =======================================================================

/* *** Spodziewane wyjście ***

ERROR: Rover not linked to an interface.
Linking interface:MikeIface to rover:Opportunity...
Opportunity is now online.
MikeIface@Opportunity>> current position: (30.0112,121.346)
Arriving at (29.3669,122.159)
Arriving at (30.598,121.816)
Arriving at (31.5343,119.052)
MikeIface@Opportunity>> current position: (31.5343,119.052)
Collecting samples...
Arriving at (32.5343,118.052)
Arriving at (33.5343,118.052)
Arriving at (34.5343,117.052)
Drilling surface...
Arriving at (30.0112,121.346)
MikeIface@Opportunity>> current position: (30.0112,121.346)

*/
