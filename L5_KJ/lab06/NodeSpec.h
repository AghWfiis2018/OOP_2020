#pragma once
#include <iostream>
#include "Node.h"

class Node;


class NodeInt : public Node
{
public:
    NodeInt(int);
    ~NodeInt();
    int valInt();
    
    std::string toString() const override;
    NodeInt* clone() override;
    
private:
    int m_value; 
};


class NodeFloat : public Node
{
public:
    NodeFloat(float);
    ~NodeFloat();
    float valFloat();
    
    std::string toString() const override;
    NodeFloat* clone() override;
private:
    float m_float;
};


class NodeString : public Node
{
public:
    NodeString(std::string);
    ~NodeString();
    std::string valString();
    
    std::string toString() const override;
    NodeString * clone() override;
    
private:
    std::string m_str; 
};

