#include "retezce.h"
#include <iostream>

int main() {
    char s[] = "ahoj svete";
    std::cout << s << '.' << std::endl;
    strdel(s, 2, 2);
    // strdel(s, 4, 6);
    std::cout << s << '.' << std::endl;
    // strins(s, " adame", 4);
    strins(s, "oj", 2);
    std::cout << s << '.' << std::endl;
    return 0;
}
