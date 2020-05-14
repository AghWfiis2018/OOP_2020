#include "Postacie.h"
#include "Plansza.h"
#include "OpoznionyRysownik.h"
#include <iostream>

int main() 
{
    Bohater mario("Mario", 1, 3, 8);                                    // Imie, PosX, PosY, Punkty zycia
    std::cout << mario.opis() << std::endl;
    
    std::cout << "\n=====-===== 1 =====-=====" << std::endl;
    Plansza board;                                                      // Plansza 10 x 10
    board.dodaj(std::make_shared<Bohater>(mario));
    board.dodaj(std::make_shared<Koopa>(6, 7));                         
    board.dodaj(new Goomba(7, 1));                                      // PosX, PosY
    board.dodaj(std::shared_ptr<Goomba>(new Goomba(3, 2)));             // Prawie to samo co wyzej... tylko lepiej :)
    board.dodaj(std::make_shared<Goomba>(1, 5));                        // Prawie to samo co wyzej... tylko jeszcze lepiej :)
    board.dodaj(std::make_shared<Bohater>("Luigi", 7, 7, 7));
    board.dodaj(std::make_shared<Koopa>(2, 9));                         
    board.dodaj(std::make_shared<Goomba>(9, 5));                        
    board.listaPostaci();
            
    std::cout << "\n=====-===== 1 =====-=====" << std::endl;
    std::cout << "Przeciwnik poza plansza" << std::endl;
    board.dodaj(std::make_shared<Goomba>(20, 6));           
    
    std::cout << "\n=====-===== 1 =====-=====" << std::endl;
    std::cout << "Policz Goomby" << std::endl;
    std::cout << "Goombow jest " << board.policzGoomby() << std::endl;
       
    std::cout << "\n=====-===== 2 =====-=====" << std::endl;
    std::cout << "Uwaga na duplikaty! Specjalny kontener moze pomoc..." << std::endl;
    std::vector<std::string> legenda = static_cast<const Plansza>(board).przygotujLegende();
    
    for(auto l: legenda)
    {
        std::cout << l << std::endl;
    }
    
    {       
        const OpoznionyRysownik rysownik(board.postacie(), legenda);

        std::cout << "\n=====-===== 1 =====-=====" << std::endl;
        std::cout << "Zabijanie grzybow!" << std::endl;
        board.zabijGoomby();
        board.listaPostaci();
        
        std::cout << "\n=====-===== 1 =====-=====" << std::endl;        // To dlatego potrzebujemy shared_ptr
        std::cout << "A na rysunku sa grzyby... ale zaraz naprawde zgina!" << std::endl;
    }
   
    std::cout << "\n=====-===== 1 =====-=====" << std::endl;
    std::cout << "Posortowanie po X: " << std::endl;
    board.sortuj([](const Postac & p1, const Postac & p2){ return p1.posX() < p2.posX(); });
    board.listaPostaci();
    
    std::cout << "\n=====-===== 1 =====-=====" << std::endl;
    
    return 0;
}

/*********************************** OUTPUT ************************************
--------------------------------------------------------------------------------
Mario (1, 3) zycie = 8

=====-===== 1 =====-=====
Mario (1, 3) zycie = 8
Koopa (6, 7)
Goomba (7, 1)
Goomba (3, 2)
Goomba (1, 5)
Luigi (7, 7) zycie = 7
Koopa (2, 9)
Goomba (9, 5)

=====-===== 1 =====-=====
Przeciwnik poza plansza
Postac: Goomba (20, 6) jest poza plansza!
Wrog Goomba zginal rozdeptany.

=====-===== 1 =====-=====
Policz Goomby
Goombow jest 4

=====-===== 2 =====-=====
Uwaga na duplikaty! Specjalny kontener moze pomoc...
Bohaterowie: 
M - Mario (8)
L - Luigi (7)

Wrogowie:
G - Goomba
K - Koopa

=====-===== 1 =====-=====
Zabijanie grzybow!
Mario (1, 3) zycie = 8
Koopa (6, 7)
Luigi (7, 7) zycie = 7
Koopa (2, 9)

=====-===== 1 =====-=====
A na rysunku sa grzyby... ale zaraz naprawde zgina!
 \Y   0 1 2 3 4 5 6 7 8 9
 X\ +---------------------+
 0  | . . . . . . . . . . |    Bohaterowie: 
 1  | . . . . . . G . . . |    M - Mario (8)
 2  | . . G . . . . . . . |    L - Luigi (7)
 3  | M . . . . . . . . . |    
 4  | . . . . . . . . . . |    Wrogowie:
 5  | G . . . . . . . G . |    G - Goomba
 6  | . . . . . . . . . . |    K - Koopa
 7  | . . . . . K L . . . |
 8  | . . . . . . . . . . |
 9  | . K . . . . . . . . |
    +---------------------+
Wrog Goomba zginal rozdeptany.
Wrog Goomba zginal rozdeptany.
Wrog Goomba zginal rozdeptany.
Wrog Goomba zginal rozdeptany.

=====-===== 1 =====-=====
Posortowanie po X: 
Mario (1, 3) zycie = 8
Koopa (2, 9)
Koopa (6, 7)
Luigi (7, 7) zycie = 7

=====-===== 1 =====-=====
Bohater Mario przetrwal z liczba punktow zycia 8
Wrog Koopa zginal zepchniety.
Wrog Koopa zginal zepchniety.
Bohater Luigi przetrwal z liczba punktow zycia 7
Bohater Mario przetrwal z liczba punktow zycia 8
--------------------------------------------------------------------------------
*******************************************************************************/
