#pragma once

////////////////////////////////////////////////////////////////////////
//              Tego pliku Państwo nie mogą modyfikować.              //
////////////////////////////////////////////////////////////////////////

#include "MyPrintable.h"
#include "Attributes.h"

class MyPrinter
{
public:
	MyPrinter(unsigned int width);

	void print( const MyPrintable & obj ) const;

public:	
	static const char * resetSeq();
	static const char * controlSeq( AttFormat::Attribute opt );
	static const char * controlSeq( AttColor::Attribute opt );
	
private:
	unsigned int m_width;
};