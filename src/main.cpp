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
  //  cin >> w1;
  
  //cout << w1 << endl;
  double init[]={14,-5,10};
  double init2[]={2,3,-7};
  double init3[]={1,11,-4};
  double zmiana[]={0,0,0};   
     Wektor w1(init);
     Wektor w2(init2);
     Wektor w3(init3);
     Wektor new_column(zmiana);
     
     Wektor tablica[]={w1,w2,w3};
     Wektor tablica2[]={w3,w2,w1};
     
     Macierz m1(tablica);
     // Macierz m2(tablica2);
      
    cout << "macierz m1: " << endl << m1;
    //cout << "macierz m2: " << m2;
    cout << endl;
    double wynik;
    wynik = m1.wyznacznik();
    

    // cout << wynik << endl;
    cout << "Wyznacznik "<< endl << wynik << endl;
    //Macierz m2;
    //cout << "wpisz macierz" << endl;
    //cin >> m2;
    //cout << m2;
    
  //Wektor wynik;
  // double liczba;
                   
  
    //  if(m1==m2){
    //cout<<"macierze równe"<< endl;
    // }
    // else
    //cout<<"macierze nierówne"<<endl;
  // liczba = w1.dlugosc();
  // wynik = w1+w2;
  //wynik = w1-w2;
    //cout << "wektor 1: " << w1 << endl;
    //cout << "wektor 2: " << w2 << endl;
  // cout << "Wynik działania: " << liczba << endl;
  //  cout << "Wynik dodawania: " << wynik <<endl;
  exit(1);
}
