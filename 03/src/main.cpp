#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

std::vector<int> sieve(int n);

int main() {
    int n;
    std::cout << "Give N: ";
    std::cin >> n;
    std::ofstream out("primes.txt");
    if (!out.is_open()) {
        std::cerr << "Could not open primes.txt\n";
        return 1;
    }
    auto primes = sieve(n);
    for (const auto &p : primes)
        out << p << ", ";
    out << std::endl;
    return 0;
}

std::vector<int> sieve(int n) {
    std::vector<bool> nums(n, true);
    std::vector<int> ret;
    int n_sqrt = std::sqrt(n);
    nums[0] = nums[1] = false;
    for (int i = 2; i < n; ++i) {
        if (!nums[i])
            continue;
        ret.push_back(i);
        if (i > n_sqrt)
            continue;
        for (int j = 2 * i; j < n; j += i) {
            nums[j] = false;
        }
    }
    return ret;
}
