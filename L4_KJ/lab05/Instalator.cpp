#include "ListaString.h"
#include "MaszynaStanow.h"
#include "StanyBazowe.h"
#include <iostream>

int main()
{
    std::cout << "=====-===== 3 =====-=====" << std::endl;
	ListaString::rob_halas(true);
		
	ListaString systems;
	systems << "Windows";
	
	std::cout << "Na liscie sa systemy:" << std::endl
	          << systems << "Malo? To dodajmy kolejne." << std::endl;
	
	systems << "Linux" << "OS X";	
	
	std::cout << std::endl;
	std::cout << "=====-===== 2 =====-=====" << std::endl;
	
	MaszynaStanow m;
	m += new DostepneSystemy(systems);
	m += new ZbieranieDanych("Adres email");
	// Ten stan powinien zebrac inforacje o adresie email i zapisac go
	// Prosze o "zamockowanie" tej sytuacji, tj przyjac ze zostaje wpisany adres Nowak@mail.com
	// std::cint >> adres;    ----->     adres = "Nowak@mail.com";		
	m += new Podsumowanie();
	// W tym stanie wyswietlamy informacje o zebranych danych (np. adres email)
	
	m.start();	
	m()();
	std::cout << "=====-===== 1 =====-=====" << std::endl;
	//-------
	++m;
	std::cout << "Po pierwszej inkrementacji: \n" << "m = " << m << std::endl;
	m()();
	std::cout << std::endl;
	//-------
	++m;
	std::cout << "Po drugiej inkrementacji: \n" << "m = " << m << std::endl;
	m()();
	std::cout << "=====-===== 1 =====-=====" << std::endl;
	//-------
	--m;
	std::cout << "Po pierwszej dekrementacji: \n" << "m = " << m << std::endl;
	m()();
	std::cout << std::endl;
	//-------
	++m;
	m()();
	std::cout << std::endl;
	std::cout << "=====-===== 1 =====-=====" << std::endl;
	//-------
	m += new Instalacja();
	++m;
	std::cout << "Na koncu: \n" << "m = " << (const MaszynaStanow&)m << std::endl;
	m()();
	
	return 0;
}

/*********************************** OUTPUT ************************************
--------------------------------------------------------------------------------
=====-===== 3 =====-=====
 (list-def-ctor) 
Na liscie sa systemy:
   1. Windows
Malo? To dodajmy kolejne.

=====-===== 2 =====-=====
 (list-copy-ctor) 
 (list-move-ctor) 
 (list-dtor) 
Rozpoczynamy dzialanie maszyny stanow!
Program mozna uruchomic na nastepujacych systemach: 
   1. Windows
   2. Linux
   3. OS X
wybrano 'Linux'
=====-===== 1 =====-=====
Po pierwszej inkrementacji: 
m = DostepneSystemy >ZbieranieDanych< Podsumowanie 
Prosze podac dana: Adres email = ?, podano 'Nowak@mail.com'

Po drugiej inkrementacji: 
m = DostepneSystemy ZbieranieDanych >Podsumowanie< 
Podsumowanie: 
 * Wybrano system: 'Linux'
 * Adres email = Nowak@mail.com
=====-===== 1 =====-=====
Po pierwszej dekrementacji: 
m = DostepneSystemy >ZbieranieDanych< Podsumowanie 
Prosze podac dana: Adres email = ?, podano 'Nowak@mail.com'

Podsumowanie: 
 * Wybrano system: 'Linux'
 * Adres email = Nowak@mail.com

=====-===== 1 =====-=====
Na koncu: 
m = DostepneSystemy ZbieranieDanych Podsumowanie >Instalacja< 
Instalacja w toku... 
OK!
 (list-dtor) 
 (list-dtor) 
--------------------------------------------------------------------------------
*******************************************************************************/