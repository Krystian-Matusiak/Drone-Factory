#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include <tgmath.h>
using namespace std;



/*! \brief Klasa ta reprezentuje macierz (tablica n-wymiarowa, metoda rotacji,
    przeciążenia operatorów itp).  */
template <int Wymiar>
class Macierz{
  double Mac[Wymiar][Wymiar];
  char axis;
  
public:
  /*! Tworzy macierz obrotu wokół konkretnej osi o konkretny kąt  */
  Macierz<Wymiar> Rotate(double kat,char axis);
  double operator ()(int row, int col) const {return Mac[row][col];};
  double & operator ()(int row, int col) {return Mac[row][col];};
};



template <int Wymiar>
Macierz<Wymiar> Macierz<Wymiar>::Rotate(double kat, char axis){
  Macierz<Wymiar> M;
  double katrad=(kat*3.141592)/180;
  for(int i=0 ; i<Wymiar ; i++)
    for(int j=0 ; j<Wymiar ; j++)
      M(i,j)=0;
  for(int i=0 ; i<Wymiar ; i++)
    M(i,i)=1;
    
  switch(axis){
  case 'x':
    M(1,1)=cos(katrad);
    M(1,2)=-sin(katrad);
    M(2,1)=sin(katrad);
    M(2,2)=cos(katrad);
    break;
  case 'y':
    M(0,0)=cos(katrad);
    M(0,2)=sin(katrad);
    M(2,0)=-sin(katrad);
    M(2,2)=cos(katrad);
    break;
  case 'z':
    M(0,0)=cos(katrad);
    M(0,1)=-sin(katrad);
    M(1,0)=sin(katrad);
    M(1,1)=cos(katrad);
    break;
  }
  
  return M;
}



#endif
