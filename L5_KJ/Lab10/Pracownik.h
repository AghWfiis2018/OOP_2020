#pragma once
#include "Osoba.h"

class Pracownik : virtual public Osoba                  
{
public:
    Pracownik(const std::string& name) : Osoba(name)        // sets name of each person
    {}
    virtual ~Pracownik() = default;
    virtual std::string print() const = 0;
};
