/*
 * Celem zadania jest napisanie klasy opisujacej katalogi.
 * Mozna wykozystac fragmenty poprzedniego zadania. 
 * 
 * Implementacja sama zarzadza pamiecia poprzez uzycie shared_ptr
 * W implementacji nalezy uzyc kontenera std::list
 * 
 * Interfejs moglby oczywiscie nie wymagac uzycia shared_ptr. Dla uproszczenia, jednak zadanie jest tak sformulowane zeby bylo to oczywiste.
 *
 * UWAGA: w domu nalezy sobie zadanie rozbudowac tak ze by mozna bylo dodac tez klase File, SoftLink/Lacze.
 */
#include <memory>
#include "Dir.h"


int main() {
  auto top = std::shared_ptr<Dir>(new Dir("."));  
  auto home = std::make_shared<Dir>("home"); // to jest to samo
  *top += home; // dodajemy do kat TOP podkatalog  
  *home += std::make_shared<Dir>("ewa");
  *home += std::make_shared<Dir>("adam");
  *home += std::make_shared<Dir>("kacper");  
  top->findDir("ewa")->add( std::make_shared<Dir>("desk") );
  top->findDir("ewa")->add( std::make_shared<Dir>("work") );
  std::cout << *top;
  std::cout << "--------------" << std::endl;  

  home->rem("kacper");
  top->findDir("adam")->add( top->findDir("desk") ); // tu jest trick, gdy dobrze uzyjemy shared_ptr to nie musimy sie martwic pamiecia  
  std::cout << *top;
  std::cout << "--------------" << std::endl;
   

   
}
/* wynik 
.
  home
    ewa
      desk
      work
    adam
    kacper
--------------
Deleting Dir: kacper
.
  home
    ewa
      desk
      work
    adam
      desk
--------------
Deleting Dir: .
Deleting Dir: home
Deleting Dir: ewa
Deleting Dir: work
Deleting Dir: adam
Deleting Dir: desk

 */
