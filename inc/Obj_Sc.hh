#ifndef OBJ_SC_HH
#define OBJ_SC_HH

#include <iostream>
#include <vector>
#include <memory>
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "Prostopadloscian.hh"

using namespace std;

/*! \brief Klasa ta jest dziedziczona do drona oraz przeszkody. Jego metodą jest wykrywanie kolizji. */

class Obj_Sc{
 
public:
  /*
  static unsigned int D_counter;
  static unsigned int D_sum;
  
  Obj_Sc(){++D_counter;++D_sum;};
  ~Obj_Sc(){--D_counter;};

  static unsigned int OShowCounter();
  static unsigned int OShowSum();
  */
  double r;
  Wektor3D point;
  Wektor3D speed;
  Prostopadloscian boxS;
  
  virtual bool AssignChar(Wektor3D move) const {return 1;};
  virtual double Radius() const {return r;};
  virtual Wektor3D Point() const {return point;};
  virtual Wektor3D Speed() const {return speed;};
  virtual Prostopadloscian BoxS() const {return boxS;};


  virtual bool IsColision( shared_ptr<Obj_Sc> OS) const { return false;};
  
  /*
    Obj_Sc(const Obj_Sc &obj){};
  */
};
/*
unsigned int Obj_Sc::OShowCounter(){return D_counter;}
unsigned int Obj_Sc::OShowSum(){return D_sum;}

unsigned int Obj_Sc::D_counter=0;

unsigned int Obj_Sc::D_sum=0;
*/

#endif
