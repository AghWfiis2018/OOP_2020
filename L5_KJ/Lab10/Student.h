#pragma once
#include "Osoba.h"
#include "NumerID.h"

class Student : virtual public Osoba
{
public:
    Student(const std::string& name, const NumerID& id)                     // sets unique ID of each strudent & name
    : Osoba(name), m_studentID(id)
    {}
    
    ~Student() {};
    
    std::string print() const                                               // returns formatted info of student
    {   return m_fullName + " - student (id " + m_studentID.getID() + ")";}
    
    std::string numID() const                                               // returns unique ID of student
    {   return m_studentID.getID();}
    
protected:
    NumerID m_studentID;                                                    // unique ID of each student
};
