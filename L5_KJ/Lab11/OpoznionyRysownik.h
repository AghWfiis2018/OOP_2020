#pragma once

#include "Postacie.h"
#include <vector>
#include <iostream>

    /* Plansza 10 x 10:
     \Y   0 1 2 3 4 5 6 7 8 9
     X\ +---------------------+
     0  | . . . . . . . . . . |    Bohaterowie:
     1  | . . . . . . . G . . |    M - Mario (8) 
     2  | . . . G . . . . . . |    L - Luigi (7)
     3  | . M . . . . . . . . |    
     4  | . . . . . . . . . . |    Wrogowie:  
     5  | . G . . . . . . . G |    G - Goomba
     6  | . . . . . . . . . . |    K - Koopa
     7  | . . . . . . K L . . |    
     8  | . . . . . . . . . . | 
     9  | . . K . . . . . . . | 
        +---------------------+   */

class OpoznionyRysownik {
using GrupaPostaci = std::vector<std::shared_ptr<Postac>>;

public:
    OpoznionyRysownik(const GrupaPostaci & grPost, std::vector<std::string> legenda)
        : m_grPost{grPost} , m_leg{std::move(legenda)} 
        {}
              
    ~OpoznionyRysownik() {
        // Przygotowanie planszy
        std::vector<std::string> splansza(13);
        splansza[0] = " \\Y   0 1 2 3 4 5 6 7 8 9";
        splansza[1] = " X\\ +---------------------+";
        for(auto y = 0u; y<10; ++y)
        {
            splansza[y + 2] = " " + std::to_string(y) + "  | . . . . . . . . . . |";
        }
        splansza.back() = "    +---------------------+";
        
        // Ustawianie pozycji na planszy
        for(auto & p: m_grPost)
        {
            splansza[p->posY() + 2][2*p->posX() + 4] = p->inicjal();
        }
        
        // Dodawanie legendy
        for(auto y = 0u; y<m_leg.size(); ++y)
        {
            splansza[y + 2] += "    " + m_leg[y];
        }
        
        // Rysowanie
        for(auto & sp: splansza)
        {
            std::cout << sp << std::endl;
        }
    }
            
private:
    GrupaPostaci m_grPost;
    std::vector<std::string> m_leg;
};
