#pragma once

#include "ListaString.h"
#include "Stan.h"
#include <iostream>
#include <string>
#include <vector>

STATE_TYPE( DostepneSystemy ) {
public:
	DostepneSystemy(ListaString systems)
		: m_systList(std::move(systems))
		, m_selected(0)
	{
		
	}
	
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

STATE_TYPE( Instalacja ) {
public:
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