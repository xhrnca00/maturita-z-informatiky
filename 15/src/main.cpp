#include <cmath>
#include <iostream>
#include <limits>

using dec_t = double;

constexpr dec_t f(dec_t x) {
    return std::pow(x, 5) - 3 * std::pow(x, 4) - 23 * std::pow(x, 3) + 51 * std::pow(x, 2)
           + 94 * x - 120;
}

void solve(dec_t l, dec_t r, dec_t step);
dec_t find(dec_t l, dec_t r);

int main() {
    dec_t l, r, step;
    std::cout << "Give l: ";
    std::cin >> l;
    std::cout << "Give r: ";
    std::cin >> r;
    std::cout << "Give step: ";
    std::cin >> step;
    solve(l, r, step);
    return 0;
}

void solve(dec_t l, dec_t r, dec_t step) {
    dec_t last = f(l);
    l += step;
    while (l <= r) {
        dec_t curr = f(l);
        if (last * curr < 0 || last == 0) {
            dec_t root = find(l - step, l);
            std::cout << "Root at interval [" << l - step << ", " << l << "): " << root
                      << std::endl;
        }
        last = curr;
        l += step;
    }
}

constexpr dec_t PRECISION = 1e-6;
dec_t find(dec_t l, dec_t r) {
    std::cout << l << ' ' << r << std::endl;
    dec_t lv = f(l);
    if (lv == 0)
        return lv;
    while (r - l > PRECISION) {
        dec_t mid = (l + r) / 2;
        dec_t mv = f(mid);
        if (mv == 0)
            return mid;
        if (mv * lv < 0)
            r = mid;
        else {
            l = mid;
            lv = mv;
        }
    }
    return (l + r) / 2;
}
