#include "HarmonicMean.h"
#include "ArithmeticMean.h"
#include <iostream>

void calcAverage(Mean & m)
{
	std::cout << "Mean type: " << m << std::endl;
	m << 2.0 << 1.2 << -3 << 5.0;
	std::cout << "Results: " << m.result() << std::endl;
}

int main() 
{
	std::cout << "=====-===== 1 =====-=====" << std::endl;
	HarmonicMean * hm = new HarmonicMean;
	calcAverage(*hm);
	delete hm;

	std::cout << "=====-===== 1 =====-=====" << std::endl;
	ArithmeticMean am;
	calcAverage(am);

	std::cout << "=====-===== 1 =====-=====" << std::endl;
	am << 4.8;
	std::cout << "Adding 4.8: " << am.result() << std::endl;

	std::cout << "=====-===== 1 =====-=====" << std::endl;
	am.reset();
	std::cout << "Reset: " << am.result() << std::endl;
	calcAverage(am);

	std::cout << "=====-===== 1 =====-=====" << std::endl;
	const ArithmeticMean cam;
	cam << 1.0 << 1.2;

	std::cout << "=====-===== 1 =====-=====" << std::endl;
	const HarmonicMean chm;
	std::cout << chm << std::endl;
	chm << 2.0;
	std::cout << chm << std::endl;
}

/*********************************** OUTPUT ************************************
--------------------------------------------------------------------------------
=====-===== 1 =====-=====
Mean type: Harmonic
Results: 3.33333
=====-===== 1 =====-=====
Mean type: Arithmetic
Results: 1.3
=====-===== 1 =====-=====
Adding 4.8: 2
=====-===== 1 =====-=====
Reset: 0
Mean type: Arithmetic
Results: 1.3
=====-===== 1 =====-=====
ERROR: cannot add value 1 to const Arithmetic Mean
ERROR: cannot add value 1.2 to const Arithmetic Mean
=====-===== 1 =====-=====
Harmonic
ERROR: cannot add value 2 to const Harmonic Mean
Harmonic
--------------------------------------------------------------------------------
*******************************************************************************/