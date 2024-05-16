#include <iostream>

using namespace std;

class SetridenePole {
private:
    int *polePrvku;
    int pocetPrvku;
    int maxPocet;

public:
    SetridenePole(int max = 1000);
    int vlozDoPole(int cislo);
    void tiskniPole();
};
SetridenePole::SetridenePole(int max) {
    polePrvku = new int[max];
    pocetPrvku = 0;
    maxPocet = max;
    cout << "Vzniklo pole o " << max << " prvcich" << endl;
}
int SetridenePole::vlozDoPole(int cislo) {
    if (pocetPrvku < maxPocet) {
        polePrvku[pocetPrvku] = cislo;
        pocetPrvku++;

        int kdeJeNovy = pocetPrvku - 1;
        while (kdeJeNovy > 0 && polePrvku[kdeJeNovy] < polePrvku[kdeJeNovy - 1]) {
            int pom = polePrvku[kdeJeNovy];
            polePrvku[kdeJeNovy] = polePrvku[kdeJeNovy - 1];
            polePrvku[kdeJeNovy - 1] = pom;
            kdeJeNovy--;
        }

        return 1;
    } else
        return 0;
}
void SetridenePole::tiskniPole() {
    for (int i = 0; i < pocetPrvku; i++) {
        cout << polePrvku[i] << " ";
    }
    cout << endl << endl;
}

int main() {
    SetridenePole a;
    int vstup;
    do {
        cout << "Zadej cislo (0=konec):";
        cin >> vstup;
        a.vlozDoPole(vstup);
        a.tiskniPole();
    } while (vstup != 0);

    return 0;
}
