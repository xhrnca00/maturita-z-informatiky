#include <fstream>
#include <iomanip>
#include <iostream>

struct Clovek {
    char jmeno[30];
    char prijmeni[30];
    char rodneCislo[11];
};

const char FILENAME[] = "people.bin";

void create();
void add();
void print();

int main() {
    char ans = 0;
    while (ans != 'Q') {
        std::cout << "Vytvorit (C), Pridat (A), Tisknout (P), Ukoncit (Q): ";
        std::cin >> ans;
        switch (ans) {
        case 'C':
            create();
            break;
        case 'A':
            add();
            break;
        case 'P':
            print();
            break;
        }
    }
    return 0;
}

void create() {
    std::ofstream f(FILENAME);
    f.close();
}

void add() {
    Clovek p;
    std::fill(p.jmeno, p.jmeno + 30, 0);
    std::fill(p.prijmeni, p.prijmeni + 30, 0);
    std::fill(p.rodneCislo, p.rodneCislo + 11, 0);
    std::cout << "Jmeno (max 29): ";
    std::cin >> p.jmeno;
    std::cout << "Prijmeni (max 29): ";
    std::cin >> p.prijmeni;
    std::cout << "Rodne cislo: ";
    std::cin >> p.rodneCislo;
    std::cout << "Zena? (a/n): ";
    char w;
    std::cin >> w;
    if (w == 'a')
        p.rodneCislo[2] += 5;
    std::ofstream f(FILENAME, std::ios::binary | std::ios::app);
    if (!f.is_open()) {
        std::cerr << "Nepodarilo se otevrit soubor\n";
        return;
    }
    f.write((char *)&p, sizeof(p));
    f.close();
}

void print() {
    std::ifstream f(FILENAME, std::ios::binary);
    if (!f.is_open()) {
        std::cerr << "Nepodarilo se otevrit soubor\n";
        return;
    }
    Clovek p;
    while (f.read((char *)&p, sizeof(p))) {
        bool woman = false;
        int day = (p.rodneCislo[4] - '0') * 10 + (p.rodneCislo[5] - '0');
        int month = (p.rodneCislo[2] - '0') * 10 + (p.rodneCislo[3] - '0');
        if (month > 12) {
            month -= 50;
            woman = true;
        }
        int year = (p.rodneCislo[0] - '0') * 10 + (p.rodneCislo[1] - '0');
        if (p.rodneCislo[9] == '\0') {
            if (year <= 53)
                year += 1900;
            else
                year += 1800;
        } else {
            if (year > 24)
                year += 1900;
            else
                year += 2000;
        }
        std::cout << (woman ? 'Z' : 'M') << ' ' << std::left << std::setw(29) << p.jmeno
                  << ' ' << std::setw(29) << p.prijmeni << ' ' << std::setfill('0')
                  << std::right << std::setw(2) << day << '.' << std::setfill('0')
                  << std::setw(2) << month << '.' << year << std::setfill(' ') << '\n';
    }
    std::cout << std::flush;
    f.close();
}
