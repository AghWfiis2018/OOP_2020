/*
Zadanie polega na napisaniu dwóch klas: VirCode i Virus. W obu klasach do napisania są głównie konstruktory, destruktor i operatory przypisania. Część klasy VirCode jest już przygotowana.

VirCode zapisuje materiał genetyczny wirusa. Implementacja ma oprzeć się na ciągu znaków, nie można używać żadnych kontenerów z biblioteki standardowej, nawet std::string! Klasa ma na celu sprawdzenie umiejętności zarządzania pamięcią.

Mutacja polega na zmianie kolejności genów: ostatni gen wchodzi na początek.

Klasa Virus to emulacja wirusa, który może się duplikować i przenosić. Przechowuje swój
kod genetyczny i wiek.

    Każda replikacja wirusa (konstruktor kopiujący i przenoszący) powoduje powstanie nowego obiektu wirusa ze zmutowanym kodem. Bazowy wirus ma niezmutowany kod.
    Każde odwzorowanie wirusa (konstruktor i operator kopiujący) powoduje postarzenie się bazowego wirusa. Jeżeli bazowy wirus miał wiek X, to po odwzorowaniu drugi wirus ma wiek X, a bazowy wirus ma wiek X+1.
    Wywołanie konstruktora i operatora przenoszącego nie przenosi kodu genetycznego bazowego wirusa, ale go kopiuje (nie próbujcie tego w domu).

UWAGA:

    Nie można używać żadnych kontenerów z biblioteki standardowej, nawet std::string!
    Do kopiowania cstringa można użyć funkcji strlen i strcpy. Proszę pamiętać, że należy zaalokować tablicę o 1 większą niż zwraca strlen (znak \0).
    Proszę zwrócić uwagę na możliwość optymalizacji przy tworzeniu wirusów.
    Dla uproszczenia nie trzeba przenosić definicji do plików źródłowych.

Podstawowe zasady:

    Po zakończeniu (można też w trakcie) zadania, klikamy opcję "Oceń". Nie ma żadnych kar za wielokrotne ocenianie, można testować swój program do woli. Dla krótkiego sprawdzenia kompilacji i działania używamy opcji "Kompiluj".
    Po uzgodnieniach z innymi prowadzącymi, pracujemy tylko w edytorze VPL. Nie ma możliwości wrzucenia pliku ze swojego komputera.
    Plik main.cpp zostanie sprawdzony przed ewaluacją. Modyfikacje mogą skutkować oceną zero.
    Do zadania został dołączony generyczny makefile. Pozwala on na wykonanie tego zadania bez modyfikacji.
    Plik makefile zostanie podmieniony na domyślny przed kompilacją.
    Używanie cmake nie jest obsługiwane.

*/



#include "VirCode.h"
#include "Virus.h"
#include <iostream>

void print_code(const VirCode & code)
{
    std::cout << "Genetic code: <" << (code.c_str() ? code.c_str() : "------") << ">" << std::endl;
}

int main() 
{
    std::cout << "=====-===== 2 =====-=====" << std::endl;              // Tworzenie kodu genetycznego i test mutacji
    VirCode code = "AGACTG";
    print_code(code);
    code.mutate();
    print_code(code);
   
    std::cout << "=====-===== 1 =====-=====" << std::endl;              // Kopiowanie kodu genetycznego
    VirCode copy_code(code);
    code.mutate();
    print_code(code);
    print_code(copy_code);
    
    std::cout << "=====-===== 1 =====-=====" << std::endl;              // Przenoszenie kodu genetycznego
    VirCode copy_move(std::move(copy_code));
    print_code(copy_code);
    print_code(copy_move);
       
    // #################################################################
       
    std::cout << std::endl;                                             // Dwa sopsoby tworzenia wirusów
    std::cout << "=====-===== 1 =====-=====" << std::endl;
    Virus vir_1(code);
    std::cout << vir_1 << std::endl;
    
    std::cout << "=====-===== 1 =====-=====" << std::endl;
    Virus vir_2(VirCode("CCCTTT"));
    std::cout << vir_2 << std::endl;


    std::cout << std::endl;                                             // Replikacja wirusów (ze starzeniem i bez)
    std::cout << "=====-===== 2 =====-=====" << std::endl;
    Virus vir_3(vir_1);
    std::cout << "Copy: " << vir_1 << " -> " << vir_3 << std::endl;

    std::cout << "=====-===== 2 =====-=====" << std::endl;
    Virus vir_4(std::move(vir_2));
    std::cout << "Move: " << vir_2 << " -> " << vir_4 << std::endl;


    std::cout << std::endl;                                             // Odwzorowywanie wirusów (ze starzeniem i bez)
    std::cout << "=====-===== 2 =====-=====" << std::endl;
    Virus vir_5(vir_1);
    vir_4 = vir_5;
    std::cout << "Copy: " << vir_5 << " => " << vir_4 << std::endl;
    
    std::cout << "=====-===== 2 =====-=====" << std::endl;
    vir_4 = Virus(VirCode("AAAAAT"));
    std::cout << "Move: " << "virus{ 0, <AAAAAT> }" << " => " << vir_4 << std::endl;

    std::cout << "=====-===== 1 =====-=====" << std::endl;              // Odwzorowywanie samego w siebie
    vir_3 = vir_3;
    vir_4 = std::move(vir_4);
    std::cout << "Test: " << vir_3 << " -- " << vir_4 << std::endl;


    std::cout << std::endl;                                             // Mycie szkła labolatoryjnego
    std::cout << "=====-===== 1 =====-=====" << std::endl;
    std::cout << "Destructors:" << std::endl;
}

/*********************************** OUTPUT ************************************
--------------------------------------------------------------------------------
=====-===== 2 =====-=====
Genetic code: <AGACTG>
Genetic code: <GAGACT>
=====-===== 1 =====-=====
Genetic code: <TGAGAC>
Genetic code: <GAGACT>
=====-===== 1 =====-=====
Genetic code: <------>
Genetic code: <GAGACT>

=====-===== 1 =====-=====
Created new virus{ 0, <TGAGAC> } (code copied) 
virus{ 0, <TGAGAC> }
=====-===== 1 =====-=====
Created new virus{ 0, <CCCTTT> } (code moved) 
virus{ 0, <CCCTTT> }

=====-===== 2 =====-=====
Copy: virus{ 1, <TGAGAC> } -> virus{ 0, <CTGAGA> }
=====-===== 2 =====-=====
Move: virus{ 0, <CCCTTT> } -> virus{ 0, <TCCCTT> }

=====-===== 2 =====-=====
Copy: virus{ 2, <CTGAGA> } => virus{ 1, <CTGAGA> }
=====-===== 2 =====-=====
Created new virus{ 0, <AAAAAT> } (code moved) 
Killed virus{ 0, <AAAAAT> }
Move: virus{ 0, <AAAAAT> } => virus{ 0, <AAAAAT> }
=====-===== 1 =====-=====
Test: virus{ 0, <CTGAGA> } -- virus{ 0, <AAAAAT> }

=====-===== 1 =====-=====
Destructors:
Killed virus{ 2, <CTGAGA> }
Killed virus{ 0, <AAAAAT> }
Killed virus{ 0, <CTGAGA> }
Killed virus{ 0, <CCCTTT> }
Killed virus{ 2, <TGAGAC> }
--------------------------------------------------------------------------------
*******************************************************************************/
