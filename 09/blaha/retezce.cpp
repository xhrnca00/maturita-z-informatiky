#include "retezce.h"
#include <cstring>
#include <iostream>

using namespace std;

void pokusnyPozdrav() {
    cout << "Nazdar" << endl;
}

void strdel(char *s, int pozice, int pocet) {
    int odkud = pozice + pocet;
    int kam = pozice;
    do {
        s[kam] = s[odkud];
        odkud++;
        kam++;
    } while (s[kam - 1] != 0);
}

void strins(char *s1, char *s2, int pozice) {
    int delkaS1 = strlen(s1);
    int delkaS2 = strlen(s2);
    // vytvor prostor
    for (int i = delkaS1; i >= pozice; i--)
        s1[i + delkaS2] = s1[i];
    // zkopiruj s2 do s1
    for (int i = 0; i < delkaS2; i++)
        s1[pozice + i] = s2[i];
}
