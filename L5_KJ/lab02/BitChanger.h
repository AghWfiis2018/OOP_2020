#pragma once
#include "BitArray.h"
#include <iostream>

class BitChanger
{
public: 
    BitChanger(unsigned int , unsigned char &);
    /*
        BitChanger constructor takes 2 arguments. The first one is 
        an index of a bit in unsigned char that we want to change.  
    */
    ~BitChanger() {};                          // Nothing special to do so it does
    friend std::ostream& operator<<(std::ostream &, const BitChanger &); 
    /*
        provides an ability to print one bit of bit array
        from BitArray class.
    */
    void operator=(bool); 
    /*
        operator= gives ability to get change one bit of bit array
        from BitArray class.
    */
    operator bool() const;
    /*
        bool() provides an ability to get one bit of bit array
        from BitArray class.
    */
private:
    unsigned int m_bitPos;
    unsigned char & m_dataPtr;
};