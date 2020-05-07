#include "MyLine.h"

MyLine::MyLine(const char& c, const int& size, const AttColor::Attribute& color) 
: AttColor(color),  m_char(c), m_size(size)
{}

std::string MyLine::rawString() const
{    return std::string(m_size, m_char); }

void MyLine::setLength(const int& newSize)
{    m_size = newSize;   }

void MyLine::setChar(const char& c)
{    m_char = c;    }