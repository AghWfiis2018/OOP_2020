/// \file main.cpp
///
/// \n\n
///
/// **********************************************************************************
/// 
/// Program testowy dla klas implementujących grę Saper.
/// Patrz plik README.txt.
/// Wyjście tego programu znajduje się w pliku 'test.out'.
///
/// ----------------------------------------------------------------------------------
///
///    \n\n


#include <iostream>

#include "board.h"
#include "sapper_board.h"
#include "game.h"
#include "sapper.h"

using namespace std;




// =======================================================================
int main() {

	srand(1343375771);// seed dla generatora liczb pseudolosowych

	std::cout << "\n";

	// Definiujemy nową (pustą) grę. Plansza zostaje utworzona później.
	Game *game1 = new Sapper;

	// Ustawmy nazwę użytkownika.
	game1->new_player("Waldek");

	// Tworzymy obiekt opisujący całkowito-liczbowe parametry planszy
	// Pierwsze dwie liczby to wymiary X,Y, trzeci parametr to liczba min.
	Board *board = new SapperBoard(4,5,4);

	// Używamy obiektu board do wygenerowania planszy gry saper
	game1->new_board(*board);

	// Drukujemy aktualny stan planszy. Wszystkie pola powinny być zakryte.
	game1->print_board();

	// Odkrywamy jakieś pole, np. o x=0 i y =1
	(*game1)(0,1);

	// Drukujemy nowy stan planszy:
	game1->print_board();

	// Kolejne ruchy	
	(*game1)(1,1);
	(*game1)(0,2);
	(*game1)(1,2);
	(*game1)(2,2);
	(*game1)(2,1);
	(*game1)(1,1);
	game1->print_board();

	// Ten ruch powinien być niedozwolony
	(*game1)(10,2);

	// Ten ruch powinien zakończyć się eksplozją	
	(*game1)(0,0);


	delete board;
	delete game1;

return 0;}
/// =======================================================================


