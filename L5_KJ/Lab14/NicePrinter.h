#pragma once
#include <iostream>
#include <string>


class NicePrinter
{
public:
    NicePrinter(int);                                           // Constructor sets the width
                                                                // parameter of the stream out 
    void separator(int) const;                                  // prints out separating line 
    void header(std::string) const;                             // prints out header line 
    
    template<typename T> 
    void operator()(T toPrint) const                            // operator() template prints counter
                                                                // and given input variable of type T
    {
        std::cout << counter++ << ": " << toPrint << std::endl;
    }
    
private:
    static int counter;                                         // counting amount of uses operator()
};