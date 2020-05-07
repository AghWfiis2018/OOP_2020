#pragma once
#include <iostream>

class Osoba
{
public:
    Osoba(const std::string& name) : m_fullName(name)   // set name of a person
    {}
    virtual ~Osoba() = default;                         
    
    virtual std::string print() const = 0;              // virtual info getter
    
protected:
    std::string m_fullName;
};


