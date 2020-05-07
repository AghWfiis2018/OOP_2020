#include "Predkosc.h"
#include "Pojazdy.h"
#include <iostream>

void sprawdzWskaznik(const void* p) {
	if ( p == 0 )
		std::cout << "null ptr" << std::endl;
	else
		std::cout << "ok ptr" << std::endl;
}

void fotoradar(const Pojazd* poj) {
	if ( poj )
		std::cout << "Typ pojazdu: " << (*poj) << std::endl;
	else
		std::cout << "Pojaz nierozpoznany." << std::endl;
}

int main() {
    std::cout << "=====-===== 1 =====-=====" << std::endl;
	PredkoscMaksymalna prMax(140);
	std::cout << "Przykladowa predkosc maksymalna = " << prMax << std::endl;
	
    std::cout << std::endl;
	
	std::cout << "=====-===== 1 =====-=====" << std::endl;
	Samochod * ss = new Samochod( "KRA 1234", prMax );
	sprawdzWskaznik(dynamic_cast<PojazdLadowy*>(ss));
	fotoradar(ss);

    std::cout << "=====-===== 1 =====-=====" << std::endl;
	Motorowka * mm = new Motorowka( "MB 234", PredkoscMaksymalna(50) );
	sprawdzWskaznik(dynamic_cast<const PojazdLadowy*>(mm));
	fotoradar(mm);
	
    std::cout << "=====-===== 1 =====-=====" << std::endl;
	const Rower rr = Rower("R44236");
	sprawdzWskaznik(dynamic_cast<const PojazdLadowy*>(&rr));
	fotoradar(&rr);

	std::cout << std::endl;

    std::cout << "=====-===== 4 =====-=====" << std::endl;
	Pojazd * aa =  new Amfibia( "MBA 986", PredkoscMaksymalna(80), PredkoscMaksymalna(40) );
	const Motorowka * m = dynamic_cast<Motorowka*>(aa);
	const Samochod * s = dynamic_cast<Samochod*>(aa);  
	const Rower * r = dynamic_cast<Rower*>(aa);  
	sprawdzWskaznik(m);
	fotoradar(m);
	sprawdzWskaznik(s);
	fotoradar(s);
	sprawdzWskaznik(r);
	fotoradar(r);
	
	std::cout << std::endl;

    std::cout << "=====-===== 1 =====-=====" << std::endl;
	std::cout << "Na ladzie: v_max = " << s->predkoscMaksymalna() << std::endl;
	std::cout << "W wodzie:  v_max = " << m->predkoscMaksymalna() << std::endl;

    std::cout << "=====-===== 1 =====-=====" << std::endl;
	Amfibia * amfib = dynamic_cast<Amfibia*>(aa);
	std::cout << "Na ladzie: v_max = " << amfib->predkoscMaksymalna_Lad() << std::endl;
	std::cout << "W wodzie:  v_max = " << amfib->predkoscMaksymalna_Woda() << std::endl;

	delete ss; delete mm; delete aa;
}

/*********************************** OUTPUT ************************************
--------------------------------------------------------------------------------
=====-===== 1 =====-=====                                                       
Przykladowa predkosc maksymalna = 140 km/h                                      

=====-===== 1 =====-=====                                                       
ok ptr                                                                          
Typ pojazdu: Samochod <KRA 1234>                                                
=====-===== 1 =====-=====                                                       
null ptr                                                                        
Typ pojazdu: Motorowka <MB 234>                                                 
=====-===== 1 =====-=====                                                       
ok ptr                                                                          
Typ pojazdu: Rower <R44236>                                                     
                                                                                
=====-===== 4 =====-=====                                                       
ok ptr                                                                          
Typ pojazdu: Amfibia <MBA 986>                                                  
ok ptr                                                                          
Typ pojazdu: Amfibia <MBA 986>                                                  
null ptr                                                                        
Pojaz nierozpoznany.                                                            
                                                                                
=====-===== 1 =====-=====                                                       
Na ladzie: v_max = 80 km/h                                                      
W wodzie:  v_max = 40 km/h                                                      
=====-===== 1 =====-=====                                                       
Na ladzie: v_max = 80 km/h                                                      
W wodzie:  v_max = 40 km/h 
--------------------------------------------------------------------------------
*******************************************************************************/
