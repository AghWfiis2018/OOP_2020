// *** Nie wolno modyfikować tego pliku ***
#pragma once

#include <string>


/// Implemetuje dowolny rodzaj broni.
/// Jest to typ abstrakcyjny (dlaczego?), ale dla ułatwienia bez fcji wirtualnych.
struct Weapon {

	/// Sposoby działania broni.
	/// Metody zostaną zasłonięte w klasach pochodnych.
	void shoot() const { };
	void cut() const { };
	void chop() const { };
	void explode() const { };

 protected:

	/// nazwa broni
	const std::string name;

	Weapon(const std::string& name_):name(name_) { }

 private:

	/// Prywatny konstruktor domyślny
	Weapon() { }
};



/// Implemetuje broń nóż
struct Knife: public Weapon {
	void cut() const {
		std::cout << "Slash!" << std::endl;
	}
	Knife():Weapon("Knife") { }
};



/// Implemetuje broń karabin
struct Rifle: public Weapon {
	void shoot() const  {
		std::cout << "Ratatatata!" << std::endl;
	}
	Rifle():Weapon("Rifle") { }
};	



/// Implemetuje broń bombę
struct Bomb: public Weapon {
	void explode() const  {
		std::cout << "Kaaaa-booooom!" << std::endl;
	}
	Bomb():Weapon("Bomb") { }
};



/// Implemetuje broń topór
struct Axe: public Weapon {
	void chop() const {
		std::cout << "Chop!" << std::endl;
	}
	Axe():Weapon("Axe") { }
};