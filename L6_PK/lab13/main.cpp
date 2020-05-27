// *** Nie wolno modyfikować tego pliku ***

/*==========================================================================

*** Dosłowne kontenery i szablony ***

Zadanie polega na napisaniu dwóch prostych klas oraz szablonów kilku prostych funkcji operujących na ich obiektach.
Deklaracje wszystkich klas i fcji powinny znaleźć się w pliku 'containers.h'.
UWAGA: należy programować efektywnie (i szybko) używając poznanych bibliotek STL.


1. klasa 'WaterContainer'

Klasa pojemnika na wodę o zadanej maksymalnej pojemności. Po utworzeniu pojemnik jest pusty. Wodę nalewamy metodą 'put(double V)'. Naturalnie, nie możemy wlać więcej wody niż pojemność pojemnika (obsługa wyjątków). Metoda put wypełnia naczynie od zera, tj. nie służy do dolewania (należy o niej myśleć jak o przypisaniu). Do dolewania wody służy operator +=. Klasa musi mieć też getter 'get' or metodę 'clean' czyszczącą pojemnik, która może się przydać później.


2. klasa 'Wallet'

Klasa implementująca portfel o zadanej pojemności (maksymalnej liczbie banknotów). Banknoty (przechowywane dowolnym kontenerem) są typu enum 'Bill', który składa się z elementów widocznych w fcji main(). Kontener ma metody o takich samych nazwach i funkcjonalnościach jak WaterContainer tzn. 'put', 'get', 'clean' oraz operator +=.
UWAGA: Wydruk wektora obiektów 'Bill' najszybiej zrealizować tworząc mapę o kluczach Bill i wartościach std::string. Użycie 'case' jest niezalecane i będzie niżej oceniane.


3. szablon funkcji 'move_to_container'

Specjalizacje szablonu powinny 'przelewać' wodę z jednego kontenera do drugiego, lub przekładać pieniądze. Czyli pierwszy kontener przejmuje zawartość drugiego (jak się da), drugi zaś staje się pusty.
Przyjmujemy zasadę 'wszystko albo nic', czyli zawartość drugiego kontenera jest przełożona, tylko jeśli się zmieści.


4. szablon funkcji 'replicate_container'

Specjalizacje szablonu zwracają wektor identycznych kopii podanego konetnera.


5. szablon funkcji 'compare_container_type'

Specjaliacje mają porównać typ kontenerów przesłanych w argumencie obiektów i wypisać komunikat. 
WSKAZÓWKA: Można użyć std::is_same_v<T1,T2> z biblioteki STL <type_traits>.


*///==========================================================================


#include <iostream>

#include "containers.h"



// nakładka na metodę put kontenerów
template <typename Container_T, typename T>
void put(Container_T& container, const T& obj) {
	try {
		container.put(obj); }
	catch (const std::string& info) {
		std::cout << ">> " << info << std::endl; }
}


 

// =======================================================================
int main() {

	std::cout << "\n";

	// tworzymy pojemniki na wodę o zadanej maksymalnej pojemności
	WaterContainer bucket(10);
	WaterContainer bottle(1.5);

	// wypełniamy pojemniki wodą o podanej objętości
	put(bottle,1.8);
	put(bottle,0.33);
	bucket.put(7.5);

	// wydruk
	std::cout << bottle.get() << std::endl;
	std::cout << bucket.get() << std::endl;

	// --------------------------------------------------------------
	std::cout << "\n";	

	// tworzymy kontener-portfel na banknoty o podanej maksymalnej pojemności
	Wallet myprecious(5);

	// tworzymy wektor banknotów
	std::vector<Bill> bills  
		{ Ten_PLN, Ten_PLN, Hundred_PLN, Fifty_PLN, Twenty_PLN, Hundred_PLN };

	// wkładamy banknoty do portfela
	put(myprecious, bills);
	bills.pop_back();
	put(myprecious, bills);

	// --------------------------------------------------------------
	std::cout << "\n";

	// inny portfel
	Wallet unclesam(100);
	unclesam.put( { Fifty_PLN, Twenty_PLN, Ten_PLN } );

	// wydruk
	std::cout << myprecious.get() << std::endl;
	std::cout << unclesam.get() << std::endl;

	// --------------------------------------------------------------
	std::cout << "\n";

	// próba przelania wody z wiadra do butelki
	move_to_container(bottle,bucket);
	// przelewamy wodę z butelki do wiadra
	move_to_container(bucket,bottle);

	// wydruk
	std::cout << bottle.get() << std::endl;
	std::cout << bucket.get() << std::endl;
	
	// próba przełożenia pieniędzy
	move_to_container(myprecious,unclesam);
	// przekładamy pieniądze
	move_to_container(unclesam,myprecious);

	// wydruk
	std::cout << myprecious.get() << std::endl;
	std::cout << unclesam.get() << std::endl;


	// --------------------------------------------------------------
	std::cout << "\n";

	// wydruk replik kontenerów

	for (auto& l : replicate_container<3>(bucket)) 
		std::cout << l.get() << std::endl;

	for (auto& l : replicate_container<4>(unclesam)) 
		std::cout << l.get() << std::endl;

	// --------------------------------------------------------------
	std::cout << "\n";

	// porównujemy typy kontenerów
	compare_container_type(bottle,bucket);
	compare_container_type(bottle,myprecious);

	std::cout << "\n";

return 0;}
/// =======================================================================

/* *** Spodziewane wyjście ***


>> Error: Container too small.
0.33
7.5

>> Error: Wallet too small.

Ten Ten Hundred Fifty Twenty 
Fifty Twenty Ten 

Error: Container too small.
0
7.83
Error: Wallet too small.
No bills.
Fifty Twenty Ten Ten Ten Hundred Fifty Twenty 

7.83
7.83
7.83
Fifty Twenty Ten Ten Ten Hundred Fifty Twenty 
Fifty Twenty Ten Ten Ten Hundred Fifty Twenty 
Fifty Twenty Ten Ten Ten Hundred Fifty Twenty 
Fifty Twenty Ten Ten Ten Hundred Fifty Twenty 

The containers are of same type.
The containers are of different type.


*/