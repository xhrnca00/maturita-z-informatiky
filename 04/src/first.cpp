#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

void print(const std::vector<int> &nums);
void fill(std::vector<int> *nums);
void sort(std::vector<int> *nums);

#define FOR(name, pre, cond, post, block)      \
    pre;                                       \
    name##_BEG : if (!(cond)) goto name##_END; \
    block post;                                \
    goto name##_BEG;                           \
    name##_END :;

#define WHILE(name, cond, block)               \
    name##_BEG : if (!(cond)) goto name##_END; \
    block goto name##_BEG;                     \
    name##_END :;

int main() {
    std::vector<int> nums(100);
    srand(time(nullptr));
    print(nums);
    fill(&nums);
    print(nums);
    sort(&nums);
    print(nums);
    return 0;
}

void print(const std::vector<int> &nums) {
    for (const auto &x : nums) {
        std::cout << x << ", ";
    }
    std::cout << std::endl;
}

void fill2(std::vector<int> *const nums) {
    auto &ns = *nums;
    FOR(FILL2_L0, int i = 0, i < ns.size(), ++i, ns[i] = rand() % 1000 + 1; std::cout << "HI\n";)
    return;
}

void fill(std::vector<int> *const nums) {
    auto &ns = *nums;
    int i = 0;
FILL_L0_BEG:
    if (i >= ns.size())
        goto FILL_L0_END;

    ns[i] = rand() % 1000 + 1;

    i++;
    goto FILL_L0_BEG;

FILL_L0_END:;
}

void sort2(std::vector<int> *nums) {
    auto &ns = *nums;
    int j;
    FOR(SORT2_L0, int i = 0, i < ns.size(), ++i,
        FOR(SORT2_L1, j = 1, j < ns.size(), ++j,
            if (ns[j - 1] > ns[j])
                std::swap(ns[j - 1], ns[j]);))
}

void sort(std::vector<int> *nums) {
    auto &ns = *nums;
    int j = 0;
    int i = 0;
SORT_L0_BEG:
    if (i >= ns.size())
        goto SORT_L0_END;
    j = 1;
SORT_L1_BEG:
    if (j >= ns.size())
        goto SORT_L1_END;
    if (ns[j - 1] > ns[j])
        std::swap(ns[j - 1], ns[j]);
    j++;
    goto SORT_L1_BEG;
SORT_L1_END:
    i++;
    goto SORT_L0_BEG;
SORT_L0_END:
    return;
}
