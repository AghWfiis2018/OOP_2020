/*
 Celem zadania jest przećwiczenie obsługi wyjątków.

 Metoda run klasy SecureCalc oblicza wartość danej funkcji 
 matematycznej z podanym argumentem.
 Proszę uzupełnić brakujące klasy.

 */

#include "SecureCalc.h"
#include "Functions.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

double legendre(int n, double x){
	if(n==0) return 1;
	else if(n==1) return x;
	else return ((2*n-1) * x * legendre(n-1, x) - (n-1) * legendre(n-2, x))/n;
}

double Log10::calc(double x)const{
	if(x>0) return std::log10(x);
	else throw std::domain_error("wrong argument of log10");
}

double Asin::calc(double x)const{
	if(std::abs(x) > 1) throw std::domain_error("wrong argument of arcsin");
	else return std::asin(x);
}

double Legendre::calc(double x)const{
	if(std::abs(x) > 1) throw std::domain_error("wrong argument of Legendre polynomial");
	return legendre(_n, x); // od c++17 mamy std::legendre
}

int main() {
	SecureCalc::run(Asin{}, 0.5);
	SecureCalc::run(Asin{}, M_PI/2);
	
	SecureCalc::run(Log10{}, 1e-10);
	SecureCalc::run(Log10{}, -20);
	
	SecureCalc::run(Legendre{2}, -0.4);
	SecureCalc::run(Legendre{2}, 1.6);
}

/* wynik

--- Calculation: arcsin(0.5)
==> result: 0.523599
--- Calculation: arcsin(1.5708)
failed: wrong argument of arcsin
--- Calculation: log10(1e-10)
==> result: -10
--- Calculation: log10(-20)
failed: wrong argument of log10
--- Calculation: Legendre polynomial(-0.4)
==> result: -0.26
--- Calculation: Legendre polynomial(1.6)
failed: wrong argument of Legendre polynomial

 */