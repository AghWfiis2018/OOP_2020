#pragma once

// Liczba mnoga - postacie - jest poprawna - prof. Miodek potwierdza. 
// Liczba mnoga - postaci - tez, ale jakby troche mniej. 

#include <string>
#include <iostream>

class Postac {
public:
    Postac(int x, int y)
        : m_x{x}, m_y{y} {}
        
    virtual ~Postac(){}
    
    virtual std::string imie() const = 0;
  
    virtual std::string opis() const 
    {
        return imie() + " (" + std::to_string(m_x) + ", " + std::to_string(m_y) + ")";
    }

    virtual char inicjal() const { return imie()[0];}

    int posX() const { return m_x; };
    int posY() const { return m_y; };
    
private:
    int m_x;
    int m_y;
};

class Bohater : public Postac {
public:
    Bohater(std::string imie, int x, int y, unsigned int zycie)
        : Postac{x, y}, m_imie{std::move(imie)}, m_zycie{zycie} {}
    
    virtual ~Bohater() { std::cout << "Bohater " << m_imie << " przetrwal z liczba punktow zycia " << m_zycie << std::endl; }
    
    virtual std::string imie() const { return m_imie; }
    
    virtual std::string opis() const { return Postac::opis() + " zycie = " + std::to_string(m_zycie);}
    
    unsigned int zycie() const { return m_zycie; };
    
private:
    std::string m_imie;
    unsigned int m_zycie;
};

class Wrog : public Postac {
public:
    Wrog(int x, int y) 
        : Postac{x, y} {}
        
    virtual ~Wrog() {}
};

class Goomba : public Wrog {
public:
    Goomba(int x, int y) 
        : Wrog{x, y} {}
        
    virtual ~Goomba() { std::cout << "Wrog Goomba zginal rozdeptany." << std::endl; }
        
    virtual std::string imie() const { return "Goomba"; }
};

class Koopa : public Wrog {
public:
    Koopa(int x, int y) 
        : Wrog{x, y} {}
        
    virtual ~Koopa() { std::cout << "Wrog Koopa zginal zepchniety." << std::endl; }
        
    virtual std::string imie() const { return "Koopa"; }
};
