#include <iostream>

using namespace std;

int main() {
    string a, b;
    int poleA[100], poleB[100], poleC[100];

    cout << "Zadej 1. cele cislo:";
    cin >> a;
    cout << "Zadej 2. cele cislo:";
    cin >> b;

    // nulovani poli
    for (int i = 0; i < 100; i++)
        poleA[i] = poleB[i] = poleC[i] = 0;

    // prevod a do poleA
    int delkaA = a.length();
    for (int i = delkaA - 1, j = 0; i >= 0; i--, j++)
        poleA[j] = a[i] - 48;

    // prevod b do poleB
    int delkaB = b.length();
    for (int i = delkaB - 1, j = 0; i >= 0; i--, j++)
        poleB[j] = b[i] - 48;

    // soucet
    int prenos = 0;
    for (int i = 0; i < 100; i++) {
        poleC[i] = poleA[i] + poleB[i] + prenos;
        if (poleC[i] > 9) {
            poleC[i] -= 10;
            prenos = 1;
        } else
            prenos = 0;
    }
    // tisk vysledku
    bool uzMuzuTisknout = false;
    for (int i = 99; i >= 0; i--) {
        if (poleC[i] != 0)
            uzMuzuTisknout = true;
        if (uzMuzuTisknout)
            cout << poleC[i];
    }
    cout << endl;

    return 0;
}
