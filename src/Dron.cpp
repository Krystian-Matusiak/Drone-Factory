#include "Dron.hh"
using namespace std;


bool Dron::AssignChar(Wektor3D move){
  this->r = 143,005;
  this->point = this->Corpus1()[0] + (0.5)*(this->Corpus1()[5]-this->Corpus1()[0]);
  this->speed = move;
  this->boxS = this->Corpus1();
  return 1;
}
/*
Prostopadloscian & Dron::BoxS(){
  boxS=Korpus;
 return boxS;
 }*/

Prostopadloscian& Dron::Corpus1(){
  return this->Korpus;
}

Prostopadloscian& Dron::DownD(int ind){
  return this->Down[ind];
}

Prostopadloscian Dron::Corpus(){
  return this->Korpus;
}

void Dron::Rotate(  int kat){
  this->Corpus1().Rotate(this->Corpus1(),kat);
  
  Wektor3D V;
  Macierz3x3 M;
  M=M.Rotate(kat , 'z');

  V[0]=(this->Corpus1()[0][0]+this->Corpus1()[7][0])/(-2);
  V[1]=(this->Corpus1()[0][1]+this->Corpus1()[7][1])/(-2);
  V[2]=0;
  for(int c=0 ; c<4 ; c++)
    (*this)(c).Translate((*this)(c),V);
  for(int c=0 ; c<4 ; c++)
    (*this)(c)=M*(*this)(c);

  for(int j=0 ; j<2 ; j++) V[j]=-V[j];
  for(int c=0 ; c<4 ; c++)
    (*this)(c).Translate((*this)(c),V);
}


void Dron::Translate(  Wektor3D V){
  this->Corpus1().Translate(this->Corpus1(),V);

  for(int i=0 ; i<4 ; i++){
    (*this)(i).Translate((*this)(i),V);
  }
}

bool Dron::IsColision( shared_ptr<Obj_Sc> OS){
  double d;
  Wektor3D r=OS->Point()-this->Point();
  Wektor3D XY=r;
  XY[2]=0;

  if(
     this->Point()[0] <= OS->BoxS()[4][0]+143
     &&
     this->Point()[0] >= OS->BoxS()[2][0]-143
     &&
     this->Point()[1] <= OS->BoxS()[0][1]+143
     &&
     this->Point()[1] >= OS->BoxS()[2][1]-143
     &&
     this->Point()[2] <= OS->BoxS()[1][2]+130
     &&
     this->Point()[2] >= OS->BoxS()[0][2]-70
     ){
    return 1;
  }
      
  if(  fabs(r[2])<=200  && XY.DlWek() <= 2*OS->Radius() ){
    return 1;
  }
  else return 0;
}

