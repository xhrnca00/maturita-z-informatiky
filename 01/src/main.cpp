#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <string>

using longnum_t = std::string;

longnum_t add(const longnum_t &a, const longnum_t &b) {
    constexpr char ALEN = '9' - '0' + 1;
    std::string ret;
    char carry = 0;
    std::size_t max_i = std::max(a.size(), b.size());
    for (std::size_t i = 0; i < max_i; ++i) {
        char digit = carry;
        if (i < a.size())
            digit += a[a.size() - 1 - i] - '0';
        if (i < b.size())
            digit += b[b.size() - 1 - i] - '0';
        carry = digit / ALEN;
        ret.push_back(digit % ALEN + '0');
    }
    ret.push_back(carry + '0'); // carry is possibly non-0
    // delete leading zeroes (up to the last one)
    while (ret.size() > 1 && ret[ret.size() - 1] == '0')
        ret.pop_back();
    std::reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    longnum_t a, b;
    std::cout << "First number: ";
    std::cin >> a;
    std::cout << "Second number: ";
    std::cin >> b;
    auto res = add(a, b);
    int max = std::max({a.size(), b.size(), res.size()});
    std::cout
        << std::setw(max) << a << '\n'
        << std::setw(max) << b << '\n'
        << std::setw(max) << std::setfill('-') << "" << std::setfill(' ') << '\n'
        << std::setw(max) << res << std::endl;
    return 0;
}
