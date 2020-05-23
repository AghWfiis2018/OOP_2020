#include "Loudy.h"

Loudy::Loudy(const std::string& name) : m_name(name)
{
    std::cout << "Laudy " << m_name << " is waking up!\n";
}

Loudy::~Loudy()
{
    std::cout << "Laudy " << m_name << " is going to sleep...\n";
}

void Loudy::skip()
{
    throw 'a';        
}

////////////////////////////////////////////////////////////////////////////////////////
LoudyArray::LoudyArray(unsigned int size) : m_size(size)
{
    m_array = new Loudy*[size];
    
    for(unsigned int i = 0; i<size; ++i)
        m_array[i] = nullptr;
}

LoudyArray::~LoudyArray()
{
    for(unsigned int i = 0; i<m_size; ++i)
        delete m_array[i];
    
    delete[] m_array; 
}

void LoudyArray::set(unsigned int pos, Loudy* toSet)
{
    if(pos >= m_size)
    {
        delete toSet;
        throw MyException(this);
    }
    else
    {
        delete m_array[pos];
        m_array[pos] = toSet;
    }
}
////////////////////////////////////////////////////////////////////////////////////////
MyException::MyException(LoudyArray* ptr) : m_ptr(ptr)
{}

MyException::~MyException()
{
    delete m_ptr;
}

////////////////////////////////////////////////////////////////////////////////////////
