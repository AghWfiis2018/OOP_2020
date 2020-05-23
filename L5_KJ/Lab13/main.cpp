#include "Miotacz.h"
#include "MyException.h"
#include "VPL_Utility.h"
#include <iostream>
#include <stdexcept>
	
void FunkcjaMiotajaca ()
{
	try {
		Miotacz * miotacz = new Miotacz;
		miotacz->rzuc();
		std::cout << "Ukryty przekaz"<<std::endl;
	}
	catch (const std::out_of_range& wyjatek)
	{
		MyHandling::HandleException(wyjatek);  // Process exception std::out_of_range with adress [ptr_adr=0x02]
	}
	catch (const std::runtime_error& wyjatek)
	{
		MyHandling::HandleException(wyjatek);  // Process exception std::runtime_error with adress [ptr_adr=0x02]
	}
}


int main ()
{
	using namespace std;

    cout << "=====-===== 1 =====-=====" << endl;
    MyExceptionOne one("One msg"); one.introduce();	   // My name is One. Exception One.
	MyExceptionTwo two("Two msg"); two.introduce();	   // My name is Two. Exception Two.
    cout << "MyExceptionOne adres : " << VPL::PtrAdress(&one) << endl;
	cout << "Koniec wprowadzenia" << endl << endl;

	try {
	    cout << "=====-===== 1 =====-=====" << endl;
		FunkcjaMiotajaca();
		cout << "Ukryty przekaz" << endl;
	}
	catch (const MyExceptionOne& wyjatek) {
	    cout << endl << "=====-===== 1 =====-=====" << endl;
		cout << "Zlapalem wyjatek MyExceptionOne w <" << __FILE__ << ":" << __LINE__ << ">. " << endl; 
		MyHandling::HandleException();   // Handle MyExceptionOne with adress [ptr_adr=0x02]
		                                 // Exception message: "Rzucono wyjatek!"   
	}
	catch (const MyExceptionTwo& wyjatek) {
	    cout << endl << "=====-===== 1 =====-=====" << endl;
		cout << "Zlapalem wyjatek MyExceptionTwo w <" << __FILE__ << ":" << __LINE__ << ">. " << endl;
		MyHandling::HandleException();   // Handle MyExceptionTwo with adress [ptr_adr=0x02]
		                                 // Exception message: "Rzucono wyjatek!"   
	}
    
    cout << endl << "Zadanie wykonane, Mr Exception." << endl;
    
    return 0;
}
/*********************************** OUTPUT ************************************
--------------------------------------------------------------------------------
=====-===== 1 =====-=====
My name is One. Exception One.
My name is Two. Exception Two.
MyExceptionOne adres : [ptr_adr=0x01]
Koniec wprowadzenia

=====-===== 1 =====-=====
Miotacz::Konstruktor
Process exception std::runtime_error with adress [ptr_adr=0x02]

=====-===== 1 =====-=====
Zlapalem wyjatek MyExceptionTwo w <main.cpp:48>. 
Handle MyExceptionTwo with adress [ptr_adr=0x02]
Exception message: "Rzucono wyjatek!"
Miotacz::Destruktor

Zadanie wykonane, Mr Exception.                                            
--------------------------------------------------------------------------------
*******************************************************************************/