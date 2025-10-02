#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// Fungsi untuk menambah elemen ke Stack (Push)
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
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

// Fungsi helper untuk mengecek apakah dua bracket cocok
bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

// Fungsi untuk memeriksa apakah bracket seimbang
bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;
    
    // Loop setiap karakter dalam string
    for(char c : expr) {
        // Jika karakter adalah kurung buka, push ke stack
        if(c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        // Jika karakter adalah kurung tutup
        else if(c == ')' || c == '}' || c == ']') {
            // Jika stack kosong, berarti tidak seimbang
            if(stackTop == nullptr) {
                return false;
            }
            
            // Pop kurung buka terakhir dan bandingkan
            char lastOpening = pop(stackTop);
            if(!isMatchingPair(lastOpening, c)) {
                return false;
            }
        }
    }
    
    // jika seimbang, stack harus kosong
    return stackTop == nullptr;
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;
    
    
    return 0;
}
