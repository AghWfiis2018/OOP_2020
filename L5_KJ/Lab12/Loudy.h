#pragma once
#include <iostream>
#include <string>


class Loudy
{
public:
    Loudy(const std::string&);          // sets name of an object & 
                                        // & print info about constructed item 
    ~Loudy();                           // print info about destructed object
    void skip();                        // throw char type exception
    
private:
    std::string m_name;                 // stores name of an object 
};


class LoudyArray
{
public:
    LoudyArray(unsigned int);           // sets an dynamic array of Loudy*
                                        // type pointers with given length 
    ~LoudyArray();                      // free allocated memory
    
    void set(unsigned int, Loudy*);     // sets element of an m_array in 
                                        // a given position if possible
    
private:
    Loudy** m_array;                    // array of Loudy* objects
    unsigned int m_size;                // size of an array
};


class MyException                       // Class MyException provides 
                                        // memory leaks protection
{
public:
    MyException(LoudyArray*);           // takes a pointer to an object 
                                        // and stores it in m_ptr variable 
    ~MyException();                     // deallocating memory after m_ptr
private:
    LoudyArray* m_ptr;                  // stores a pointer to an object 
                                        // to be handled 
};