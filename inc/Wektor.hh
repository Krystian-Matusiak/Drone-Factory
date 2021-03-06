#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <math.h>

/*! \brief Klasa ta reprezentuje wektor (tablica n-wymiarowa,
    przeciążenia operatorów itp).  */
template <int Wymiar>
class Wektor {
  double Vec[Wymiar];
  static unsigned int counter;
  static unsigned int sum;


public:
  // Wektor();
  //~Wektor();
  Wektor(){
    //std::cout<<counter<<"  a suma  "<<sum<<std::endl;
    ++counter;++sum;
  };
  
  ~Wektor(){--counter;};
  Wektor(const Wektor &obj){
    ++counter;
    for(int i=0 ; i<Wymiar ; ++i) Vec[i]=obj[i];
  }
    static unsigned int ShowCounter();
    static unsigned int ShowSum();

  /*! DlWek()-oblicza długości wektora  */
  double DlWek();
  double operator [](int ind) const {return Vec[ind];};
  double & operator [](int ind) {return Vec[ind];};
};

template <int Wymiar>
unsigned int Wektor<Wymiar>::counter=0;

template <int Wymiar>
unsigned int Wektor<Wymiar>::sum=0;


template <int Wymiar>
unsigned int Wektor<Wymiar>::ShowCounter(){
  return Wektor<Wymiar>::counter;
}

template <int Wymiar>
unsigned int Wektor<Wymiar>::ShowSum(){
  return Wektor<Wymiar>::sum;
}

template <int Wymiar>
double Wektor<Wymiar>::DlWek(){
  double dl=0;
  for( int i=0 ; i<Wymiar; i++ )
    dl=dl+this->Vec[i]*this->Vec[i];
  dl=sqrt(dl);
  return dl;
}
#endif
