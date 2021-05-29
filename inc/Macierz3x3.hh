#ifndef MACIERZ3X3_HH
#define MACIERZ3X3_HH


#include <iostream>
#include "Macierz.hh"

typedef Macierz<3>  Macierz3x3;

std::ostream& operator << (std::ostream &Strm, const Macierz3x3 &Mac);

#endif
