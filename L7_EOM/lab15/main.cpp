/* Należy zdefiniować szablon klasy Array ze specjalizacją dla wskaźników.
   Specjalizacja wpływa na kilka aspektów działania tego szablonu. W szczególności na to, co robi destruktor szablonu Array (czy kasuje obiekty, czy nie). Zmieniaja sie także operator[] i operator <<.
   Klasa X jest trywialnie prosta: przechowuje napis, dostarcza metody dostępowej i podczas destrukcji wypisuje ten napis.
   Klasa Y dziedziczy po X.
   Nie korzystamy z std::vector ani std::array, a tablica w klasie Array ma podaną przy deklaracji wartość.
 */

#include <iostream>
#include <stdexcept>

#include "main.h"

// Do odkomentowania i sprawdzenia wywoływanych konstruktorów i destruktorów
// Zauważ, ile razy są wywoływane konstruktory
//#define XARRAY

int main() {
  {
    Array<7, int> iArray;
    iArray[0] = 10;
    iArray[1] = 8;
    iArray[3] = 6;
    try {
      iArray[7] = 0; // operacja poza zakresem
    } catch (const std::invalid_argument& e) {
      std::cout << e.what() << std::endl; 
    }
    std::cout << " iArray: " <<iArray << std::endl;  // wypisuje całą tablicę
    
    Array<5, int*> iPtrArray;
    iPtrArray[0] = new int(5);
    iPtrArray[3] = new int(10);

    std::cout << " iPtrArray: " << iPtrArray << std::endl;  // wypisuje tylko wartości utworzonych obiektów
  }
  #ifdef XARRAY
  {
    Array<4, X> xArray;     // tablica obiektów typu X
    X X1("A0");
    xArray[0] = X1;
    xArray[2] = X("A2");
    
    std::cout << " xArray: " <<xArray << std::endl; // wypisuje tylko nazwy utworzonych obiektów
  }
  #endif
  {
    Array<5, X*> xPtrArray;    // tablica wskaźników na obiekty typu X
    xPtrArray[0] = new X("obiekt 0 ");
    xPtrArray[1] = new X("obiekt 1 ");
    xPtrArray[2] = new X("obiekt 2 ");
    xPtrArray[3] = new Y("obiekt Y-0 ");
    std::cout << " xPtrArray: " <<xPtrArray << std::endl;
  }  
}
/* wynik
---Tworze wersje T
Indeks poza zakresem
 iArray: 10 8 0 6 0 0 0
---Tworze wersje T*
 iPtrArray: 5 10
---Usuwam wersje T*
---Tworze wersje T*
Tworze X obiekt 0
Tworze X obiekt 1
Tworze X obiekt 2
Tworze X obiekt Y-0
Tworze Y obiekt Y-0
 xPtrArray: obiekt 0  obiekt 1  obiekt 2  obiekt Y-0
Usuwam X obiekt 0
Usuwam X obiekt 1
Usuwam X obiekt 2
Usuwam Y obiekt Y-0
Usuwam X obiekt Y-0
---Usuwam wersje T*
 */
