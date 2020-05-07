#include "InfoSmartPtr.h"


InfoSmartPtr::InfoSmartPtr(InfoClass * ptr)
{
    m_ptr = ptr;
    m_copyCounter = new int(1);
}

InfoSmartPtr::InfoSmartPtr(InfoSmartPtr& toCopy)
{
    m_ptr = toCopy.m_ptr;
    m_copyCounter = toCopy.m_copyCounter;
    (*m_copyCounter)++;
}

InfoSmartPtr::~InfoSmartPtr()
{
    (*m_copyCounter)--;

    if(*m_copyCounter == 0)
    {
        delete m_ptr;
        delete m_copyCounter;
    }
        
}

InfoClass& InfoSmartPtr::operator*() const
{   return *m_ptr;}

InfoClass* InfoSmartPtr::operator->() const
{   return m_ptr;}
    

InfoSmartPtr& InfoSmartPtr::operator=(InfoSmartPtr& toCopy)
{
    // checking if toCopy is same as destination 
    if (this == &toCopy)
        return *this;

    // kind of destructor if there is no other copy 
    (*m_copyCounter)--;

    if(*m_copyCounter == 0)
    {
        delete m_ptr;
        delete m_copyCounter;
    }

    // number of copy++;
    m_ptr = toCopy.m_ptr;
    m_copyCounter = toCopy.m_copyCounter;
    (*m_copyCounter)++;
    

    return *this;
}

