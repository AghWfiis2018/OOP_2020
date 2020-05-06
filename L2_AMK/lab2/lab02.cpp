// Proszę napisać klasy: Path, która reprezentuje ścieżkę pliku
// oraz Symlink, która reprezentuje link symobliczny
// i które posiadają metody i przeciążone operatory:

// - operator /	do łączenia ścieżek
// - str 		zwraca ścieżkę jako zwykły string
// - parent		zwraca ścieżkę o 1 katalog wyżej jako string
// - operator->	do operacji na ścieżce, na którą wskazuje link

// Ponadto klasa Path posiada parametr informujący o tym, czy
// używany jest slash / (Unix), czy backslash \ (Windows)
// np. przy pomocy typów wyliczeniowych (enum)

// Uwagi:
// - przy wypisywaniu backslasha mamy "\\"
// - można korzystać z klasy std::string jeśli ktoś umie
//   (jeśli nie, to char* pamiętając o alokacji).
// - konkatenacja stringów: operator +
// - pomocne może być użycie w std::string np.:
//   tekst.substr(begin, len);
//	 tekst.find_last_of(pattern));
//   gdzie tekst, pattern są typu std::string, a begin, len typu int

// Skończone zadanie proszę spakować i wysłać na UPEL, np.
// tar -czvf lab02.tar.gz lab02

#include <iostream>
#include "Path.h"
#include "Symlink.h"

int main() {
	const Path home("/home/bruce"); 
	Path hobby = home / "hobby" / "oop";

	std::cout << home << std::endl;			 // Path(/home/bruce)
	std::cout << hobby << std::endl;		 // Path(/home/bruce/hobby/oop)
	std::cout << home.parent() << std::endl; // /home
	std::cout << home.str() << std::endl;	 // /home/bruce

	Symlink link("link_to_hobby", &hobby);

	std::cout << link->parent() << std::endl;// /home/bruce/hobby
	std::cout << link << std::endl;			 // Symlink(link_to_hobby)

	Path winpath("C:\\Users\\Public", Path::WIN);
	
	std::cout << winpath << std::endl;		 // Path(C:\Users\Public)
	std::cout << winpath / "Katalog" / "Podkatalog" << std::endl;	// Path(C:\Users\Public\Katalog\Podkatalog)

	winpath.reset(Path::UNIX);
	// dla tych, co się nudzą, albo do dokończenia w domu
	// std::cout << winpath << std::endl;	// Path(C:/Users/Public)
	
}
/* wyniki

Path(/home/bruce)
Path(/home/bruce/hobby/oop)
/home
/home/bruce
Symlink(link_to_hobby)
/home/bruce/hobby
Path(C:\Users\Public)
Path(C:\Users\Public\Katalog\Podkatalog)
Path(C:/Users/Public)

*/