#include "Macierz3x3.hh"

std::ostream& operator << (std::ostream &Strm, const Macierz3x3 &Mac)
{
  for( int i=0 ; i<3 ; i++){
    for( int j=0 ; j<3 ; j++){
      Strm<<Mac(i,j);
    }
    Strm<<endl;
  }
  return Strm;  
}
