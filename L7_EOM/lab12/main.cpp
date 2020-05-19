
/* Prosze zdefiniować klasę Number, która będzie przechowywać nazwę oraz wartość.
   Klasa może przechowywać jedynie wartości z wcześniej ustawionego zakresu.
   Klasa ma glośny konstruktor i destruktor, które wypisują odpowiednie komunikaty.
   Ponadto mamy też klasę NumArray o rozmiarze ustalanym w konstruktorze, 
   która przechowuje w tablicy dynamicznej wskaźniki do obiektów Number.

   Celem zadania jest obsłużenie wyjątków:
   * w przypadku, gdy wyjdziemy poza zdefiniowany w main zakres (rzucany jest obiekt klasy OutOfRange) - drugi blok try
   * w przypadku, gdy w tablicy NumArray nie będzie wolnych miejsc  (klasa OutOfSize -  obiekt jest rzucany, 
     jeśli w tablicy NumArray nie będzie wolnych miejsc albo alternatywnie po zakomentowaniu wskazanej linii 
     w miejscu jego rzucenia - trzeci blok try.
   Komunikaty "kontrola zakresu" i "kontrola rozmiaru" są wypisywane przez konstruktory tych klas.

   Proszę zwrócić uwagę na zarządzanie pamięcią tak, aby nie było wycieków,
   ani podwójnego usuwania obiektów. W tym celu, dla drugiego bloku warto rozważyć 
   zdefiniowanie statycznego wektora albo tablicy std oraz pól statycznych w klasie.

   Komentarze w kodzie w cudzysłowiu mówią, jakie wyjście powinna generowac dana linia.
 */

#include "main.h"
#include <iostream>

int main ()
{
// pierwszy blok
  try {
    Number first ("jeden", 1.0);     // "Tworzymy liczbe jeden 1"
    first.print();				     // "jeden = 1"
    first.Skip();		    // poniższy tekst się nie wyświetla dzięki tej funkcji
    std::cout <<"Ten tekst sie nie wyswietla"<<std::endl;
    throw "Nic waznego";
      }
  catch (...) { }
  
  // drugi blok
  std::cout << "\n***** Testowanie zakresu ******\n";
  Number::setRange(1, 8);  //ustawienie zakresu od 1 do 6
  try {
    Number* lowest = Number::set("najmniejsza", 2.2); // "Tworzymy liczbe 2.2"
    lowest->print();				                  // "najmniejsza = 2.2"
    Number* middle = Number::set("srodkowa", 5.4);    // "Tworzymy liczbe 5.4"
    middle->print();				                  // "middle = 5.4"
    // Number::setRange(1, 10); // po odkomentowaniu wyjątek nie jest rzucany, ale czyszczenie ma się odbyć
    Number* highest = Number::set("najwieksza", 8.3); // "Tworzymy liczbe 8.3"
    highest->print();
    std::cout<<"***** KONIEC WPISYWANIA *****"<<std::endl;
  }
  catch (const OutOfRange exception) {
    //std::cout<<"UPS! Mamy problem z zakresem"<<std::endl; //Ten komunikat wypisuje funkcja obsługująca wyjątek
    std::cout<< exception <<std::endl; // "Numer najwieksza na wartosc 8.3 ktora jest poza dopuszczalnym zakresem: [1, 6]
    std::cout<<"------ Czyszczenie ------"<<std::endl;
  }

 // trzeci blok
  std::cout << "\n***** Testowanie rozmiaru ******\n";
  try {
    NumArray* ptr = new NumArray (3);
    ptr->set(0, new Number("dwa",2));     // "Tworzymy liczbe 2"
    ptr->set(1, new Number("trzy",3));    // "Tworzymy liczbe 3" 
    ptr->set(2, new Number("cztery",4));  // "Tworzymy liczbe 4"

    // WARIANT 1 do zakomentowania i sprawdzenia rezultatu działania (skorzystaj z podpowiedzi w liniach 69 i 71 - OutOfSize)  
    ptr->set(2, new Number("nowe cztery",4.5)); //linia do zakomentowania
    
    // WARIANT 2 po zakomentowaniu linii 65 - oba wiarianty mają działać
    std::cout << "Tworzymy liczbe 4.5\n";   // żeby output się zgadzał
    OutOfSize problem (ptr);                // "Kontrola rozmiaru"
    std::cout << "Usuwamy liczbe 4.5\n";    // żeby output się zgadzał
    throw problem;	                        // "Tablica pelna, konczymy wpisywanie"

    std::cout<<"***** KONIEC WPISYWANIA *****"<<std::endl;
  }
    catch (...) {std::cout<<"------ Czyszczenie ------"<<std::endl;}
  std::cout<<"To tyle na dzisiaj!"<<std::endl;

}
/* output (tym razem sprawdzony z tym kontrolnym)
Tworzymy liczbe 1
jeden = 1
Usuwamy liczbe 1

***** Testowanie zakresu ******
Tworzymy liczbe 2.2
najmniejsza = 2.2
Tworzymy liczbe 5.4
srodkowa = 5.4
Tworzymy liczbe 8.3
Kontrola zakresu                 // komunikat konstruktora
UPS! Mamy problem z zakresem     // komunikat wypisywany przez funkcję obsługującą wyjątek
Liczba najwieksza ma wartosc 8.3 spoza dopuszczalnego zakresu: [1, 8]
------ Czyszczenie ------
Usuwamy liczbe 2.2
Usuwamy liczbe 5.4
Usuwamy liczbe 8.3

***** Testowanie rozmiaru ******
Tworzymy liczbe 2
Tworzymy liczbe 3
Tworzymy liczbe 4
Tworzymy liczbe 4.5
Kontrola rozmiaru                  // komunikat konstruktora
Usuwamy liczbe 4.5
UPS! Tablica pelna, koniec zabawy  // komunikat wypisywany przez funkcję obsługującą wyjątek
------ Czyszczenie ------
Usuwamy liczbe 2
Usuwamy liczbe 3
Usuwamy liczbe 4
To tyle na dzisiaj!
*/
