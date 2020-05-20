#include "LicznikPoziomow.h"
#include "Calc_error.h"

#include <iostream>
#include <stdexcept>

using namespace std;

struct Obliczenia{   
    static void Start(){
        try {           
            cout << "Zaczynamy obliczenia." << endl;
            Obliczenia::Poziom_1();
        } catch (std::runtime_error* err) {
            throw new Calc_error(err, "Wyjatek w Obliczenia::Start()", __FILE__, __LINE__);
        }
    }
    
    static void Poziom_1(){
        try {
            LicznikPoziomow licznik;
            Obliczenia::Poziom_2();
        } catch (std::runtime_error* err) {          
            throw new Calc_error(err, "Wyjatek w Obliczenia::Poziom_1()", __FILE__, __LINE__);
        }
    }
    
    static void Poziom_2(){
        try {
            LicznikPoziomow licznik;
            Obliczenia::NajglebszyPoziom();
        } catch (std::runtime_error* err) {          
            throw new Calc_error(err, "Wyjatek w Obliczenia::Poziom_2()", __FILE__, __LINE__);
        }
    }
            
    static void NajglebszyPoziom(){
        cout << "Najglebszy poziom." << endl;
        throw new std::runtime_error("Pojawil sie problem na najglebszym poziomie!");
    }
   
};


int main(int argc, char** argv) {
    try {
        std::cout << "=====-===== 1 =====-=====" << std::endl;
        Obliczenia::Start(); 
    } catch (...) {
        std::cout << "=====-===== 2 =====-=====" << std::endl;
        Calc_error::handler();
    }
    
    return 0;
}


/*********************************** OUTPUT ************************************
--------------------------------------------------------------------------------
=====-===== 1 =====-=====                                                       
Zaczynamy obliczenia.                                                           
Rozpoczynamy poziom numer 1.                                                    
Rozpoczynamy poziom numer 2.                                                    
Najglebszy poziom.                                                              
Konczymy poziom numer 2.                                                        
Konczymy poziom numer 1.                                                        
=====-===== 2 =====-=====                                                       
 Zlapano wyjatek:                                                               
 -- z powodu: Wyjatek w Obliczenia::Start(), [plik = main.cpp, linia = 15]      
 -- z powodu: Wyjatek w Obliczenia::Poziom_1(), [plik = main.cpp, linia = 24]   
 -- z powodu: Wyjatek w Obliczenia::Poziom_2(), [plik = main.cpp, linia = 33]   
 -- z powodu: Pojawil sie problem na najglebszym poziomie!                      
--------------------------------------------------------------------------------
*******************************************************************************/