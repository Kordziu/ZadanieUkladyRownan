#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>

using namespace std;

class Macierz{
  Wektor tab[ROZMIAR];//3 propozycja, sugerowana

public:
  Macierz();
  Macierz(Wektor a1, Wektor a2, Wektor a3);
  const Macierz & transpozycja() const;
  void transpozycja();

  const Macierz & odwrotnosc() const;
  void odwrotnosc();//z definicji, gauss

  double wyznacznik();//laplace, gauss, sarrus
  double wyznacznikGauss(); //double wyznacznik(Metoda = Gauss) <- enum
  
  Wektor operator * (Wektor W);
  Macierz operator * (Macierz W);
  Macierz operator + (Macierz W);
  Macierz operator - (Macierz W);
  Macierz operator * (double l);

  bool operator == (const Macierz & W2) const;
  bool operator != (const Macierz & W2) const;

  const Wektor & operator[] (int index) const;
  Wektor & operator[] (int index); // M[2][0] - zerowy element drugiego wektora macierzy

  const double & operator() (int ind1, int ind2) const;
  double & operator() (int ind1, int ind2); //M(2,0)

  const Wektor & zwroc_kolumne(int ind); //dla wierszowej
  void zmien_kolumne(int ind, Wektor nowa);
};



/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
istream& operator >> (istream &Strm, Macierz &m1);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
ostream& operator << (ostream &Strm, const Macierz &m1);


#endif
