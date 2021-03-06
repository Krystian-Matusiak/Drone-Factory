#ifndef SCENA_HH
#define SCENA_HH

#include <iostream>
#include "lacze_do_gnuplota.hh"
#include "Dron.hh"
#include "Obstacle.hh"
#include <memory>
using namespace std;

/*! \brief Klasa ta reprezentuje scene. Jego polami to lista objektów scen oraz dronów.  */

class Scena{
  list<shared_ptr<Dron>> DronList;
  list<shared_ptr<Obj_Sc>> ObjList;
  
public:
    list< shared_ptr<Dron> >::iterator iter=DronList.begin();

  void DPushBack( shared_ptr<Dron> &D);
  void OPushBack( shared_ptr<Obj_Sc> O);

  
  shared_ptr<Dron>& operator [] (int i)       {
    list< shared_ptr<Dron> >::iterator iter=DronList.begin();
    for( int a=0 ; a<i ; a++) ++iter;
    return *iter;
  };

  shared_ptr<Obj_Sc>& operator () (int i)       {
    list< shared_ptr<Obj_Sc> >::iterator iter=ObjList.begin();
    for( int a=0 ; a<i ; a++) ++iter;
    return *iter;
  };
  
};

  
#endif
