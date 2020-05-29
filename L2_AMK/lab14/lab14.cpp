/*
  Celem zadania jest przećwiczenie funkcji szablonowych. 
  Chcemy utworzyć klasę Factory, która gwarantuje, że mamy mozliwość 
  wytworzenia identycznych obiektów.

  Sama klasa Factory nie jest szablonowa, tylko jej funkcje są szablonowe.
  W rozwiązaniu należy wykorzystać statyczne składniki w funkcji i to, 
  że każda instancjacja szablonu to odrębna funkcja.

  Uwaga! Zadanie jest do zrobienia na samych szablonach funkcji. 
  Innych szablonów do tej pory nie było na wykładzie.
 */

#include <iostream>
#include <string>
#include "Factory.h"

struct Book{
  Book(){}
  Book(const std::string& title, const std::string& author): _title(title), _author(author){}
  void print()const{ std::cout << "\"" << _title << "\" by " << _author << std::endl; }
  std::string _title;
  std::string _author;
};

int main() {   
  Factory f1;
  f1.prototype<int>(7);
  f1.prototype<float>(3.14);  
  std::cout << f1.manufacture<int>() << std::endl;
  std::cout << f1.manufacture<float>() << std::endl;
  std::cout << f1.manufacture<float>() << std::endl;

  std::cout << "==== Zmiana int i wymiana fabryki ====" << std::endl;
  Factory f2;
  f2.prototype<int>(9);
  std::cout << f2.manufacture<int>() << std::endl;
  std::cout << f2.manufacture<float>() << std::endl;

  f1.prototype<Book>(Book("Beginning C++", "I. Horton"));
  Book x = f1.manufacture<Book>();
  x.print();
  Book y = f1.manufacture<Book>();
  y.print();
  f1.prototype(Book("The Feynman Lectures on Physics", "R. P. Feynman"));
  Book z = f1.manufacture<Book>();
  z.print();

  try{
    std::cout << f1.manufacture<double>() << std::endl;
    std::cout << "This should not happen! " << std::endl;
  }
    catch(const std::runtime_error& e){
    std::cout << "exception: " << e.what() << std::endl;
  }
  f1.prototype<double>(10.4);
  std::cout << f1.manufacture<double>() << std::endl;
  const float &r = f2.manufacture<float>();
  std::cout << r << std::endl;
}

/* wynik
7
3.14
3.14
==== Zmiana int i wymiana fabryki ====
9
3.14
"Beginning C++" by I. Horton
"Beginning C++" by I. Horton
"The Feynman Lectures on Physics" by R. P. Feynman
exception: no prototype for this type
10.4
3.14
13.14
 */
