/*
 Celem zadania jest napisanie kilku klas związanych relacją
 dziedziczenia. Klasy te opisują średnie:

 - arytmetyczna: suma x_i/N
 - harmoniczna:  N/(suma 1/x_i)

 UWAGI:
 - Nigdzie nie jest wymagane, żeby wypisywać liczby, z których 
   wyliczamy średnią. 
 - Proszę wykorzystać ten fakt i stworzyc tylko potrzebne zmienne.
 - Niektóre funkcje działają dokładnie tak samo dla wszystkich 
   klas pochodnych. Unikamy copy-paste'a.
 - Zmienne protected nie są zalecane. Metody protected tak.

 Pliku lab07.cpp proszę nie modyfikować. 
 */

#include "HarmonicMean.h"
#include "ArithmeticMean.h"
#include <iostream>
#include <cmath>

void calcAverage(Mean &m){
  std::cout << "Obliczam: " << m << std::endl;
  m << 2.0 << 1.2 << -3 << 5.;
  std::cout << "Wynik: " << m.result() << std::endl;
}

int main() {
  HarmonicMean *hm = HarmonicMean::create();
  calcAverage(*hm);

  ArithmeticMean am;
  calcAverage(am);

  am << 4.8;
  std::cout << "Po dodaniu 4.8: " << am.result() << std::endl;
  
  std::cout << "======= reset =======" << std::endl;
  am.reset();
  std::cout << "Po reset: " << am.result() << std::endl;
  calcAverage(am);

  const ArithmeticMean cam;
  const HarmonicMean chm;
  cam << 2.0;
  chm << 1.0 << 1.2;

  delete hm;
}

/* wynik

Obliczam: Harmonic
Wynik: 3.33333
Obliczam: Arithmetic
Wynik: 1.3
Po dodaniu 4.8: 2
======= reset =======
Po reset: 0
Obliczam: Arithmetic
Wynik: 1.3
cannot add value 1 to const
cannot add value 2 to const
cannot add value 1.2 to const

 */
