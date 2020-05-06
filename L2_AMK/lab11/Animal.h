#pragma once
#include <string>

// Tego pliku nie można modyfikować.
class Animal{
public:
	explicit Animal(const std::string &name):_name(name){}
	virtual ~Animal(){}
	std::string name()const{return _name;}
	virtual void print()const = 0;
private:
	std::string _name; // imię zwięrzęcia
};
