#pragma once

#include "Attributes.h"
#include "MyPrintable.h"


class MyLine : public AttColor, public MyPrintable
{
public:
    MyLine(const char&, const int&, const AttColor::Attribute&);  // sets color in base class AttColor, m_char and m_size
    ~MyLine() = default;
    
    std::string rawString() const;                  // returns string with m_size number of characters
    void setLength(const int&);                     // sets m_size of line
    void setChar(const char&);                      // sets m_char

private:
    char m_char;
    int m_size;
};