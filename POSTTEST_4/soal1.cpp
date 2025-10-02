#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk Stack
struct Node {
    char data;
    Node* next;
};

// Fungsi untuk menambah elemen ke Stack (Push)
void push(Node*& top, char data) {
    Node* nodeBaru = new Node{data, top};
    top = nodeBaru;
}

// Fungsi untuk mengambil dan menghapus elemen dari Stack (Pop)
char pop(Node*& top) {
    if (top == nullptr) return '\0'; // Return null character jika stack kosong
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

// Fungsi untuk membalik string menggunakan Stack
string reverseString(string s) {
    Node* topStack = nullptr;
    string reversed = "";
    
    // Push semua karakter ke dalam stack
    for(char c : s) {
        push(topStack, c);
    }
    
    // Pop semua karakter dan tambahkan ke string reversed
    while(topStack != nullptr) {
        reversed += pop(topStack);
    }
    
    return reversed;
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl;
    
    return 0;
}
