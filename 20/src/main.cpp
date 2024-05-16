#include <fstream>
#include <iostream>

constexpr char PATHSEP =
#if defined WIN32 || defined _WIN32
    '\\'
#else
    '/'
#endif
    ;
constexpr char INSTFILE[] = "SOUBORY.TXT";

void install(const std::string &folder);
void copy_file(const char dst[], const char src[]);

int main() {
    std::string folder;
    std::cout << "Do jake slozky? ";
    std::cin >> folder;
    if (folder.back() != '/' || folder.back() != '\\')
        folder.push_back(PATHSEP);
    install(folder);
    return 0;
}

void install(const std::string &folder) {
    std::clog << "Zahajuji instalaci do " << folder << std::endl;
    std::ifstream f(INSTFILE);
    if (!f.is_open()) {
        std::cerr << "Nepodarilo se otevrit " << INSTFILE << '\n';
        abort();
    }

    std::string fname;
    while (f >> fname) {
        std::clog << "Kopirujeme soubor " << fname;
        fname = folder + fname;
        std::clog << " do " << fname << std::endl;
        copy_file(fname.c_str(), fname.c_str() + folder.length());
        std::clog << "Kopirovani ukonceno" << std::endl;
    }

    f.close();
    std::clog << "Instalace ukoncena" << std::endl;
}

void copy_file(const char dst[], const char src[]) {
    constexpr std::size_t BUFSIZE = 64;

    std::ifstream in(src, std::ios::binary);
    std::ofstream out(dst, std::ios::binary);
    if (!in.is_open() || !out.is_open()) {
        std::cerr << "Nepodarilo se otevrit jeden ze souboru\n";
        return;
    }

    char buf[BUFSIZE];
    while (in.read(buf, BUFSIZE))
        out.write(buf, in.gcount());

    in.close();
    out.close();
}
