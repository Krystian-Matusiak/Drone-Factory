#include <iostream>
#include <iomanip>
#include <fstream>
#include <unistd.h>
#include <math.h>
#include "Scena.hh"

#include <cstdlib>
#include <ctime>
#include <memory>

using namespace std;

void SS(){
  cout<<"Ilość wektorów : "<<Wektor3D::ShowCounter()<<endl;
  cout<<"Ilość laczna wektorów : "<<Wektor3D::ShowSum()<<endl;
}

/*! \brief Struktura pomocnicza.
    Przechowuje dane dotyczące osi wokół której wykonujemy rotację oraz kąt.
*/

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Pr - klasa prostopadłościan. Z niej pobieramy kolejne współrzędne.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void PrzykladZapisuWspolrzednychDoStrumienia( ostream&     StrmWy, 
                                              Prostopadloscian &Pr
                                            )
{ 
  StrmWy<<Pr;  
}

void PrzykladZapisuWspolrzednychDoStrumienia( ostream&     StrmWy, 
                                              Rotor &R
                                            )
{ 
  StrmWy<<R;  
}

void PrzykladZapisuWspolrzednychDoStrumienia( ostream&     StrmWy, 
                                              Wektor3D &W
                                            )
{
  StrmWy<< setw(16) << fixed << setprecision(10) << W<<endl;
}

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Pr - klasa prostopadłościan. Z niej pobieramy kolejne współrzędne.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku,
                                         Prostopadloscian &Pr
                                       )
{
  ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
	 << ":(  nie powiodla sie." << endl;
    return false;
  }

  PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy,Pr);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

bool PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku,
                                         Rotor &R
                                       )
{
  ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
	 << ":(  nie powiodla sie." << endl;
    return false;
  }

  PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy,R);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

bool PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku,
                                         Wektor3D &W
                                       )
{
  ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku,ios::app);
  if (!StrmPlikowy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
	 << ":(  nie powiodla sie." << endl;
    return false;
  }

  PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy,W);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

void PrzykladZapisuWspolrzednychZeStrumienia( istream&     StrmWe, 
                                              Prostopadloscian &Pr
                                            )
{
  StrmWe>>Pr;
}

void PrzykladZapisuWspolrzednychZeStrumienia( istream&     StrmWe, 
                                              Rotor &R
                                            )
{ 
  StrmWe>>R;  
}

bool PrzykladZapisuWspolrzednychzPliku( const char  *sNazwaPliku,
                                         Prostopadloscian &Pr
                                       )
{
  ifstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
	 << ":(  nie powiodla sie." << endl;
    return false;
  }

  PrzykladZapisuWspolrzednychZeStrumienia(StrmPlikowy,Pr);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}
bool PrzykladZapisuWspolrzednychzPliku( const char  *sNazwaPliku,
                                         Rotor &R
                                       )
{
  ifstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
	 << ":(  nie powiodla sie." << endl;
    return false;
  }
  PrzykladZapisuWspolrzednychZeStrumienia(StrmPlikowy,R);
  
  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

bool SaveToFile(int ind, Scena S){
  switch(ind-1){
  case 0:////////////////////////  CASE DLA 1 DRONA  /////////////////


    
    if (!PrzykladZapisuWspolrzednychDoPliku("Dron1/Korpus.dat",S[ind-1]->Corpus1())) return 1;
    if (!PrzykladZapisuWspolrzednychDoPliku("Dron1/Rotor1.dat",S[ind-1]->Take(0))) return 1;
    if (!PrzykladZapisuWspolrzednychDoPliku("Dron1/Rotor2.dat",S[ind-1]->Take(1))) return 1;
    if (!PrzykladZapisuWspolrzednychDoPliku("Dron1/Rotor3.dat",S[ind-1]->Take(2))) return 1;
    if (!PrzykladZapisuWspolrzednychDoPliku("Dron1/Rotor4.dat",S[ind-1]->Take(3))) return 1;
    break;


    
  case 1:////////////////////////  CASE DLA 2 DRONA  /////////////////


    
   if (!PrzykladZapisuWspolrzednychDoPliku("Dron2/Korpus.dat",S[ind-1]->Corpus1())) return 1;
    if (!PrzykladZapisuWspolrzednychDoPliku("Dron2/Rotor1.dat",S[ind-1]->Take(0))) return 1;
    if (!PrzykladZapisuWspolrzednychDoPliku("Dron2/Rotor2.dat",S[ind-1]->Take(1))) return 1;
    if (!PrzykladZapisuWspolrzednychDoPliku("Dron2/Rotor3.dat",S[ind-1]->Take(2))) return 1;
    if (!PrzykladZapisuWspolrzednychDoPliku("Dron2/Rotor4.dat",S[ind-1]->Take(3))) return 1;
    break;


    
  case 2://////////////////////// CASE DLA 3 DRONA  /////////////////


    
   if (!PrzykladZapisuWspolrzednychDoPliku("Dron3/Korpus.dat",S[ind-1]->Corpus1())) return 1;
    if (!PrzykladZapisuWspolrzednychDoPliku("Dron3/Rotor1.dat",S[ind-1]->Take(0))) return 1;
    if (!PrzykladZapisuWspolrzednychDoPliku("Dron3/Rotor2.dat",S[ind-1]->Take(1))) return 1;
    if (!PrzykladZapisuWspolrzednychDoPliku("Dron3/Rotor3.dat",S[ind-1]->Take(2))) return 1;
    if (!PrzykladZapisuWspolrzednychDoPliku("Dron3/Rotor4.dat",S[ind-1]->Take(3))) return 1;
    break;
  }//switch 
}


void Menu(){
  cout<<"=================================="<<endl;
  cout<<" M E N U :"<<endl;
  cout<<"o - obrot bryly o zadana sekwencje katow"<<endl;
  cout<<"t - powtorzenie poprzedniego obrotu"<<endl;
  cout<<"p - przesuniecie prostokata o zadany wektor"<<endl;
  cout<<"w - wyswietlenie wspolrzednych wierzcholkow"<<endl;
  cout<<"s - sprawdzenie dlugosci przeciwlelych bokow"<<endl;  
  cout<<"m - wyswietl menu"<<endl;
  cout<<"k - koniec dzialania programu"<<endl;
  cout<<"=================================="<<endl;
}

void menu(){
  cout<<"=================================="<<endl;
  cout<<" M E N U :"<<endl;
  cout<<"o - obrot drona"<<endl;
  cout<<"j - lot na wprost"<<endl;
  cout<<"s - selekcja drona"<<endl;
  cout<<"m - wyswietl menu"<<endl;
  cout<<"k - koniec dzialania programu"<<endl;
  cout<<"=================================="<<endl;
}
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

int main()
{
  shared_ptr<Dron> D=make_shared<Dron>();
  shared_ptr<Dron> Dr=make_shared<Dron>();
  shared_ptr<Dron> Q=make_shared<Dron>();
  shared_ptr<Obstacle> Obs1=make_shared<Obstacle>();
  shared_ptr<Obstacle> Obs2=make_shared<Obstacle>();
  shared_ptr<Obstacle> Obs3=make_shared<Obstacle>();

  Scena S;

  S.OPushBack(D);
  S.OPushBack(Dr);
  S.OPushBack(Q);
    
  S.OPushBack(Obs1);
  S.OPushBack(Obs2);
  S.OPushBack(Obs3);

  S.DPushBack(D);
  S.DPushBack(Dr);
  S.DPushBack(Q);

  
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //

  Lacze.DodajNazwePliku("Dron1/Korpus.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("Dron1/Rotor1.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("Dron1/Rotor2.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("Dron1/Rotor3.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("Dron1/Rotor4.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("Dron1/Track.dat",PzG::RR_Ciagly,2);

  
  Lacze.DodajNazwePliku("Dron2/Korpus.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("Dron2/Rotor1.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("Dron2/Rotor2.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("Dron2/Rotor3.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("Dron2/Rotor4.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("Dron2/Track.dat",PzG::RR_Ciagly,2);


  
  Lacze.DodajNazwePliku("Dron3/Korpus.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("Dron3/Rotor1.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("Dron3/Rotor2.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("Dron3/Rotor3.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("Dron3/Rotor4.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("Dron3/Track.dat",PzG::RR_Ciagly,2);

  // Przeszkody
  Lacze.DodajNazwePliku("Obstacle/Obstacle2.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("Obstacle/Obstacle3.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("Obstacle/Obstacle4.dat",PzG::RR_Ciagly,2);
 
   //
   //  Ustawienie trybu rysowania 3D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy x,y,z.
   //
  Lacze.ZmienTrybRys(PzG::TR_3D);

   // Ustawienie zakresow poszczegolnych osi
  Lacze.UstawZakresY(-800,800);
  Lacze.UstawZakresX(-800,800);
  Lacze.UstawZakresZ(-700,1400);
  Lacze.Rysuj();
  
  /*!
    DronAngle - kąt wznoszenia drona
    DronShift - długość trasy lotu drona
    vxyz oraz l_vxyz - wektor przesuwający drona oraz długość tego wektora
    param_t - parametr określający stosunek długości wektora w płaszczyźnie
              XY do długości drona. Parametr ten potrzebny jest do wyznaczenia
	      kierunku ruchu drona.
    RotAngle - kat rotacji drona
   */
  Wektor3D vxyz;
  double l_vxyz;
  double DronAngle;
  double DronShift;
  double param_t;
  int RotAngle;

  if (!PrzykladZapisuWspolrzednychzPliku("Dron1/Korpus.dat",S[0]->Corpus1())) return 1;
  if (!PrzykladZapisuWspolrzednychzPliku("Dron1/Rotor1.dat",S[0]->Take(0))) return 1;
  if (!PrzykladZapisuWspolrzednychzPliku("Dron1/Rotor2.dat",S[0]->Take(1))) return 1;
  if (!PrzykladZapisuWspolrzednychzPliku("Dron1/Rotor3.dat",S[0]->Take(2))) return 1;
  if (!PrzykladZapisuWspolrzednychzPliku("Dron1/Rotor4.dat",S[0]->Take(3))) return 1;

  if (!PrzykladZapisuWspolrzednychzPliku("Dron2/Korpus.dat",S[1]->Corpus1())) return 1;
  if (!PrzykladZapisuWspolrzednychzPliku("Dron2/Rotor1.dat",S[1]->Take(0))) return 1;
  if (!PrzykladZapisuWspolrzednychzPliku("Dron2/Rotor2.dat",S[1]->Take(1))) return 1;
  if (!PrzykladZapisuWspolrzednychzPliku("Dron2/Rotor3.dat",S[1]->Take(2))) return 1;
  if (!PrzykladZapisuWspolrzednychzPliku("Dron2/Rotor4.dat",S[1]->Take(3))) return 1;

  if (!PrzykladZapisuWspolrzednychzPliku("Dron3/Korpus.dat",S[2]->Corpus1())) return 1;
  if (!PrzykladZapisuWspolrzednychzPliku("Dron3/Rotor1.dat",S[2]->Take(0))) return 1;
  if (!PrzykladZapisuWspolrzednychzPliku("Dron3/Rotor2.dat",S[2]->Take(1))) return 1;
  if (!PrzykladZapisuWspolrzednychzPliku("Dron3/Rotor3.dat",S[2]->Take(2))) return 1;
  if (!PrzykladZapisuWspolrzednychzPliku("Dron3/Rotor4.dat",S[2]->Take(3))) return 1;
  
  if (!PrzykladZapisuWspolrzednychzPliku("Obstacle/Obstacle2.dat",Obs1->BoxS())) return 1;
  if (!PrzykladZapisuWspolrzednychzPliku("Obstacle/Obstacle3.dat",Obs2->BoxS())) return 1;
  if (!PrzykladZapisuWspolrzednychzPliku("Obstacle/Obstacle4.dat",Obs3->BoxS())) return 1;
  
  

  int Nr_Drona=1;
  Wektor3D Position;

  char choose='r';
  while(choose!='k'){
    cout<<"Aktualnie wyselekcjonowanym dronem jest:\nDron nr "<<Nr_Drona<<endl;
    cout<<"Wybierz opcje dla drona: ";
    cin.clear();
    cin>>choose;
    int one=1;
    int velocity;

    
    if(choose!='s'){
    cout<<"Podaj szybkość poruszania się wirnikow (miare kata w 10000ms)"<<endl;
    cin>>velocity;
    }
    
    int nDron_Col=0;
    switch(choose){
    case 's':
      cout<<"Podaj numer drona, ktorym chcesz sterowac :";
      cin>>Nr_Drona;
      break;
    case 'o':
	cout<<"Podaj kat obrotu drona: ";
	cin>>RotAngle;

	if(RotAngle<0) one=-1;
	for(int i=0 ; i<fabs(RotAngle) ; i++){
	  S[Nr_Drona-1]->Rotate(one);
	  for(int j=0; j<4 ; j++){
	    if(j==0||j==3)
	      velocity=-velocity;
	    S[Nr_Drona-1]->Take(j).Rotate(S[Nr_Drona-1]->Take(j),velocity);
	    
	  }//for

	  SaveToFile(Nr_Drona,S);

	  Lacze.Rysuj();
	  usleep(10000);
	}//for
      break;
      
    case 'j':
	cout<<"Podaj dlugosc drogi przelotu i kat wznoszenia (+) / opadania (-) "<<endl;
	cin>>DronShift>>DronAngle;

	//////////////////  KOMBAJN OBLICZEŃ   ////////////////////
	
	vxyz=S[Nr_Drona-1]->Corpus()[0]-S[Nr_Drona-1]->Corpus()[1];
	l_vxyz=DronShift*cos((DronAngle*3.141592)/180);
	param_t=l_vxyz/sqrt( vxyz[0]*vxyz[0] + vxyz[1]*vxyz[1] );
	if(DronAngle>0) vxyz[2]=DronShift*sin((DronAngle*3.141592)/180);
	else vxyz[2]=DronShift*sin((DronAngle*3.141592)/180);
	for(int i=0 ; i<2 ; i++) vxyz[i] = param_t*vxyz[i];	
	for(int i=0 ; i<3 ; i++) vxyz[i] = vxyz[i]/(int)DronShift;

	//////////////////  KONIEC KOMBAJNU   ////////////////////
	
	for( int i=0 ; i<(int)DronShift ; i++){ // for większy
	  S[Nr_Drona-1]->Translate(vxyz);
	  
	  if(!S[Nr_Drona-1]->AssignChar(vxyz)) cout<< "ERROR !!!"<<endl;
	  for(int d=0 ; d<3 ; d++)
	    if(!S[d]->AssignChar(vxyz)) cout<< "ERROR !!!"<<endl;

	  for( int c=0 ; c<6 ; c++){
	    if(Nr_Drona-1 != c){
	      if( S[Nr_Drona-1]->IsColision(S(c)) ){
		cout<<"\n\nUWAGA !!!\nWykryto kolizje.\n\n\n";
		i=100000;
		c=7;
		for(int d=0 ; d<3 ; d++) vxyz[d]=-vxyz[d];
		S[Nr_Drona-1]->Translate(vxyz);
	      }
	    }
	  }
	  if(i!=100000){
	    
	    for(int j=0; j<4 ; j++){
	      if(j%2==0)
		velocity=-velocity;
	      S[Nr_Drona-1]->Take(j).Rotate(S[Nr_Drona-1]->Take(j),velocity);
	    }//for
	    
	    
	    if(!SaveToFile(Nr_Drona,S));
	    
	    Position = S[Nr_Drona-1]->Corpus1()[0] + (0.5)*(S[Nr_Drona-1]->Corpus1()[5]-S[Nr_Drona-1]->Corpus1()[0]);
	    if(Nr_Drona-1==0)
	      if (!PrzykladZapisuWspolrzednychDoPliku("Dron1/Track.dat",Position)) return 1;
	    if(Nr_Drona-1==1)
	      if (!PrzykladZapisuWspolrzednychDoPliku("Dron2/Track.dat",Position)) return 1;
	    if(Nr_Drona-1==2)
	      if (!PrzykladZapisuWspolrzednychDoPliku("Dron3/Track.dat",Position)) return 1;
	    Lacze.Rysuj();
	    usleep(7000);
	  }
	}//for większy
	break;
    case 'm':
      menu();
      break;
    }//switch
    
    
  }//while
  
  SS();
  
  
  return 0;
}//main

