#include <iostream>
using namespace std;

int main() {
    int matriks[3][3];

    // Input matriks 3x3
    cout << "Masukkan elemen matriks 3x3:\n" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Elemen [" << i << "][" << j << "]: ";
            cin >> matriks[i][j];
        }
    }

    // Hitung jumlah elemen pada baris genap (0 dan 2)
    int jumlah = 0;
    cout << endl;
    cout << "Contoh : Elemen[Baris][Kolom]" << endl;
    cout << "Baris genap adalah baris dengan indeks 0 dan 2." << endl;
    for (int i = 0; i < 3; i++) {
        if (i % 2 == 0) { // baris genap
            cout << "Baris " << i << " (genap): ";
            for (int j = 0; j < 3; j++) {
                cout << matriks[i][j] << " ";
                jumlah += matriks[i][j];
            }
            cout << endl;
        }
    }

    // Cetak matriks
    cout << "\nMatriks 3x3 yang dimasukkan:"<< endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    // Cetak hasil
    cout << "\nJumlah semua elemen pada baris genap = " << jumlah << endl;

    return 0;
}
