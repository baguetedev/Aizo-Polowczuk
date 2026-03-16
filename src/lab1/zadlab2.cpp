#include <iostream>
#include <thread>
#include <vector>

long long obliczWyznacznik(const std::vector<std::vector<long long>> &macierz, long long wiersz,
                     std::vector<long long> dostepne_kolumny) {
  long long n = dostepne_kolumny.size();
  if (n == 1)
    return macierz[wiersz][dostepne_kolumny[0]];
  if (n == 2)
    return macierz[wiersz][dostepne_kolumny[0]] *
               macierz[wiersz + 1][dostepne_kolumny[1]] -
           macierz[wiersz][dostepne_kolumny[1]] *
               macierz[wiersz + 1][dostepne_kolumny[0]];

  long long wyznacznik = 0, znak = 1;
  for (long long i = 0; i < n; ++i) {
    std::vector<long long> nowe_kolumny;
    nowe_kolumny.reserve(n - 1);
    for (long long j = 0; j < n; ++j) {
      if (i != j)
        nowe_kolumny.push_back(dostepne_kolumny[j]);
    }
    wyznacznik += znak * macierz[wiersz][dostepne_kolumny[i]] *
                  obliczWyznacznik(macierz, wiersz + 1, nowe_kolumny);
    znak = -znak;
  }
  return wyznacznik;
}

void watekLaplace(const std::vector<std::vector<long long>> &macierz, long long id_watku,
                  long long liczba_watkow, std::vector<long long> dostepne_kolumny,
                  long long &wynik) {
  wynik = 0;
  long long n = dostepne_kolumny.size();
  for (long long indeks = id_watku; indeks < n; indeks += liczba_watkow) {
    std::vector<long long> nowe_kolumny;
    nowe_kolumny.reserve(n - 1);
    for (long long j = 0; j < n; ++j) {
      if (indeks != j)
        nowe_kolumny.push_back(dostepne_kolumny[j]);
    }
    long long podwyznacznik = obliczWyznacznik(macierz, 1, nowe_kolumny);
    long long znak = (indeks % 2 == 0) ? 1 : -1;
    wynik += znak * macierz[0][dostepne_kolumny[indeks]] * podwyznacznik;
  }
}

int main() {
  long long wiersze, kolumny, liczba_watkow;
  std::cout << "podaj ilosc wierszy: ";
  std::cin >> wiersze;
  std::cout << "podaj ilosc kolumn: ";
  std::cin >> kolumny;
  std::cout << "podaj ilosc watkow: ";
  std::cin >> liczba_watkow;

  if (wiersze != kolumny) {
    std::cout << "zeby policzyc wyznacznik musi to byc macierz kwadratowa \n";
    return 0;
  }

  std::vector<std::vector<long long>> macierz(wiersze, std::vector<long long>(kolumny, 0));
  for (long long i = 0; i < wiersze; i++) {
    for (long long j = 0; j < kolumny; j++)
      std::cin >> macierz[i][j];
  }

  if (wiersze == 1) {
    std::cout << macierz[0][0] << "\n";
    return 0;
  }

  std::vector<std::thread> watki;
  std::vector<long long> wyniki(liczba_watkow, 0), kolumny_pocz(wiersze);
  for (long long i = 0; i < wiersze; ++i)
    kolumny_pocz[i] = i;

  for (long long i = 0; i < liczba_watkow; ++i) {
    watki.push_back(std::thread(watekLaplace, std::cref(macierz), i,
                                liczba_watkow, kolumny_pocz,
                                std::ref(wyniki[i])));
  }

  long long wyznacznik = 0;
  for (long long i = 0; i < liczba_watkow; ++i) {
    watki[i].join();
    wyznacznik += wyniki[i];
  }

  std::cout << wyznacznik << "\n";
  return 0;
}
