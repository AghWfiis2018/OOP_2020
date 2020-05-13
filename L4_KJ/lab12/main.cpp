#include "Loudy.h"
#include <iostream>

// bloskujemy uzycie std::vector
namespace std { class vector{}; }

int main ()
{
    try {
        std::cout << "=====-===== 1 =====-=====" << std::endl;
        Loudy test("Test");
        test.skip();
        
        std::cout << "Niewidzialny tekst" << std::endl;
        throw "Dziwny wyjatek - czy tak mozna?";
    }
    catch (...) { }

    std::cout << std::endl << std::endl;

    try {
        std::cout << "=====-===== 1 =====-=====" << std::endl;
        LoudyArray * p_array = new LoudyArray(3);
        p_array->set(0, new Loudy("First"));
        p_array->set(1, new Loudy("Second"));
        p_array->set(2, new Loudy("Third"));
        
        std::cout << "=====-===== 1 =====-=====" << std::endl;
        p_array->set(1, new Loudy("NewSec"));
        
        std::cout << "=====-===== 2 =====-=====" << std::endl;
        p_array->set(3, new Loudy("Fourth"));
        
        std::cout << "Chyba cos nie dziala, co nie?" << std::endl;
    }
    catch (...)
    {
        std::cout << std::endl << std::endl;
        std::cout << "=====-===== 2 =====-=====" << std::endl;
        std::cout << "Memory cleaning..." << std::endl;
    } 
    
    std::cout << "Good job!" << std::endl;
}

/*********************************** OUTPUT ************************************
--------------------------------------------------------------------------------
=====-===== 1 =====-=====                                                       
Laudy Test is waking up!                                                        
Laudy Test is going to sleep...                                                 


=====-===== 1 =====-=====                                                       
Laudy First is waking up!                                                       
Laudy Second is waking up!                                                      
Laudy Third is waking up!                                                       
=====-===== 1 =====-=====                                                       
Laudy NewSec is waking up!                                                      
Laudy Second is going to sleep...                                               
=====-===== 2 =====-=====                                                       
Laudy Fourth is waking up!                                                      
Laudy Fourth is going to sleep...                                               


=====-===== 2 =====-=====                                                       
Memory cleaning...                                                              
Laudy First is going to sleep...                                                
Laudy NewSec is going to sleep...                                               
Laudy Third is going to sleep...                                                
Good job!                                                                       
--------------------------------------------------------------------------------
*******************************************************************************/
