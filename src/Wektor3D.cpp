#include "Wektor3D.hh"
#include "Macierz3x3.hh"




Wektor3D operator*(Macierz3x3 M , Wektor3D V){
  Wektor3D V2;
  for( int i=0 ; i<3 ; i++)
    V2[i]=0;
  
  for( int a=0 ; a<3 ; a++)
    for( int c=0 ; c<3 ; c++)
      V2[a] += M(a,c) * V[c];
    
  return V2;
}

Wektor3D operator *(Wektor3D V1, Wektor3D V2){
  


}

double operator &(Wektor3D V1, Wektor3D V2){
  double v=0;
  for( int i=0 ; i<3 ; i++)
    V1[i]*=V2[i];
  for( int i=0 ; i<3 ; i++)
    v+=V1[i];
  return v;
}


Wektor3D operator *(double value, Wektor3D V){
  Wektor3D V2;
  
  for( int a=0 ; a<3 ; a++)
      V2[a] = value * V[a];
    
  return V2;
}

Wektor3D operator +(Wektor3D W1, Wektor3D W2){
  Wektor3D V;

  for( int i=0 ; i<3 ; i++){
    V[i]=W1[i]+W2[i];
  }
 
  return V;
}

Wektor3D operator -(Wektor3D W1, Wektor3D W2){
  Wektor3D V;

  for( int i=0 ; i<3 ; i++){
    V[i]=W1[i]-W2[i];
  }
 
  return V;
}

std::istream& operator >> (std::istream &Strm, Wektor3D &Wek)
{
  for( int i=0 ; i<3 ; i++){
    Strm>>Wek[i];
  }
  return Strm;
}

std::ostream& operator << (std::ostream &Strm, const Wektor3D &Wek)
{
  for( int i=0 ; i<3 ; i++){
    Strm<<Wek[i]<<" ";
  }
  
  return Strm;  
}
