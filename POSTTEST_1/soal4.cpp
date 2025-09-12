#include <iostream>
using namespace std;

// Fungsi untuk menukar dua variabel integer (pakai reference)
void tukar(int &a, int &b) {
    int sementara = a;
    a = b;
    b = sementara;
}

int main() {
    int nilaiPertama, nilaiKedua;

    // Input dua bilangan
    cout << "Masukkan nilai pertama: ";
    cin >> nilaiPertama;
    cout << "Masukkan nilai kedua  : ";
    cin >> nilaiKedua;

    // Sebelum pertukaran
    cout << "\nSebelum ditukar:" << endl;
    cout << "Nilai pertama = " << nilaiPertama << ", Nilai kedua = " << nilaiKedua << endl;

    // Proses tukar
    tukar(nilaiPertama, nilaiKedua);

    // Sesudah pertukaran
    cout << "\nSesudah ditukar:" << endl;
    cout << "Nilai pertama = " << nilaiPertama << ", Nilai kedua = " << nilaiKedua << endl;

    return 0;
}
