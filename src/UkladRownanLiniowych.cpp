#include "UkladRownanLiniowych.hh"
#include "Macierz.hh"
#include "Wektor.hh"
#include "rozmiar.h"

using namespace std;

// Zwracanie macierzy glownej
//const Macierz & UkladRownan::get_A() const {
// return A;
//}

//Zwracanie wektora wyrazow wolnych
//const Wektor & UkladRownan::get_b() const {
//  return b;
//}

//Wektor błędu
Wektor UkladRownan::w_bledu() const {
  Wektor wynik;

  wynik = get_A() * Oblicz() - get_b();

  return wynik;
}

//Dlugosc Wektora błędu
double UkladRownan::dl_bledu() const {
  double wynik = w_bledu().dlugosc();

  return wynik;
}

//Obliczanie metodą Cramera
Wektor UkladRownan::Oblicz() const {
  Wektor wynik;
  Macierz temp = get_A(); // Kopia macierzy głównej, żeby nie pracować na oryginale
  double tab_wyznacznikow[ROZMIAR]; // Tablica z wynikami x1, x2... żeby potem wrzucić ją do Wektora wynikowego
  double wyznacznik_glowny;

  wyznacznik_glowny = get_A().wyznacznik();

  if(abs(wyznacznik_glowny) > dokladnosc) {
  
  for(int i = 0; i < ROZMIAR; i++) {
    temp.zmien_kolumne(i, get_b());
    tab_wyznacznikow[i] = temp.wyznacznik();
    tab_wyznacznikow[i] /= wyznacznik_glowny;
    temp = get_A();
    }
  }
  else
    {
      cerr << "Wyznacznik macierzy głównej wynosi 0. Uklad równań nie ma rozwiązania.";
    }
  return Wektor(tab_wyznacznikow);
}

istream & operator >> (istream &is, UkladRownan & UklRown) {
  Wektor tempw;
  Macierz tempm;

  is >> tempm;
  is >> tempw;

  UklRown = UkladRownan(tempm, tempw);
  return is;
}

ostream & operator << (ostream & os, const UkladRownan & UklRown) {
  cout << "Macierz główna: " << endl << UklRown.get_A() << endl;
  cout << "Wektor wyrazów wolnych: " << endl << UklRown.get_b() << endl;
  cout << "Rozwiązanie (x1, x2, ... xn): " << endl << UklRown.Oblicz() << endl;
  cout << "Wektor błędu: Ax-b = " << UklRown.w_bledu() << endl;
  cout << "Długość wektora błędu: |Ax-b| = " << UklRown.dl_bledu() << endl;
  return os;
}
