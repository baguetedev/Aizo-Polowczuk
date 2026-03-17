#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Regula {
    string stan; char symbol; char nowy_symbol; char kierunek; string nowy_stan;
};

int main() {
    vector<Regula> reguly;
    string aktualny_stan, tasma;
    int pozycja_glowicy = 0;

    ifstream plik_z_regulami("zasady.txt");
    string wczytany_stan, wczytany_nowy_stan; 
    char wczytany_symbol, wczytany_nowy_symbol, wczytany_kierunek;
    
    while (plik_z_regulami >> wczytany_stan >> wczytany_symbol >> wczytany_nowy_symbol >> wczytany_kierunek >> wczytany_nowy_stan) {
        reguly.push_back({wczytany_stan, wczytany_symbol, wczytany_nowy_symbol, wczytany_kierunek, wczytany_nowy_stan});
    }

    ifstream plik_z_danymi("dane.txt");
    plik_z_danymi >> aktualny_stan >> tasma;

    bool czy_maszyna_dziala = true;
    
    while (czy_maszyna_dziala) {
        czy_maszyna_dziala = false;

        for (int i = 0; i < reguly.size(); i++) {
            if (reguly[i].stan == aktualny_stan && reguly[i].symbol == tasma[pozycja_glowicy]) {
                tasma[pozycja_glowicy] = reguly[i].nowy_symbol;
                aktualny_stan = reguly[i].nowy_stan;
                
                if (reguly[i].kierunek == 'R') pozycja_glowicy++;
                if (reguly[i].kierunek == 'L') pozycja_glowicy--;
                
                czy_maszyna_dziala = true;
                break;
            }
        }
    }

    cout << "Koniec! Wynik to: " << tasma << endl;
    
    return 0;
}
