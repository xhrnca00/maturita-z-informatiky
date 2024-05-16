#include <algorithm>
#include <iostream>

class SetridenePole {
protected:
    const int maxPocet;
    int pocetPrvku = 0;
    int *const polePrvku = nullptr;

public:
    explicit SetridenePole(int max) : maxPocet(max), polePrvku(new int[max]) {
    }

    ~SetridenePole() {
        delete[] polePrvku;
    }

    int vlozDoPole(int cislo) {
        if (maxPocet == pocetPrvku)
            return 0;
        auto pos = std::lower_bound(polePrvku, polePrvku + pocetPrvku, cislo);
        pocetPrvku++;
        do
            std::swap(*pos++, cislo);
        while (pos != polePrvku + pocetPrvku);
        return 1;
    }

    void tiskniPole() const {
        const char *sep = "";
        for (int i = 0; i < pocetPrvku; ++i) {
            std::cout << sep << polePrvku[i];
            sep = ", ";
        }
        std::cout << std::endl;
    }
};

int main() {
    SetridenePole sp(10);
    for (int i = 0; i < 11; ++i) {
        int val;
        std::cout << "Give val: ";
        std::cin >> val;
        val = sp.vlozDoPole(val);
        std::cout << "Inserted success: " << val << '\n';
        std::cout << "Arr: ";
        sp.tiskniPole();
    }
    return 0;
}
