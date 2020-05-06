/* Celem zadania jest napisanie uzytecznych klas, ktore pozwalaja na dostep 
   do tekstu (slow w zdaniu) "tak jakby" tekst to byla tablica dwuwymiarowa.
   Pierwszy wymiar zmienia sie od 0 do N-1, gdzie N to ilosc slow w napisie.
   Drugi wymiar to ilosc liter w slowie.
   
   Konieczne bedzie napisanie dwoch klas, ReadAccess i ReadWriteAccess, 
   ktore udostepniaja operatory [] o nieznacznie roznej funkcjonalnosci.

   W zadaniu wystepuja tez przydatne funkcje:
   koniec slowa - eofWord - zwraca true jesli w slowie niema wiecej liter,
   i koniec tekstu - eofSentence - zwraca true jesli w napisie nie ma juz kolejnych slow.
   
   UWAGA: w operatorze[] musimy sie przenosic do i-tego slowa, a dokladnie na jego poczatek.
   Najlepiej napisac sobie w tym celu osobna funkcje, ktora obliczy przesuniecie wzgledem poczatku napisu gdzie zaczyna sie i-te slowo.

   UWAGA: w rozwiazniu nie nalezy kpiowac napisow, dzielic ich itp. nigdzie nie wymagamy tego zeby mozna bylo wypisac samo i-te slowo.
 */

#include <iostream>
#include "WordAccess.h"
#include "WordAccess.h"

int main() {
  const ReadAccess p("Ala ma kota");

  int i = 0;
  while ( p[i][0] != 0 ) {  // przypomnienie, sprawdzamy tutaj pierwsza litere slowa, 0 == chal char* oznacza koniec napisu
    std::cout << "Litera pierwsza i druga w slowie " << p[i][0] << " " << p[i][1] << std::endl;
    i++;
  }

  const ReadAccess p2("Dawniej wszystko bylo lepsze");
  i= 0;
  while ( not WordAccess::eofSentence( p2[i] ) ) {
    int j = 0;
    while ( not WordAccess::eofWord( p2[i][j] ) ) {
      std::cout << " " << p2[i][j];
      ++j;
    }
    ++i;
    std::cout << std::endl;
  }

  char z[] = {"To jest tekst, ktory bedziemy zmieniac"};
  ReadWriteAccess pz(z);
  i = 0;
  while ( pz[i][0] != 0 ) {
    std::cout << "Litera pierwsza i druga w slowie przed zmianami " << pz[i][0] << " " << pz[i][1] << std::endl;
    pz[i][1] = '-'; // trzeba wymyslec co zwraca ten operator skoro mozna do jego wyniku zrobic przypisanie
    std::cout << "Litera pierwsza i druga w slowie po zmianie     " << pz[i][0] << " " << pz[i][1] << std::endl;
    i++;
  }
  std::cout << z << std::endl;
}
/* wynik
Litera pierwsza i druga w slowie A l
Litera pierwsza i druga w slowie m a
Litera pierwsza i druga w slowie k o
 D a w n i e j
 w s z y s t k o
 b y l o
 l e p s z e
Litera pierwsza i druga w slowie przed zmianami T o
Litera pierwsza i druga w slowie po zmianie     T -
Litera pierwsza i druga w slowie przed zmianami j e
Litera pierwsza i druga w slowie po zmianie     j -
Litera pierwsza i druga w slowie przed zmianami t e
Litera pierwsza i druga w slowie po zmianie     t -
Litera pierwsza i druga w slowie przed zmianami k t
Litera pierwsza i druga w slowie po zmianie     k -
Litera pierwsza i druga w slowie przed zmianami b e
Litera pierwsza i druga w slowie po zmianie     b -
Litera pierwsza i druga w slowie przed zmianami z m
Litera pierwsza i druga w slowie po zmianie     z -
T- j-st t-kst, k-ory b-dziemy z-ieniac
*/
