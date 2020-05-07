#include "BitChanger.h"



BitChanger::BitChanger(unsigned int bitPos, unsigned char & dataPtr) 
    : m_bitPos(bitPos), m_dataPtr(dataPtr)
{}

void BitChanger::operator=(bool inputBool)
{
    if (inputBool)
        m_dataPtr |= 1 << m_bitPos;
    else 
        m_dataPtr &= ~(1 << m_bitPos);
}

BitChanger::operator bool() const
{
    return static_cast<bool>( m_dataPtr & (1 << m_bitPos) );
}


std::ostream& operator<< (std::ostream & out, const BitChanger & theBit)
{
    bool result = theBit;
    out << result;
    return out;
}