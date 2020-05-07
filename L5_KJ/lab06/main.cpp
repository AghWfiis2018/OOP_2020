#include "CyclicList.h"
#include "NodeSpec.h"
#include "Node.h"
#include <iostream>

std::string str(const Node * n)
{
	return n->toString();
}

int main()
{
	std::cout << "=====-===== 1 =====-=====" << std::endl;
	
	NodeInt *    nI = new NodeInt(7);
	NodeFloat *  nF = new NodeFloat(0.37);
	NodeString * nS = new NodeString("Kot");

	std::cout << "nI%4 = " << nI->valInt() % 4 << std::endl;
	std::cout << "nF*2 = " << nF->valFloat() * 2.0 << std::endl;
	std::cout << "nS   = " << nS->valString() << std::endl;
	
	std::cout << "=====-===== 1 =====-=====" << std::endl;				// Polimorfizm
	
	std::cout << "str(nI) = " << str(nI) << std::endl;
	std::cout << "str(nF) = " << str(nF) << std::endl;
	std::cout << "str(nS) = " << str(nS) << std::endl;

 	std::cout << "=====-===== 2 =====-=====" << std::endl;              // Klonowanie
	
	Node * copyS = nS->clone();
	std::cout << str(copyS) << " " << str(nS) << std::endl;
	nS->valString()[2] = 'c';			
	std::cout << str(copyS) << " " << str(nS) << "  (zamiana literki!)" <<  std::endl;
	delete copyS;

 	std::cout << "=====-===== 4 =====-=====" << std::endl;

	CyclicList clist;
	clist << nI << nF << nS;							     	        // Dodawanie do listy
	
	std::cout << "Cykliczna lista clist ma " << clist.count() << " elementy." << std::endl;
	std::cout << "Sa to: [ " << clist << "]" << std::endl;
	
 	std::cout << "=====-===== 2 =====-=====" << std::endl;				// Obracanie lista
	
 	std::cout << "Curent element = "  << clist()->toString() << std::endl;
	
	clist.rotate().rotate();
	std::cout << "Po przesunieciu 2 razy w przod:" << std::endl;
	std::cout << "Curent element = "  << clist()->toString() << std::endl;
	std::cout << "Cala lista     = [ " << clist << "]" << std::endl;

	clist.rotate_back();
	std::cout << "Po przesunieciu w tyl:" << std::endl;
	std::cout << "Curent element = "  << clist()->toString() << std::endl;
	std::cout << "Cala lista     = [ " << clist << "]" << std::endl;
		
	std::cout << "=====-===== 2 =====-=====" << std::endl;
	const CyclicList ccccc = clist;										// Konstruktor kopiujący
	clist << new NodeInt(0) << new NodeString("Dom");
	
	std::cout << "Nowa lista     = [ " << clist << "]" << std::endl;
	std::cout << "Backup listy   = [ " << ccccc << "]" << std::endl;

	return 0;
}

/*********************************** OUTPUT ************************************
--------------------------------------------------------------------------------
=====-===== 1 =====-=====
nI%4 = 3
nF*2 = 0.74
nS   = Kot
=====-===== 1 =====-=====
str(nI) = 7
str(nF) = 0.370000
str(nS) = Kot
=====-===== 2 =====-=====
Kot Kot
Kot Koc  (zamiana literki!)
=====-===== 4 =====-=====
Cykliczna lista clist ma 3 elementy.
Sa to: [ 7 0.370000 Koc ]
=====-===== 2 =====-=====
Curent element = 7
Po przesunieciu 2 razy w przod:
Curent element = Koc
Cala lista     = [ Koc 7 0.370000 ]
Po przesunieciu w tyl:
Curent element = 0.370000
Cala lista     = [ 0.370000 Koc 7 ]
=====-===== 2 =====-=====
Nowa lista     = [ 0.370000 Koc 7 0 Dom ]
Backup listy   = [ 0.370000 Koc 7 ]
--------------------------------------------------------------------------------
*******************************************************************************/