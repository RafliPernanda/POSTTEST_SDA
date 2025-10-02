#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

// Fungsi untuk menambah dokumen ke antrian (enqueue)
void enqueue(Node*& front, Node*& rear, string document) {
    Node* nodeBaru = new Node{document, nullptr};
    
    if (front == nullptr) {
        // Set front dan rear ke node baru
        front = nodeBaru;
        rear = nodeBaru;
    } else {
        // Sambungkan node baru ke akhir queue
        rear->next = nodeBaru;
        // Update rear ke node baru
        rear = nodeBaru;
    }
}

// Fungsi untuk mengambil dan menghapus dokumen dari antrian (dequeue)
string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return "";
    
    // Simpan data dokumen yang akan dikeluarkan
    string document = front->document;
    
    // Simpan pointer ke node yang akan dihapus
    Node* temp = front;
    
    // Geser front ke node berikutnya
    front = front->next;
    
    // Jika setelah dequeue queue menjadi kosong
    if (front == nullptr) {
        rear = nullptr; // Set rear juga ke nullptr
    }
    
    // Hapus node lama
    delete temp;
    
    return document;
}

// Fungsi untuk memproses semua dokumen dalam antrian
void processAllDocuments(Node*& front, Node*& rear) {
    while (front != nullptr) {
        // Ambil dan proses dokumen dari antrian
        string document = dequeue(front, rear);
        cout << "Memproses: " << document << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;
    
    // Menambahkan beberapa dokumen ke antrian
    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");
    
    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);
    
    return 0;
}
