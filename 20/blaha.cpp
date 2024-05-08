#include <iostream>
#include <fstream>

using namespace std;

void kopirujSoubor(string nazev, string slozka){
    cout << "Zacinam kopirovat soubor "<<nazev<<endl;

    ifstream soubor1;
    ofstream soubor2;
    char bajt;

    soubor1.open(nazev.c_str(),ios::binary|ios::in);
    soubor2.open((slozka+nazev).c_str(),ios::binary|ios::out);

    while(soubor1.read((char*)&bajt, sizeof(char))){
        soubor2.write(&bajt, 1);
    }

    soubor2.close();
    soubor1.close();

    cout << "Kopirovani ukonceno"<<endl;
}

int main()
{
    ifstream soubor;
    string slozka;
    string nazev;

    cout << "Instalacni program" << endl;
    cout << "Zadej slozku pro instalaci:";
    cin >> slozka;

    soubor.open("soubory.txt");
    while(getline(soubor,nazev)){
        cout << "Budeme kopirovat soubor "<<nazev<<endl;
        kopirujSoubor(nazev, slozka);
    }

    soubor.close();
    cout << "Instalace dokoncena."<<endl;

    return 0;
}
