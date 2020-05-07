#include "Fun.h"
#include "Elementarne.h"
#include "FZlozona.h"
#include "ProstaRozniczka.h"
#include <iostream>

int main() 
{  
	std::cout << "=====-===== 2 =====-=====" << std::endl;
	
	Fun * lfun = Liniowa::utworz()->a(2.)->b(-1.); 					 // To jest ax + b = 2x-1
	Fun * sfun = new Sinus;

	std::cout << lfun->wartosc(0.1)   << " "  << lfun->wartosc(0)  << std::endl;
	std::cout << sfun->wartosc(0.1)   << " "  << sfun->wartosc(0)  << std::endl;

	std::cout << "=====-===== 2 =====-=====" << std::endl;

	Fun * qbase = Kwadratowa::utworz()->a(1)->b(0.)->c(-4.);		 
	Fun * qfun = qbase->clone();                                         // Klonowanie
	std::cout << qbase->wartosc(0.1)  << " "  << qbase->wartosc(0) << std::endl;
	std::cout << qfun->wartosc(0.1)   << " "  << qfun->wartosc(0)  << std::endl;
	
	delete qbase;	
	std::cout << qfun->wartosc(0.1)   << " "  << qfun->wartosc(0)  << std::endl;

	std::cout << "=====-===== 2 =====-=====" << std::endl;

	ProstaRozniczka pochodna(0.01); 									 // Krok / precyzja

	std::cout <<  "Wartosc pochodnej z lfun w punkcie 1.0  = " << pochodna.z(lfun)->w(1)    << std::endl;
	std::cout <<  "Wartosc pochodnej z qfun w punkcie 2.1  = " << pochodna.z(qfun)->w(2.1)  << std::endl;
	std::cout <<  "Wartosc pochodnej z sfun w punkcie 0.12 = " << pochodna.z(sfun)->w(0.12) << std::endl;
	
	// Proszę spróbować dopisać operatory, aby zadziałał następujący zapis:
	// double y = pochodna(lfun)(1);
	
	std::cout << "=====-===== 1 =====-=====" << std::endl;

	Fun* zloz = new FZlozona(lfun, qfun);
	std::cout << "Wartosc f. zlozonej " << zloz->wartosc(2) << std::endl; // To jest wynik: qfun( lfun( 2 ) )

	delete lfun;
	delete qfun;
	delete sfun;
	
	std::cout << "=====-===== 1 =====-=====" << std::endl;	
	std::cout << "F. zlozona dziala dalej: " << zloz->wartosc(2) << std::endl;
	
	delete zloz;
}
/*********************************** OUTPUT ************************************
--------------------------------------------------------------------------------
=====-===== 2 =====-=====
-0.8 -1
0.0998334 0
=====-===== 2 =====-=====
-3.99 -4
-3.99 -4
-3.99 -4
=====-===== 2 =====-=====
Wartosc pochodnej z lfun w punkcie 1.0  = 2
Wartosc pochodnej z qfun w punkcie 2.1  = 4.2
Wartosc pochodnej z sfun w punkcie 0.12 = 0.992792
=====-===== 1 =====-=====
Wartosc f. zlozonej 5
=====-===== 1 =====-=====
F. zlozona dziala dalej: 5
--------------------------------------------------------------------------------
*******************************************************************************/