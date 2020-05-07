#include "MyFile.h"
#include "MyDir.h"
#include "MyUnique.h"
#include <iostream>

// Destruktor MyDir ma być pusty
MyDir::~MyDir() = default;

MyUnique makeUnique(MyItem * item)
{
    return MyUnique(item);
}

MyUnique createSrc()
{
    MyDir *src = new MyDir("src");
    *src /= new MyFile("Class.h");
    *src /= new MyFile("Class.cpp");    
    
    return MyUnique(src);
}

int main()
{
    {
        std::cout << "=====-===== 2 =====-=====" << std::endl;          // Przykładowy plik
        MyFile * myFile = new MyFile("base.txt");
        *myFile << "Ala ma kota" << "a kot ma Ale";
        myFile->cat();

        std::cout << "=====-===== 2 =====-=====" << std::endl;          // Unikalny wskaźnik          
        MyUnique uniq{ myFile };
        uniq->ls();
    }
    {
        std::cout << "=====-===== 2 =====-=====" << std::endl;          // Przenoszenie wskaźnika - konstruktor
        MyUnique uniqOld( new MyFile("base.txt") );
        MyItem * addrOld = uniqOld.get();
        std::cout << "uniqOld = "; uniqOld->ls(); 

        MyUnique uniqNew( std::move(uniqOld) );
        MyItem * addrNew = uniqNew.get();
        std::cout << "uniqNew = "; uniqNew->ls(); 
        
        std::cout << "addrOld " << (addrOld == addrNew ? "==" : "!=") << " addrNew" << std::endl;
        std::cout << "new old address " << uniqOld.get() << std::endl;
    }
    {
        std::cout << "=====-===== 2 =====-=====" << std::endl;          // Przenoszenie wskaźnika - operator
        MyUnique uniqOld( new MyFile("base.txt") );
        MyUnique uniqNew( new MyFile("test.txt") );
        std::cout << "uniqNew = "; uniqNew->ls(); 
                    
        uniqNew = std::move( uniqNew );
        std::cout << "uniqNew = "; uniqNew->ls(); 

        uniqNew = std::move( uniqOld );
        std::cout << "uniqNew = "; uniqNew->ls(); 
        std::cout << "new old address " << uniqOld.get() << std::endl;
    }
    #ifdef MY_EXPECTED_ERROR                                           // Unikalnego wskaźnika nie można kopiować
    {
        MyUnique p( new MyFile("unique.txt") );
        MyUnique a = p;
    }
    #endif

    std::cout << "=====-===== 2 =====-=====" << std::endl;
    MyDir ppo("PPO");
    ppo /= new MyFile("main.cpp");
    ppo.ls();

    std::cout << "=====-===== 2 =====-=====" << std::endl;
    ppo /= makeUnique( new MyFile("makefile") );
    ppo.ls();

    // src
    std::cout << "=====-===== 2 =====-=====" << std::endl;
    MyUnique srcDir = createSrc();
    srcDir->ls();
    
    ppo /= std::move(srcDir);
    ppo.ls();

    // copy
    std::cout << "=====-===== 4 =====-=====" << std::endl;   
    MyUnique copyDir{ new MyDir(ppo) };
    copyDir->rename("COPY");

    ppo /= new MyDir("build");
    
    ppo.ls();
    std::cout << std::endl;
    copyDir->ls();
    
    // move
    std::cout << "=====-===== 2 =====-=====" << std::endl;   
    MyUnique moveDir{ new MyDir( std::move(ppo) ) };
    moveDir->rename("MOVE");

    ppo /= new MyDir("build");
    
    ppo.ls();
    std::cout << std::endl;
    moveDir->ls();

    return 0;
}

/*********************************** OUTPUT ************************************
--------------------------------------------------------------------------------
=====-===== 2 =====-=====
Ala ma kota
a kot ma Ale
=====-===== 2 =====-=====
base.txt
=====-===== 2 =====-=====
uniqOld = base.txt
uniqNew = base.txt
addrOld == addrNew
new old address 0
=====-===== 2 =====-=====
uniqNew = test.txt
uniqNew = test.txt
uniqNew = base.txt
new old address 0
=====-===== 2 =====-=====
PPO/
-- main.cpp
=====-===== 2 =====-=====
PPO/
-- main.cpp
-- makefile
=====-===== 2 =====-=====
src/
-- Class.h
-- Class.cpp
PPO/
-- main.cpp
-- makefile
-- src/
---- Class.h
---- Class.cpp
=====-===== 2 =====-=====
PPO/
-- main.cpp
-- makefile
-- src/
---- Class.h
---- Class.cpp
-- build/

COPY/
-- main.cpp
-- makefile
-- src/
---- Class.h
---- Class.cpp
=====-===== 2 =====-=====
PPO/
-- build/

MOVE/
-- main.cpp
-- makefile
-- src/
---- Class.h
---- Class.cpp
-- build/
--------------------------------------------------------------------------------
*******************************************************************************/