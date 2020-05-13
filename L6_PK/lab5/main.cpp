// *** Nie wolno modyfikować tego pliku ***

/*  ---------------------------------------------------------------------
*** Mały Genetyk ***

Zadanie polega na zaimplementowaniu następujących klas:

1. GeneSeq (gene_sequence.h)

Klasa implementuje dowolną sekwencję nukleotydów.
Nukleotydy są nowym typem enum.
UWAGA: deklaracja tej klasy oraz typu 'Nucleotide' jest dana (plik gene_sequence.h). 
Należy dopisać jedynie plik 'gene_sequence.cpp'.

2. DNA (dna.h)

Klasa pochodna klasy GeneSeq implementująca łańcuch DNA.
Łańcuch DNA jest ciągiem dwóch łańcuchów nukleotydów, połączonych słabymi wiązaniami.
Należy napisać minimalny kod implementujący tą klasę, tak aby program działał.

3. Virus (virus.h)

Klasa implemetuje wirus o następujących cechach:
-- zadanej nazwie
-- łańcuchu RNA (dynamiczny obiekt GeneSeq)
-- 'wiek' wirusa
   Wiek wirusa zwiększa się o jeden, po każdej replikacji (skopiowaniu konstr. kopiującym).
   Na przykład, jeśli wiek virusa vir1 wynosi 1, to nowy wirus vir2 utworzony przez
   instrukcję 'Virus vir2(vir1)' bedzie miał wiek 0, zaś vir1 wiek 2.

4. CoronaVirus (coronavirus.h)

Klasa pochodna klasy Virus, implementująca koronawirusy. 
Dodatkową cechą koronawirusów jest:
-- nazwa zwięrzęcia, które jest hostem wirusa

UWAGA 1: Odpowiednie klasy muszą posiadać nie-domyślne konstruktory 
         kopiujące/przenoszące oraz operatory=, aby program działał poprawnie.

UWAGA 2: Proszę pamiętać, o oprogramowaniu antyplagiatowym używanym na 
         platformie VPL -- proszę próbować samodzielnie.

UWAGA 3: Szczegóły implementacji klas należy odczytać z funkcji main().

Spodziewane wyjście podane jest na końcu pliku.

*/ //---------------------------------------------------------------------


#include <iostream>

#include "gene_sequence.h"
#include "dna.h"
#include "virus.h"
#include "coronavirus.h"

using namespace std;



/// Fcja pomocnicza, do sprawdzania konstruktora przenoszącego.
/// Nie należy się ją przejmować.
template<class T> T _copy_(T org) {
	return org; }


// =======================================================================
int main() {

	std::cout << "\n";

	// -------------------------------------------
	
	// tworzymy dwie sekwencje genów
	GeneSeq seq1a( vector<Nucleotide>({A,C,A,T,A,G,A,C,T,A,G,T,C,A,T}) );
	GeneSeq seq1b( vector<Nucleotide>({C,A,T,C,C,A,G,A,G,T,A,C,T,C,A}) );

	// tworzymy z nich DNA
	DNA dna1(seq1a,seq1b);

	cout << dna1;
	
	// -------------------------------------------
	std::cout << "\n";

	// tworzymy nowego wirusa (z pustą informacją o kodzie RNA)
	Virus vir1("ChPox-9");

	cout << vir1.get_name() << " " << vir1.get_RNA() << endl;
	
	// dodajemy sekwencję RNA
	vir1.set_RNA(vector<Nucleotide>({A,C,C,A,G,G,U,A,U,G,A}));
	cout << *vir1.get_RNA();

	// reprodukcja i 'stażenie się' wirusów
	// (użycie fcji _copy_ testuje przenoszenie)
	Virus vir2 = Virus(_copy_(vir1));
	Virus vir3(vir1);
	Virus vir4(_copy_(vir3));
	cout << vir4.get_age() << " " << vir3.get_age() << " " << vir1.get_age() << endl;	

	// -------------------------------------------
	std::cout << "\n";

	// tworzymy nowego koronawirusa, podając nazwę wirusa, nazwę zwierzęcia od którego pochodzi
	// oraz kod RNA
	CoronaVirus cvir1("Critt-12","Horseshoe bat",vector<Nucleotide>({U,C,A,A,A,C,C,U,C,A,U,C,A}));
	cout << cvir1.get_name() << endl;
	cout << "host: " << cvir1.get_animal_host() << endl;
	cout << *cvir1.get_RNA();
	CoronaVirus cvir2 = CoronaVirus() = CoronaVirus(_copy_(cvir1));
	cout << cvir2.get_age() << " " << cvir1.get_age() << endl;
	
	std::cout << "\n";

return 0;}
/// =======================================================================

/* *** Spodziewane wyjście ***

A C A T A G A C T A G T C A T 
| | | | | | | | | | | | | | | 
C A T C C A G A G T A C T C A 

ChPox-9 0
A C C A G G U A U G A 
0 1 2

Critt-12
host: Horseshoe bat
U C A A A C C U C A U C A 
0 1

*/
