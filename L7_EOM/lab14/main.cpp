/* Zdefiniować szablon klasy tablicy asocjacyjnej gdzie typ klucza i typ wartosci sa argumentami szablonu.
 Implementacja wnętrza wg własnego uznania, oceniana będzie optymalność i czytelność rozwiązania.
 Funkcje składowe należy odczytać z kodu.
 Proszę zdefiniować je na zewnątrz klasy, nie jako funkcje inline.
*/

#include <iostream>
#include <string>
#include <stdexcept>

#define CONTEXT "Plik: "<<__FILE__<<" Linia: "<<__LINE__<< ": " 

#include "main.h"

using namespace std;

int main() {
  cout << "***** Tablica z kluczem napisowym *****" << endl;
  Map<std::string, int> m;  // kolejność klucz, wartość
  m.insert("styczen", 2999 ); 
  m.insert("luty", 2500 ); 
  m.print("Element tablicy");
  m["marzec"] = 1850; // dodawanie wartości za pomocą klucza
  m["luty"] = 666;
  cout << "Czy tak mozna dodac element zerowy? " << m["kwiecien"] << endl;// proba wyciagniecia elementu z Map
  m["kwiecien"] = m["luty"] + m["marzec"];
  m.print("Po modyfikacji");
  
  cout << "\n***** Tablica const *****" << endl;
  const Map<std::string, int>& cm = m;  
  cout << CONTEXT << "Wartosc pod luty? " << cm["luty"] << endl;
  cout << CONTEXT << "Czy jest maj? " << print(cm.contains("maj")) << endl;
  cout << CONTEXT << "Czy jest marzec? " << print(cm.contains("marzec")) << endl;

  try {
    cm["czerwiec"]; // proba wyciagniecia nieistniejacego elementu z const Map skutkuje wyjatkiem
  } 
  catch (const std::invalid_argument& e) {
    cout << CONTEXT << e.what() << endl;
  }
  cout << "\n***** Tablice z innymi kluczami *****" << endl;
  Map<int, std::string> inv;
  inv[0] = "zero ";
  inv[1] = "jeden ";
  inv[10] = inv[1]+inv[0];
  inv[111] = inv[1]*3;
  inv.print("Zmiana klucza");

  Map<bool, std::string> bl;
  bl[true] = "Udalo sie!!! ";
  bl[false] = "Niestety, bylo za trudne :(";
  bl.print("Na zakonczenie");
  cout << "Zwykle mnozenie: " << m["luty"] * 6 << endl;
  cout << 5* bl[true] << endl;
}

/* oczekiwany wynik
***** Tablica z kluczem napisowym *****
--- Element tablicy --- klucz: styczen wartosc: 2999
--- Element tablicy --- klucz: luty wartosc: 2500
Czy tak mozna dodac element zerowy? 0
--- Po modyfikacji --- klucz: styczen wartosc: 2999
--- Po modyfikacji --- klucz: luty wartosc: 666
--- Po modyfikacji --- klucz: marzec wartosc: 1850
--- Po modyfikacji --- klucz: kwiecien wartosc: 2516

***** Tablica const *****
Plik: main.cpp Linia: 31: Wartosc pod luty? 666
Plik: main.cpp Linia: 32: Czy jest maj? Nie znaleziono
Plik: main.cpp Linia: 33: Czy jest marzec? Znaleziono
Plik: main.cpp Linia: 39: Niewlasciwy klucz

***** Tablice z innymi kluczami *****
--- Zmiana klucza --- klucz: 0 wartosc: zero
--- Zmiana klucza --- klucz: 1 wartosc: jeden
--- Zmiana klucza --- klucz: 10 wartosc: jeden zero
--- Zmiana klucza --- klucz: 111 wartosc: jeden jeden jeden
--- Na zakonczenie --- klucz: 1 wartosc: Udalo sie!!!
--- Na zakonczenie --- klucz: 0 wartosc: Niestety, bylo za trudne :(
Zwykle mnozenie: 3996
Udalo sie!!! Udalo sie!!! Udalo sie!!! Udalo sie!!! Udalo sie!!!
 */
