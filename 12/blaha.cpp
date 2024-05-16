#include <iostream>

using namespace std;

struct TPRVEK {
    int hodnota;
    TPRVEK *dalsi;
};

TPRVEK *zacatek = NULL;

void pridejHodnotu(int cislo) {
    TPRVEK *pom, *pom2;
    if (zacatek == NULL || zacatek->hodnota > cislo) {
        // pridej novy prvek na zacatek
        pom = new TPRVEK;
        pom->hodnota = cislo;
        pom->dalsi = zacatek;
        zacatek = pom;
    } else {
        // pridavame nekam dal
        pom = zacatek;
        while (pom->dalsi != NULL && pom->dalsi->hodnota < cislo)
            pom = pom->dalsi;

        pom2 = new TPRVEK;
        pom2->hodnota = cislo;
        pom2->dalsi = pom->dalsi;
        pom->dalsi = pom2;
    }
}

void tisk() {
    TPRVEK *pom;
    pom = zacatek;
    while (pom != NULL) {
        cout << pom->hodnota << " ";
        pom = pom->dalsi;
    }
    cout << endl << endl;
}

int main() {
    pridejHodnotu(6);
    tisk();
    pridejHodnotu(4);
    tisk();
    pridejHodnotu(2);
    tisk();
    pridejHodnotu(12);
    tisk();
    pridejHodnotu(1);
    tisk();
    pridejHodnotu(5);
    tisk();

    return 0;
}
