#include <cstdlib>
#include <ctime>
#include <iostream>

void fill(int arr[], int len);
void sort(int arr[], int len);
void print(const int arr[], int len);
bool binary_search(const int arr[], int len, int x);

constexpr int MAX = 100;

int main() {
    constexpr int LEN = 25;
    srand(time(nullptr));
    int arr[LEN];

    fill(arr, LEN);
    // print(arr, LEN); // to comment
    sort(arr, LEN);
    print(arr, LEN);
    std::cout << "Give number to find: ";
    int num;
    std::cin >> num;
    bool res = binary_search(arr, LEN, num);
    std::cout << num << (res ? " IS" : " is NOT") << " in the interval\n";
    return 0;
}

void fill(int arr[], int len) {
    for (int i = 0; i < len; ++i)
        arr[i] = rand() % MAX;
}

void sort(int arr[], int len) {
    // COUNT SORT, O(N + max)
    int counts[MAX];
    std::fill(counts, counts + MAX, 0);
    for (int i = 0; i < len; ++i)
        counts[arr[i]]++;
    int curr = 0;
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < counts[i]; ++j)
            arr[curr++] = i;
    }
}

void print(const int arr[], int len) {
    const char *sep = "";
    for (int i = 0; i < len; ++i) {
        std::cout << sep << arr[i];
        sep = ", ";
    }
    std::cout << std::endl;
}

bool binary_search(const int arr[], int len, int x) {
    int l = 0, r = len;
    while (r - l) {
        int mid = (l + r) / 2;
        if (arr[mid] == x)
            return true;
        if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid;
    }
    return false;
}
