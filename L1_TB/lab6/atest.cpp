/*
  Celem zadania jest implementacja wzorca zachowania zwanego dekoratorem.
  Modelowana struktura dotyczy formowania cen produktow.
  Mianowicie na cene w sklepie moze sie skladac:
  Cena bazowa towaru, marza, dodatkowa oplata stala czy to ze artykulu dotyczy jakas promocja.
  Skladniki finalnej ceny mozemy dowolnie "skladac" wiec nie da sie tego zaimplementowac jako zestawu klas:
  Maslo
  MasloPlusMarza
  MasloPlusMarzaPlusOplataPolkowaStala
  .....                               NaPromocji ...
  Bo ilosc potrzebnych klas bylaby nieskonczona. Trzeba to rozwiazac inaczej.

  UWAGA: Dbamy o usuniecie zaalokowanej pamieci. To jest bardzo proste!


  Uwagi techniczne:
  Liczby na napisy mozemy konwertowac z uzyciem: std::to_string zdefiniowane sa tutaj: https://en.cppreference.com/w/cpp/string/basic_string/to_string
  Do "zaokraglenia" potrzebnego z klasie "Zaokroglenie" mozna uzyc funkcji std::ceil (cena) - 0.01; trzeba zainkludowac cmath

  Wszyskie klasy mozna zaimplementowane w jednym naglowku i w jednym pliku zrodlowym. 
  Male funkcje moga byc takze zaimplementowane w naglowku.

 */
 
 #include <iostream>
#include "Cennik.h" // wszystkiekie klasy sa tutaj

class Maslo: public Towar {
public:
  Maslo( double cena,  const std::string& nazwa, double procentMasla=0.82)
    : m_cena(cena),
      m_nazwa(nazwa),
      m_procent(procentMasla){}
  std::string nazwa() const override { return "Maslo " + m_nazwa + std::to_string(m_procent*100)+"tluszczu "; }
  double cena() const override { return m_cena; }
private:
  double m_cena;
  std::string m_nazwa;
  double m_procent;
};

class Ser: public Towar {
public:
  Ser( double cena, const std::string& nazwa, bool plesniowy=true)
    : m_cena(cena),
      m_nazwa(nazwa),
      m_plesniowy(plesniowy) {}
  double cena() const override { return m_cena; }
  std::string nazwa() const override { return "Ser "+m_nazwa + ( m_plesniowy? "(plesniowy)": ""); }
private:
  double m_cena;
  std::string m_nazwa;
  bool m_plesniowy;
};

int main() {
  Towar* maslo = new Maslo(4.50, "Zwykle", 0.70);
  Towar* masloExtra = new Zaokraglenie( new OplataStala( new Marza( new Maslo(4.50, "Extra", 0.70), 0.15 /*15% marzy*/), 0.4 /*40gr za wystawienie na polke*/));
  Towar* oselkaNaPromocji =   new Promocja( new OplataStala( new Maslo(15.0, "Oselkowe"), 0.4 ), 0.3 /*30 proc obnizka */ );

  Towar* serMorskiOpakowanie = new OplataStala( new Ser( 5.20, "Morski", false ), 0.2 /*oplata mniejsza bo towar mniej chodliwyi nie trzeba ciagle dokladac*/);

  Towar* polka[] = { maslo, masloExtra, oselkaNaPromocji, serMorskiOpakowanie };
  for ( auto t: polka ) {
    std::cout << t->nazwa() ;
    std::cout << t->cena() << std::endl;
    delete t;
  }
}
/* wyniki
Maslo Zwykle70.000000tluszczu 4.5
Maslo Extra70.000000tluszczu *Marza: 15.000000% +Oplata Stala: 0.400000 Zaokraglone w gore 5.99
Maslo Oselkowe82.000000tluszczu +Oplata Stala: 0.400000  Na promocji: 30.000000% 10.78
Ser Morski+Oplata Stala: 0.200000 5.4
*/