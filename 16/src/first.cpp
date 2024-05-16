#include <fstream>
#include <iostream>
#include <tuple>
#include <vector>

constexpr char FILENAME[] = "ROVNICE.TXT";

// (x, y)
using dim_t = std::pair<std::size_t, std::size_t>;
template <typename T>
using mat_t = std::vector<T>;
using mat = mat_t<int>;

mat load_mat(const dim_t &dim, std::istream &is);
void print_mat(const mat &m, const dim_t &dim, std::ostream &os);
void add(mat &m, const dim_t &dim, std::size_t res_r, std::size_t add_r);
void mul(mat &m, const dim_t &dim, std::size_t res_r, int coef);
void swap(mat &m, const dim_t &dim, std::size_t a, std::size_t b);

int main() {
    dim_t dim = {6, 5};
    std::ifstream f(FILENAME);
    if (!f.is_open())
        abort();
    auto m = load_mat(dim, f);
    f.close();

    add(m, dim, 0, 1);
    mul(m, dim, 2, 2);
    swap(m, dim, 1, 2);
    print_mat(m, dim, std::cout);

    return 0;
}

mat load_mat(const dim_t &dim, std::istream &is) {
    const auto [x, y] = dim;
    mat m;
    m.reserve(x * y);
    for (std::size_t i = 0; i < x * y; ++i) {
        int elem;
        is >> elem;
        m.push_back(elem);
    }
    return m;
}

void print_mat(const mat &m, const dim_t &dim, std::ostream &os) {
    const auto [x, y] = dim;
    for (std::size_t i = 0; i < y; ++i) {
        const char *sep = "";
        for (std::size_t j = 0; j < x; ++j) {
            os << sep << m[i * x + j];
            sep = " ";
        }
        os << '\n';
    }
    os << std::endl;
}

void add(mat &m, const dim_t &dim, std::size_t res_r, std::size_t add_r) {
    const auto [x, y] = dim;
    for (std::size_t i = 0; i < x; ++i)
        m[res_r * x + i] += m[add_r * x + i];
}

void mul(mat &m, const dim_t &dim, std::size_t res_r, int coef) {
    const auto [x, y] = dim;
    for (std::size_t i = 0; i < x; ++i)
        m[res_r * x + i] *= coef;
}

void swap(mat &m, const dim_t &dim, std::size_t a, std::size_t b) {
    const auto [x, y] = dim;
    for (std::size_t i = 0; i < x; ++i)
        std::swap(m[a * x + i], m[b * x + i]);
}
