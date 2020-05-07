#include "ListaString.h"

bool ListaString::m_noise = false;


ListaString::ListaString()
{
    if (m_noise)
        std::cout << "(list-def-ctor)\n";
}

ListaString::ListaString(ListaString& x)
{
    if (m_noise)
        std::cout << "(list-copy-ctor)\n";
    
    m_sysNames = x.m_sysNames;
}
ListaString::ListaString(ListaString&& x) : m_sysNames(std::move(x.m_sysNames))
{
    if (m_noise)
        std::cout << "(list-move-ctor)\n";
}  

ListaString::~ListaString()
{
    if (m_noise)
        std::cout << "(list-dtor)\n";
}


std::ostream& operator<<(std::ostream& output, const ListaString& list)
{
    int i = 1;
    for (auto name : list.m_sysNames)
        output << "\t" << i++ << ". "<< name <<std::endl;

    return output;
}

ListaString& operator<<( ListaString& vec,const std::string str)
{
    vec.m_sysNames.push_back(str);
    return vec;
}

std::string ListaString::operator[](unsigned int index) const
{
    return m_sysNames[index];
}