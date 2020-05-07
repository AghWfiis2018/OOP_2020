#pragma once
#include <iostream>
#include "MaszynaStanow.h"
#define STATE_TYPE(klasa) class klasa: public Stan
class MaszynaStanow;

class Stan
{
public:
    virtual void setPointerToStateMachine(MaszynaStanow* ptr = nullptr) = 0;
    virtual void operator()() = 0;
    virtual const char* nazwa() const = 0;
    virtual void podsumowanie() const = 0;
    virtual ~Stan() = default;
};