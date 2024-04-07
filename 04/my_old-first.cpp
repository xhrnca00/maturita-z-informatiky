#include <ctime>
#include <iostream>
#include <random>

constexpr int N = 100;

void fillArray(int arr[N]);
void sortArray(int arr[N]);
void printArray(int arr[N]);

int main() {
    srand(time(nullptr));
    int arr[N];
    fillArray(arr);
    sortArray(arr);
    printArray(arr);
    return 0;
}

void fillArray(int arr[N]) {
    int i = 0;
START:
    if (i >= N)
        goto END;
    arr[i] = rand();
    i++;
    goto START;
END:
    return;
}

void sortArray(int arr[N]) {
    int i = 0, j = 0;
OUTER_START:
    if (i > N)
        goto OUTER_END;
    j = 0;
INNER_START:
    if (j >= N - i)
        goto INNER_END;
    if (arr[j] > arr[j + 1]) {
        int tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
    }
    j++;
    goto INNER_START;
INNER_END:
    i++;
    goto OUTER_START;
OUTER_END:
    return;
}

void printArray(int arr[N]) {
    int i = 0;
START:
    if (i >= N)
        goto END;
    std::cout << arr[i] << ' ';
    i++;
    goto START;
END:
    std::cout << std::endl;
    return;
}
