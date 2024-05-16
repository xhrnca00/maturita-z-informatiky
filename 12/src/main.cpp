#include <iostream>

struct Prvek {
    int hodnota;
    Prvek *dalsi = nullptr;
    explicit Prvek(int hodnota, Prvek *dalsi) : hodnota(hodnota), dalsi(dalsi) {
    }
};

Prvek *init() {
    return nullptr;
}

Prvek *add(Prvek *&&arr, int value) {
    if (!arr || arr->hodnota >= value)
        return new Prvek(value, arr);
    Prvek *last = arr;
    Prvek *curr = arr->dalsi;
    while (curr && curr->hodnota < value) {
        last = curr;
        curr = curr->dalsi;
    }
    last->dalsi = new Prvek(value, curr);
    return arr;
}

void del(Prvek *&&arr) {
    while (arr) {
        auto n = arr->dalsi;
        delete arr;
        arr = n;
    }
}

void print(const Prvek *arr) {
    const char *sep = "";
    while (arr != nullptr) {
        std::cout << sep << arr->hodnota;
        arr = arr->dalsi;
        sep = ", ";
    }
    std::cout << std::endl;
}

int main() {
    auto arr = init();
    for (int i = 0; i < 10; ++i) {
        std::cout << "Give val: ";
        int val;
        std::cin >> val;
        arr = add(std::move(arr), val);
        print(arr);
    }
    del(std::move(arr));
}
