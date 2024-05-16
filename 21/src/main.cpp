#include <cstdint>
#include <fstream>
#include <iostream>

constexpr char INFILE[] = "in.txt";
constexpr char OUTFILE[] = "out.txt";

enum class State : uint8_t {
    F, // first letter of word
    W, // in word
    X, // not in word
    S, // one letter word behind (eat spaces)
};

int main() {
    constexpr char NBSP[] = "&nbsp;";
    std::ifstream in(INFILE);
    std::ofstream out(OUTFILE);
    if (!in.is_open() || !out.is_open())
        abort();
    char c;
    auto s = State::X;
    while (in.read(&c, 1)) {
        bool is_s = c == ' ';
        if (s == State::S && is_s)
            continue;
        if (s == State::F && is_s) {
            s = State::S;
            out.write(NBSP, sizeof(NBSP) - 1); // not writing '\0'
            continue;
        }
        out.write(&c, 1);
        if (is_s) {
            s = State::X;
        } else if (s == State::X || s == State::S)
            s = State::F;
        else
            s = State::W;
    }
    return 0;
}
