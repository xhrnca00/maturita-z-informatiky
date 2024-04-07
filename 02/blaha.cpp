#include <iostream>

using namespace std;

string sifruj(string zprava, string klic) {
    int delkaZpravy = zprava.length();
    int delkaKlice = klic.length();

    for (int i = 0; i < delkaZpravy; i++) {
        zprava[i] = zprava[i] + klic[i % delkaKlice] - 64;
        if (zprava[i] > 'Z')
            zprava[i] -= 26;
    }
    return zprava;
}

string desifruj(string zprava, string klic) {
    int delkaZpravy = zprava.length();
    int delkaKlice = klic.length();

    for (int i = 0; i < delkaZpravy; i++) {
        zprava[i] = zprava[i] - klic[i % delkaKlice] + 64;
        if (zprava[i] < 'A')
            zprava[i] += 26;
    }
    return zprava;
}

int main() {
    string zprava, klic, zasifrovanost;
    cout << "Zadej zpravu:";
    cin >> zprava;
    cout << "Zadej klic:";
    cin >> klic;
    zasifrovanost = sifruj(zprava, klic);
    cout << zasifrovanost << endl;
    zprava = desifruj(zasifrovanost, klic);
    cout << zprava << endl;

    return 0;
}
