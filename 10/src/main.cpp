#include <cstdint>
#include <fstream>
#include <iostream>

constexpr char IN[] = "VYPOVED.TXT";
constexpr char OUT[] = "SKUTECNE.TXT";

enum class State : uint8_t {
    X, // middle of word
    W, // new word about to begin
    N, // 'n' seen
};

int main() {
    std::ifstream infile(IN);
    std::ofstream outfile(OUT);
    if (!infile.is_open() || !outfile.is_open()) {
        std::cerr << "Unable to open one of the files\n";
        abort();
    }
    auto s = State::W;
    char c;
    while (infile.read(&c, 1)) {
        if (s == State::W && c == 'n') {
            s = State::N;
            continue;
        }
        if (s == State::N) {
            if (c == 'e') {
                s = State::X;
                continue;
            }
            outfile << 'n';
        }
        outfile << c;
        if (std::iswspace(c))
            s = State::W;
        else
            s = State::X;
    }
    infile.close();
    outfile.close();
    return 0;
}
