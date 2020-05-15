/* Ponieważ w czasach koronawirusa fryzjer jest na wagę złota, już teraz zdefiniujemy sobie kolejkę priorytetową, 
   która obsłuży nam niecierpliwych, zarośniętych klientów, przy czym w tym programie kobiety mają pierwszeństwo :).
   Oferowane są dwie niezależne usługi: fryzjer i makijaż (dla kobiet) albo golenie (dla mężczyzn), 
   ale kolejka jest jedna do wszystkich usług i opuszcza się ją dopiero po zrealizowaniu obu usług.
   Dmyślnie obie usługi są do obsłużenia.
   Zdefiniuj potrzebne klasy Person, Woman oraz Man z odpowiednimi metodami.
   Zdefiniuj również "kulturalną kolejkę", która puszcza przodem kobiety.
   Wykorzystaj std::priority_queue oraz potrzebne algorytmyi inne przydatne kontenery.
*/ 

#include "main.h"

int main() {
  QKolejka kolejka;
  kolejka.add (std::make_unique<Woman> ("Aga") );  // domyślnie potrzebuje strzyżenia i makijażu
  kolejka.add (std::make_unique<Man> ("Rysiek"));  // domyślnie potrzebuje strzyżenia i golenia
  kolejka.add (std::make_unique<Woman> ("Ewa"));
  kolejka.add (std::make_unique<Woman> ("Anna"));
  kolejka.add (std::make_unique<Man> ("Tomasz"));
  kolejka.add (std::make_unique<Woman> ("Ewa"));

  kolejka.print("W kolejce stoi:");

  std::cout << "\n*** Obcinamy wszystkie kobiety ***\n";
  // zwracamy wektor, ale całość mamy w kolejce
  std::vector<Woman*> women = kolejka.getWoman();
  for (const auto &ptr: women){
    ptr->makeup();      // malujemy wszystkie panie
  	std::cout << ptr->name() << " zostala umalowana" << std::endl;
  }
  // strzyzenie = false - nie potrzebuje, golenie = true - potrzebuje
  kolejka.add (std::make_unique<Man> ("Tomasz", true, false)); // potrzebuje strzyzenia, nie potrzebuje golenia
  kolejka.add (std::make_unique<Man> ("Piotr", false, true)); // nie potrzebuje strzyzenia, potrzebuje golenia
  kolejka.add (std::make_unique<Woman> ("Aga", true, true));  //potrzebuje strzyzenia, potrzebuje makijażu
  std::cout << "\n*** Zliczamy alfabetycznie imiona ***\n";
  kolejka.countNames();
  std::cout << "\n*** Malowanie i golenie ***";
  kolejka.haircut(); // obcinamy pierwszą Agę, juz jest umalowana, więc opuszcza kolejkę
  kolejka.haircut("Anna"); // Anna ma chody, weszła przed Ewą
  kolejka.haircut("Ewa"); // to samo co kolejka.haircut() -  obcinamy Ewę, opuszcza kolejkę
  kolejka.shave("Piotr"); // golimy Piotra i opuszcza kolejkę
  kolejka.shave("Rysiek"); //golimy Ryśka, został mu fryzjer, zostaje
  kolejka.shave("Tomasz"); //golimy Ryśka, został mu fryzjer, zostaje
  kolejka.shave("Rysiek"); // błąd
  std::cout << std::endl<< std::endl;
  kolejka.print("A teraz w kolejce stoi:");
  std::cout << "\n*** Zaklad zamkniety, pora sie zbierac.";
}
/* output
*** W kolejce stoi: ***
Aga nieobcieta i niepomalowana
Ewa nieobcieta i niepomalowana
Anna nieobcieta i niepomalowana
Ewa nieobcieta i niepomalowana
Rysiek nieobciety i nieogolony
Tomasz nieobciety i nieogolony

*** Obcinamy wszystkie kobiety ***
Aga zostala umalowana
Ewa zostala umalowana
Anna zostala umalowana
Ewa zostala umalowana

*** Zliczamy alfabetycznie imiona ***
Aga: 2
Anna: 1
Ewa: 2
Piotr: 1
Rysiek: 1
Tomasz: 2

*** Malowanie i golenie ***                 // kominikaty destruktora
Aga obcieta i pomalowana idzie na zakupy  
Anna obcieta i pomalowana idzie na zakupy
Ewa obcieta i pomalowana idzie na zakupy
Piotr obciety i ogolony idzie na piwko
!!! Juz ogolony !!!

*** A teraz w kolejce stoi: ***
Ewa nieobcieta i pomalowana
Aga nieobcieta i niepomalowana
Rysiek nieobciety i ogolony
Tomasz nieobciety i ogolony
Tomasz nieobciety i ogolony

*** Zaklad zamkniety, pora sie zbierac.
Ewa nieobcieta i pomalowana idzie na zakupy
Aga nieobcieta i niepomalowana  idzie na zakupy
Rysiek nieobciety i ogolony idzie na piwko
Tomasz nieobciety i ogolony idzie na piwko
Tomasz nieobciety i ogolony idzie na piwko
 */
