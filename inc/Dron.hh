#ifndef DRON_HH
#define DRON_HH

#include <iostream>
//#include "Prostopadloscian.hh"
#include "Rotor.hh"
#include "Obj_Sc.hh"
using namespace std;

/*! \brief Klasa określa współrzędne rotorów oraz korpusu. Jest fragmentem objektu sceny. */

class Dron: public Obj_Sc{
  unsigned int Nr_Dron;
  Prostopadloscian Korpus;
  Prostopadloscian Down[2];
  Rotor Propeller[4];
  //  list<Wektor3D> track;
  
public:
  
  
  virtual bool IsColision(  shared_ptr<Obj_Sc> OS);

  virtual double& Radius()  {return r;};
  virtual Wektor3D& Point() {return point;};
  virtual Wektor3D& Speed() {return speed;};
  virtual Prostopadloscian& BoxS() {return boxS;};
  
  virtual bool AssignChar(Wektor3D move);

  //void Track(Wektor3D Position){  track.push_back(Position); };
  
  void Rotate(  int kat);
  void Translate(  Wektor3D V);
  
  Prostopadloscian& DownD(int ind);
  Prostopadloscian& Corpus1();
  Prostopadloscian Corpus();

  Rotor& Take(int ind) {return Propeller[ind];};

  
  Rotor operator () (int ind) const{return Propeller[ind];};
  Rotor &operator () (int ind) {return Propeller[ind];};

  //void PushBack(Wektor3D VV) { Vector.push_back(VV);};
};

Dron operator*(Macierz3x3 M , Dron D);

Dron operator +(Dron D1, Wektor3D W2);


#endif
