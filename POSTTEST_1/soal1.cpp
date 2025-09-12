#include <iostream>
using namespace std;

int balikArray(int *arr, int jumlahElemen){
    int *startPointer = arr;
    int *endPointer = arr + jumlahElemen - 1;

    while (startPointer < endPointer) {
        int nilaiSementara = *startPointer;
        *startPointer = *endPointer;
        *endPointer = nilaiSementara;

        startPointer++;
        endPointer--;
    }
    return 0;
}

int main() {
    int bilanganPrima[7] = {2, 3, 5, 7, 11, 13, 17};

    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < 7; i++) {
        cout << bilanganPrima[i] << " ";
    }
    cout << endl;

    balikArray(bilanganPrima, 7);
    cout << "Array setelah dibalik: ";
    for (int i = 0; i < 7; i++) {
        cout << bilanganPrima[i] << " ";
    }
    cout << endl;

    return 0;
}