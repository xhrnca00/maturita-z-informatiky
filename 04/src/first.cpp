#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

void print(const std::vector<int> &nums);
void fill(std::vector<int> *nums);
void sort(std::vector<int> *nums);

// as in: `for (pre; cond; post) { block; }`
// name should be unique and without spaces
#define FOR(name, pre, cond, post, block)          \
    {                                              \
        pre;                                       \
        name##_BEG : if (!(cond)) goto name##_END; \
        block;                                     \
        post;                                      \
        goto name##_BEG;                           \
        name##_END :;                              \
    }

// as in: `while (cond) { block; }`
// name should be unique and without spaces
#define WHILE(name, cond, block)                   \
    {                                              \
        name##_BEG : if (!(cond)) goto name##_END; \
        block;                                     \
        goto name##_BEG;                           \
        name##_END :;                              \
    }

int main() {
    std::vector<int> nums(100);
    srand(time(nullptr));
    fill(&nums);
    print(nums);
    sort(&nums);
    print(nums);
    return 0;
}

void print2(const std::vector<int> &nums) {
    if (nums.empty()) {
        std::cout << "Empty vector" << std::endl;
        return;
    }
    auto it = nums.begin();
    std::cout << *it++;
    WHILE(
        PRINT2_L0, it != nums.end(),
        std::cout << ", " << *it++
    )
    std::cout << std::endl;
}

void print(const std::vector<int> &nums) {
    if (nums.empty()) {
        std::cout << "Empty vector" << std::endl;
        return;
    }
    auto it = nums.begin();
    std::cout << *it++;
PRINT_L0_BEG:
    if (it == nums.end())
        goto PRINT_L0_END;
    std::cout << ", " << *it++;
    goto PRINT_L0_BEG;
PRINT_L0_END:
    std::cout << std::endl;
}

void fill2(std::vector<int> *const nums) {
    auto &ns = *nums;
    FOR(
        FILL2_L0, int i = 0, i < ns.size(), ++i,
        ns[i] = rand() % 1000 + 1;
        std::cout << "HI\n"
    )
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
    FOR(
        SORT2_L0, int i = 0, i < ns.size(), ++i,
        FOR(
            SORT2_L1, int j = 1, j < ns.size(), ++j,
            if (ns[j - 1] > ns[j])
                std::swap(ns[j - 1], ns[j]);
        )
    )
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
SORT_L0_END:;
}
