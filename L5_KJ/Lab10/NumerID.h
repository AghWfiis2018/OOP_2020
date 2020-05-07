#pragma once
#include <iostream>

class NumerID
{
public:
    NumerID(const unsigned int&);                       // set ID number
    ~NumerID();

    std::string getID() const;                          // getter of formatted ID string
    
private:
    unsigned int m_ID;                                  // stores ID number
};


std::ostream& operator<<(std::ostream&, const NumerID&); // print formatted ID