#include <fstream>
#include <iostream>

using namespace std;

struct TPRVEK {
    string slovo;
    int pocet;
    TPRVEK *dalsi;
};

TPRVEK *zacatek = NULL;

void zpracujSlovo(string noveSlovo) {
    // 1. prohledani seznamu
    TPRVEK *pom;
    pom = zacatek;
    while (pom != NULL) {
        if (pom->slovo == noveSlovo) {
            pom->pocet = pom->pocet + 1;
            cout << "Slovo bylo nalezeno v seznamu" << endl;
            return;
        }
        pom = pom->dalsi;
    }

    // 2.pridani noveho prvku na zacatek
    pom = new TPRVEK;
    pom->slovo = noveSlovo;
    pom->pocet = 1;
    pom->dalsi = zacatek;
    zacatek = pom;
    cout << "Nove slovo bylo pridano na zacatek" << endl;
}

void tisk() {
    TPRVEK *pom;
    pom = zacatek;
    while (pom != NULL) {
        cout << pom->slovo << " " << pom->pocet << endl;
        pom = pom->dalsi;
    }
    cout << "Tisk ukoncen." << endl;
}

int main() {
    ifstream soubor;
    string noveSlovo;
    soubor.open("ZPRAVA.TXT");

    // while(getline(soubor,noveSlovo)){
    while (soubor >> noveSlovo) {
        cout << "Bylo nacetno: " << noveSlovo << endl;
        zpracujSlovo(noveSlovo);
    }
    soubor.close();
    tisk();

    return 0;
}
