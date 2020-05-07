#pragma once
#include <string>

class MyPrintable                               // virtual base class
{
public:
    virtual std::string rawString() const = 0;  // virtual function for inherited classes
};