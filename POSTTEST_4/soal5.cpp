#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void exchangeHeadAndTail(Node*& head_ref) {
    // Hanya berjalan jika ada 2 node atau lebih
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return;
    }
    
    Node* head = head_ref;
    Node* tail = head_ref->prev;  // Tail adalah prev dari head
    
    // Kasus khusus: jika hanya ada 2 node
    if (head->next == tail && tail->prev == head) {
        head_ref = tail;
        return;
    }
    
    // Simpan node tetangga
    Node* head_next = head->next;
    Node* tail_prev = tail->prev;
    
    // Update koneksi untuk head
    head->next = tail->next;
    head->prev = tail->prev;
    tail_prev->next = head;
    
    // Update koneksi untuk tail
    tail->next = head_next;
    tail->prev = head->prev;
    head_next->prev = tail;
    
    // Update referensi circular
    if (head->next == head) {
        head->next = tail;
    }
    if (tail->prev == tail) {
        tail->prev = head;
    }
    
    // Update head_ref ke tail
    head_ref = tail;
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

void insertEnd(Node*& head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }
    
    Node* tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main() {
    Node* head = nullptr;
    
    // Buat list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);
    
    cout << "List sebelum exchange: ";
    printList(head);
    
    exchangeHeadAndTail(head);
    
    cout << "List setelah exchange head dan tail: ";
    // Expected output: 5 2 3 4 1
    printList(head);
    
    // Test kasus dengan 2 node
    Node* head2 = nullptr;
    insertEnd(head2, 1);
    insertEnd(head2, 2);
    cout << "\nTest dengan 2 node:" << endl;
    cout << "Sebelum exchange: ";
    printList(head2);
    exchangeHeadAndTail(head2);
    cout << "Setelah exchange: ";
    printList(head2);
    
    return 0;
}
