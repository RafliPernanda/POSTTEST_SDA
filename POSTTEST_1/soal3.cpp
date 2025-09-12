#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    const int jumlah = 4;
    Mahasiswa mhs[jumlah];

    // Input 4 mahasiswa
    cout << "Masukkan data " << jumlah << " mahasiswa:\n" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        getline(cin, mhs[i].nama);
        cout << "NIM  : ";
        getline(cin, mhs[i].nim);
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
        cin.ignore();
        cout << endl;
    }

    // Urutkan berdasarkan IPK (ascending) - bubble sort
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (mhs[j].ipk > mhs[j + 1].ipk) {
                Mahasiswa sementara = mhs[j];
                mhs[j] = mhs[j + 1];
                mhs[j + 1] = sementara;
            }
        }
    }

    // Tampilkan semua data setelah diurutkan
    cout << "\nData mahasiswa setelah diurutkan berdasarkan IPK (ascending):\n" << endl;
    cout << "No. Nama  -  NIM  -  IPK" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". " << mhs[i].nama
             << "   -   " << mhs[i].nim
             << "   -   " << mhs[i].ipk << endl;
    }

    return 0;
}
