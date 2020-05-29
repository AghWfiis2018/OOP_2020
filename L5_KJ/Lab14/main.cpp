/*
Standard C++14 wprowadza możliwość tworzenia samodzielnego szablonu zmiennej. Wcześniej takie rozwiązanie można było rozwiązać za pomocą szablonu klasy. Celem tego ćwiczenia jest próba otrzymanie tej funkcjonalności za pomocą szablonów funkcji.

Wyobraźmy sobie projekt, w którym chcemy w różnych miejscach programu tworzyć takie same wartości, ale różne dla różnych typów. Ma się tym zająć klasa SetHoldRet. W rozwiązaniu należy skorzystać ze zmiennych statycznych i statycznych składników funkcji, oraz z tego, że każda instancja szablonu to oddzielna funkcja.

Dodatkowo proszę napisać klasę NicePrinter z operatorem() jako szablonem, który będzie pomocny przy wypisywaniu. Do zachowania stałej szerokości prefiksu z numerem linii, najłatwiej użyć manipulatora std::setw(int n), znajdujący  się w <iomanip>, który przygotuje miejsce na n cyfr:

    std::cout << std::setw(prefix_width) << number << ... ;

UWAGA:

    Proszę zwrócić uwagę, że sama klasa SetHoldRet nie jest szablonowa - szablonowe są tylko jej funkcje składowe.
    Użycie samodzielnego szablonu zmiennej lub szablonu klasy do rozwiązania zadania jest traktowane jako zadanie nie na temat i skutkuje oceną zadania na 0 punktów.
    Przez samodzielny szablon zmiennej rozumiem zmienną której szablon jest określony niezależnie od szablonu funkcji/klasy, wprowadzony w standardzie C++14 tzw. variable template:
    https://en.cppreference.com/w/cpp/language/variable_template
    Nie ma żadnych ograniczeń w tworzeniu zmiennych wewnątrz ciała funkcji, których typ jest określony przez szablon funkcji. 
*/

#include "NicePrinter.h"
#include "SetHoldRet.h"
#include <string>

int main() {
    const NicePrinter printer(3);                                               // NicePrinter: Set 3-digits prefix
    
    printer.separator(4);                                                       // =====-===== 4 =====-=====
    printer.header("dwa typy, pierwszy SetHoldRet");                            // * dwa typy, pierwszy SetHoldRet *
    SetHoldRet pierwszy;
    pierwszy.base<int>( 7 );
    pierwszy.base<float>( 3.14 );
    printer( pierwszy.product<int>() );                                         //   1: 7
    printer( pierwszy.product<float>() );                                       //   2: 3.14
    float liczba1 = pierwszy.product<float>();
    printer( liczba1 );                                                         //   3: 3.14

    printer.separator(4);                                                       // =====-===== 4 =====-=====
    printer.header("wymiana int, drugi SetHoldRet");                            // * wymiana int, drugi SetHoldRet *
    SetHoldRet drugi;
    drugi.base<int>(9);
    printer( drugi.product<int>() );                                            //   4: 9
    printer( drugi.product<float>() );                                          //   5: 3.14

    printer.separator(2);                                                       // =====-===== 2 =====-=====
    printer.header("pierwszy SetHoldRet *");                                    // * pierwszy SetHoldRet *
    printer( pierwszy.product<int>() );                                         //   6: 9
    
    printer.separator(3);                                                       // =====-===== 3 =====-=====
    printer.header("nowy typ, pierwszy SetHoldRet");                            // * nowy typ, pierwszy SetHoldRet *
    pierwszy.base<std::string>( std::string("Napis") );
    std::string text1 = pierwszy.product<std::string>();
    printer( text1 );                                                           //   7: Napis
    std::string text2 = pierwszy.product<std::string>();
    printer( text2 );                                                           //   8: Napis
    
    printer.separator(2);                                                       // =====-===== 2 =====-=====
    printer.header("pierwszy i drugi SetHoldRet");                              // * pierwszy i drugi SetHoldRet *
    pierwszy.base( std::string("Cos innego") );
    std::string text3 = drugi.product<std::string>();                    
    printer( text3 );                                                           //   9: Cos innego
    
    printer.separator(2);                                                       // =====-===== 2 =====-=====
    printer.header("testowanie");                                               // * testowanie *
    text3.append(" teraz");
    printer( text3 );                                                           //  10: Cos innego teraz
    printer( drugi.product<std::string>() );                                    //  11: Cos innego

    printer.separator(2);                                                       // =====-===== 2 =====-=====
    printer.header("referencja?");                                              // * referencja? *
    const std::string & text4 = drugi.product<std::string>();
    pierwszy.base( std::string("Cos innego v2") );
    printer( text4 );                                                           //  12: Cos innego v2

    return 0;
}

/*********************************** OUTPUT ************************************
--------------------------------------------------------------------------------
NicePrinter: Set 3-digits prefix                                                
=====-===== 4 =====-=====
* dwa typy, pierwszy SetHoldRet *                                               
  1: 7                                                                          
  2: 3.14                                                                       
  3: 3.14                                                                       
=====-===== 4 =====-=====                                                       
* wymiana int, drugi SetHoldRet *                                               
  4: 9                                                                          
  5: 3.14                                                                       
=====-===== 2 =====-=====                                                       
* pierwszy SetHoldRet * *                                                       
  6: 9                                                                          
=====-===== 3 =====-=====                                                       
* nowy typ, pierwszy SetHoldRet *                                               
  7: Napis                                                                      
  8: Napis                                                                      
=====-===== 2 =====-=====                                                       
* pierwszy i drugi SetHoldRet *                                                 
  9: Cos innego                                                                 
=====-===== 2 =====-=====                                                       
* testowanie *                                                                  
 10: Cos innego teraz                                                           
 11: Cos innego     
=====-===== 2 =====-=====                                                       
* referencja? *         
 12: Cos innego v2  
--------------------------------------------------------------------------------
*******************************************************************************/
