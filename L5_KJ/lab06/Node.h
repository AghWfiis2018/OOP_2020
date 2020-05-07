#pragma once
#include <iostream>

class Node
{
public:
    Node();
    virtual ~Node();
    
    virtual std::string toString() const = 0;
    virtual Node *clone() = 0;
    Node *next;    
};