/* UWAGA! Do rozwiązania zadania NIE WOLNO wykorzystywać biblioteki standardowej z wyjątkiem cout i endl

   Proszę zdefiniować prostą klasę TestObject, która będzie przechowywała numer ID i miała zaimplementowane funkcje:
   * print - wypisującą informacje o tym obiekcie. 
   * set - ustawiającą numer ID.

   Prosze zdefiniować szablon, którego będzie dało sie używać jak tablicę. 
   W programie może istnieć tylko jedna tego typu tablica. 
   Tablica może przechowywać różne typy.

   Proszę zwrocić uwagę na zarządzanie pamięcią.
   Pliku main.cpp nie wolno modyfikować.
*/


#include <iostream>
#include "main.h"

int main ()
{
  const int intSize (3);
  Vector::initialise<int>(intSize);
  Vector::at<int>(0) = 4;
  Vector::at<int>(1) = 2;
  Vector::at<int>(2) = 5;

  std::cout<<"Liczby calkowite: "<<Vector::at<int>(0)<<" "<<Vector::at<int>(1)<<" "<<Vector::at<int>(2)<<"\n"; // Liczby calkowite: 4 2 5

  Vector::reset<int>();

  std::cout<<"***** Test pierwszego obiektu *****\n";
  TestObject firstObj (1);
  firstObj.print();

  std::cout<<"***** Obiekt pierwszy *****\n";
  const int objSize (4);
  Vector::initialise (objSize, firstObj);
  for (int i = 0; i < Vector::size(); ++i)
    Vector::at<TestObject>(i).print();

  std::cout<<"***** Zmodyfikowano Obiekt pierwszy *****\n";

  Vector::at<TestObject>(1).set(10);
  Vector::at<TestObject>(2).set(20);
  Vector::at<TestObject>(3).set(30);

  for (int i = 0; i < Vector::size(); ++i)
    Vector::at<TestObject>(i).print();

  Vector::reset<TestObject>();
  Vector::reset<TestObject>();


  std::cout<<"***** Obiekt drugi *****\n";

  const TestObject* secondObj = new const TestObject(2000);

  const int objSize2 (6);
  Vector::initialise (objSize2, secondObj);
  for (int i = 0; i < objSize2; ++i)
    Vector::at<const TestObject*>(i)->print();

  std::cout<<"***** Zmodyfikowano Obiekt drugi *****\n";

  Vector::at<const TestObject*>(1) = new const TestObject (100);
  Vector::at<const TestObject*>(2) = new TestObject (110);
  Vector::at<const TestObject*>(3) = new TestObject (120);
  Vector::at<const TestObject*>(4) = new TestObject (130);
  Vector::at<const TestObject*>(5) = new TestObject (140);

  for (int i = 0; i < Vector::size(); ++i)
    Vector::at<const TestObject*>(i)->print();

  for (int i = 0; i < Vector::size(); ++i)
    delete Vector::at<const TestObject*>(i);

  Vector::reset<const TestObject*>();

  return 0;
}
/*
Liczby calkowite: 4 2 5
***** Test pierwszego obiektu *****
Obiekt o identyfikatorze ID=1
***** Obiekt pierwszy *****
Obiekt o identyfikatorze ID=1
Obiekt o identyfikatorze ID=1
Obiekt o identyfikatorze ID=1
Obiekt o identyfikatorze ID=1
***** Zmodyfikowano Obiekt pierwszy *****
Obiekt o identyfikatorze ID=1
Obiekt o identyfikatorze ID=10
Obiekt o identyfikatorze ID=20
Obiekt o identyfikatorze ID=30
***** Obiekt drugi *****
Obiekt o identyfikatorze ID=2000
Obiekt o identyfikatorze ID=2000
Obiekt o identyfikatorze ID=2000
Obiekt o identyfikatorze ID=2000
Obiekt o identyfikatorze ID=2000
Obiekt o identyfikatorze ID=2000
***** Zmodyfikowano Obiekt drugi *****
Obiekt o identyfikatorze ID=2000
Obiekt o identyfikatorze ID=100
Obiekt o identyfikatorze ID=110
Obiekt o identyfikatorze ID=120
Obiekt o identyfikatorze ID=130
Obiekt o identyfikatorze ID=140
*/
