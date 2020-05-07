#include "CyclicList.h"

CyclicList::CyclicList()
{
    m_head = nullptr;
    m_last = nullptr;
}

CyclicList::CyclicList(const CyclicList & toCopy)
{
    m_count = 0;
    m_head = m_last = nullptr;

    Node * n = toCopy.m_head;
    for(int i = 0; i<toCopy.m_count; ++i)
    {
        (*this)<<n->clone(); 
        n = n->next;
    }
}

CyclicList::~CyclicList()
{
    if(m_count > 0)
    {
        Node * prev = m_head;
        Node * n = m_head->next;
        for(int i = 0; i<m_count; ++i)
        {
            delete prev;
            if(i < m_count - 1)
            {
                prev = n;
                n = n->next;
            }
        }
    }
}

void CyclicList::addNode(Node* x)
{
    m_count++;
    if (m_head == nullptr)
        m_head = m_last = x;
    else
    {
        x->next = m_head;
        m_last->next = x;
        m_last = m_last->next;
    }
}
    
int CyclicList::count()
{
    return m_count;
}
    
CyclicList& CyclicList::rotate()
{
    m_head = m_head->next;
    m_last = m_last->next;
    return *this;
}
    
void CyclicList::rotate_back()
{
    Node*tmp = m_head;
    while(tmp->next != m_last)
        tmp = tmp->next;
    m_head = m_last;
    m_last = tmp;
}
    
CyclicList& CyclicList::operator<<(Node* x)
{
    this->addNode(x);
    return *this;
}

std::ostream& operator<<(std::ostream& out, const CyclicList& x)
{
    if(x.m_count > 0)
    {
        Node * temp = x.m_head;
    
        while(temp->next != x.m_head){
            out << temp->toString() << " ";
            temp = temp->next;   
        }
        out << temp->toString();
    }
    return out;
}