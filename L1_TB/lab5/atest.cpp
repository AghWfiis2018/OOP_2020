/*
 * W zadaniu nalezy napisac zestaw klas polaczonych w hierarchie (dziedziczacych po sobie)
 * Klasy te wspolpracuja ze soba na w przykladowym kodzie.
 *
 * UWAGA: Prosze sie przygladnac dokladnie przykladom uzycia zanim napisze sie deklaracje metod. Albo lepiej! Prosze sie zastanowic dwa razy nad poprawnoscia const dla kazdej metody i kazdego argumentu.
 *
 * UWAGA: Obiekty alokowane sa dynamicznie (on heap). Prosze zadbac o to zeby dealokacja przebiegla poprawnie.
 */

#include <iostream>
#include "Suma.h"
#include "Pierwiastek.h"
#include "Argumenty.h"

int main() {

  Algo *s = new Suma();
  Pierwiastek *p = new Pierwiastek();
  Argumenty a( 4 ); // 4 liczby
  a( 0, 2.5 )( 1, 4 )( 3, 8 )( 2, 9 ); // zadane jako pary: (indeks, wartosc),
  // w domu prosze zobic taki trick zeby mozna bylo zainicjalizowac "a" w ten sposob:
  // Argumenty a{{0, 2.5}, {1,4},..itd..};
  a.print( "Wartosci wejsciowe:" );
  
  s->wykonaj( a ).print( "Po zsumowaniu:" );
  p->wykonaj( a ).print( "Pierwiastki:" );
  s->wykonaj( p->wykonaj( a ) ).print( "Suma pierwiastkow:" );
  p->wykonaj( s->wykonaj( a ) ).print( "Pierwiastek sumy:" );
  
  Algo* z = s->sklonuj( );
  const Pierwiastek* b = p->sklonuj( ); // tu prosze sobie przypomniec o wariantnosci metod wirtualnych

  z->wykonaj( z->wykonaj( const_cast<const Argumenty&>( a ) ) ).print( "Powtorka: " );
  b->wykonaj( s->wykonaj( a ) ).print( "Powtorka: ", std::cout );
  
  delete s;
  delete p;
  delete z;
  delete b;
  // Do zastanowienia/wyszukania w domu:
  // W zadaniu zamiast wskaznikow mozna by uzyc referencji
  // Algo& s = Suma( ); itd...
  // Wydawac by sie moglo ze juz powyzsza linia zadziala zle.
  // Bo tymczasowy obiekt Suma( ) znika z zakresu
  // ( inaczej, w jakis sposob na stosie zarzadzana jest pamiec dla niego? ) i s jest referencja niekreslona.
  //A jedank tak nie jest. Dlaczego?
}
/* wynik
Wartosci wejsciowe: 2.5 4 9 8 
Po zsumowaniu: 23.5 
Pierwiastki: 1.58114 2 3 2.82843 
Suma pierwiastkow: 9.40957 
Pierwiastek sumy: 4.84768 
Powtorka:  23.5 
Powtorka:  4.84768 
 */
