/*
 * Tematem zadanie jest napisanie rodziny klas funkcji jednoargumentowych i operatorow dzialajacych na nich.
 *
 * Funkcji jednoargumentowych uzywaja operatory  pozwalajace na:
 * - ProstaRozniczka: numeryczne oblicznie wartosci pochodnej w punkcie.
 Wzor: f' = (f(x + h) - f(x - h)) / 2h gdzie h jest "krokiem" zadanym podczas konstrukcji.
 * - FZlozona: oblicznie wartosc f. zlozonej  a( b (x) ). Przy czym f. a jest zadana w konstruktorze a f. b podobnie jak w PreostaRozniczka.

 * UWAGA: W komentarzach zadane sa zadania do rozwiniecia w domu.
 * UWAGA: Skladnie wywolania operatora zrobiono specjalnie tak aby "brzmiala"  jak zapis matematyczny.
 *
 * UWAGA: W przypadku gdy mamy kilka hierarchii wspolpracujacych ze soba, uzywamy tylko i wylacznie interfejsow (klas bazowych). To jest wazna uwaga.
 *
 * Kompilowac do ftest z opcjami -Wall -g
 */


#include <iostream>
#include "Fun.h"
#include "FElementarne.h"
#include "Trygonometryczne.h"
#include "FZlozona.h"
#include "Rozniczka.h"



int main() {

  
  Fun * l = Liniowa::utworz()->a(2.)->b(-1.); // to jest ax +b = 2x-1
  Fun * q = Kwadratowa::utworz()->a(1)->b(0.)->c(-4.);
  Fun * s = new Sinus;

  std::cout << l->wartosc(0.1)  << " "  << l->wartosc(0) << std::endl;
  std::cout << q->wartosc(0.1)  << " "  << q->wartosc(0) << std::endl;
  std::cout << s->wartosc(0.1)  << " "  << s->wartosc(0) << std::endl;
  
  
  ProstaRozniczka pochodna(0.01); // krok/precyzja

  std::cout <<  "wartosc pochodnej w p 1 "    << pochodna.z(l)->w(1) << std::endl;
  std::cout <<  "wartosc pochodnej w p 2.1 "  << pochodna.z(q)->w(2.1) << std::endl;
  std::cout <<  "wartosc pochodnej w p 0.12 " << pochodna.z(s)->w(0.12) << std::endl;
  // w domu prosze sprawdzic czy da sie zrobic jeszcze czytelniejsza skladnie
  // l(0.5) - wartosc
  // pochodna(l)(0.34) - wartosc pochodnej


  Fun* zloz = new FZlozona(q, l);
  std::cout << "wartosc f. zlozonej " << zloz->wartosc(2) << std::endl; // to jest wynik: q( l( 2 ) )
  
  
  delete l;
  delete q;
  delete s;

  delete zloz;
}
/* wynik
-0.8 -1
-3.99 -4
0.0998334 0
wartosc pochodnej w p 1 2
wartosc pochodnej w p 2.1 4.2
wartosc pochodnej w p 0.12 0.992792
wartosc f. zlozonej 5

 */
