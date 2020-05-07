#include "InfoClass.h"
#include <iostream>


InfoClass::InfoClass(const std::string& setString)
{   
    m_info = setString;
    std::cout << "Tworze obiekt InfoClass:" << info() << std::endl;
}


InfoClass::~InfoClass()
{
    std::cout << "Usuwam obiekt InfoClass:" << info() << std::endl;
}


std::string InfoClass::info() const
{   return " info = " + m_info;}

void InfoClass::info(const std::string & newInfo)  
{   m_info = newInfo;}

// ==================================================================================================================
//              InfoSuperClass
// ==================================================================================================================
InfoSuperClass::InfoSuperClass(const std::string& setString, int num) : InfoClass(setString), m_number(num)
{}

InfoSuperClass::~InfoSuperClass()
{}

std::string InfoSuperClass::info() const
{
    return InfoClass::info() + ", num = " + std::to_string(m_number);
}

