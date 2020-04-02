#include "Macierz.hh"
#include "Wektor.hh"

using namespace std;
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */



//konstruktor bezparametryczny
Macierz::Macierz(){

  
  for (int i = 0; i < ROZMIAR; i++){
    tab[i] = Wektor();
  }
}


/*
//przeciazenie operatora >>
istream & operator >> (istream &is, Wektor &w1){
  
  for(int i = 0; i < ROZMIAR; i++){
    if()

    is >> w1[i];
  }

  return is;
}
*/

//przeciazenie operatora <<
ostream & operator << (ostream &os, const Macierz &m1){

   for(int i= 0; i < ROZMIAR; i++){
     os << m1[i] << endl;
   }
   os << endl;
  return os;
}

//przeciazenie []
const Wektor& Macierz::operator[] (int index) const{
    if (index < 0 || index >= ROZMIAR){
      cerr << "Wartość spoza zakresu" << endl;
      exit(1);
    }
    return tab[index];
  }

Wektor& Macierz::operator[] (int index){
    if (index < 0 || index >= ROZMIAR){
      cerr << "Wartość spoza zakresu" << endl;
      exit(1);
    }
    return tab[index];
  }
