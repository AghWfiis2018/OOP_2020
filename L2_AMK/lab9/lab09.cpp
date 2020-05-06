/*
 Celem zadania jest przećwiczenie dziedziczenia wielokrotnego. 
 W tym celu stworzymy hierarchię klas reprezentujących obiekty graficzne.

 Dodatkowo, mają one swoje własności (można je np. rysować, przesuwać), 
 ale tylko jeśli dziedziczą po odpowiednich klasach. 

 Proszę na podstawie wyniku wywnioskować, jaka jest hierarchia klas
 oraz napisać niezbędne funkcje.
 W dokumentacji proszę uzasadnić hierarchnię. Bez tego dokumentacja nieważna.

 */

#include <iostream>
#include "Main.h"

int main() {
	const Point p(1.5, 2.0);
	std::cout << p << std::endl;

	Circle circ(p, 3); // kolo o promieniu 3 i srodku p
	Line line(Point(2, 3), Point(1, 2)); // linia od punktu (2, 3) do (1, 2)
	Rectangle rec(Point(3, 3), Point(1, 4)); // prostokąt o rogach w (3, 3) i (1, 4)

	unsigned numObj = 3;
	Drawable *obj[]{&circ, &line, &rec};
	for (unsigned i = 0; i < numObj; ++i){
		draw(obj[i]); 

		Transformable *t = dynamic_cast<Transformable*>(obj[i]);
		if(t) t->shift(1.0, 1.0);
		draw(obj[i]); 

		const ClosedShape *shape = dynamic_cast<const ClosedShape*>(obj[i]);
		if(shape) std::cout << "--- area = " << shape->area() << "\n";
	}
	Transformable *t = &rec;
	t->shift(2.0, 2.0);

	#ifdef ERROR1
	Drawable* d = t; // ma powodować błąd komilacji: "cannot convert ..."
	#endif
	#ifdef ERROR2
	Transformable* t2 = obj[0]; // ma powodować błąd komilacji: "cannot convert ..."
	#endif
}

/* wynik 

(1.5, 2)
++ Rysuje kolo o srodku (1.5, 2) i promieniu 3
++ Rysuje kolo o srodku (2.5, 3) i promieniu 3
--- area = 28.2743
++ Rysuje linie od (2, 3) do (1, 2)
++ Rysuje linie od (3, 4) do (2, 3)
++ Rysuje prostokat o rogach w (3, 3) i (1, 4)
++ Rysuje prostokat o rogach w (4, 4) i (2, 5)
--- area = 2

 */
