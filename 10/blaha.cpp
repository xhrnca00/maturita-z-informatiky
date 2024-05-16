#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream soubor1("vypoved.txt");
    ofstream soubor2;
    char znak;
    int pozor = 0;
    string radek;
    soubor2.open("skutecne.txt");

    // while(getline(soubor,radek))
    while (soubor1.get(znak)) {
        if (pozor == 0) { // nebyla ani mezera
            soubor2 << znak;
            cout << znak;
            if (znak == ' ')
                pozor = 1;
        } else {
            if (pozor == 1) { // bacha, minule byla mezera
                if (znak == 'n')
                    pozor = 2;
                else {
                    soubor2 << znak;
                    cout << znak;
                    pozor = 0;
                }
            } else { // bacha, minule byla mezera a 'n'
                if (znak != 'e') {
                    soubor2 << "n" << znak;
                    cout << "n" << znak;
                }
                pozor = 0;
            }
        }
    }

    soubor2.close();
    soubor1.close();
    return 0;
}
