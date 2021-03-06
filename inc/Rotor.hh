#ifndef ROTOR_HH
#define ROTOR_HH

#include <iostream>
#include <vector>
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "Obj_Geo.hh"

using namespace std;

/*! \brief Klasa określa współrzędne rotorów oraz jak się obracają */


class Rotor: private Obj_Geo{
  
public:

  /*! Obraca prostopadłościan o zadany kąt */
  void Rotate( Rotor &R, int kat);
  /*! Wykonuje translacje o zadany wektor */
  void Translate(Rotor &R, Wektor3D V);
  Wektor3D operator () (int ind) const {return Vector[ind];};
  void PushBack(Wektor3D VV) { Vector.push_back(VV);};
  Wektor3D &operator () (int ind) {return Vector[ind];};
};

std::ostream& operator << ( std::ostream       &Strm, 
                            const Rotor   &Pr
                          );

Rotor operator*(Macierz3x3 M , Rotor P);

Rotor operator +(Rotor P1, Wektor3D W2);

Rotor operator +(Rotor P1, Rotor P2);

std::istream& operator >> ( std::istream       &Strm, 
                             Rotor   &Pr
                          );

#endif
