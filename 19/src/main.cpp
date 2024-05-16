#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

struct Pracovnik {
    char jmeno[50];
    int plat;
    char funkce[30];
};

// CSV: ID;jmeno;plat;funkce
const char INFILE[] = "workers.csv";
const char OUTFILE[] = "workers.bin";

void convert();

int main() {
    // encoding moment!!! (CSV is in UTF-8)
    // CP 852, check `chcp`
    convert();
    return 0;
}

void convert() {
    std::ifstream in(INFILE);
    std::ofstream out(OUTFILE, std::ios::binary);
    if (!in.is_open() || !out.is_open())
        abort();
    std::clog << "Soubory otevreny" << std::endl;

    std::string line;
    while (std::getline(in, line)) {
        std::clog << "Precten radek: " << line << std::endl;
        line.push_back(';'); // to be able to use the same method for function
        Pracovnik p;

        auto start = line.find(';') + 1;
        auto end = line.find(';', start);
        auto jmeno = line.substr(start, end - start);
        std::clog << "Jmeno: " << jmeno << std::endl;

        start = end + 1;
        end = line.find(';', start);
        p.plat = std::stoi(line.substr(start, end - start));
        std::clog << "Plat: " << p.plat << std::endl;

        start = end + 1;
        end = line.find(';', start);
        auto funkce = line.substr(start, end - start);
        std::clog << "Funkce: " << funkce << std::endl;

        std::strncpy(p.jmeno, jmeno.c_str(), 50);
        std::strncpy(p.funkce, funkce.c_str(), 30);
        p.jmeno[49] = '\0';
        p.funkce[29] = '\0';

        out.write((char *)&p, sizeof(p));
        std::clog << "Zapsano do souboru" << std::endl;
    }

    in.close();
    out.close();
    std::clog << "Soubory zavreny" << std::endl;
}
