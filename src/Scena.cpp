#include "Scena.hh"
#include "lacze_do_gnuplota.hh"
using namespace std;

/*
void Scena::AsPtr(Dron &D,Obj_Sc &O){
  this->wD=D;
  this->wO=O;
  }*/


void Scena::DPushBack(  shared_ptr<Dron> &D){
  this->DronList.push_back(D);
}

void Scena::OPushBack( shared_ptr<Obj_Sc> O){
  this->ObjList.push_back(O);
}

