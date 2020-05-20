// *** Nie wolno modyfikować tego pliku ***

/*==========================================================================


*** User Exception ***

Tym razem nieco inny styl zadania. Polegać ono będzie na napisaniu prostej 
klasy User z głośnym konstruktorem i destruktorem, przechowującej nazwę 
użytkownika, oraz napisaniu klasy dodatkowej przechowującej 
zadaną liczbę użytkowników. 

Należy napisać odpowiednią obsługę wyjątków, tak aby program dawał identyczne
 wyjście oraz nie miał wycieków pamięci. Ze względu na specyfikę zdania, 
brak wycieków pamięci jest kluczowy. 

Kod został specjalnie spreparowany aby wymusić wykorzystanie pewnych 
elementów języka i nie ma być realistyczny. Dlatego też nie zawiera 
prawie komentarzy.

UWAGA:
-- Niepoprawne wyjście lub wycieki pamięci skutkują ZEREM punktów za 
wyjście (i odpowiednio zredukowaną liczbą punktów za kod, 
w zależności od powagi błędów).

*///==========================================================================


#include <iostream>
#include <vector>
#include <cmath>

#include "user.h"


// -----------------------------------------------------------------------
void play(const User& usr_) {
	std::cout << "User " << usr_.get_name() << " is playing....\n";
}
// -----------------------------------------------------------------------


// =======================================================================
int main() {

	std::cout << "\n";

	// Należy uważnie przeanalizować wyjście podane na końcu pliku.

	try {
		User user1("Abe Johansson");
		user1.authorize(true);
		play(user1);
		
		User user2("John Shaft");
		user2.authorize(false);
		play(user2);

	}

	catch (const std::string& info_) {
		std::cout << info_ << std::endl; }


	try {

		const int N = 3;

    		UserArray* array = new UserArray (N);

		array->set(0, new User("kotka2001"));
		array->set(1, new User("olek56wt"));
		array->set(2, new User("boneCrusher11"));
		array->set(3, new User("gosiaczek931"));

		for (auto l=0;l<N;++l) 
			play(*array->get(l));
  	}
  
	catch (...) { 
	    std::cout << "Deleting Users...\n";
  	}

	std::cout << "\n";

return 0;}
/// =======================================================================

/* *** Spodziewane wyjście ***

Creating User Abe Johansson
User Abe Johansson is playing....
Creating User John Shaft
Deleting User John Shaft
Deleting User Abe Johansson
Authorisation for User John Shaft was not granted.
Creating User kotka2001
Creating User olek56wt
Creating User boneCrusher11
Creating User gosiaczek931
Deleting User gosiaczek931
Deleting Users...
Deleting User kotka2001
Deleting User olek56wt
Deleting User boneCrusher11

*/