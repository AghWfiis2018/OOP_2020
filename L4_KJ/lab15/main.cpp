#include "list.h"
#include "list.h"

#include <iostream>
#include <string>

int main() {
    std::cout << "=====-===== 3 =====-=====" << std::endl;
    std::cout << "Create List<int>" << std::endl;
    List<int> listInt;   
    for(int i = 0; i < 5; ++i)
    {
		listInt.push_back( i );
	}
    std::cout << "List<int> = " << listInt << std::endl;
    
    std::cout << "\n=====-===== 1 =====-=====" << std::endl;
    std::cout << "Delete last element" << std::endl;
    listInt.pop_back();
    std::cout << "List<int> = " << listInt << std::endl;
    
    std::cout << "\n=====-===== 1 =====-=====" << std::endl;
    std::cout << "Access front element (by reference)" << std::endl;
    listInt.front() = 10;   
    std::cout << "List<int>::front() = " << listInt.front() << std::endl;

    std::cout << "\n=====-===== 3 =====-=====" << std::endl;
    std::cout << "Copy list" << std::endl;
    const List<int> listIntSec = listInt;
    listInt.front() = 5; 
    std::cout << "List<int> = " << listInt << std::endl;
    std::cout << "List<int> = " << listIntSec << std::endl;


    std::cout << "\n\n===================================================" << std::endl;
    std::cout << "=====-===== 1 =====-=====" << std::endl;
    std::cout << "Create List<std::string>" << std::endl;
    const std::string staticArray[4] = {"Anna", "Elsa", "Olaf", "Zen"};
    List<std::string> listStr(4, staticArray);
    std::cout << "List<std::string> = "<< listStr << std::endl;       
    
    std::cout << "\n=====-===== 3 =====-=====" << std::endl;
    std::cout << "Iterators" << std::endl;
    for(List<std::string>::Iterator it = listStr.begin(); it != listStr.end(); ++it){     
        std::cout << "\tBefore: " << *it << std::endl;
        it->append(" Ice");												                
        std::cout << "\tAfter : " << *it << std::endl;
    }
    std::cout << "List<std::string> = "<< listStr << std::endl;
    
    std::cout << "\n=====-===== 1 =====-=====" << std::endl;
    std::cout << "Reverse iterators" << std::endl;
    for(List<std::string>::Iterator it = listStr.rbegin(); it != listStr.rend(); ++it){     
        std::cout << "\tIn reverse : " << *it << std::endl;
    }
    
    std::cout << "The end" << std::endl;
    return 0;
}

/*********************************** OUTPUT ************************************
--------------------------------------------------------------------------------
=====-===== 3 =====-=====
Create List<int>
List<int> = {"0", "1", "2", "3", "4"}

=====-===== 1 =====-=====
Delete last element
List<int> = {"0", "1", "2", "3"}

=====-===== 1 =====-=====
Access front element (by reference)
List<int>::front() = 10

=====-===== 3 =====-=====
Copy list
List<int> = {"5", "1", "2", "3"}
List<int> = {"10", "1", "2", "3"}


===================================================
=====-===== 1 =====-=====
Create List<std::string>
List<std::string> = {"Anna", "Elsa", "Olaf", "Zen"}

=====-===== 3 =====-=====
Iterators
	Before: Anna
	After : Anna Ice
	Before: Elsa
	After : Elsa Ice
	Before: Olaf
	After : Olaf Ice
	Before: Zen
	After : Zen Ice
List<std::string> = {"Anna Ice", "Elsa Ice", "Olaf Ice", "Zen Ice"}

=====-===== 1 =====-=====
Reverse iterators
	In reverse : Zen Ice
	In reverse : Olaf Ice
	In reverse : Elsa Ice
	In reverse : Anna Ice
The end
--------------------------------------------------------------------------------
*******************************************************************************/