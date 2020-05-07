#pragma once
#include "Student.h"
#include "Dydaktyk.h"

class Doktorant : public Student, public Dydaktyk
{
public:
    Doktorant(const std::string& name, const NumerID& studentID, const NumerID& teacherID)      // sets student & teacher ID & full name  
    : Osoba(name), Student(name, studentID), Dydaktyk(name, teacherID)
    {}

    ~Doktorant() {};
    
    std::string print() const                                                                   // returns formatted info about postgraduate
    {   return m_fullName + " - doktorant";}
    
    std::string numID_student() const                                                           // returns student ID
    {   return Student::numID();}
    
    std::string numID_dydaktyk() const                                                          // returns teacher ID
    {   return Dydaktyk::numID();}
    
};
