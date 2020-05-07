#pragma once

#include <cstring>
#include <utility>

// Używanie kontenerów z biblioteki standerdowej jest w tym pliku zabronione
// Należy napisać własny kontener, bazując na surowych wskaźnikach
// Klasa std::string też jest kontenerem!

// Funkcja std::strlen(const char * cstr) zwraca długość cstring (nie licząc '\0')
// Funkcja std::strcpy(char * destination, const char * source) kopuje znaki (w tym znak '\0')

class VirCode {
public:
    VirCode(const char *);      // Constructor that sets m_code variable
    VirCode(const VirCode&);    // Copy constructor
    VirCode(VirCode&&);         // Move constructor
    ~VirCode();                 // Destructor delete m_code variable

    VirCode&operator=(VirCode&);    // copy operator=. 
    VirCode&operator=(VirCode&&);   // move operator=
    

    void mutate();              // rotates genetic code 
    char* c_str()               // print output
    {   return m_code;}
    const char * c_str() const  // return m_code
    {   return m_code;}

private:
    char * m_code;              // variable that stores nucleotides
};
