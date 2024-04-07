#include <cstring>
#include <iostream>

std::string encode(const std::string &text, const std::string &pass);
std::string decode(const std::string &text, const std::string &pass);

constexpr char ALPH_BEG = 'A';
constexpr char ALPH_LEN = 'Z' - 'A' + 1;

int main() {
    std::string msg, key;
    std::cout << "Give msg: ";
    std::cin >> msg;
    std::cout << "Give key: ";
    std::cin >> key;
    std::string enc = encode(msg, key);
    std::cout << "Encoded: " << enc << '\n';
    std::string dec = decode(enc, key);
    std::cout << "Decoded: " << dec << '\n';
    return 0;
}

char shift_c(char c, signed char amt) {
    return ALPH_BEG + ((c - ALPH_BEG + amt) % ALPH_LEN + ALPH_LEN) % ALPH_LEN;
}

std::string shift_s(
    const std::string &text,
    const std::string &pass,
    const signed char &coef = 1) {
    std::size_t pi = 0;
    std::string ret;
    for (const auto &c : text) {
        signed char shift_amt = (pass[pi] - ALPH_BEG + 1) * coef;
        ret += shift_c(c, shift_amt);
        pi = (pi + 1) % pass.length();
    }
    return ret;
}

std::string encode(const std::string &text, const std::string &pass) {
    return shift_s(text, pass);
}
std::string decode(const std::string &text, const std::string &pass) {
    return shift_s(text, pass, -1);
}
