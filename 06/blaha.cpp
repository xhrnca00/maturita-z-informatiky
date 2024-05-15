#include <iostream>

using namespace std;

void prevod10do2(unsigned char vstup, char *vystup) {
    unsigned char testovaciBit = 0x01;
    for (int i = 7; i >= 0; i--) {
        vystup[i] = (vstup & testovaciBit) ? '1' : '0';
        testovaciBit = testovaciBit << 1;
    }
    // for (int i = 7; i >= 0; i--) {
    //     vystup[i] = (vstup % 2) + '0';
    //     vstup = vstup / 2;
    // }
    vystup[8] = '\0';
}

void prevod2do10(char *vstup, unsigned char *vystup) {
    // unsigned char soucet = 0, mocnina = 0x80;
    // do {
    //     if (*vstup - '0')
    //         soucet |= mocnina;
    //     vstup += 1;
    //     mocnina >>= 1;
    // } while (mocnina);

    unsigned char soucet = 0, mocnina = 1;
    for (int i = 7; i >= 0; i--) {
        if (vstup[i] == '1') {
            soucet = soucet + mocnina;
        }
        mocnina = mocnina * 2;
    }
    *vystup = soucet;
}

int main() {
    char ret[9];
    unsigned char cislo;
    prevod10do2(241, ret);
    cout << ret << endl;
    prevod2do10(ret, &cislo);
    cout << (int)cislo << endl;
    return 0;
}
