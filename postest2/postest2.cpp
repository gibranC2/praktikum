#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;

struct Book {
    string title;
    string author;
    int year;
};

struct User {
    string name;
    int nim;
};

void displayMenu() {
    cout << "\nMenu Perpustakaan:\n";
    cout << "1. Tambah Data Buku\n";
    cout << "2. Tampilkan Data Buku\n";
    cout << "3. Ubah Data Buku\n";
    cout << "4. Hapus Data Buku\n";
    cout << "5. Keluar\n";
}

int main() {
    User user;
    int loginAttempt = 0;

    // Login
    do {
        cout << "Masukkan Nama: ";
        cin >> user.name;;
        cout << "Masukkan NIM: ";
        cin >> user.nim;
        loginAttempt++;
    } while ((user.name != "gibran" || user.nim != 139) && loginAttempt < 3);

    if (loginAttempt >= 3) {
        cout << "Anda telah salah login sebanyak 3 kali. Program berhenti.\n";
        return 0;
    }

    // Data buku
    Book books[MAX_BOOKS];
    int numBooks = 0;

    int choice;
    do {
        displayMenu();
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (numBooks < MAX_BOOKS) {
                    cout << "Masukkan judul buku: ";
                    cin.ignore();
                    getline(cin, books[numBooks].title);
                    cout << "Masukkan penulis buku: ";
                    getline(cin, books[numBooks].author);
                    cout << "Masukkan tahun terbit: ";
                    cin >> books[numBooks].year;
                    numBooks++;
                    cout << "Data buku berhasil ditambahkan.\n";
                } else {
                    cout << "Maaf, sudah mencapai batas maksimum data buku.\n";
                }
                break;
            case 2:
                if (numBooks > 0) {
                    cout << "Daftar Buku:\n";
                    for (int i = 0; i < numBooks; ++i) {
                        cout << i + 1 << ". " << books[i].title << " oleh " << books[i].author << " (" << books[i].year << ")\n";
                    }
                } else {
                    cout << "Belum ada data buku.\n";
                }
                break;
            case 3:
                // Tambahkan kode untuk mengubah data buku
                break;
            case 4:
                // Tambahkan kode untuk menghapus data buku
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program perpustakaan.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 5);

    return 0;
} 