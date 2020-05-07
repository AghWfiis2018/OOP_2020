#include "NumerID.h"
#include <string>

std::ostream& operator<<(std::ostream& out, const NumerID& id)
{
    return out << id.getID();
}


NumerID::NumerID(const unsigned int& newID) : m_ID(newID)
{}
    
NumerID::~NumerID()
{}

std::string NumerID::getID() const
{
    std::string result("<");
    
    std::string tmp = std::to_string(m_ID);
    size_t size = tmp.length(); 
    
    while (size < 6)
    {
        result += "0";
        size++;
    }
    result += tmp + ">";
    return result;
}