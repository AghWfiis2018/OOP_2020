#include "MyText.h"
#include "MyLine.h"
#include "MyPrinter.h"
#include <iostream>

int main()
{
	const AttFormat * ptrFor;
	const AttColor * ptrCol;
	
	////////////////////////////////////////////////////////////////////
	MyLine line('*', 60, AttColor::MAGENTA);	
	
	ptrCol = &line;
	#ifdef MY_EXPECTED_ERROR
	{
		ptrFor = &line; // -> blad kompilacji!!!
	}
	#endif
	
	std::cout << MyPrinter::controlSeq( ptrCol->getColor() );
	std::cout << line.rawString();
	std::cout << MyPrinter::resetSeq() << std::endl;

	////////////////////////////////////////////////////////////////////
	MyText text("JULIUSZ SLOWACKI", AttFormat::BOLD, AttColor::GREEN);
	
	ptrCol = &text;
	ptrFor = &text;
	
	std::cout << MyPrinter::controlSeq( ptrFor->getFormat() ) 
	          << MyPrinter::controlSeq( ptrCol->getColor() );
	std::cout << std::string(22, ' ') << text.rawString();
	std::cout << MyPrinter::resetSeq() << std::endl;

	////////////////////////////////////////////////////////////////////
	std::cout << MyPrinter::controlSeq( line.getColor() );
	std::cout << line.rawString();
	std::cout << MyPrinter::resetSeq() << std::endl;
	          
	////////////////////////////////////////////////////////////////////
	MyPrinter printer(60);

	line.setLength(50);
	line.setChar('-');
	line.setColor( AttColor::GRAY );
	printer.print( line );
	
	text.setFormat( AttFormat::NORMAL );
	text.setColor( AttColor::WHITE );
	text.setText("Lecz zaklinam: niech zywi nie traca nadziei");
	printer.print( text );
	text.setText("I przed narodem niosa oswiaty kaganiec;");
	printer.print( text );
	
	printer.print( line );
	
	text.setColor( AttColor::RED );
	text.setText("A kiedy trzeba, na smierć ida po kolei,");
	printer.print( text );
	text.setText("Jak kamienie, przez Boga rzucane na szaniec!");
	printer.print( text );
				
	printer.print( line );
		
	return 0;
}

/*********************************** OUTPUT ************************************
-------------------------- (oczywiscie pokolorowany) ---------------------------

************************************************************
                      JULIUSZ SLOWACKI
************************************************************
     --------------------------------------------------
        Lecz zaklinam: niech zywi nie traca nadziei
          I przed narodem niosa oswiaty kaganiec;
     --------------------------------------------------
          A kiedy trzeba, na smierć ida po kolei,
        Jak kamienie, przez Boga rzucane na szaniec!
     --------------------------------------------------

--------------------------------------------------------------------------------
*******************************************************************************/