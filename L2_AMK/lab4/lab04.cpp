 // Celem zadania jest stworzenie klasy SmartPtr będącej sprytnym wskaźnikem. 
 // Jest to klasa opakowująca wskaźnik na TestClass tak, 
 // aby w danej chwili tylko 1 obiekt SmartPtr mógł wskazywać na 1 obiekt. 
 
 // - Nie jest możliwe kopiowanie lub "zwykłe" przypisanie wskaźnika
 //	- Możliwe jest przenoszenie (konstruktor i przenoszący operator przypisania)
  
 // Sprytny wskaźnik ma obslugiwać prostą klasę TestClass, 
 // która ma tylko konstruktor i destruktor i metodę info() wypisujące informacje.

 // Uwaga, w TestClass zalecane użycie std::string
 // Skończone zadanie proszę spakować i wysłać na UPEL, np.
 // tar -czvf lab04.tar.gz lab04
 // Oprócz tego proszę umieścić pliki w wirtualnym laboratorium programistycznym.

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
		test.setName("test_AA");
		printInfo(test);
	}
	std::cout << std::endl;

 	SmartPtr smart1( new TestClass("test_B") );
    SmartPtr::ptrType *ptr = smart1.get();
    ptr->info();
 	{
		SmartPtr smart2 = std::move(smart1);
	    if(smart1) std::cout<< "...Nie powinno byc widoczne: " << smart1->info() << std::endl;
	    if(smart2) std::cout<< "...To powinno byc widoczne: " << smart2->info() << std::endl;
	    
	    smart2->setName("test_BB");
		printInfo(*smart2);

	    SmartPtr smart3( new TestClass("test_C") );
		printInfo(*smart3);

		smart3 = std::move(smart2);
		printInfo(*smart3);
	    if(smart2) std::cout<< "...Nie powinno byc widoczne: " << smart2->info() << std::endl;

	    // próba skopiowania nie powinna się kompilować (proszę sprawdzić)
	    // SmartPtr smartX = smart1;

	    // próba jakiegokolwiek porównania nie powinna się kompilować (proszę zapewnić to najkrótszym możliwym sposobem)
	    // if(smart1 != smart2 ) std::cout<< "=== Nie powinno sie skompilowac === " << "\n";
	}

	SmartPtr smart4( new TestClass("test_D") );
	TestClass *rawPtr = smart4.release();
	delete rawPtr;
}

/* wynik działania programu:

++ Tworze obiekt TestClass: test_A
   printInfo: test_A
   printInfo: test_AA
-- Usuwam obiekt TestClass: test_AA

++ Tworze obiekt TestClass: test_B
...To powinno byc widoczne: test_B
   printInfo: test_BB
++ Tworze obiekt TestClass: test_C
   printInfo: test_C
-- Usuwam obiekt TestClass: test_C
   printInfo: test_BB
-- Usuwam obiekt TestClass: test_BB
++ Tworze obiekt TestClass: test_D
-- Usuwam obiekt TestClass: test_D

*/
