#include <iostream>
#include <thread>
#include <vector>
void Dzielniki(long long start, long long koniec, long long liczba) {
  for (; start <= koniec; start++) {
    if (liczba % start == 0)
      std::cout << start << " \n";
  }
}

int main() {
  int ile_watkow;
  long long start;
  long long  koniec;
  long long liczba;
  std::cout << "ile watkow uzyc?: ";
  std::cin >> ile_watkow;
  std::cout << "podaj liczbe: \n";
  std::cin >> liczba;
  std::vector<std::thread> lista_roboli;
  for (int i = 0; i < ile_watkow; i++) {
    long long ilosc = liczba / ile_watkow;
    start = i * ilosc + 1;
    koniec = (i + 1) * ilosc;
    if (i == ile_watkow - 1) {
      koniec = liczba;
    }
    lista_roboli.push_back(std::thread(Dzielniki, start, koniec, liczba));
  }
  for (int j = 0; j < lista_roboli.size(); j++) {
    lista_roboli[j].join();
  }
}
