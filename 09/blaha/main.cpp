#include "retezce.h"
#include <iostream>

using namespace std;

int main() {
    char textik[300] = "Ahoj Hugo!";
    cout << textik << endl;
    strdel(textik, 2, 2);
    cout << textik << endl; // Ah Hugo!
    strins(textik, "oj", 2);
    cout << textik << endl; // Ahoj Hugo!

    pokusnyPozdrav();
    cout << "Hello world!" << endl;
    cin.get();
    return 0;
}
