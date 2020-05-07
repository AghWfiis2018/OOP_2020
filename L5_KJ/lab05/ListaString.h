#pragma once
#include <iostream>
#include <string>
#include <vector>

class ListaString
{
public:
    ListaString();
    ListaString(ListaString&);
    ListaString(ListaString&&); 
    ~ListaString();   

    friend std::ostream& operator<<(std::ostream& output, const ListaString& list);
    friend ListaString& operator<<( ListaString& vec, std::string str);

    std::string operator[](unsigned int) const;


    static void rob_halas(bool isNoisy)
    {   m_noise = isNoisy; }

    static bool m_noise;

private:
    std::vector<std::string> m_sysNames {};
};

