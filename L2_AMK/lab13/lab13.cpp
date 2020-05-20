/*
 Celem zadania jest przećwiczenie wyjątków.
 Proszę napisać klasę Number, która pozwala na 
 przechowanie liczb tylko w pewnym określonym zakresie.
 
 Proszę uzupełnić brakujące metody tak, by wynik programu
 był taki jak na końcu tego pliku.

 */

#include "Number.h"
#include <iostream>
#include <stdexcept>

int main() {
	Number::setRange(-3, 4);
	try{
		Number n1(3); //ok
		n1.print();
		n1.value() = -2.5; //ok
		n1.print();

		try{
			const Number n2(2); //ok
			std::cout << "second number: " << n2.value() << std::endl;

			Number n3(-4); // tu za mała liczba
			n3.print();
		}
		catch(const std::out_of_range &e){
			std::cout << "exception: " << e.what() << std::endl;
		}
		n1.value() = 5; // nie ok
		n1.print();
    		std::cout<<"THIS IS TOO FAR..."<<std::endl;
	}
	catch(const std::out_of_range &e){
		std::cout << "exception: " << e.what() << std::endl;
	}
}

/* wynik

Number: 3 is in the range [-3, 4]
Number: -2.5 is in the range [-3, 4]
second number: 2
exception: Out of range during construction
exception: Out of range during assignment

 */
