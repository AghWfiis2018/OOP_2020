#pragma once
#include <iostream>
#include "VirCode.h"
class VirCode;

class Virus
{
public:
    Virus(const VirCode&);              // Copy constructor | sets m_code from VirCode
    Virus(VirCode&&);                   // Move constructor | sets m_code from VirCode
    Virus(Virus&);                      // Copy constructor | creates m_code form other Virus
    Virus(Virus&&);                     // Move constructor | creates m_code form other Virus
    
    ~Virus();                           // Loudly destructor
    
    Virus&operator=(Virus&);            // Copy assignment operator | spreads m_code form other Virus
    Virus&operator=(Virus&&);           // Move assignment operator | spreads m_code form other Virus
    friend std::ostream&operator<<(std::ostream&, const Virus&);    // overloaded << prints info about Virus
    
private:
    VirCode m_data;                      // m_data stores genetic code of Virus
    int m_age;                           // age of Virus. Increase when spreads.
};