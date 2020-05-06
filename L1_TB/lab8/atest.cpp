/* Celem zadania jest zapoznanie sie z podstawami dziedziczenia
   wielokrotnego.  W hierarchii wystepuja 4 klasy. Nalezy poprawnie
   odwzorowac zaleznosci miedzy nimi.

   UWAGA: Klasa bazowa Mebel nie moze byc interfejsem (czysto wirtualna).
   UWAGA: Operator << zachowuje sie jak, wirtualna metoda, nalezy to rozwiazac przez przekierowania jego funkcjonalnosci do takiej wlasnie wirtualnej metody.

 */
#include <iostream>
#include "Mebel.h"
#include "Sofa.h"
#include "Lozko.h"
#include "Kanapa.h"



int main() {
  {
    Mebel m(100, 120, 150);
    std::cout << "jakis mebel " << m  << std::endl;
  }

  {
    Sofa* s = new Sofa(90, 100, 200, 180);
    Mebel *x  = s;
    std::cout << "jakas sofa "  << *x << std::endl;
    delete x;
  }

  {
    Lozko* l = new Lozko(90, 100, 200, 190);
    const Mebel* x  = l;
    std::cout << "kinkg bed "  << *x << std::endl;
    delete x;
  }

  { // zabawa z wielokrotnym dziedziczeniem
    Kanapa* k = new Kanapa( 80, 90, 220, 195, 200);
    Sofa* s = k;
    Lozko* l = k; l = 0;

    std::cout << "kanapa z ikei " << *s << std::endl;
    delete s;
  }

}
/* wynik
jakis mebel Mebel: sz:100 wys:120 dl:150
~Mebel
jakas sofa Sofa: Mebel: sz:90 wys:100 dl:200  siedzisko: 180
~Sofa
~Mebel
kinkg bed Lozko: Mebel: sz:90 wys:100 dl:200  sz.spania: 190
~Lozko
~Mebel
kanapa z ikei jako Mebel: sz:80 wys:90 dl:220
 jako Sofa: Mebel: sz:80 wys:90 dl:220  siedzisko: 195
 jako Lozko: Mebel: sz:80 wys:90 dl:220  sz.spania: 200
~Kanapa
~Lozko
~Sofa
~Mebel

 */