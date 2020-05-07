#pragma once
#include <vector>
#include "Stan.h"


class MaszynaStanow
{
public:
    MaszynaStanow();
    ~MaszynaStanow();

    friend std::ostream& operator<<(std::ostream&, const MaszynaStanow& );

    MaszynaStanow& operator+=(Stan*);
    Stan& operator()();
    void operator++();
    void operator--();

    void start();
    void info();
private:
    std::vector<Stan*> m_stateList {};
    unsigned int m_currentState = 0;
};

inline std::ostream& operator<<(std::ostream& out, const MaszynaStanow& stateMachine)
{
    unsigned int it = 0;
    for (auto state : stateMachine.m_stateList)
    {
        if( it == stateMachine.m_currentState )
        {
            std::cout << ">" << state->nazwa() << "< ";
        }
        else
        {
            std::cout << state->nazwa() << " ";
        }
        ++it;
    }
    return out;
}