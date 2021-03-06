#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include "Obj_Geo.hh"

/*! \brief Klasa ta reprezentuje prostopadłościan oraz to co go określa (współrzędne,
    metody obrotu, translacji itp).  */
class Prostopadloscian: public Obj_Geo {
  //Wektor3D V[8];
  int angle=0;
  Wektor3D Vec;

public:
  
  int ReAngle1(Prostopadloscian &P, int kat);
  int ReAngle2(Prostopadloscian &P);
  Wektor3D ReTrans1(Prostopadloscian &P, Wektor3D Ve);
  Wektor3D ReTrans2(Prostopadloscian &P);
  void AssignReWek() {Vec[0]=0; Vec[1]=0; Vec[2]=0;};

  
  /*! Obraca prostopadłościan o zadany kąt */
  void Rotate( Prostopadloscian &Pr, int kat);
  /*! Wykonuje translacje o zadany wektor */
  void Translate(Prostopadloscian &Pr, Wektor3D V);

  
  Wektor3D operator [] (int ind) const {return Vector[ind];};
  void PushBack(Wektor3D VV) { Vector.push_back(VV);};
  Wektor3D &operator [] (int ind) {return Vector[ind];};
};


std::ostream& operator << ( std::ostream       &Strm, 
                            const Prostopadloscian    &Pr
                          );

Prostopadloscian operator*(Macierz3x3 M , Prostopadloscian P);

Prostopadloscian operator +(Prostopadloscian P1, Wektor3D W2);

Prostopadloscian operator +(Prostopadloscian P1, Prostopadloscian P2);

std::istream& operator >> ( std::istream       &Strm, 
                             Prostopadloscian    &Pr
                          );

#endif
