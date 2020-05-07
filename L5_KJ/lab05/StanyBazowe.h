#pragma once

#include "ListaString.h"
#include "Stan.h"
#include <string>
#include <vector>

class ListaString;

STATE_TYPE( DostepneSystemy ) 
{
public:
	DostepneSystemy(ListaString systems) : m_systList(std::move(systems)),
		                                   m_selected(0)
	{
		
	}

	virtual void setPointerToStateMachine(MaszynaStanow* ptr = nullptr)
    {   return;}

	virtual void operator()() {
		std::cout << "Program mozna uruchomic na nastepujacych systemach: " << std::endl;
		std::cout << m_systList;
		
		//std::cin >> m_selected; 
		m_selected = 1; // <- udajemy wczytywanie danych
		
		std::cout << "wybrano \'" << m_systList[m_selected] << "\'" << std::endl;
	}
	
	virtual const char* nazwa() const { 
		return "DostepneSystemy";
	}
	
	virtual void podsumowanie() const {
		std::cout << " * Wybrano system: \'" << m_systList[m_selected] << "\'" << std::endl;;
	}
	
private:
	ListaString  m_systList;
	unsigned int m_selected;
};



STATE_TYPE( Instalacja ) 
{
public:
	virtual void setPointerToStateMachine(MaszynaStanow* ptr = nullptr)
    {   return;}

	virtual void operator()() {
		std::cout << "Instalacja w toku... " << std::endl;
		std::cout << "OK!" << std::endl;
	}
	
	virtual const char* nazwa() const { 
		return "Instalacja";
	}
	
	virtual void podsumowanie() const {
		return;
	};
};



STATE_TYPE( ZbieranieDanych ) 
{
public:
    ZbieranieDanych(const std::string dataTitle) : m_dataTitle(dataTitle)
    {} 

	virtual void setPointerToStateMachine(MaszynaStanow* ptr = nullptr)
    {   return;}

	virtual void operator()() 
    {
		std::cout << "Prosze podac dana: Adres email = ";
        // std::string str;
        // std::cin >> str;     ------> Nowak@mail.com
        m_mail = "Nowak@mail.com";
		std::cout << ", podano '" << m_mail << "'" <<std::endl;
	}
	
	virtual const char* nazwa() const { 
		return "ZbieranieDanych";
	}
	
	virtual void podsumowanie() const {
		std::cout << " * Adres email = " << m_mail << std::endl;
	};

private:
    std::string m_dataTitle;
    std::string m_mail;
};



STATE_TYPE( Podsumowanie ) 
{
public:
    Podsumowanie()
    {} 

	virtual void setPointerToStateMachine(MaszynaStanow* ptr = nullptr)
    {
        m_ptr = ptr;
    }

	virtual void operator()() 
    {
        std::cout << "Podsumowanie:\n";
        m_ptr->info();
	}
	
	virtual const char* nazwa() const { 
		return "Podsumowanie";
	}
	
	virtual void podsumowanie() const {
        return;
	};
private:
    MaszynaStanow* m_ptr = nullptr;

};
