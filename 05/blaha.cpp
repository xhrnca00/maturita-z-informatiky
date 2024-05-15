#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

/*void nactiMatici(char nazevSouboru[200],
                   matice[5][5]){
void nactiMatici(char nazevSouboru[],
                   matice[][5]){
void nactiMatici(char *nazevSouboru,
                   matice[5][5]){
                   */
void nactiMatici(string nazevSouboru, int matice[5][5]) {
    ifstream soubor;
    // soubor.open(nazevSouboru);
    soubor.open(nazevSouboru.c_str());
    for (int radek = 0; radek < 5; radek++)
        for (int sloupec = 0; sloupec < 5; sloupec++)
            soubor >> matice[radek][sloupec];
    soubor.close();
}

void zapisMatici(string nazevSouboru, int matice[5][5]) {
    ofstream soubor;
    // soubor.open(nazevSouboru);
    soubor.open(nazevSouboru.c_str());
    for (int radek = 0; radek < 5; radek++) {
        for (int sloupec = 0; sloupec < 5; sloupec++)
            soubor << setw(6) << matice[radek][sloupec];
        soubor << endl;
    }
    soubor.close();
}

void tiskniMatici(int matice[5][5]) {
    for (int radek = 0; radek < 5; radek++) {
        for (int sloupec = 0; sloupec < 5; sloupec++)
            cout << matice[radek][sloupec] << " ";
        cout << endl;
    }
    cout << endl;
}

void sectiMatice(int matice1[5][5], int matice2[5][5], int matice3[5][5]) {
    for (int radek = 0; radek < 5; radek++) {
        for (int sloupec = 0; sloupec < 5; sloupec++) {
            matice3[radek][sloupec] = matice1[radek][sloupec] + matice2[radek][sloupec];
        }
    }
}

int main() {
    int A[5][5], B[5][5], C[5][5];
    nactiMatici("mata.txt", A);
    tiskniMatici(A);
    nactiMatici("matb.txt", B);
    tiskniMatici(B);
    sectiMatice(A, B, C);
    tiskniMatici(C);
    zapisMatici("matc.txt", C);
    return 0;
}
