#pragma once
#include "BitChanger.h"
#include <iostream>

class BitChanger;


class BitArray
{
public:
    BitArray(unsigned int , bool );                 
    /* 
        BitArray class constructor alocates new array of unsignetd int N
        bits. By default all bits are zeros.
    */

    ~BitArray();
    /*
        BitArray destructor. Free memory after alocating const char array.
    */
    void print() const;
    /*
        print() functions prints in commandline as exaple shows.
    */
    BitChanger operator[](unsigned int) const;
    /*
        overloaded operator[] returns object class BitChanger 
        to unlock ability of cahnging one bit in an array of unsigned chars. 
    */
    BitArray *operator=(const BitArray &);
    /*
        overloaded operator= creates a copy of given object. 
    */

private:
    unsigned char * m_data;
    unsigned int m_size;
};


inline BitArray::BitArray(unsigned int size, bool onesOrZeros = 0) 
{
    m_size = size;
    unsigned int numberOfChars = (size / 8) + 1;
    m_data = new unsigned char [numberOfChars];

    for (unsigned int i = 0; i<numberOfChars; ++i )
    {
        if (onesOrZeros)
            m_data[i] = 0xFF;
        else
            m_data[i] = 0x00;
    }
}

inline BitArray::~BitArray()
{
    delete [] m_data;
}