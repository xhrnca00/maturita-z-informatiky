#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

int gcd(int a, int b);

int main() {
    std::size_t n;
    std::cout << "Give n: ";
    std::cin >> n;
    std::vector<int> nums(n);
    std::cout << "Now give " << n << " nums:\n";
    for (auto &x : nums)
        std::cin >> x;
    int val = nums[0];
    for (std::size_t i = 1; i < n; ++i) {
        val = gcd(val, nums[i]);
        assert(val == std::gcd(val, nums[i]));
    }
    std::cout << "GCD is: " << val << std::endl;
    return 0;
}

int gcd(int a, int b) {
    assert(a > 0 && b > 0);
    while (a != 0) {
        if (a < b)
            std::swap(a, b);
        a %= b;
    }
    return b;
}
