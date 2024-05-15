#include <cstdint>
#include <iostream>

void prevod10do2(unsigned char vstup, char *vystup);
void prevod2do10(const char *vstup, unsigned char *vystup);

int main() {
    constexpr unsigned char NUMBER = 243;
    std::cout << (uint16_t)NUMBER << std::endl;
    char text[9];
    prevod10do2(NUMBER, text);
    std::cout << text << std::endl;
    unsigned char num;
    prevod2do10(text, &num);
    std::cout << (uint16_t)num << std::endl;
    return 0;
}

void prevod10do2(unsigned char vstup, char *vystup) {
    unsigned char d = 1;
    constexpr unsigned char radix = 2;
    constexpr unsigned char max_pow = sizeof(vstup) * CHAR_BIT - 1;
    for (int pow = 0; pow <= max_pow; ++pow) {
        vystup[max_pow - pow] = vstup & d ? '1' : '0';
        d *= radix;
    }
    vystup[8] = '\0';
}

void prevod2do10(const char *vstup, unsigned char *vystup) {
    *vystup = 0;
    constexpr unsigned char max_pow = sizeof(*vystup) * CHAR_BIT - 1;
    for (int pow = 0; pow <= max_pow; ++pow)
        *vystup += (vstup[max_pow - pow] - '0') * (1 << pow);
}
