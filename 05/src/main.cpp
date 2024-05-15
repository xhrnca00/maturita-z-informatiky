#include <array>
#include <fstream>
#include <iostream>

template <typename T, std::size_t X, std::size_t Y>
using mat_t = std::array<std::array<T, X>, Y>;

using mat = mat_t<int, 5, 5>;

mat load(const char *filename);
void save(const char *filename, const mat &m);
mat add(const mat &a, const mat &b);

int main() {
    constexpr char MATA[] = "MATA.DAT";
    constexpr char MATB[] = "MATB.DAT";
    constexpr char MATR[] = "MATC.DAT";
    auto ma = load(MATA);
    auto mb = load(MATB);
    auto mr = add(ma, mb);
    save(MATR, mr);
    std::cout << "Finished successfully\n";
    return 0;
}

mat load(const char *filename) {
    mat m;
    std::ifstream f(filename);
    if (!f.is_open()) {
        std::cerr << filename << " could not be opened\n";
        abort();
    }
    for (auto &row : m)
        for (auto &elem : row)
            f >> elem;
    f.close();
    return m;
}

void save(const char *filename, const mat &m) {
    std::ofstream f(filename);
    if (!f.is_open()) {
        std::cerr << filename << " could not be opened\n";
        abort();
    }
    for (auto &row : m) {
        const char *sep = "";
        for (auto &elem : row) {
            f << sep << elem;
            sep = " ";
        }
        f << '\n';
    }
    f.close();
}

mat add(const mat &a, const mat &b) {
    mat res;
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            res[i][j] = a[i][j] + b[i][j];
    return res;
}
