// *** Nie wolno modyfikować tego pliku ***

/*==========================================================================

*** Simple Math Templates ***

Zadanie składa się z dwóch części, w których należy użyć szablonów aby 
zaimplementować proste zagadnienie matematyczne.

1. Całka onzaczona wielomianu x^n

Należy napisać szablon prostej klasy (lub struktury) 'IntegralXn', 
który obliczy całkę oznaczoną wielomianu x^n w zadanym przedziale (x1,x2).
Parametrami szablonu są: stopień wielomianu n (int) oraz przedziały 
całkowania typu double (uwaga na standard <c++20 -- trzeba użyć adresów)
Zakładamy n>=0. Jeśli n<0 kładziemy wynik = 0.

UWAGA: obliczenie musi się wykonać podczas kompilacji.

2. Grupa cykliczna

Grupa cykliczna w matematyce, to grupa n elementów {e,g_1,g_2,...,g_(n-1)} 
wraz z działaniem (mnożeniem grupowym *) takich, że:
a) e*g_i=g_i (i=1,...,n-1 -- g_i jest dowolnym elementem grupy); e jest tzw.
   elementem neutralnym grupy,
b) g_2=g_1*g_1, g_3=g_1*g_1*g_1=g_2*g_1=g_1*g_2,  itd...
c) g_1^n=e  (pomnożenie g_1 n razy daje element neutralny)

Należy zaimplementować taką grupę jako szablon 'GroupZn'. Implementacja klasy 
będzie przechowywać zbiór elementów dowolnego typu i implementować 
działanie grupowe opisane powyżej. Działanie grupowe jest realizowane 
operatorem () o dwóch argumentach będących elementami grupy, które mnożymy. 
Konstruktor przyjmuje zbiór elementów dowolnego typu, które odpowiadają 
zbiorowi {e,g_1,g_2,...}.

WSKAZÓWKA: Wykorzystanie kontenerów std::map umożliwia napisanie tego 
szablonu w kilku linijkach.


*///==========================================================================


#include <iostream>

#include "math.h"
 

// ---------------------------------------------------------------------------
// Szablon do testowania, czy wynik całkowania jest otrzymany podczas kompilacji.
template < int k>
void test() {
 std::cout << ">> Testing compile time evaluation... " << k << std::endl; }
// ---------------------------------------------------------------------------


// globalne zmienne -- przedział całkowania
constexpr double x1 = 1.44;
constexpr double x2 = 3.14;


// =======================================================================
int main() {

	std::cout << "\n";

	// Pierwsza całka dla n=3 w przedziale (x1,x2)
	constexpr double result1 = IntegralXn<3,&x1,&x2>::value;

	// Druga całka dla n=-4 w przedziale (x1,x2)
	constexpr double result2 = IntegralXn<-4,&x1,&x2>::value;

	// Wydruk
	std::cout << result1 << " " << result2 << std::endl;

	// Test wykonania obliczeń podczas kompilacji
	test< static_cast<int>(result1) >();

	// -----------------------------------------------------------------------------
	std::cout << "\n";

	// Tworzymy grupę cykliczną czterech elementów o podanych nazwach
	GroupZn<const char*> G1( {"1","A","B","C"} );

	// Wyniki mnożenia grupowego
	std::cout << "1*A=" << G1("1","A") << "\t A*B=" << G1("A","B") 
		<< "\t B*C=" << G1("B","C") << "\t B*1=" << G1("B","1") 
		<< "\t B*B=" << G1("B","B") << std::endl;

	std::cout << "\n";

	// Tym razem grupa cykliczna innych pięciu elementów
	GroupZn<std::string> G2( {"|0|","|#|","|$|","|@|","|&|"} );

	// Wyniki mnożenia grupowego
	std::cout << "|0|*|#|=" << G2("|0|","|#|") << "\t |$|*|&|=" << G2("|$|","|&|") 
		<< "\t |$|*|#|=" << G2("|$|","|#|") << "\t |@|*|@|=" << G2("|@|","|@|") 
		<< "\t |$|*|@|=" << G2("|$|","|@|") << std::endl;

	std::cout << "\n";

return 0;}
/// =======================================================================

/* *** Spodziewane wyjście ***

23.228 0
>> Testing compile time evaluation... 23

1*A=A	 A*B=C	 B*C=A	 B*1=B	 B*B=1

|0|*|#|=|#|	 |$|*|&|=|#|	 |$|*|#|=|@|	 |@|*|@|=|#|	 |$|*|@|=|0|


*/