#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void sortedInsert(Node*& head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};
    
    // Kasus 1: List masih kosong
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }
    
    // Kasus 2: Data baru lebih kecil dari head (sisipkan di awal)
    if (data <= head_ref->data) {
        // Sambungkan newNode ke head_ref
        newNode->next = head_ref;
        newNode->prev = head_ref->prev;
        
        // Update pointer yang mengarah ke newNode
        head_ref->prev->next = newNode;
        head_ref->prev = newNode;
        
        // Update head_ref ke node baru
        head_ref = newNode;
        return;
    }
    
    // Kasus 3: Cari posisi yang tepat (tengah/akhir)
    Node* current = head_ref;
    
    // traversal sampai menemukan posisi yang tepat
    // Loop berhenti jika:
    // 1. Mencapai node terakhir (current->next == head_ref), atau
    // 2. Menemukan node dengan data yang lebih besar
    while (current->next != head_ref && current->next->data < data) {
        current = current->next;
    }
    
    // Sisipkan newNode setelah current
    newNode->next = current->next;
    newNode->prev = current;
    
    // Update pointer dari node sekitarnya
    current->next->prev = newNode;
    current->next = newNode;
}

void printList(Node* head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }
    
    Node* current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

int main() {
    Node* head = nullptr;
    
    // Test sorted insert
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);
    
    cout << "Circular Doubly Linked List (sorted): ";
    // Expected output: 10 20 30 40
    printList(head);
    
    // Test tambahan
    sortedInsert(head, 25); // Menyisipkan di tengah
    cout << "Setelah insert 25: ";
    printList(head);
    
    sortedInsert(head, 5);  // Menyisipkan di awal
    cout << "Setelah insert 5: ";
    printList(head);
    
    sortedInsert(head, 45); // Menyisipkan di akhir
    cout << "Setelah insert 45: ";
    printList(head);
    
    return 0;
}
