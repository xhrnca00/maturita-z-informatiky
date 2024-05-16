#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    int pole[25];
    srand(time(NULL));

    for (int i = 0; i < 25; i++) {
        pole[i] = rand() % 100;
        cout << pole[i] << " ";
    }
    cout << endl << endl;

    for (int j = 0; j < 24; j++) {
        // jeden pruchod
        for (int i = 0; i < 24; i++) {
            if (pole[i] > pole[i + 1]) {
                int pom = pole[i];
                pole[i] = pole[i + 1];
                pole[i + 1] = pom;
            }
        }
    }

    for (int i = 0; i < 25; i++) {
        cout << pole[i] << " ";
    }
    cout << endl << endl;

    int hledaneCislo;
    cout << "Zadej hledane cislo:";
    cin >> hledaneCislo;

    int dolni, horni, stred;
    dolni = 0;
    horni = 24;
    do {
        cout << "Hledam na intervalu od " << dolni << " po " << horni << endl;
        stred = (dolni + horni) / 2;
        if (pole[stred] == hledaneCislo) {
            cout << "Nalezeno na pozici " << stred << endl;
        } else if (pole[stred] < hledaneCislo) {
            // je to v prave pulce
            dolni = stred + 1;
        } else {
            // je to v leve pulce
            horni = stred - 1;
        }
    } while (pole[stred] != hledaneCislo && dolni <= horni);

    if (dolni > horni) {
        cout << "Nenalezeno." << endl;
    }

    return 0;
}
