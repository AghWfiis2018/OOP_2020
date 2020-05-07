#pragma once
#include "Node.h"
class Node;

class CyclicList
{
public:
    CyclicList();
    CyclicList(const CyclicList &);
    ~CyclicList();
    
    void addNode(Node *);
    int count();
    CyclicList& rotate();
    void rotate_back();
    
    Node* operator()(){return m_head;}
    CyclicList& operator<<(Node*);
    friend std::ostream& operator<<(std::ostream&, const CyclicList&);
    
private:
    Node * m_head;
    Node * m_last;
    int m_count = 0;
};