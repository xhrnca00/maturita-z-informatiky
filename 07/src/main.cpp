#include <cstdint>
#include <iomanip>
#include <iostream>

using data_t = int64_t;
using dec_t = double;

data_t pow(data_t x, data_t n);
data_t fact(data_t n);

dec_t ex(data_t x);

int main() {
    std::cout << "Give x: ";
    data_t x;
    std::cin >> x;
    auto res = ex(x);
    std::cout << std::fixed << std::setprecision(3) << "e^" << x << " = " << res
              << std::endl;
    return 0;
}

data_t pow(data_t x, data_t n) {
    if (n == 0)
        return 1;
    return x * pow(x, n - 1);
}

data_t fact(data_t n) {
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

dec_t ex(data_t x) {
    dec_t curr = 0;
    dec_t last = -1;
    data_t i = 0;
    while (std::abs(curr - last) >= 1e-4) {
        last = curr;
        std::clog << "pow: " << pow(x, i) << ' ' << "fact: " << fact(i) << std::endl;
        curr += (dec_t)pow(x, i) / (dec_t)fact(i);
        ++i;
        std::clog << "last: " << last << ' ' << "curr: " << curr << std::endl;
    }
    return curr;
}
