/*
W zadaniu należy skonstruować logiczna hierarchie klas na podstawie poniższego programu. Proszę zauważyć, ze NumerId to osobna klasa (wraper na unsigned int) służąca do przechowywania numeru id w wirtualnym dziekanacie.

Zadanie ma na celu pokazać problemy związane z dziedziczeniem wielokrotnym, które mogą się pojawiać; oraz wyjaśnić, dlaczego należy uważać przy próbach projektowania kodu, gdzie może wystąpić struktura diamentu.

Proszę nie implementować pol w klasach bazowych jeżeli nie są one tam wymagane (na podstawie poniższego kodu).

UWAGA:

    Proszę nie używać przyjaźni jeżeli to nie jest potrzebne (w zadaniu nie jest).

Podstawowe zasady:

    Po zakończeniu (można też w trakcie) zadania, klikamy opcję "Oceń". Nie ma żadnych kar za wielokrotne ocenianie, można testować swój program do woli. Dla krótkiego sprawdzenia kompilacji i działania używamy opcji "Kompiluj".
    Kompilacja programu ze zdefiniowaną zmienną MY_EXPECTED_ERROR powinna wygenerować błąd kompilacji. W przeciwnym razie za wykonanie odejmowany jest jeden punkt. Zmiennej MY_EXPECTED_ERROR nie można używać poza plikiem main.cpp.
    Po uzgodnieniach z innymi prowadzącymi, pracujemy tylko w edytorze VPL. Nie ma możliwości wrzucenia pliku ze swojego komputera.
    Plik main.cpp zostanie sprawdzony przed ewaluacją. Modyfikacje mogą skutkować oceną zero.
    Do zadania został dołączony generyczny makefile. Pozwala on na wykonanie tego zadania bez modyfikacji.
    Plik makefile zostanie podmieniony na domyślny przed kompilacją.
    Używanie cmake nie jest obsługiwane.
*/


#include "Osoby.h"
#include "NumerID.h"
#include <iostream>

void sprawdzWskaznik(const void* p) {
	if ( p == 0 )
		std::cout << "null ptr" << std::endl;
	else
		std::cout << "ok ptr" << std::endl;
}

void przedstawOsobe(const Osoba* poj) {
	if ( poj )
		std::cout << "Osoba: " << (*poj) << std::endl;
	else
		std::cout << "Osoba nierozpoznana." << std::endl;
}

int main() {
    std::cout << "=====-===== 1 =====-=====" << std::endl;
	NumerID idNum(1456);
	std::cout << "Przykladowe Id = " << idNum << std::endl;  // prosze zwrocic uwage na zera z przodu
	
    std::cout << std::endl;
	
	std::cout << "=====-===== 1 =====-=====" << std::endl;
	Dydaktyk * dd = new Dydaktyk( "Zenon Podlaski", idNum );
	sprawdzWskaznik(dynamic_cast<Pracownik*>(dd));
	przedstawOsobe(dd);

    std::cout << "=====-===== 1 =====-=====" << std::endl;
	Student * ss = new Student( "Kinga Podwawelska", NumerID(222222) );
	sprawdzWskaznik(dynamic_cast<const Pracownik*>(ss));
	przedstawOsobe(ss);

    std::cout << "=====-===== 1 =====-=====" << std::endl;
	const Wozny ww = Wozny( "Tomasz Podchorazy" );
	sprawdzWskaznik(dynamic_cast<const Pracownik*>(&ww));
	przedstawOsobe(&ww);

	std::cout << std::endl;

    std::cout << "=====-===== 4 =====-=====" << std::endl;
	Osoba * dok =  new Doktorant( "Jozef Podbipieta", NumerID(772280), NumerID(773340) );
	const Student * s  = dynamic_cast<Student*>(dok);
	const Dydaktyk * d = dynamic_cast<Dydaktyk*>(dok);  
	const Wozny * w    = dynamic_cast<Wozny*>(dok);  
	sprawdzWskaznik(s);
	przedstawOsobe(s);
	sprawdzWskaznik(d);
	przedstawOsobe(d);
	sprawdzWskaznik(w);
	przedstawOsobe(w);
	
	std::cout << std::endl;

    std::cout << "=====-===== 1 =====-=====" << std::endl;
	std::cout << "NumId - uczen = "      << s->numID() << std::endl;
	std::cout << "NumId - nauczyciel = " << d->numID() << std::endl;

    std::cout << "=====-===== 1 =====-=====" << std::endl;
	Doktorant * dokdok = dynamic_cast<Doktorant*>(dok);
	std::cout << "NumId - uczen = "      << dokdok->numID_student() << std::endl;
	std::cout << "NumId - nauczyciel = " << dokdok->numID_dydaktyk() << std::endl;

	delete dd; delete ss; delete dok;
}

/*********************************** OUTPUT ************************************
--------------------------------------------------------------------------------
=====-===== 1 =====-=====
Przykladowe Id = <001456>

=====-===== 1 =====-=====
ok ptr
Osoba: Zenon Podlaski - dydaktyk
=====-===== 1 =====-=====
null ptr
Osoba: Kinga Podwawelska - student (id <222222>)
=====-===== 1 =====-=====
ok ptr
Osoba: Tomasz Podchorazy - wozny

=====-===== 4 =====-=====
ok ptr
Osoba: Jozef Podbipieta - doktorant
ok ptr
Osoba: Jozef Podbipieta - doktorant
null ptr
Osoba nierozpoznana.

=====-===== 1 =====-=====
NumId - uczen = <772280>
NumId - nauczyciel = <773340>
=====-===== 1 =====-=====
NumId - uczen = <772280>
NumId - nauczyciel = <773340>
--------------------------------------------------------------------------------
*******************************************************************************/
