/*
 Celem zadania jest napisanie kilku klas związanych relacją
 dziedziczenia. Klasy te opisuja funcje matematyczne i pochodną.
 Należy znaleźć hierarchię, którą są połączone.

 Pochodną wyliczamy numerycznie: 

	df/dx ----> ( f(x+dx)-f(x-dx) )/(2 dx)

 gdzie dx jest bardzo małym krokiem)
 
 - Do konstruktorów klas Sin, Quadratic przekazujemy parametry, tj.
   - sin(a*x) -- przekazujemy parametr a
   - quadratic: a*x*x + b*x + c -- przekazujemy a, b, c
 - Derivative przechowuje przyjęty w konstruktorze obiekt i jest 
   odpowiedzialny za jego usunięcie.
 - efektem kopiowania powinna być "głęboka" kopia, a nie kopia samego
   wskaźnika. Potwierdza to m.in. brak zmian po pewnych modyfikacjach
   skopiowanego obiektu.

 Pliku lab06.cpp proszę nie modyfikować.
 */

#include "Math.h"
#include <iostream>
#include <cmath>

int main() {
  Sin sinus(4.); // sin(4*x)
  std::cout << "sin: " << sinus.calc(0.5) << std::endl;
  sinus.set_parameter(2); // sin(2*x)
  std::cout << "sin: " << sinus.calc(0.5) << std::endl;

  Function *quadratic_fun = new Quadratic( 4, 6, 2); // 4*x*x + 6*x + 2
  std::cout << "quadratic: " << quadratic_fun->calc(1.5) << std::endl;
  
  std::cout << "==== Derivatives ====" << std::endl;
    
  Derivative *diff_1 = new Derivative( quadratic_fun ); // pierwsza pochodna fcji kwadratowej
  Derivative diff_2( diff_1 ); // druga pochodna fcji kwadratowej
  Sin *sinus2 = new Sin(2);
  Derivative diff_sin( sinus2 ); // pierwsza pochodna sinusa 

  diff_1->set_dx(0.01);
  diff_2.set_dx(0.1);
  diff_sin.set_dx(0.01);
  
  // wyliczamy pochodne w punkcje x 
  std::cout << "2nd order: " << diff_2.calc( M_PI/2 ) << std::endl;
  std::cout << "1st order sin: " << diff_sin.calc( M_PI/2 ) << std::endl;
  
  // skopiowanie całego ciągu - przydatna może być specjalna funkcja polimorficzna 
  std::cout << "======= Copy =======" << std::endl;
  Derivative f = diff_sin;

  std::cout << "copy: " << f.calc( M_PI/2 ) << std::endl;
  std::cout << "sin': " << diff_sin.calc( M_PI/2 ) << std::endl << std::endl;

  sinus2->set_parameter(0.5); // sprawdzamy, czy kopia będzie bez zmian
  std::cout << "copy: " << f.calc( M_PI/2 ) << std::endl;
  std::cout << "sin': " << diff_sin.calc( M_PI/2 ) << std::endl;
  // Pamiętamy o posprzątaniu
}

/* wynik

sin: 0.909297
sin: 0.841471
quadratic: 20
==== Derivatives ====
2nd order: 8
1st order sin: -1.99987
======= Copy =======
copy: -1.99987
sin': -1.99987

copy: -1.99987
sin': 0.353552

 */
