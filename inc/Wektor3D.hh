#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH


#include "Wektor.hh"
#include "Macierz3x3.hh"

typedef Wektor<3> Wektor3D;

Wektor3D operator *(Macierz3x3 M , Wektor3D V);

Wektor3D operator *(Wektor3D V1, Wektor3D V2);

double operator &(Wektor3D V1, Wektor3D V2);

Wektor3D operator *(double value, Wektor3D V);

Wektor3D operator +(Wektor3D W1, Wektor3D W2);

Wektor3D operator -(Wektor3D W1, Wektor3D W2);

std::istream& operator >> (std::istream &Strm, Wektor3D &Wek);

std::ostream& operator << (std::ostream &Strm, const Wektor3D &Wek);

#endif
