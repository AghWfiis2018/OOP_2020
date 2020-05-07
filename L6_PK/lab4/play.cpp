/// \file play.cpp
///
/// **********************************************************************************
/// 
/// Mini gra Sapper. 
/// Patrz opis w pliku README.txt.
/// Dwa przykładowe wyjścia znajdują się w plikach 'play1.out', 'play2.out'
///
/// ---------------------------------------------------------------------------------

#include <iostream>

#include "board.h"
#include "sapper_board.h"
#include "game.h"
#include "sapper.h"

using namespace std;


// =======================================================================
int main() {

	cout << "\n";
	cout << "*************************************************************\n";
	cout << "Welcome to Sapper game.\n";
	string player;
	cout << "Say your name: "; cin >> player;
	cout << "OK " << player << ", choose the field size (X x Y) (min. 5x5, max. 20x20):\n";
	const int Nmax = 20;
	const int Nmin = 5;
	int X; // szerokość
	int Y; // długość
	cout << "X = "; cin >> X;
	cout << "Y = "; cin >> Y;
	X = (X>Nmax)? Nmax : X; X = (X<Nmin)? Nmin : X;
	Y = (Y>Nmax)? Nmax : Y; Y = (Y<Nmin)? Nmin : Y;
	int M; // liczba min
	int Mmax = X*Y/3; // maksymalna liczba min (jedna trzecia pól planszy)
	int Mmin = 2;
	cout << "Now choose the number of mines (min. " << Mmin << ", max. " << Mmax << "): ";
	cin >> M;
	cout << "\nSplendid. Let's play.\n\n";

	// tworzymy grę
	Game *game = new Sapper;
        game->new_player(player);	

	bool play = true;

	// główna pętla gry
	while (play) {

		cout << "---------------------------------------------------------------------\n";

		// ustaw parametry nowej planszy:
		Board *board = new SapperBoard(X,Y,M);
		// wygeneruj planszę
		game->new_board(*board);
		int x; // współrzędna x wskazanego pola
		int y; // współrzędna y wskazanego pola
		// pętla odkrywania pól
		do {
			// wydruk planszy
			game->print_board();
			cout << "\n";
			cin >> x; cin >> y;
		} while ((*game)(x,y));
		cout << "\nWant to play again? Type Y for yes.\n";
		char choice;
		cin >> choice;
		if (choice=='y' || choice=='Y') play=true;
		else play=false;
		delete board;
	}

	cout << "Bye bye. \n";

	delete game;

	
	
return 0;}
/// =======================================================================


