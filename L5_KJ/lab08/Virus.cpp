#include "Virus.h"

Virus::Virus(const VirCode& toCopy) : m_data(toCopy), m_age(0)
{
    std::cout << "Created new virus{ " << m_age  << ", <" << m_data.c_str() << "> } (code copied)\n";
}

Virus::Virus(VirCode&& toMove) : m_data(std::move(toMove)), m_age(0)
{
    std::cout << "Created new virus{ " << m_age  << ", <" << m_data.c_str() << "> } (code moved)\n";
}

Virus::Virus(Virus& toCopy) : m_data(toCopy.m_data), m_age(toCopy.m_age)
{
    toCopy.m_age++;
    m_data.mutate();
}

Virus::Virus(Virus&& toMove) : m_data(toMove.m_data), m_age(0)
{}
    
Virus::~Virus()
{
    std::cout << "Killed virus{ "<< m_age << ", <" << m_data.c_str() << "> }\n";
}

Virus&Virus::operator=(Virus& toCopy)
{
    if(this == &toCopy)
        return *this;

    m_age = toCopy.m_age;
    m_data = toCopy.m_data;
    
    toCopy.m_age++;
    return *this;
}

Virus&Virus::operator=(Virus&&toMove)
{
    if(this == &toMove)
        return *this;
        
    m_age = toMove.m_age;
    m_data = toMove.m_data;
    
    return *this;
}

std::ostream&operator<<(std::ostream& out, const Virus& x)
{
    return out << "virus{ " << x.m_age << ", <" << x.m_data.c_str() << ">}";
}