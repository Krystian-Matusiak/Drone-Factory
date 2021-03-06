#include "Prostopadloscian.hh"
#include <vector>
#include "iomanip"
using namespace std;

int Prostopadloscian::ReAngle1(Prostopadloscian &P, int kat){
  P.angle+=kat;
  return P.angle;
}

int Prostopadloscian::ReAngle2(Prostopadloscian &P){
  P.angle*=-2;
  return P.angle;
}

Wektor3D Prostopadloscian::ReTrans1(Prostopadloscian &P, Wektor3D Ve){
  P.Vec=P.Vec+Ve;
  return P.Vec;
}

Wektor3D Prostopadloscian::ReTrans2(Prostopadloscian &P){
  for(int i=0 ; i<3 ; i++) P.Vec[i]*=-1;
  return P.Vec;
}

void Prostopadloscian::Rotate( Prostopadloscian &Pr, int kat){
    Wektor3D V;
    Macierz3x3 M;
    V[0]=(Pr[0][0]+Pr[7][0])/(-2);
    V[1]=(Pr[0][1]+Pr[7][1])/(-2);
    V[2]=0;
    Pr.Translate(Pr,V);
    for(int i=0 ; i<2 ; i++) V[i]=-V[i];
    M=M.Rotate(kat , 'z');
    Pr=M*Pr;
    Pr.Translate(Pr,V);
}

void Prostopadloscian::Translate( Prostopadloscian &Pr, Wektor3D V){
  Pr=Pr+V;
}

std::ostream& operator << ( std::ostream       &Strm, 
                            const Prostopadloscian    &Pr
			    ){
  for(int i=0 ; i<8 ; i++){
    Strm<< setw(16) << fixed << setprecision(10) << Pr[i]<<endl;
    if(i%2)Strm<<endl;
  }
  Strm<< setw(16) << fixed << setprecision(10) << Pr[0]<<endl;
  Strm<< setw(16) << fixed << setprecision(10) << Pr[1]<<endl;
  Strm<<endl;

  return Strm;
}

Prostopadloscian operator*(Macierz3x3 M , Prostopadloscian P){
  Prostopadloscian P2=P;
    
  for( int a=0 ; a<8 ; a++)
    P2[a] = M * P[a];
  
  return P2;
}

Prostopadloscian operator +(Prostopadloscian P1, Wektor3D W2){
  Prostopadloscian P=P1;

  for( int i=0 ; i<8 ; i++){
    P[i]=P1[i]+W2;
  }

  return P;
}

Prostopadloscian operator +(Prostopadloscian P1, Prostopadloscian P2){
  Prostopadloscian P=P1;
  for( int i=0 ; i<8 ; i++){
    P[i]=P1[i]+P2[i];
  }
  return P;
}

std::istream& operator >> ( std::istream       &Strm, 
                             Prostopadloscian    &Pr
			    ){
  Wektor3D Assign;

  for(int i=0 ; i<8 ; i++){
    Strm>>Assign;

    Pr.PushBack(Assign);
  }

  return Strm;
}
