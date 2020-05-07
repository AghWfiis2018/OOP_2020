// *** Nie wolno modyfikować tego pliku ***
#pragma once

#include <vector>


/// Klasa abstrakcyjna implementująca interfejs 'terrorysty'.
class Terrorist {
public:

	/// Drukuje informacje na temat terrorysty i jego broni.
	/// Implementacja musi wykorzystać fcję print.
	virtual void what() const = 0;

	/// Metoda symulująca atak terrorysty.
	/// Atak następuje przy użyciu broni -- metod klas pochodnych
	/// klasy Weapon, które powinny być wywołane w implementacji tej fcji. 
	virtual void attack() const = 0;

	Terrorist(const std::string& name_):
		name(name_) { }
	
	virtual ~Terrorist() { }

protected:

	/// Nazwisko terrorysty
	std::string name;
	
	/// Alias dla wektora stringów
	typedef std::vector< std::string > weapons;

	/// Fcja drukująca nazwisko oraz nazwę broni terrorysty.
	/// Lista broni jest przekazana jako wektor stringów.
	void print(const weapons& w_) const { 
		std::cout << "This is " << name  << " carrying: ";
		size_t j=0;
	        for ( auto s : w_)
			std::cout << s << ( (++j<w_.size())? ", " : "." ) ;
		std::cout << std::endl; 
	}

	/// Prywatny konstruktor domniemany, do użytku tylko dla klas pochodnych
	Terrorist() { }
};