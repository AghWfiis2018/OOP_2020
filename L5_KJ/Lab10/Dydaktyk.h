#pragma once
#include "Pracownik.h"
#include "NumerID.h"

class Dydaktyk : public Pracownik
{
public:
    Dydaktyk(const std::string&, const NumerID&);   // sets name and unique ID of teacher
    ~Dydaktyk();
    
    std::string print() const;                      // returns formatted info about teacher 
    std::string numID() const;                      // retruns formatted ID of the teacher
    
protected:
    NumerID m_teacherID;                            // stores teacher ID
};
