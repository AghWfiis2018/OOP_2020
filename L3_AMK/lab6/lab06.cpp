/*
 Celem zadania jest napisanie kilku klas związanych relacją
 dziedziczenia.  Klasy te opisują pliki.

 - funkcja print() wypisuje dla klas:
   - File - nazwę pliku klasy 
   - Directory - strukturę i zawartość podkatalogów (patrz w treści) 
 - "/" służy do dodawania kolejnych plików do katalogu (jak / w ścieżce)
  
 - do wypisania wcięć można przekazać do print zmienną informującą o poziomie 
 - przy kopiowaniu do katalogu wykonujemy KOPIĘ całej zawartości.
   Przydatna będzie do tego specjalna funkcja polimorficzna.

 Pliku lab06.cpp proszę nie modyfikować.
 Proszę też nie modyfikować makefile'a, bo program się nie uruchomi.
 */

#include <iostream>
#include "File.h"
#include "Directory.h"

int main() {
  Directory *ppo = new Directory("PPO");
  *ppo / new File("main.cpp");
  ppo->print();
  
  Directory *src = new Directory("src");
  File* cppFile = new File("Klasa.h");
  cppFile->print(); 
  *src / cppFile;
  *src / new File("Klasa.cpp");

  std::cout << "=========== src: ===========" << std::endl;
  File *srcPtr = src;
  srcPtr->print();

  std::cout << "=========== ppo: ===========" << std::endl;
  *ppo / src;
  ppo->print();

  Directory *lab02 = new Directory("Lab02");
// przekopiowanie do lab02 całego katalogu z podkatalogami
  lab02->copy(src);
  src->rename("SOURCE");

  std::cout << "========= copied: =========" << std::endl;
  lab02->print(); 
  std::cout << "======== original: ========" << std::endl;
  src->print(); 

  delete ppo;
  delete lab02;
}
/* wynik

PPO/
__main.cpp
Klasa.h
=========== src: ===========
src/
__Klasa.h
__Klasa.cpp
=========== ppo: ===========
PPO/
__main.cpp
__src/
____Klasa.h
____Klasa.cpp
========= copied: =========
Lab02/
__src/
____Klasa.h
____Klasa.cpp
======== original: ========
SOURCE/
__Klasa.h
__Klasa.cpp

 */
