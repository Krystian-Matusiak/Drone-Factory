#ifndef OBSTACLE_HH
#define OBSTACLE_HH

#include <iostream>
#include "Prostopadloscian.hh"
#include "Rotor.hh"
#include "Obj_Sc.hh"

using namespace std;

/*! \brief Klasa określa przeszkode. Jest fragmentem objektu sceny. */


class Obstacle:  public Obj_Sc , public Prostopadloscian {
  Prostopadloscian Box;
public:
  
  virtual double& Radius()  {return r;};
  virtual Wektor3D& Point() {return point;};
  virtual Wektor3D& Speed() {return speed;};
  virtual Prostopadloscian& BoxS() {boxS=Box ; return boxS;};
  
  virtual bool AssignChar(Wektor3D move){return false;};

  
  Prostopadloscian& ShowBox(){return Box;};

};

#endif
