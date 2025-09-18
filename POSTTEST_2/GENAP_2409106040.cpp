#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Struktur data untuk jadwal penerbangan
struct JadwalPenerbangan {
    string kodePenerbangan;
    string tujuan;
    string status;
    JadwalPenerbangan* next;
};

// Global variables
JadwalPenerbangan* head = nullptr;
int totalJadwal = 0;
string nama, nim;

// Fungsi untuk generate kode penerbangan otomatis
string generateKodePenerbangan() {
    string tigaDigitTerakhir = nim.substr(nim.length() - 3);
    if (totalJadwal == 0) {
        return "JT-" + tigaDigitTerakhir;
    } else {
        return "JT-" + tigaDigitTerakhir + "-" + to_string(totalJadwal);
    }
}

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "\n" << string(58, '-') << endl;
    cout << "         SISTEM JADWAL PENERBANGAN" << endl;
    cout << "      [ " << nama << " - " << nim << " ]" << endl;
    cout << string(58, '-') << endl;
    cout << "| 1. Tambah Jadwal Penerbangan                           |" << endl;
    cout << "| 2. Sisipkan Jadwal Penerbangan                         |" << endl;
    cout << "| 3. Hapus Jadwal Paling Awal                            |" << endl;
    cout << "| 4. Update Status Penerbangan                           |" << endl;
    cout << "| 5. Tampilkan Semua Jadwal                              |" << endl;
    cout << "| 6. Cari Jadwal Berdasarkan Tujuan                      |" << endl;
    cout << "| 7. Statistik Status                                    |" << endl;
    cout << "| 0. Keluar                                              |" << endl;
    cout << string(58, '-') << endl;
    cout << "Pilih menu (0-7): ";
}

// Fungsi untuk menambah jadwal baru di akhir
void tambahJadwalPenerbangan() {
    JadwalPenerbangan* jadwalBaru = new JadwalPenerbangan;
    
    jadwalBaru->kodePenerbangan = generateKodePenerbangan();
    
    cout << "\n=== TAMBAH JADWAL PENERBANGAN ===" << endl;
    cout << "Kode Penerbangan: " << jadwalBaru->kodePenerbangan << endl;
    
    cout << "Masukkan tujuan penerbangan: ";
    cin.ignore();
    getline(cin, jadwalBaru->tujuan);
    
    // Set status default
    jadwalBaru->status = "Menunggu Flight";
    
    jadwalBaru->next = nullptr;
    
    if (head == nullptr) {
        head = jadwalBaru;
    } else {
        JadwalPenerbangan* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = jadwalBaru;
    }
    
    totalJadwal++;
    cout << "\nJadwal berhasil ditambahkan!" << endl;
}

// Fungsi untuk menyisipkan jadwal di posisi tertentu
void sisipkanJadwalPenerbangan() {
    if (totalJadwal == 0) {
        cout << "\nBelum ada jadwal. Tambahkan jadwal pertama dulu!" << endl;
        return;
    }

    // Posisi berdasarkan digit terakhir NIM + 1
    int digitTerakhir = (nim[nim.length() - 1] - '0');
    int posisiSisip = digitTerakhir + 1;
    
    cout << "\n=== SISIPKAN JADWAL PENERBANGAN ===" << endl;
    cout << "Posisi penyisipan berdasarkan NIM: " << posisiSisip << endl;
    
    if (posisiSisip > totalJadwal + 1) {
        cout << "Posisi terlalu besar! Maksimal posisi: " << totalJadwal + 1 << endl;
        return;
    }

    JadwalPenerbangan* jadwalBaru = new JadwalPenerbangan;
    jadwalBaru->kodePenerbangan = generateKodePenerbangan();
    
    cout << "Kode Penerbangan: " << jadwalBaru->kodePenerbangan << endl;
    
    cout << "Masukkan tujuan penerbangan: ";
    cin.ignore();
    getline(cin, jadwalBaru->tujuan);
    
    // Set status default
    jadwalBaru->status = "Menunggu Flight";

    if (posisiSisip == 1) {
        jadwalBaru->next = head;
        head = jadwalBaru;
    } else {
        JadwalPenerbangan* current = head;
        for (int i = 1; i < posisiSisip - 1; i++) {
            current = current->next;
        }
        jadwalBaru->next = current->next;
        current->next = jadwalBaru;
    }
    
    totalJadwal++;
    cout << "\nJadwal berhasil disisipkan di posisi " << posisiSisip << "!" << endl;
}

// Fungsi untuk menghapus jadwal paling awal
void hapusJadwalAwal() {
    if (head == nullptr) {
        cout << "\nTidak ada jadwal yang bisa dihapus!" << endl;
        return;
    }
    
    JadwalPenerbangan* temp = head;
    cout << "\n=== HAPUS JADWAL PALING AWAL ===" << endl;
    cout << "Jadwal yang dihapus:" << endl;
    cout << "Kode: " << temp->kodePenerbangan << endl;
    cout << "Tujuan: " << temp->tujuan << endl;
    cout << "Status: " << temp->status << endl;
    
    head = head->next;
    delete temp;
    totalJadwal--;
    
    cout << "\nJadwal paling awal berhasil dihapus!" << endl;
}

// Fungsi untuk update status penerbangan (fungsi paling kompleks)
void updateStatusPenerbangan() {
    if (head == nullptr) {
        cout << "\nBelum ada jadwal penerbangan!" << endl;
        return;
    }

    string kodeYangDicari;
    cout << "\n=== UPDATE STATUS PENERBANGAN ===" << endl;
    cout << "Masukkan kode penerbangan yang ingin diupdate: ";
    cin.ignore();
    getline(cin, kodeYangDicari);

    JadwalPenerbangan* current = head;
    bool ditemukan = false;
    
    // Mencari jadwal berdasarkan kode penerbangan
    while (current != nullptr) {
        if (current->kodePenerbangan == kodeYangDicari) {
            ditemukan = true;
            cout << "\nJadwal ditemukan!" << endl;
            cout << "Kode Penerbangan: " << current->kodePenerbangan << endl;
            cout << "Tujuan: " << current->tujuan << endl;
            cout << "Status saat ini: " << current->status << endl;
            
            // Tampilkan pilihan status
            cout << "\nPilihan Status Penerbangan Baru:" << endl;
            cout << "1. Menunggu Flight" << endl;
            cout << "2. Flight" << endl;
            cout << "3. Delay" << endl;
            cout << "4. Dibatalkan" << endl;
            
            int pilihanStatus;
            string statusBaru;
            do {
                cout << "Pilih status baru (1-4): ";
                cin >> pilihanStatus;
                
                switch(pilihanStatus) {
                    case 1: statusBaru = "Menunggu Flight"; break;
                    case 2: statusBaru = "Flight"; break;
                    case 3: statusBaru = "Delay"; break;
                    case 4: statusBaru = "Dibatalkan"; break;
                    default:
                        cout << "Pilihan tidak valid! Pilih 1-4." << endl;
                        continue;
                }
                break;
            } while (true);
            
            string statusLama = current->status;
            current->status = statusBaru;
            
            cout << "\nStatus berhasil diupdate!" << endl;
            cout << "Status lama: " << statusLama << endl;
            cout << "Status baru: " << current->status << endl;
            break;
        }
        current = current->next;
    }
    
    if (!ditemukan) {
        cout << "\nJadwal dengan kode '" << kodeYangDicari << "' tidak ditemukan!" << endl;
        cout << "Pastikan kode penerbangan sudah benar." << endl;
    }
}

// Fungsi untuk menampilkan semua jadwal
void tampilkanSemuaJadwal() {
    cout << "\n=== SEMUA JADWAL PENERBANGAN ===" << endl;
    
    if (head == nullptr) {
        cout << "Belum ada jadwal penerbangan." << endl;
        return;
    }
    
    cout << left << setw(15) << "Kode" << setw(20) << "Tujuan" << setw(15) << "Status" << endl;
    cout << string(50, '-') << endl;
    
    JadwalPenerbangan* current = head;
    int nomor = 1;
    while (current != nullptr) {
        cout << left << setw(15) << current->kodePenerbangan 
             << setw(20) << current->tujuan 
             << setw(15) << current->status << endl;
        current = current->next;
        nomor++;
    }
    cout << "\nTotal jadwal: " << totalJadwal << endl;
}

// Fungsi tambahan: Cari jadwal berdasarkan tujuan
void cariJadwalByTujuan() {
    if (head == nullptr) {
        cout << "\nBelum ada jadwal penerbangan!" << endl;
        return;
    }

    string tujuanCari;
    cout << "\n=== CARI JADWAL BERDASARKAN TUJUAN ===" << endl;
    cout << "Masukkan tujuan yang dicari: ";
    cin.ignore();
    getline(cin, tujuanCari);

    JadwalPenerbangan* current = head;
    bool ditemukan = false;
    
    cout << "\nHasil pencarian untuk tujuan '" << tujuanCari << "':" << endl;
    cout << left << setw(15) << "Kode" << setw(20) << "Tujuan" << setw(15) << "Status" << endl;
    cout << string(50, '-') << endl;
    
    while (current != nullptr) {
        if (current->tujuan.find(tujuanCari) != string::npos) {
            cout << left << setw(15) << current->kodePenerbangan 
                 << setw(20) << current->tujuan 
                 << setw(15) << current->status << endl;
            ditemukan = true;
        }
        current = current->next;
    }
    
    if (!ditemukan) {
        cout << "Tidak ada jadwal dengan tujuan tersebut." << endl;
    }
}

// Fungsi tambahan: Hitung jadwal berdasarkan status
void hitungJadwalByStatus() {
    if (head == nullptr) {
        cout << "\nBelum ada jadwal penerbangan!" << endl;
        return;
    }

    cout << "\n=== STATISTIK JADWAL BERDASARKAN STATUS ===" << endl;
    
    // Hitung berbagai status
    int menunggu = 0, flight = 0, delay = 0, dibatalkan = 0;
    
    JadwalPenerbangan* current = head;
    while (current != nullptr) {
        if (current->status == "Menunggu Flight") {
            menunggu++;
        } else if (current->status == "Flight") {
            flight++;
        } else if (current->status == "Delay") {
            delay++;
        } else if (current->status == "Dibatalkan") {
            dibatalkan++;
        }
        current = current->next;
    }
    
    cout << "Menunggu Flight: " << menunggu << " jadwal" << endl;
    cout << "Flight: " << flight << " jadwal" << endl;
    cout << "Delay: " << delay << " jadwal" << endl;
    cout << "Dibatalkan: " << dibatalkan << " jadwal" << endl;
    cout << "Total: " << totalJadwal << " jadwal" << endl;
}

int main() {
    // Input identitas di awal program
    cout << "=== SISTEM JADWAL PENERBANGAN ===" << endl;
    cout << "Masukkan nama Anda: ";
    getline(cin, nama);
    cout << "Masukkan NIM Anda: ";
    getline(cin, nim);
    
    int pilihan;
    
    do {
        tampilkanMenu();
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                tambahJadwalPenerbangan();
                break;
            case 2:
                sisipkanJadwalPenerbangan();
                break;
            case 3:
                hapusJadwalAwal();
                break;
            case 4:
                updateStatusPenerbangan();
                break;
            case 5:
                tampilkanSemuaJadwal();
                break;
            case 6:
                cariJadwalByTujuan();
                break;
            case 7:
                hitungJadwalByStatus();
                break;
            case 0:
                cout << "\nTerima kasih telah menggunakan sistem!" << endl;
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "\nPilihan tidak valid! Coba lagi." << endl;
        }
        
    } while (pilihan != 0);
    
    return 0;
}