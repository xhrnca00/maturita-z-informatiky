#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct TPRACOVNIK {
    char jmeno[50];
    int plat;
    char funkce[30];
};

int main() {
    ifstream soubor1;
    ofstream soubor2;
    string radek;
    TPRACOVNIK pracovnik;

    soubor1.open("tabulka.csv");
    soubor2.open("tabulka.bin", ios::binary | ios::out);

    while (getline(soubor1, radek)) {
        cout << "Nacteno: " << radek << endl;
        // odstraneni cisla
        int pozice = radek.find(";");
        radek.erase(0, pozice + 1);
        cout << radek << endl;
        // hledani, ziskani a odstraneni jmena
        pozice = radek.find(";");
        string jmeno = radek.substr(0, pozice);
        cout << "Jmeno: " << jmeno << endl;
        radek.erase(0, pozice + 1);
        cout << radek << endl;
        // hledani, ziskani a odstraneni platu
        pozice = radek.find(";");
        string plat = radek.substr(0, pozice);
        cout << "Plat: " << plat << endl;
        radek.erase(0, pozice + 1);
        cout << radek << endl;
        // prevod stringu do struktury
        strcpy(pracovnik.jmeno, jmeno.c_str());
        pracovnik.plat = stoi(plat);
        // pracovnik.plat=atoi(plat.c_str());
        strcpy(pracovnik.funkce, radek.c_str());
        // zapis do souboru
        soubor2.write((char *)&pracovnik, sizeof(TPRACOVNIK));
    }

    soubor2.close();
    soubor1.close();

    return 0;
}
