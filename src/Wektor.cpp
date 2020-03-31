#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>

using namespace std;


//dodaj i podstaw wynik za podany wektor
const Wektor& Wektor::operator += (const Wektor &w1){
  int i;
  for(i=0; i < ROZMIAR; i++){

    this[i] = this[i] + w1[i]; 
  };
  return this;
}

//dodawanie dwóch wektorów
const Wektor& Wektor::operator + (const Wektor &w1) const{
  Wektor wynik;
  int i;
  for(i=0; i < ROZMIAR; i++){

    wynik[i] = this[i] + w1[i];
  };
   
  return wynik;
}
/*
//odejmowanie dwóch wektorów
const Wektor& Wektor::operator - (const Wektor &w1) const{
  Wektor w2;
  Wektor wynik;
  
    wynik.tab[0] = w1.tab[0] - w2.tab[0];
    wynik.tab[1] = w1.tab[1] - w2.tab[1];
    wynik.tab[2] = w1.tab[2] - w2.tab[2];

  return wynik;
}

//iloczyn skalarny
double Wektor::operator * (const Wektor &w1) const{
  Wektor w2;
  double wynik;

    wynik = w1.tab[0] * w2.tab[0] + w1.tab[1] * w2.tab[1] + w1.tab[3] * w2.tab[3];

  return wynik;
}

//mnożenie wektora przez liczbę
const Wektor& Wektor::operator * (double liczba) const{
  Wektor w1;
  Wektor wynik;

    wynik.tab[0] = w1.tab[0] * liczba;
    wynik.tab[1] = w1.tab[1] * liczba;
    wynik.tab[2] = w1.tab[2] * liczba;

  return wynik;
}

//porównanie dwóch wektorów
bool Wektor::operator == (const Wektor &w1) const{
  Wektor w1
}
*/
ostream & operator << (ostream &os, Wektor &w1){
  int i;

  os <<'[';
  for(i=0;i<ROZMIAR;i++){
    os << w1[i] << ',';
  }
  os << ']';
  os << endl;
  
  return os;
}

 //przeciazenie []
const double& Wektor::operator[] (int index) const{
    if (index < 0 || index >= ROZMIAR){
      cerr << "Wartość spoza zakresu" << endl;
      exit(1);
    }
    return this->tab[index];
  }

 double& Wektor::operator[] (int index){
    if (index < 0 || index >= ROZMIAR){
      cerr << "Wartość spoza zakresu" << endl;
      exit(1);
    }
    return this->tab[index];
  }
 

