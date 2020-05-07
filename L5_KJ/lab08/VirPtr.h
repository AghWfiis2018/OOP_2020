#pragma once
#include "VirCode.h"

class VirPtr
{
public:
    VirPtr(VirCode *ptr) : m_ptr(ptr)
    {}
    
    VirPtr(VirPtr&& x) : m_ptr(std::move(x.m_ptr))
    {   x.m_ptr = nullptr;}
    
    ~VirPtr()
    {   delete m_ptr;}
    
    VirCode* operator->() const
    {   return m_ptr;}
    
    
private:
    VirCode* m_ptr;
};