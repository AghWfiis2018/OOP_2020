/* Celam zadnaia jest napisanie klasy opisujacej ulamek zyczajny.
   Klasa ta pozwala na konwersje z liczby calkowitej i z liczby typu double 
   (w tym przypadku z kontrolowana precyzja).
   
   Dostepna jest takze konwersja na typ double. 
   Zeby zadanie nie bylo nudne ulamki mozna dodawac (metoda add).

   UWAGA: Ulamkow nie trzeba skracac.
   UWAGA: Prosze sie zastanowic nad poprawnoscia const.
   UWAGA: Trudnoscia moze sie okazac konwersja z typu double na ulamek. 
   Niemniej, algorytm jest trywialnie prosty. Nalezy mnozyc liczbe rzeczywista przez 10 
   az do momentu gdy czesc dziesietna ulamka bedzie == 0 lub gdy odpowiednia precyzja 
   zostanie osiagnieta (czyli mianownik bedzie rowny precyzji, ktora zesmy ustalili).
 */

#include <iostream>
#include "Frac.h"
#include "Frac.h"

int main() {

  Frac f1(1,2);
  double fdec = f1;
  std::cout << "dziesietnie " << fdec << std::endl;

  
  Frac f2{ f1 };
  f2.print(" skopiowana wartosc w formie ulamka\n"); // ta metoda wypisuje ulamek jako 1/2, napis w argumencie wypisywany jest po wypisaniu ulamka tu, nowa linia


  // konwersje
  const Frac f3(4);
  f3.print("\n");
  double f3dec = f3;
  f2.print("\n");

  // operacje matematyczne
  const Frac podo( f2 + f1 );
  podo.print(" dodane proste ulamki \n");

  std::cout << f3dec << std::endl;
  {
    Frac a = 7 + f2;
    std::cout << "+ " << a << std::endl;
  }
  {
    Frac a = f1 - 7 ;
    std::cout << "- " << a << std::endl;
  }
  {
    Frac a = f2 * 3;
    std::cout << "* " << a << std::endl;
  }
  {
    Frac a = 5 * Frac(1,3);
    std::cout << "* ";
    a.print("\n");
    std::cout << std::endl;
  }

  

  Frac::setCnvPrecision(1000000);
  const Frac fd(9.12);
  fd.print("\n");
  Frac::setCnvPrecision(1000);
  const Frac fd2(0.333333333);
  fd2.print(" na double ");
  std::cout << fd2 << std::endl;

  const Frac sim(4.0);
  sim.print(" okragla wartosc\n");




  
  
}
/*
dziesietnie 0.5
1/2 skopiowana wartosc w formie ulamka
4/1
1/2
4/4 dodane proste ulamki 
4
+ 7.5
- -6.5
* 1.5
* 5/3

9119999/1000000
333/1000 na double 0.333
4/1 okragla wartosc
*/
