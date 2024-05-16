#include "retezce.h"
#include <cstring>

void strdel(char *s, int pozice, int pocet) {
    char last = 1;
    while (last != '\0') {
        s[pozice] = s[pozice + pocet];
        last = s[pozice + pocet];
        ++pozice;
    }
}

void strins(char *s1, char *s2, int pozice) {
    int l = std::strlen(s2);
    for (int i = std::strlen(s1); i >= pozice; --i) {
        s1[i + l] = s1[i];
    }
    for (int i = 0; i < l; ++i) {
        s1[pozice + i] = s2[i];
    }
}
