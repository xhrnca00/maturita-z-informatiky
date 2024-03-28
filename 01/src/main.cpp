#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

std::string add(const std::string &a, const std::string &b) {
    constexpr char ALEN = '9' - '0' + 1;
    if (a.size() < b.size())
        return add(b, a);
    std::string ret(a.size() + 1, '0');

    auto ai = a.crbegin();
    auto bi = b.crbegin();
    char carry = 0;
    auto ri = ret.rbegin();
    while (bi != b.crend()) {
        char digit = *ai++ - '0' + *bi++ - '0' + carry;
        *ri++ = digit % ALEN + '0';
        carry = digit / ALEN;
    }
    while (ai != a.crend()) {
        char digit = *ai++ - '0' + carry;
        *ri++ = digit % ALEN + '0';
        carry = digit / ALEN;
    }
    *ri += carry;
    auto ri2 = ret.begin();
    while (ri2 != ret.end() && *ri2 == '0') {
        ri2++;
    }
    return std::string(ri2, ret.end());
}

int main() {
    std::string a, b;
    std::cout << "First number: ";
    std::cin >> a;
    std::cout << "Second number: ";
    std::cin >> b;
    auto res = add(a, b);
    int max = std::max({a.size(), b.size(), res.size()});
    std::cout
        << std::setw(max) << a << '\n'
        << std::setw(max) << b << '\n'
        << std::setw(max) << std::setfill('-') << "" << '\n'
        << res << std::endl;
    return 0;
}
