 // Celem zadania jest stworzenie klasy, będącej przykładem sprytnego wskaźnika.
 // Jest to klasa opakowująca wskaźnik, w której liczona jest liczba
 // referencji do niego. 
 
 // - Podczas konstruowania sprytnego wskaźnika przekazujemy do niego
 //   wskaźnik do obiektu stworzonego operatorem new i startujemy licznik.
 // - Każdy kolejny sprytny wskaźnik pokazujący na ten obiekt (stworzony 
 //   z innego sprytnego wskaźnika) zwiększa licznik.
 //	- Każde zniszczenie sprytnego wskaźnika (np. przy wyjściu poza zakres)
 //   zmniejsza licznik. 
 // - Gdy licznik dochodzi do zera, pamięć jest zwalniana. 
 
 // Kluczową sprawą jest zapewnienie współdzielenia licznika pomiędzy różnymi
 // instancjami klasy sprytnego licznika (static nie jest rozwiązaniem - dlaczego?)
 
 // Sprytny wskaźnik ma obslugiwać prostą klasę TestClass, 
 // która ma tylko konstruktor i destruktor i metodę info() wypisujące informacje.

 // Uwaga, w TestClass zalecane użycie std::string
 
 // Skończone zadanie proszę spakować i wysłać na UPEL, np.
 // tar -czvf lab03.tar.gz lab03

#include "SmartPtr.h"
#include "TestClass.h"
#include <iostream>

void printInfo(const TestClass& info){
	std::cout << "   printInfo: " << info.info() << std::endl;
}

int main(){
	{
		TestClass test("test_A");
		printInfo(test);
	}
	std::cout << std::endl;
	
	SmartPtr smart1( new TestClass("test_B") );
	SmartPtr smart2( new TestClass("test_C") );
	
	SmartPtr smart3 = smart1;
	smart2 = smart1;          // <---- Kasujemy test_C, bo żaden inny wskaźnik na niego nie wskazuje
	std::cout << "--> Juz " << smart1.useCount() << " wskazniki pokazuja na " << smart1->info() << std::endl << std::endl;
	
	SmartPtr smart5( new TestClass("test_D") );
	smart3 = smart5;
	{
		const SmartPtr smart4 = smart2;
		printInfo(*smart4);		
		std::cout << "== " << smart4->info() << std::endl;
	}
	std::cout << "== " << smart2->info() << std::endl;
}

/* wynik działania programu:

++ Tworze obiekt TestClass: test_A
   printInfo: test_A
-- Usuwam obiekt TestClass: test_A

++ Tworze obiekt TestClass: test_B
++ Tworze obiekt TestClass: test_C
-- Usuwam obiekt TestClass: test_C
--> Juz 3 wskazniki pokazuja na test_B

++ Tworze obiekt TestClass: test_D
   printInfo: test_B
== test_B
== test_B
-- Usuwam obiekt TestClass: test_D
-- Usuwam obiekt TestClass: test_B

*/
