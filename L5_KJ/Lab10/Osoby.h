#pragma once
#include "Doktorant.h"
#include "Wozny.h"

std::ostream& operator<<(std::ostream& out, const Osoba& person)    // print info abouot any person
{   return out << person.print();}

