#include <iostream>

using namespace std;

long double mocnina(int x, int n);
long double faktorial(int n);

// x^0 = 1
// x^n = x * x^(n-1)
long double mocnina(int x, int n) {
    if (n == 0)
        return 1;
    else
        return x * mocnina(x, n - 1);
}
// 0! = 1
// n! = n * (n-1)!
long double faktorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * faktorial(n - 1);
}

int main() {
    int x;
    cout << "Zadej x: ";
    cin >> x;

    long double soucet = 0;
    for (int i = 0; i < 40; i++) {
        cout << "i: " << i << endl;
        cout << "Mocnina: " << mocnina(x, i) << endl;
        cout << "Faktorial: " << faktorial(i) << endl << endl;
        soucet += (mocnina(x, i) / faktorial(i));
    }

    cout << "e na " << x << " ma hodnotu " << soucet << endl;

    return 0;
}
