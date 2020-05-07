#include "Dydaktyk.h"

Dydaktyk::Dydaktyk(const std::string& name, const NumerID& id)
: Osoba(name), Pracownik(name), m_teacherID(id)
{}

Dydaktyk::~Dydaktyk() 
{}

std::string Dydaktyk::print() const
{
    return m_fullName + " - dydaktyk";
}

std::string Dydaktyk::numID() const
{
    return m_teacherID.getID();
}