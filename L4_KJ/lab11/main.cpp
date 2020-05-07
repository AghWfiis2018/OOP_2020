#include "Farma.h"
#include "Zwierz.h"
#include <iostream>
#include <vector>

// Konstruktor Farmy jest pusty! 
// Uzycie sprytnych wskaznikow zalatwi sprawe zwalniania pamieci
Farma::~Farma() {}

int main(){
    std::cout << std::endl << "=====-===== 1 =====-=====" << std::endl;
    Owca malaOwieczka("Beata");
    malaOwieczka.opisz();
    
    std::cout << std::endl << "=====-===== 1 =====-=====" << std::endl;
    Farma farma;
    farma.wypisz("Pusta farma");

    std::cout << std::endl << "=====-===== 1 =====-=====" << std::endl;
    farma.dodaj(std::make_unique<Owca>("Bernadeta"));
    farma.dodaj(std::make_unique<Krowa>("Mucka"));
    farma.dodaj(std::make_unique<Krowa>("Krasula"));
    farma.dodaj(std::make_unique<Kon>("Rafal"));
    farma.dodaj(std::make_unique<Owca>("Beata"));
    farma.dodaj(std::make_unique<Krowa>("Mucka"));
    farma.dodaj(std::make_unique<Owca>(malaOwieczka));
    farma.wypisz("Zwierzeta na lace");
    
    std::cout << std::endl << "=====-===== 1 =====-=====" << std::endl;
    std::cout << "== Ile zwierzat 'Beata' =" << std::endl;
    std::cout << "Na farmie jest " << farma.zliczImie("Beata") << " Beat" << std::endl;         
    
    std::cout << std::endl << "=====-===== 1 =====-=====" << std::endl;
    std::cout << "==== Statystyka imion ===" << std::endl;
    farma.statystykaImion();                                                    // wypisanie ile razy występuje każde imię, alfabetycznie
    
    std::cout << std::endl << "=====-===== 1 =====-=====" << std::endl;
    std::cout << "===== Stado owieczek ====" << std::endl;
    std::vector<Owca*> stado = farma.wyprowadzOwce();
    for(const auto &o: stado)
    {
        std::cout << o->imie() << std::endl;
        o->ostrzyz();
    }
    
    std::cout << std::endl << "=====-===== 1 =====-=====" << std::endl;
    farma.wypisz("Po strzyzeniu owiec");
    
    std::cout << std::endl << "=====-===== 1 =====-=====" << std::endl;
    std::cout << "===== Koniec wypasu =====" << std::endl;
}

    
/*********************************** OUTPUT ************************************
--------------------------------------------------------------------------------
=====-===== 1 =====-=====
Owca Beata - nieostrzyzona

=====-===== 1 =====-=====
-- Pusta farma --

=====-===== 1 =====-=====
-- Zwierzeta na lace --
Owca Bernadeta - nieostrzyzona
Krowa Mucka
Krowa Krasula
Kon Rafal
Owca Beata - nieostrzyzona
Krowa Mucka
Owca Beata - nieostrzyzona

=====-===== 1 =====-=====
== Ile zwierzat 'Beata' =
Na farmie jest 2 Beat

=====-===== 1 =====-=====
==== Statystyka imion ===
Beata: 2
Bernadeta: 1
Krasula: 1
Mucka: 2
Rafal: 1

=====-===== 1 =====-=====
===== Stado owieczek ====
Bernadeta
Beata
Beata

=====-===== 1 =====-=====
-- Po strzyzeniu owiec --
Owca Bernadeta - ostrzyzona
Krowa Mucka
Krowa Krasula
Kon Rafal
Owca Beata - ostrzyzona
Krowa Mucka
Owca Beata - ostrzyzona

=====-===== 1 =====-=====
===== Koniec wypasu =====
Owca Bernadeta wrocila do zagrody
Krowa Mucka wrocila do obory
Krowa Krasula wrocila do obory
Kon Rafal wrocil do stajni
Owca Beata wrocila do zagrody
Krowa Mucka wrocila do obory
Owca Beata wrocila do zagrody
Owca Beata wrocila do zagrody
--------------------------------------------------------------------------------
*******************************************************************************/
