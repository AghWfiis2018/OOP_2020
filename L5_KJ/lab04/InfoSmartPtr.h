#pragma once
#include "InfoClass.h"

class InfoClass;                            // deklaracja wyprzedzajaca

class InfoSmartPtr
{
public:
    InfoSmartPtr(InfoClass *);              // Klasyczny konstruktor smartpointera 
    InfoSmartPtr(InfoSmartPtr&);            // konstruktor kopiujacy
    ~InfoSmartPtr();                        // destruktor zwalnia pamięć o ile żaden inny 
                                            // SmartPtr nie wskazuje na ten sam obiekt

    InfoClass& operator*() const;           // przeladowanie * 
    InfoClass* operator->() const;          // przeladowanie ->
    InfoSmartPtr& operator=(InfoSmartPtr&); // przeladowanie =. Kopiuje i inkrementuje licznik 
                                            // kopii obiektu na ktory SmartPtr wskazuje

private:
    InfoClass* m_ptr;
    int* m_copyCounter;
};