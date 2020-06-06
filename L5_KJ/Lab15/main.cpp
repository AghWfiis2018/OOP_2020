#include "Array.h"
#include "TemFun.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
	const int tab_size = 5;
	std::vector<double> arrayDouble(tab_size);
	int arrayInt[] = {2,7,5,4,9};
	Array a(tab_size);
	std::string text = "poiuytrewq";

	for (int i = 0; i < tab_size; ++i)
	{
		arrayDouble[i] = 1-0.5*i*i;
		a[i] = 6-i;
	}

	std::cout << "Disordered" << std::endl;
    num::print( arrayDouble, tab_size );
	num::print( arrayInt, tab_size );
	num::print( a, a.size() );
	num::print( text, text.size() );

	num::bubble_sort( arrayDouble, tab_size );
	num::bubble_sort( arrayInt, tab_size );
	num::bubble_sort( a, a.size() );
	num::bubble_sort( text, text.size() );
	
	std::cout << "\nSorted" << std::endl;
    num::print( arrayDouble );
	num::print( arrayInt );
	num::print( a );
	num::print( text );
	
	// Tak dla sprawdzenia
	std::cout << "\nTest primes" << std::endl;
	const bool f2t5 = num::all_primes<2, 5>(arrayInt);                                      // wszystkie miedzy indeksami [2, 5)
	const bool f2t4 = num::all_primes<2, 4>(arrayInt);                                      // wszystkie miedzy indeksami [2, 4)
	std::cout << "<2,5) = " << std::boolalpha << f2t5 << std::endl;
	std::cout << "<2,4) = " << std::boolalpha << f2t4 << std::endl;

    // Kolejna proba
    std::cout << "\nTest reverse" << std::endl;
    const bool is3gr4 = num::greater(3, 4);                                                 // 3 > 4 = false
    const bool isZoogrKoo = num::greater(std::string("Zoo"), std::string("Koo"));           // Zoo > Koo = true
    std::cout << "is 3 greater than 4 = " << std::boolalpha << is3gr4 << std::endl;
    std::cout << "is Zoo greater than Koo = " << std::boolalpha << isZoogrKoo << std::endl;
    
    // I na sam koniec ciekawostka dla tych co chca 10 punktow
    // Sortowanie tablicy na podstawie funkcji porownujacej
    // Kto nie da rady, moze zakomentowac te dwie linijki
    num::bubble_sort( arrayInt, tab_size, num::greater<int> );
    num::print( arrayInt );
    
	return 0;
}
/*********************************** OUTPUT ************************************
--------------------------------------------------------------------------------
Disordered
1, 0.5, -1, -3.5, -7
2, 7, 5, 4, 9
6, 5, 4, 3, 2
p, o, i, u, y, t, r, e, w, q

Sorted
-7, -3.5, -1, 0.5, 1
2, 4, 5, 7, 9
2, 3, 4, 5, 6
e, i, o, p, q, r, t, u, w, y

Test primes
<2,5) = false
<2,4) = true

Test reverse
is 3 greater than 4 = false
is Zoo greater than Koo = true
9, 7, 5, 4, 2
--------------------------------------------------------------------------------
*******************************************************************************/