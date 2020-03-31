#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  //  UkladRownanLiniowych   UklRown;   // To tylko przykladowe definicje zmiennej

  
  cout << endl << " Start programu " << endl << endl;

  Wektor w1;
  w1[0]=1;
  w1[1]=2;
  w1[2]=3;
  //Wektor w2=[2,2,2];
  //Wektor wynik;
  cout << w1;
  
}
