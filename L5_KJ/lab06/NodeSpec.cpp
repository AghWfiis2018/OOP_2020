#include "NodeSpec.h"
#include <string>

NodeInt::NodeInt(int val) : Node(), m_value(val)
{}

NodeInt::~NodeInt()
{}

int NodeInt::valInt()
{
    return m_value;
}
    
std::string NodeInt::toString() const 
{
    return std::to_string(m_value);
}

NodeInt* NodeInt::clone()
{
    return new NodeInt(m_value);
}

//--------------------------------------------------------------------------------------------------
NodeFloat::NodeFloat(float val) : Node(), m_float(val)
{}

NodeFloat::~NodeFloat()
{}

float NodeFloat::valFloat()
{
    return m_float;
}
    
std::string NodeFloat::toString() const 
{
    return std::to_string(m_float);
}

NodeFloat* NodeFloat::clone()
{
    return new NodeFloat(m_float);
}
//--------------------------------------------------------------------------------------------------

NodeString::NodeString(std::string val) : Node(), m_str(val)
{}

NodeString::~NodeString()
{}

std::string NodeString::valString()
{
    return m_str;
}
    
std::string NodeString::toString() const 
{
    return m_str;
}

NodeString* NodeString::clone()
{
    return new NodeString(m_str);
}
