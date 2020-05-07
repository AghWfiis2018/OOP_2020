
Zadanie: Gra Saper

Celem zadania jest napisanie klas implementujących grę saper, na którą był boom w czasach Windows 3.11.
Kto nie zna gry -- proszę wejść na stronę http://gra-saper.pl/ i zobaczyć. Nie będe tutaj omawiał (prostych) zasad gry.

Oczywiście, nasza gra będzie działać w trybie tekstowym. Będzie też nieco uproszczona i niestety bardziej uciążliwa do zagrania, ze względu na konieczność podawania odkrywanych pól z klawiatury.

Struktura naszego programu będzie następująca:

1. Będą dwie klasy podstawowe, udostępniające ogólny interfejs dla abstrakcyjnej gry planszowej:

a) Klasa Game
Klasa zawiera funkcje:
   i) void new_player( <nazwa użytkownika> ) 
      Funkcja zapisuje nazwę gracza.
   ii) void new_board(const Board&)
       Czysto witualna funkcja, której realizacja w klasie pochodnej ma zdefiniować planszę gry. 
   iii) void print_board() 
        Funkcja czysto wirtualna, wyświetlająca aktualny stan planszy.
   iv) bool operator()(int x, int y)
       Czysto witualna funkcja wykonująca ruch na pole x,y na planszy. 

b) Klasa Board
Klasa zawiera czysto wirtualne metody:
   i) int get_geometry(int k)
      Funkcja zwraca k-ty całkowity parametr dowolnej planszy (np szerokość, długość, itp.)
   ii) double get_params(int k)
       Funkcja zwraca k-ty zmiennoprzecinkowy parametr planszy (np. ograniczenie czasu rozgrywki itp)

2. Klasy pochodne, realizujące konkretną grę saper

a) Klasa SapperBoard
Klasa pochodna klasy Board, która definiuje parametry gry saper.
W naszym przypadku ma to być plansza prostokątna o wymiarach min 5x5 max 20x20 zdefiniowanych przez użytkownika, 
oraz zadanej liczbie min (minimum 2, maximum: liczba pól planszy/3).
Fcja get_params nie będzie używana.

b) Klasa Sapper
Klasa pochodna klasy Game.
   i) funckja new_board(const Board& board) generuje planszę gry saper, wg geometrii zadanej obiektem klasy SapperBoard.
      Liczba min. określona w obiekcie board musi być rozmieszczona losowo na planszy.
      Proponuje następującą implementację planszy, którą wymyśliłem dla potrzeb tego ćwiczenia. 
      -- Plansza jest zaimplementowana jako obiekt klasy MyStuff::matrix (ten punkt JEST OBOWIĄZKOWY).
      -- Miny, rozmieszczone losowo są jakąś liczbą ujemną, np. -200
      -- Następnie należy wypełnić wszystkie pozostałe pola inną ujemną liczbą, np -100
      -- Następnie, musimy przebadać macierz, tak aby pola stykające się z miną, były powiększone o liczbę min, których pole dotyka.
         Np. pole sąsiadujące z 3 minami, musi mieć wartość -97
      -- Pola z ujemnymi liczbami, pozostają zakryte. Funkcja print_board musi drukować macierz zakrywając ujemne pola np. gwiazdką.
      -- Odkrycie pola (operatorem ()(int x, int y) ) powoduje dodanie do pola liczby 100 -- takie pole staje się widoczne.
         Chyba, że jest to mina -- wtedy następuje koniec gry.
   ii) fcja print_board
       Drukuje planszę w ten sposób, że pola nie wyeksplorowane są zakryte np gwiazdką.
   iii) fcja bool operator()(int x, int y)
        Reprezentuje eksploracje pola macierzy o współrzędnych x,y (zaczynając od zera, jak w tablicach C). 
        Wyeksplorowane pole zostaje odkryte (dodajemy liczbę 100 w moim algorytmie, o ile nie jest to mina, lub już odkryte pole).
        Jeśli następuje koniec gry (mina, lub zwycięstwo) fcja zwraca false, inaczej true.



Są dwa programy testujące:
a) main.cpp
   Służy do testowania klas. Wyjście powinno zgadzać się z plikiem test.out
b) play.cpp
   Implementacja gry. Zapis przykładowych rozgrywek znajduje się w pliku play1.out, play2.out. Niestety, nie widać jakie było wejście z klawiatury.
   Wejście z klawiatury znajduje się w plikach play1.in, play2.in.


UWAGI KOŃCOWE
1. Program nie jest tak skomplikowany jak wygląda, ale wymaga spokojnego przemyślenia.
2. Program jest dosyć krótki.
3. Aby tak było, należy oszczędnie programować. W szczególności, należy używać krótkich funkcji implemetujących różne czynności.
 
