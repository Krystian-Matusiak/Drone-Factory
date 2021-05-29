#include "Rotor.hh"
#include "iomanip"

using namespace std;


void Rotor::Rotate( Rotor &R, int kat){
  Wektor3D V;
  Macierz3x3 M;
  V=R(15);
  V[2]=0;
  for(int i=0 ; i<2 ; i++) V[i]=-V[i];
  R.Translate(R,V);
  for(int i=0 ; i<2 ; i++) V[i]=-V[i];
  M=M.Rotate(kat , 'z');
  R=M*R;
  R.Translate(R,V);
}


void Rotor::Translate(Rotor &R, Wektor3D V){
  R=R+V;
}


std::ostream& operator << ( std::ostream       &Strm, 
                            const Rotor    &R
			    ){
  for(int i=0 ; i<42 ; i++){
    Strm<< setw(16) << fixed << setprecision(10) << R(i)<<endl;
    if(i%2)Strm<<endl;
  }
  Strm<<endl;

  return Strm;
}

Rotor operator*(Macierz3x3 M , Rotor R){
  Rotor R2=R;
    
  for( int a=0 ; a<42 ; a++)
    R2(a) = M * R(a);
  
  return R2;
}

Rotor operator +(Rotor R1, Wektor3D W2){
  Rotor R=R1;

  for( int i=0 ; i<42 ; i++){
    R(i)=R1(i)+W2;
  }

  return R;
}

Rotor operator +(Rotor R1, Rotor R2){
  Rotor R=R1;
  for( int i=0 ; i<42 ; i++){
    R(i)=R1(i)+R2(i);
  }
  return R;
}

std::istream& operator >> ( std::istream       &Strm, 
                             Rotor   &R
			    ){
  Wektor3D Assign;
  for(int i=0 ; i<42 ; i++){
    Strm>>Assign;
    R.PushBack(Assign);
  }

  return Strm;
}
