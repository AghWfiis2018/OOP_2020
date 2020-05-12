/*
 Celem zadania jest napisanie kilku klas powiązanych relacją
 dziedziczenia. Klasy te opisują elementarne operacje matematyczne. 
 Każda z nich ma jakies polimorficzne metody i konieczna infrastrukture.
 
 Proszę dopisać potrzebne klasy o oodpowiedniej hierarchii
 oraz potrzebne funkcje tak aby program kompilował się i dawał oczekiwany 
 wynik.
 - proszę wykorzystać dziedziczenie to uniknięcia copy-paste'a.
 - W klasie SumOfElements nie trzeba na razie się przejmować,
   czy rozmiar tablicy jest prawidłowy

 Gotowy program proszę wczytać na upel do VPL. Można go uruchomić 
 i przetestować online.
 */

#include "Division.h"
#include "Exponentiation.h"
#include "SumOfElements.h"
#include <iostream>

int main() {
  Division divide(4,2);
  Exponentiation pow(5, 0.5);
  const int n = 4;
  double numbers[n] = {1,3.2,5,11};
  const SumOfElements suma(numbers, n);

  "***" >>= divide;
  "---" >>= pow;
  "===" >>= suma;

  Operation* d1 = new Division(7,2);
  "---" >>= *d1;
  delete d1;

  Operation* d2 = new SumOfElements(numbers, n);
  "___" >>= *d2;
  delete d2;
  
  std::cout << "=====================================" << std::endl;
    
  const Operation* all[] = {&divide, &pow, &suma}; 
  for ( unsigned idx = 0; idx < sizeof(all)/sizeof(Operation*); ++idx ) {
    const Operation* d = all[idx];
    d->print(); 
    std::cout << " = " << d->eval() << std::endl;
  }  
}
/* wynik

*** 4 / 2 ***
--- 5 ^ 0.5 ---
=== 1 + 3.2 + 5 + 11 ===
--- 7 / 2 ---
___ 1 + 3.2 + 5 + 11 ___
=====================================
4 / 2 = 2
5 ^ 0.5 = 2.23607
1 + 3.2 + 5 + 11 = 20.2

 */
