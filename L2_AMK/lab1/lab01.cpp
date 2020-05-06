/*
 Celem zadania jest napisanie klasy Complex reprezentującej
 liczbę zespoloną. Umożliwia ona wybrane działania:
 - sumę (operator+)
 - postinkrementację (Complex operator++) części rzeczywistej i urojonej
 - preinkrementację (Complex& operator++)
 
 Oraz inne przydatne funkcje.

 Pliku lab01.cpp nie modyfikujemy (chyba, że w treści jest 
 opcjonalne odkomentowanie dla testu).

 Program prosze kompilowac przynajmniej z flaga -Wall.
 Po skonczeniu zadania proszę spakować pliki z kodem i wgrać na UPEL.
 Proszę przesłać na UPEL także makefile.
 Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
 obiektowe i plik wykonywalny. 
 */

#include <iostream>
#include "Complex.h"

int main() {
  Complex a(1.0,0.5);
  const Complex b(2, 0.5);

  std::cout << a << ", " << b << std::endl;

  std::cout << "============== suma ==============" << std::endl;
  std::cout << "a+b= " << a + b << std::endl;
  
  std::cout << "======= preinkrementacja: ========" << std::endl;
  std::cout << "pre ++a   = " << ++a << std::endl;
  std::cout << "after ++a = " << a << std::endl;

  std::cout << "======= postinkrementacja: =======" << std::endl;
  std::cout << "post a++  = " << a++ << std::endl;
  std::cout << "after a++ = " << a << std::endl;
   
  std::cout << "==================================" << std::endl;
  std::cout << a.re() << ", " << a.im() << std::endl;
  std::cout << b.re() << ", " << b.im() << std::endl;

  a.re() = 1;
  std::cout << a << std::endl;

  // nie powinno się kompilować po odkomentowaniu - nie modyfikujemy obiektu const:
  // b.re() = 3;
}
/* wynik

(1 + 0.5*i), (2 + 0.5*i)
============== suma ==============
a+b= (3 + 1*i)
======= preinkrementacja: ========
pre ++a   = (2 + 1.5*i)
after ++a = (2 + 1.5*i)
======= postinkrementacja: =======
post a++  = (2 + 1.5*i)
after a++ = (3 + 2.5*i)
==================================
3, 2.5
2, 0.5
(1 + 2.5*i)

*/
// błąd po odkomentowaniu ostatniej linii:
// error: assignment of read-only location ‘b.Complex::re()
 
