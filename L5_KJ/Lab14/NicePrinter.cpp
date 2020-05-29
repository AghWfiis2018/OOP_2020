#include "NicePrinter.h"
#include <iomanip>


int NicePrinter::counter = 1;

NicePrinter::NicePrinter(int prefix)
{
    std::setw(prefix);
}

void NicePrinter::separator(int num) const
{
    std::cout << "=====-===== " << num << " =====-=====\n";
}

void NicePrinter::header(std::string toPrint) const
{
    std::cout << "* " << toPrint << " *\n";
}
    