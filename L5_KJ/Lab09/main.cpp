/*
Zadanie polega na napisaniu systemu opartym na dziedziczeniu wielokrotnym, w którym będzie można wypisywać na konsole różne elementy graficzne, charakteryzujące się różnymi właściwościami jak kolor czy styl. Do napisania są trzy główne klasy:

    MyText - przechowująca tekst i opcje formatowania i kolorowania;
    MyLine - przechowująca styl, długość i kolor linii;
    MyPrinter - wypisze ładnie sformatowany obiekt, wycentrowany. Klasa jest prawie gotowa, należy dopisać jedynie wnętrze funkcji print. Pozostałej części pliku nie można zmieniać.

Należy dopisać kilka klas bazowych, dzięki którym będzie można użyć mechanizmu polimorfizmu do obsługi danych:

    Wszystkie klasy które da się wypisać w MyPrinter dziedziczą po wspólnej klasie abstrakcyjnej.
    Jeżeli dana klasa ma jakąś cechę (np kolor), to dodatkowo dziedziczy po kolejnej klasie która odpowiada za dany atrybut (kolor).

Ćwiczenia do zrobienia w domu:

    mozliwosc ustawienia dwoch opcji formatowania, np. AttFormat::BOLD | AttFormat::UNDERLINED;
    zaimplementowac numerowanie linii;
    dodanie nowej klasy np: MyBox i sprawdzenie, czy nie modyfikujemy żadnego innego pliku.

UWAGA:

    Nie można dodawać wszystkich atrybutów do wszystkich klas! Przykładowo, linia nie ma formatu tekstu.
    Należy rozdzielić implementacje: ani obiekty nie wiedzą kto i jak je będzie wyświetlał, ani MyPrinter nie zna wszystkich obiektów z jakimi mu przyjdzie pracować. Dodanie nowego obietku, np MyBox nie może wymagać modyfikacji żadnego z obecnych plików.
    To czy dodać odpowiednie opcje formatowania sprawdza funkcja MyPrinter::print(const MyPrintable & obj). Do sprawdzenia można użyć mechanizmu dynamic_cast.
    Polecane uzywanie std::string. Ilosc znakow mozna sprawdzic metoda size();
    Aby wycentrować tekst, wystarczy wypisać odpowiednią liczbę spacji przed tekstem.

Podstawowe zasady:

    Po zakończeniu (można też w trakcie) zadania, klikamy opcję "Oceń". Nie ma żadnych kar za wielokrotne ocenianie, można testować swój program do woli. Dla krótkiego sprawdzenia kompilacji i działania używamy opcji "Kompiluj".
    Kompilacja programu ze zdefiniowaną zmienną MY_EXPECTED_ERROR powinna wygenerować błąd kompilacji. W przeciwnym razie za wykonanie odejmowany jest jeden punkt. Zmiennej MY_EXPECTED_ERROR nie można używać poza plikiem main.cpp.
    Po uzgodnieniach z innymi prowadzącymi, pracujemy tylko w edytorze VPL. Nie ma możliwości wrzucenia pliku ze swojego komputera.
    Plik main.cpp zostanie sprawdzony przed ewaluacją. Modyfikacje mogą skutkować oceną zero.
    Do zadania został dołączony generyczny makefile. Pozwala on na wykonanie tego zadania bez modyfikacji.
    Plik makefile zostanie podmieniony na domyślny przed kompilacją.
    Używanie cmake nie jest obsługiwane.

*/
#include "MyText.h"
#include "MyLine.h"
#include "MyPrinter.h"
#include <iostream>

int main()
{
	const AttFormat * ptrFor;
	const AttColor * ptrCol;
	
	////////////////////////////////////////////////////////////////////
	MyLine line('*', 60, AttColor::MAGENTA);	
	
	ptrCol = &line;
	#ifdef MY_EXPECTED_ERROR
	{
		ptrFor = &line; // -> blad kompilacji!!!
	}
	#endif
	
	std::cout << MyPrinter::controlSeq( ptrCol->getColor() );
	std::cout << line.rawString();
	std::cout << MyPrinter::resetSeq() << std::endl;

	////////////////////////////////////////////////////////////////////
	MyText text("JULIUSZ SLOWACKI", AttFormat::BOLD, AttColor::GREEN);
	
	ptrCol = &text;
	ptrFor = &text;
	
	std::cout << MyPrinter::controlSeq( ptrFor->getFormat() ) 
	          << MyPrinter::controlSeq( ptrCol->getColor() );
	std::cout << std::string(22, ' ') << text.rawString();
	std::cout << MyPrinter::resetSeq() << std::endl;

	////////////////////////////////////////////////////////////////////
	std::cout << MyPrinter::controlSeq( line.getColor() );
	std::cout << line.rawString();
	std::cout << MyPrinter::resetSeq() << std::endl;
	          
	////////////////////////////////////////////////////////////////////
	MyPrinter printer(60);

	line.setLength(50);
	line.setChar('-');
	line.setColor( AttColor::GRAY );
	printer.print( line );
	
	text.setFormat( AttFormat::NORMAL );
	text.setColor( AttColor::WHITE );
	text.setText("Lecz zaklinam: niech zywi nie traca nadziei");
	printer.print( text );
	text.setText("I przed narodem niosa oswiaty kaganiec;");
	printer.print( text );
	
	printer.print( line );
	
	text.setColor( AttColor::RED );
	text.setText("A kiedy trzeba, na smierć ida po kolei,");
	printer.print( text );
	text.setText("Jak kamienie, przez Boga rzucane na szaniec!");
	printer.print( text );
				
	printer.print( line );
		
	return 0;
}

/*********************************** OUTPUT ************************************
-------------------------- (oczywiscie pokolorowany) ---------------------------

************************************************************
                      JULIUSZ SLOWACKI
************************************************************
     --------------------------------------------------
        Lecz zaklinam: niech zywi nie traca nadziei
          I przed narodem niosa oswiaty kaganiec;
     --------------------------------------------------
          A kiedy trzeba, na smierć ida po kolei,
        Jak kamienie, przez Boga rzucane na szaniec!
     --------------------------------------------------

--------------------------------------------------------------------------------
*******************************************************************************/
