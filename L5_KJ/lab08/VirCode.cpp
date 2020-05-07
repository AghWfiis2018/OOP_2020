#include "VirCode.h"


VirCode::VirCode(const char *str)
{
    m_code = new char[std::strlen(str)+1]; 
    std::strcpy(m_code, str);
}

VirCode::VirCode(const VirCode& toCopy)
{
    m_code = new char[std::strlen(toCopy.m_code)+1]; 
    std::strcpy(m_code, toCopy.m_code);
}

VirCode::VirCode(VirCode&& toMove) : m_code(std::move(toMove.m_code))
{
    toMove.m_code = nullptr;
}

VirCode::~VirCode()
{
    delete[] m_code;
}

void VirCode::mutate() 
{             
    if( m_code && *m_code ) {
        char * c = m_code;
        char p = *c;
        while( *(++c) ) { 
            std::swap(p, *c);
        }
        std::swap(p, *m_code);
    }
}

VirCode&VirCode::operator=(VirCode& x)
{
    if(this == &x)
        return *this;

    delete[] m_code;
    m_code = new char[std::strlen(x.m_code)+1]; 
    std::strcpy(m_code, x.m_code);
    return *this;
}

VirCode&VirCode::operator=(VirCode&& x)
{
    if(this == &x)
        return *this;

    delete[] m_code;    
    m_code = std::move(x.m_code);
    x.m_code = nullptr;

    return *this;
}