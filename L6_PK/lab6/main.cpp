// *** Nie wolno modyfikować tego pliku ***

/*  ---------------------------------------------------------------------
*** Mały Genetyk 2 ***

Kontynuujemy zabawę z kodami DNA.

1. Przygotowania

a) w pierwszej kolejności należy zrobić upload wszystkich plików z 'Małego Genetyka 1'
   tj. potrzebujemy klasy: GeneSeq, DNA, Virus, CoronaVirus
b) Należy doposażyć klasę GeneSeq w operator konwersji do typu vector< Nucleotide >
c) Należy doposażyć klasę DNA w operator [], który pozwala na zwrócenie łańcucha 
   nukleotydów jako vector< Nucleotide >; przyjmijmy, że [0] zwraca łańcuch 
   z klasy podstawowej (zwany dalej 'górny'), [1] z klasy pochodnej (zwany dalej 'dolny').
d) Należy doposażyć klasy DNA i Virus/CoronaVirus w konstruktory pozwalające na utworzenie
   obiektu podając dna jako łańcuchy vector< Nucleotide > (o ile takich jeszcze nie ma);
   patrz fcja main.

2. klasa Organism

Należy napisać abstrakcyjną klasę implementującą dowolny żywy organizm posiadający kod DNA.
Klasa musi mieć co najmniej:
-- metodę zwracającą nazwę organizmu get_name()
-- metodę zwracającą kod DNA get_dna()
-- czysto wirtualną metodę 
   Organism* reproduce(Organism*)
   która implementuje mechanizm reprodukcji organizmów.
-- operator <<, będący fcją składową, którego argumentem jest obiekt klasy Virus
   Operator ten symuluje infekcję kodu DNA organizmu przez wirusa.
   Mechanizm infekcji jest następujący:
   Najpierw losujemy którą gałąź DNA infekuje wirus ('górną' [0], lub 'dolną' [1]),
   następnie losujemy miejsce w łańcuchu, gdzie kod genetyczny wirusa zastąpi kod
   nosiciela. 
   UWAGA: jeśli kod wirusa się nie mieści, zamazujemy początkowe nukleotydy nosiciela,
   na przykład:
	
   (nosiciel)         (wirus)
   TTGTCAACTTT         ACTG
   CTGATTGCAAG

   wirus wybiera 'górny' łańcuch, zamazując nukleotydy swoimi, od przedostatniej pozycji:

   (nosiciel)
   TGGTCAACTAC
   CTGATTGCAAG

   (dwa pierwsze nukleotydy zostały zamazane).


3. klasa Bacteria

Jest to klasa pochodna klasy Organism.
Klasa musi zawierać jako minimum:
-- metodę reproduce, która implemetuje następujący 'bezpłciowy' mechanizm reprodukcji:
   Bakteria się po prostu replikuje, czyli nowy osobnik ma identyczny kod DNA,
   przy czym podczas replikacji następuje mutacja. Polega ona na powieleniu losowego
   nukleotydu w losowej gałęzji DNA. Dla ułatwienia zaimplementowałem dla Państwa fcję 
   'mutation' w pliku 'gene_utils.h'.
-- konstruktor, który tworzy bakterię o podanej nazwie i kodzie DNA (patrz fcja main)

4. klasa Protozoa

Klasa pochodna klasy Organism, implementująca organizm pierwotniaków,
które rozmnażają się 'płciowo'.
Klasa musi zawierać jako minimum:
-- metodę reproduce, która implementuje następujący mechanizm reprodukcji:
   Obiekt 'this', dalej zwany rodzic1, łączy jedną gałąź swojego DNA 
   (powiedzmy 'górną' tj daną przez operator [0])
   z jedną gałęzią organizmu (rodzic2) będącego argumentem fcji 
   'reproduce' ('dolną', daną operatorem [1]).
   Na przykład:

    rodzic1    +   rodzic2     =   potomek
   AACTAACGGA     ATGGTCACAC      AACTAACGGA
   CTAGTTGAGG     AGAGATACAA      AGAGATACAA

   Na kodzie genetycznym potomka może zajść mutacja.
   UWAGA: należy zablokować możliwość rozmnażania z innymi gatunkami 
          (o innych nazwach zwracanych metodą get_name) -- patrz fcja main.

5. fcje z pliku 'gene_utils.h'

Są to fcje zaproponowane przez mnie, nie należy ich modyfikować. Konieczne jest użycie fcji 
'mutation' w reprodukcji jak opisano wyżej.
Fcja 'dna_test' testuje na obecność zadanego wirusa -- patrz fcja main.

Spodziewane wyjście podane jest na końcu pliku.

*/ //---------------------------------------------------------------------


#include <iostream>

#include "dna.h"
#include "coronavirus.h"
#include "organism.h"
#include "bacteria.h"
#include "protozoa.h"

using namespace std;




// =======================================================================
int main() {

	std::cout << "\n";

	srand(2323423421);// seed dla generatora liczb pseudo-losowych


	// -------------------------------------------
	
	// tworzymy organizm, typu Bacteria o zadanym kodzie DNA
	Organism* bact1 
		= new Bacteria("destructella",
			DNA( vector<Nucleotide>({A,T,A,A,T,A,G,A,G,T,A,T}),
			     vector<Nucleotide>({C,T,T,G,T,G,A,A,G,T,T,A}) )
			);	

	// rozmnażamy bakterie; bakterie rozmnażają się bezpłciowo przez powielenie
	Organism *bact2 = bact1->reproduce();

	// wydruk 
	cout << bact2->get_name() << "\n\n" << bact1->get_dna() << "\n" << bact2->get_dna() << "\n\n";


	// -------------------------------------------
	
	// tworzymy organizmy typu pierwotniak (Protozoa) o zadanym kodzie DNA
	Organism* prot1 
		= new Protozoa("amazonesis",
			DNA( vector<Nucleotide>({C,T,T,A,T,A,G,A,G,T,G,G,T,C,A,T}),
			     vector<Nucleotide>({A,G,T,G,T,G,G,T,C,A,A,A,G,T,T,A})  )
			);	
	Organism* prot2 
		= new Protozoa("amazonesis",
			DNA( vector<Nucleotide>({A,T,A,G,T,A,G,A,G,T,A,G,T,C,A,T}),
			     vector<Nucleotide>({A,A,T,T,A,G,A,T,C,T,A,C,G,T,T,A})  )
			);	

	// rozmnażamy pierwotniaki poprzez wymianę kodu DNA rodziców
	Organism* prot3 = prot1->reproduce(prot2);

	// wydruk
	cout << prot3->get_name() << "\n\n" << prot1->get_dna() << "\n" 
					  << prot2->get_dna() << "\n"
					  << prot3->get_dna() << "\n\n";


	// próba krzyżówki pierwotniaka i bakterii
	Organism* prot4 = prot1->reproduce(bact1);
	if (prot4) 
		cout << prot4->get_dna() << "\n";
	else 
		std::cout << "reproduce: mismatch species" << "\n\n";


	// -------------------------------------------
	
	// koronawirus o zadanym kodzie RNA
	CoronaVirus vir1("SCritt-12","rat",vector<Nucleotide>({U,C,A,U,C,A}));

	// wydruk
	cout << "\n" << *vir1.get_RNA() << "\n";

	// infekcja niektórych pierwotniaków wirusem
	*prot1 << vir1;
	*prot3 << vir1;
	
	cout << prot1->get_dna() << "\n" << prot3->get_dna() << "\n\n";

	// testujemy na obecność wirusa
	cout << "Test sample 1: " << dna_test(*prot3,vir1) << endl;
	cout << "Test sample 2: " << dna_test(*prot2,vir1) << endl;
	cout << "Test sample 3: " << dna_test(*prot3,vir1) << endl;


	std::cout << "\n";


	delete bact1; delete bact2;
	delete prot1; delete prot2; delete prot3; delete prot4;

return 0;}
/// =======================================================================

/* *** Spodziewane wyjście ***


destructella

A T A A T A G A G T A T 
| | | | | | | | | | | | 
C T T G T G A A G T T A 

A T T A T A G A G T A T 
| | | | | | | | | | | | 
C T T G T G A A G T T A 


amazonesis

C T T A T A G A G T G G T C A T 
| | | | | | | | | | | | | | | | 
A G T G T G G T C A A A G T T A 

A T A G T A G A G T A G T C A T 
| | | | | | | | | | | | | | | | 
A A T T A G A T C T A C G T T A 

A A T T A G G T C T A C G T T A 
| | | | | | | | | | | | | | | | 
C T T A T A G A G T G G T C A T 


reproduce: mismatch species


U C A U C A 

C A U C A A G A G T G G T C A U 
| | | | | | | | | | | | | | | | 
A G T G T G G T C A A A G T T A 

A A T T U C A U C A A C G T T A 
| | | | | | | | | | | | | | | | 
C T T A T A G A G T G G T C A T 


Test sample 1: 1
Test sample 2: 0
Test sample 3: 1


*/
