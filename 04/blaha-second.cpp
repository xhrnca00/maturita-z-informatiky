#include <iostream>

using namespace std;

int nsd(int a, int b) {
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int gcd(int u, int v) {
    return (v != 0) ? gcd(v, u % v) : u;
}

int main() {
    int n;
    int delitel, vstup;
    cout << "Zadej hodnotu n:";
    cin >> n;

    cout << "Zadej 1. hodnotu:";
    cin >> delitel;
    for (int i = 2; i <= n; i++) {
        cout << "Zadej " << i << ". hodnotu:";
        cin >> vstup;
        delitel = gcd(delitel, vstup);
    }

    cout << "NSD ma hodnotu " << delitel << endl;
    return 0;
}
