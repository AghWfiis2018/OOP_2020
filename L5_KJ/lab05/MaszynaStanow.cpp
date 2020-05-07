#include "MaszynaStanow.h"

MaszynaStanow::MaszynaStanow()
{}
MaszynaStanow::~MaszynaStanow()
{
    for (auto stan: m_stateList)    
        delete stan;
}




MaszynaStanow& MaszynaStanow::operator+=(Stan* addState)
{
    addState->setPointerToStateMachine(this);
    m_stateList.push_back(addState);
    return *this;
}


Stan& MaszynaStanow::operator()()
{
    return *m_stateList[m_currentState];
}


void MaszynaStanow::start()
{
    std::cout << "Rozpoczynamy dzialanie maszyny stanow!\n";
}

void MaszynaStanow::operator++()
{
    if (m_currentState < m_stateList.size() - 1)
        ++m_currentState;
}

void MaszynaStanow::operator--()
{
    if (m_currentState > 0)
        --m_currentState;
}

void MaszynaStanow::info()
{
    for (auto stan: m_stateList)    
        stan->podsumowanie();
}