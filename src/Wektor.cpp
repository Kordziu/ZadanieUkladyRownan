#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;


//dodaj i podstaw wynik za podany wektor
const Wektor& Wektor::operator += (const Wektor &w1){
  int i;
  for(i = 0; i < ROZMIAR; i++){

   this->tab[i] = this->tab[i] + w1[i]; 
  };
  return *this;
}

//dodawanie dwóch wektorów
  Wektor Wektor::operator + (const Wektor &w1) const{
  Wektor wynik;
  int i;
  for(i = 0; i < ROZMIAR; i++){

    wynik[i] = this->tab[i] + w1[i];
  };
   
  return wynik;
}

//odejmowanie dwóch wektorów
  Wektor Wektor::operator - (const Wektor &w1) const{
  Wektor wynik;
  int i;
    for(i = 0; i < ROZMIAR; i++){

    wynik[i] = this->tab[i] - w1[i];
  };

  return wynik;
}

//iloczyn skalarny
double Wektor::operator * (const Wektor &w1) const{
  Wektor tmp;
  double wynik=0;
  int i;
    for(i = 0; i < ROZMIAR; i++){
      tmp[i] = this->tab[i] * w1[i];
  };

    for(i = 0; i < ROZMIAR; i++){
      wynik = wynik + tmp[i];
    }
  return wynik;
}

//mnożenie wektora przez liczbę
Wektor Wektor::operator * (double liczba) const{
  Wektor wynik;

  for(int i = 0; i < ROZMIAR; i++){
    wynik[i] = liczba * this->tab[i];
  }

  return wynik;
}

//mnożenie liczba * wektor
Wektor operator * (double liczba, Wektor w1){
  Wektor wynik;

  for(int i = 0; i < ROZMIAR; i++){
    wynik[i] = liczba * w1[i];
  }

  return wynik;
}

//porównanie dwóch wektorów
bool Wektor::operator == (const Wektor &w1) const{

  
  for(int i = 0; i < ROZMIAR; i++){
    if(this->tab[i]!=w1[i]){
      return false;
    }
  }
  return true;
}

//porownanie != dwóch wektorów
bool Wektor::operator != (const Wektor &w1) const{
 
  for(int i = 0; i < ROZMIAR; i++){
    if(this->tab[i]==w1[i]){
      return false;
    }
  }
  return true;
}

//dlugosc wektora
double Wektor::dlugosc() const{
  double dlugosc = 0;

  for(int i = 0; i < ROZMIAR; i++){
  dlugosc = dlugosc + this->tab[i] * this->tab[i];
  }

  return sqrt(dlugosc);
}

//przeciazenie operatora <<
ostream & operator << (ostream &os, const Wektor &w1){
  int i;
  
  os <<'[';
  for(i = 0; i < ROZMIAR; i++){
    os << w1[i];
    if(i < ROZMIAR-1){
      os << ',';
    }
  }
  os << ']';
  os << endl;
  
  return os;
}

//przeciazenie operatora >>
istream & operator >> (istream &is, Wektor &w1){
  
  for(int i = 0; i < ROZMIAR; i++){
    is >> w1[i];
  }

  return is;
}

//kontruktor bezparametryczny
Wektor::Wektor(){
  for(int i = 0; i < ROZMIAR; i++){
    tab[i] = 0.0;
  }
}

//przeciazenie []
const double& Wektor::operator[] (int index) const{
    if (index < 0 || index >= ROZMIAR){
      cerr << "Wartość spoza zakresu" << endl;
      exit(1);
    }
    return tab[index];
  }

double& Wektor::operator[] (int index){
    if (index < 0 || index >= ROZMIAR){
      cerr << "Wartość spoza zakresu" << endl;
      exit(1);
    }
    return tab[index];
  }

//konstruktor parametryczny
Wektor::Wektor(double * tab){
   for(int i = 0; i < ROZMIAR; i++){
   this->tab[i] = tab[i];
  }
  
}
