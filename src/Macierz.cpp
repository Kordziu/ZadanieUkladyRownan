#include "Macierz.hh"
#include "Wektor.hh"

using namespace std;
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

//Transpozycja
Macierz Macierz::transpozycja() const{
  Wektor kolumna;
  Macierz temp;

  for(int i = 0; i < ROZMIAR; i++){
    kolumna = zwroc_kolumne(i);
    temp[i] = kolumna;
  }
  return temp;
}


//Mnożenie macierz * wektor
Wektor Macierz::operator * (const Wektor w1) const{
  Wektor wynik;

  for(int i = 0; i < ROZMIAR; i++){
    wynik[i] = tab[i] * w1;
  }
  return wynik;
}

//Mnożenie macierz * macierz
Macierz Macierz::operator * (Macierz m1) const{
  Macierz wynik;

  for(int i = 0; i < ROZMIAR; i++){
    for(int j=0; j < ROZMIAR; j++){
      wynik[i][j] = tab[i] * m1.zwroc_kolumne(j);
  }
  }
  return wynik;
}

//Dodawanie macierzy
Macierz Macierz::operator + (const Macierz m1) const{
  Macierz wynik;

  for(int i = 0; i < ROZMIAR; i++){
    for(int j = 0; j < ROZMIAR; j++){
    wynik[i] = tab[i]+m1[i];
    }
  }
  return wynik;
}

//Odejmowanie macierzy
Macierz Macierz::operator - (const Macierz m1) const{
  Macierz wynik;

  for(int i = 0; i < ROZMIAR; i++){
    for(int j = 0; j < ROZMIAR; j++){
    wynik[i] = tab[i]-m1[i];
    }
  }
  return wynik;
}

//Mnożenie macierzy przez liczbę
Macierz Macierz::operator * (const double liczba) const{
  Macierz wynik;

  for(int i = 0; i < ROZMIAR; i++){
  wynik[i] = tab[i] * liczba;
  }
  return wynik;
}

//porównanie == dla macierzy
bool Macierz::operator == (const Macierz &m1) const{

  for(int i = 0; i < ROZMIAR; i++){
    if(tab[i]!=m1[i]){
      return false;
    }
  }
  return true;
}

//porównanie != dla macierzy
bool Macierz::operator != (const Macierz &m1) const{

  for(int i = 0; i < ROZMIAR; i++){
    if(tab[i]!=m1[i]){
      return true;
    }
  }
  return false;
}


//zwracanie kolumny z macierzy
Wektor Macierz::zwroc_kolumne(int nr_kolumny) const{
  Wektor kolumna;

  for(int i = 0; i < ROZMIAR; i++){
    kolumna[i] = tab[i][nr_kolumny];
  }
  return kolumna;
}

//zamiana kolumny na dowolny podany wektor
Macierz Macierz::zmien_kolumne(int nr_kolumny, Wektor nowa){
  Macierz pom;
  pom = transpozycja();
  pom[nr_kolumny] = nowa;
  pom = pom.transpozycja();
  return pom;
}


//konstruktor bezparametryczny
Macierz::Macierz(){
  
  for (int i = 0; i < ROZMIAR; i++){
    tab[i] = Wektor();
  }
}

//konstruktor parametryczny
Macierz::Macierz(Wektor *w1){
  for(int i=0; i < ROZMIAR; i++){
    tab[i] = w1[i];
  }
}


//przeciazenie operatora >>
istream & operator >> (istream &is, Macierz &m1){
  
  for(int i = 0; i < ROZMIAR; i++){
    
    is >> m1[i];
  }

  return is;
}


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
