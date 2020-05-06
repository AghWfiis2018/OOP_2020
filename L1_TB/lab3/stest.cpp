/*
 * Celem zadania jest napisanie klasy sprytnego wskaznika.
 * Jest to klasa opakowujaca zwykly wskaznik w nastepujacey sposob.
 * Podczas konstrukcji przekazywany do tej klasy jest wskaznik. 
 * W obiekcie oprocz wskaznika przechowywany pownien byc licznik referencji.
 * Kazdy nastepny sprytny wskaznik pokazujacy na dany obiekt (to znaczy
 * sprytny wskaznik skonsruowany z innego sprytnego wskaznika) powinien 
 * zwiekszac ten licznik. Jesli sprytny wskaznik jest kasowany 
 * n.p. wychodzi poza zakres lub jesli zaczyna pokazywac na inny obiekt 
 * zmniejsza licznik referencji. Jesli licznik ten dojdzie do zera nalezy
 * skasowac tez obiekt wskazywany przez wskaznik.
 *
 *
 * Klasa TestClassA jest trywialna (moze to byc nawet strutura)
 * ma jedynie 
 * - nietrywalne konstruktory  i destruktory wypisujace informacje o swoim wywolaniu (copy/paste z wyniku) 
 * - metode nazwa() zwracajaca nazwe obiektu;
 * Jak ktos umie moze w implementacji uzyc klasy std::string.
 * (a jak nie to char* prosze pamietac o alokacji).
 * 
 * Sompilowac do pliku stest z flagami -Wall -g
 */
 
#include <iostream>


#include "SmartPointer.h"
#include "TestClassA.h"


void print(const TestClassA& t) {
    cout <<"..... TestClassA nazwa " << t.name() << endl;
}

int main() {
  using namespace std;
  {
    TestClassA a("test_A_0");
    print(a);
  }
  cout << endl;
  SmartPointer smart1(new TestClassA("test_A_1"));
  SmartPointer smart2(new TestClassA("test_A_2"));
  smart2 = smart1; // kasujemy  A-2 bo zaden wskaznik na niego nie wskazuje
  {
    SmartPointer smart3 = smart2; // juz trzy wskazniki pokazuja na obiekt A-1
    print(*smart3);
    std::cout << "-- " << smart3->name() << std::endl;
  }
  std::cout << "== " << smart2->name() << std::endl;
}
/* wynik
.. Konstruuje TestClassA test_A_0
..... TestClassA nazwa test_A_0
.. Usuwam  TestClassA test_A_0

.. Konstruuje TestClassA test_A_1
.. Konstruuje TestClassA test_A_2
.. Usuwam  TestClassA test_A_2
..... TestClassA nazwa test_A_1
-- test_A_1
== test_A_1
.. Usuwam  TestClassA test_A_1

 */
