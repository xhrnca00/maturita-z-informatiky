#include <fstream>
#include <iostream>
#include <limits>

constexpr char F1[] = "A1.TXT";
constexpr char F2[] = "A2.TXT";
constexpr char F3[] = "A3.TXT";

void merge();
void elliminate();

int main() {
    merge();
    elliminate();
    return 0;
}

void merge() {
    std::ifstream in1(F1), in2(F2);
    std::ofstream out(F3);
    if (!in1.is_open() || !in2.is_open() || !out.is_open())
        abort();
    int a1, a2;
    auto e1 = bool(in1 >> a1), e2 = bool(in2 >> a2);
    const char *sep = "";
    while (e1 || e2) {
        out << sep;
        if (e1 && (!e2 || a1 < a2)) {
            out << a1;
            e1 = bool(in1 >> a1);
        } else {
            out << a2;
            e2 = bool(in2 >> a2);
        }
        sep = "\n";
    }
    in1.close();
    in2.close();
    out.close();
}

void elliminate() {
    constexpr char SECOND[] = "__TEMP.TXT";
    std::ifstream in(F3);
    std::ofstream out(SECOND);
    if (!in.is_open() || !out.is_open())
        abort();
    int last = std::numeric_limits<int>::min();
    int curr;
    const char *sep = "";
    while (in >> curr) {
        if (last == curr && *sep != '\0')
            continue;
        out << sep << curr;
        sep = "\n";
        last = curr;
    }
    in.close();
    out.close();
    std::ifstream m_in(SECOND);
    std::ofstream m_out(F3);
    if (!m_in.is_open() || !m_out.is_open())
        abort();
    sep = "";
    while (m_in >> curr) {
        m_out << sep << curr;
        sep = "\n";
    }
    m_in.close();
    m_out.close();
    std::ofstream del(SECOND);
    del.close();
}
