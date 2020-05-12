// 
// Celem zadania jest przećwiczenie przeciążania 
// operatora() oraz std::function.
//

// Proszę napisać klasę List zawierającą zbiór liczb.
// W programie będziemy przeprowadzać operacje na 
// elementach List przy pomocy funkcji i funktorów.

// metoda filter wybiera z Listy elementy spełniające 
// podane kryterium.

// Klasa FilterCriteria przechowuje listę różnych kryteriów. 

// Uwagi:
// - można użyć std::vector (zalecane)
// - powinna być tylko 1 wersja funkcji filter
// - w funktorach można umieszczać definicje w ciele klasy (są krótkie)

// Skończone zadanie proszę spakować i wysłać na UPEL, np.
// tar -czvf lab03.tar.gz lab03

#include "List.h"
#include "FilterCriteria.h"
#include "Functors.h"
#include <iostream>

bool negative(int x){
	return x < 0;
}

int main() {
	std::cout << std::boolalpha;
	List List1;
	for (int i = 0; i < 8; ++i){
		int sign = i % 2 ? 1 : -1;
		List1.insert(i * sign);
	}
	List1.print();
	List1[3] = 10;
	List1.print();
	std::cout << std::endl;

	Functors::divisibleBy divisible(2);
	Functors::greaterThan greater(2);
	std::cout << "9 divisible by 2? " << divisible(9) << std::endl;
	std::cout << "9 greater than 2? " << greater(9) << std::endl;

	const List list2 = List1.filter(negative);
	list2.print("values < 0 in List: ");

	FilterCriteria criteria;
	criteria.add(greater);
	criteria.add(divisible);
	criteria.add(negative);

	for (int i = 0; i < criteria.size(); ++i){
		List1.filter(criteria.get(i)).print();
	}

}
/* wyniki

[ 0 1 -2 3 -4 5 -6 7 ]
[ 0 1 -2 10 -4 5 -6 7 ]

9 divisible by 2? false
9 greater than 2? true
values < 0 in List: [ -2 -4 -6 ]
[ 10 5 7 ]
[ 0 -2 10 -4 -6 ]
[ -2 -4 -6 ]

*/
