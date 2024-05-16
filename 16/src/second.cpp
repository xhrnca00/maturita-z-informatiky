#include <fstream>
#include <iostream>
#include <tuple>
#include <vector>

// (x, y)
using dim_t = std::pair<std::size_t, std::size_t>;
template <typename T>
using mat_t = std::vector<T>;
using mat = mat_t<double>;

mat load_mat(const dim_t &dim, const char *filename);
void print_mat(const mat &m, const dim_t &dim);
bool is_row_dominant(const mat &m, const dim_t &dim);
bool is_col_dominant(const mat &m, const dim_t &dim);

// TODO: WHAT IS N??? IS THE MATRIX A SQUARE???
// assuming n = dim.y
int main() {
    dim_t dim = {3, 3};
    auto m = load_mat(dim, "ROVNICE.TXT");
    print_mat(m, dim);
    std::cout << "Dominance: row: " << is_row_dominant(m, dim)
              << " col: " << is_col_dominant(m, dim) << std::endl;
    return 0;
}

mat load_mat(const dim_t &dim, const char *filename) {
    const auto [x, y] = dim;
    std::ifstream f(filename);
    if (!f.is_open())
        abort();
    mat m;
    m.resize(x * y);
    for (std::size_t i = 0; i < x * y; ++i)
        f >> m[i];
    f.close();
    return m;
}

void print_mat(const mat &m, const dim_t &dim) {
    const auto [x, y] = dim;
    for (std::size_t i = 0; i < y; ++i) {
        const char *sep = "";
        for (std::size_t j = 0; j < x; ++j) {
            std::cout << sep << m[i * x + j];
            sep = " ";
        }
        std::cout << '\n';
    }
    std::cout << std::endl;
}

bool is_row_dominant(const mat &m, const dim_t &dim) {
    const auto [x, y] = dim;
    for (std::size_t i = 0; i < y; ++i) {
        double acc = 0;
        for (std::size_t j = 0; j < y; ++j)
            if (j != i)
                acc += m[j * x + i];
        if (acc >= m[i * x + i])
            return false;
    }
    return true;
}

bool is_col_dominant(const mat &m, const dim_t &dim) {
    const auto [x, y] = dim;
    for (std::size_t j = 0; j < y; ++j) {
        double acc = 0;
        for (std::size_t i = 0; i < y; ++i)
            if (j != i)
                acc += m[i * x + j];
        if (acc >= m[j * x + j])
            return false;
    }
    return true;
}
