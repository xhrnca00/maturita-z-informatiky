#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

struct TCLOVEK {
    char jmeno[30], prijmeni[30];
    char rodneCislo[11];
};

void vytvoreniSouboru() {
    ofstream soubor;
    soubor.open("lidi.dat");
    soubor.close();
}

void pridejCloveka() {
    TCLOVEK clovek;
    cout << "Zadej prijmeni:";
    cin >> clovek.prijmeni;
    cout << "Zadej jmeno:";
    cin >> clovek.jmeno;
    cout << "Zadej rodne cislo:";
    cin >> clovek.rodneCislo;

    fstream soubor;
    soubor.open("lidi.dat", ios::binary | ios::out | ios::app);
    if (soubor.is_open()) {
        // soubor.seekp(0, ios::end);
        soubor.write((char *)&clovek, sizeof(TCLOVEK));
        soubor.close();
        cout << "Novy clovek byl pridan do souboru." << endl;
    } else
        cout << "Soubor se nepovedlo otevrit." << endl;
}

void tiskniLidi() {
    ifstream soubor;
    TCLOVEK clovek;
    soubor.open("lidi.dat", ios::binary | ios::in);
    while (soubor.read((char *)&clovek, sizeof(TCLOVEK))) {
        cout << clovek.prijmeni << endl;
        cout << clovek.jmeno << endl;
        cout << clovek.rodneCislo << endl;
        // tisk data narozeni
        cout << clovek.rodneCislo[4] << clovek.rodneCislo[5] << ".";
        if (clovek.rodneCislo[2] > '1')
            clovek.rodneCislo[2] -= 5;
        cout << clovek.rodneCislo[2] << clovek.rodneCislo[3] << ".";
        int rok = (clovek.rodneCislo[0] - 48) * 10 + clovek.rodneCislo[1] - 48;
        if (strlen(clovek.rodneCislo) == 9 && rok >= 54)
            cout << "18"; // rc 9 znaku, rok >=54
        else if (strlen(clovek.rodneCislo) == 10 && rok < 54)
            cout << "20"; // rc 10 znaku, rok <54
        else
            cout << "19"; // vse ostatni

        cout << clovek.rodneCislo[0] << clovek.rodneCislo[1];
        cout << endl << endl;
    }
    soubor.close();
}

int main() {
    // vytvoreniSouboru();
    // pridejCloveka();
    tiskniLidi();
    return 0;
}
