#include "MyItem.h"

MyItem::MyItem(const std::string & name) 
    : m_name{name} 
{
    
}

MyItem::~MyItem() = default;

void MyItem::rename(const std::string & name)
{
    m_name = name;
}
    
void MyItem::printName(unsigned int op, char c) const
{
    std::cout << std::string(2*op, '-') << (op ? " " : "") << m_name << c << std::endl;        
}
