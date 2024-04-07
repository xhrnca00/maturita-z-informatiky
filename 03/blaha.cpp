#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ofstream soubor;
    int n = 100;
    bool plaz[n];

    soubor.open("prvocisla.txt");
    for (int i = 0; i < n; i++)
        plaz[i] = true;

    for (int i = 2; i < n; i++) {
        if (plaz[i]) {
            // cout << i << " ";
            soubor << i << " ";
            // proběhnout pláž a vyškrtat násobky
            for (int j = 2; i * j < n; j++)
                plaz[i * j] = false;
        }
    }

    soubor.close();
    return 0;
}
