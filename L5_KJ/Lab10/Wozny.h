#pragma once
#include "Pracownik.h"

class Wozny : public Pracownik
{
public:
    Wozny(const std::string& name) : Osoba(name), Pracownik(name)   // sets full name of janitor
    {}
    ~Wozny() {};
    
    std::string print() const                                       // returns formatted info about janitor
    { return m_fullName + " - wozny";}

};
