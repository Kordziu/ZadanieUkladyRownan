#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>
using namespace std;

class Wektor {
  double tab[ROZMIAR];

public:
  Wektor();
  Wektor(double * tab);
  
  const Wektor & operator += (const Wektor & W2);
  const Wektor & operator + (const Wektor & W2) const;
  const Wektor & operator - (const Wektor & W2) const;
  double operator * (const Wektor & W2) const; //iloczyn skalarny
  const Wektor & operator * (double liczba) const;
  //mnożenie przez liczbę

  bool operator == (const Wektor & W2) const;
  bool operator != (const Wektor & W2) const;

  double dlugosc() const;

  const double & operator [] (int index) const; //double z=W[3]

  double & operator [] (int index);
};

Wektor operator * (double l1, Wektor W2);
/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
istream& operator >> (istream &os, Wektor &w1);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
ostream& operator << (ostream &os, Wektor &w1);

#endif
