#include <iostream>
#include "multilist.h"
using namespace std;

int main() {
    listinduk L;
    CreateList(&L);

    int pilihan;

    do {
        cout << "\n========== MENU MULTILIST ==========\n";
        cout << "1. Tambah Induk\n";
        cout << "2. Tambah Anak pada Induk\n";
        cout << "3. Hapus Induk\n";
        cout << "4. Hapus Anak dari Induk\n";
        cout << "5. Tampilkan List\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            // Insert Induk
            int x;
            cout << "Masukkan nilai induk: ";
            cin >> x;

            address P = alokasi(x);
            if (P != NULL) {
                insertLast(&L, P);
                cout << "Induk " << x << " berhasil ditambahkan.\n";
            }

        } else if (pilihan == 2) {
            // Insert Anak
            int indukX, anakX;
            cout << "Masukkan nilai induk yang akan diberi anak: ";
            cin >> indukX;

            address P = findElm(L, indukX);
            if (P == NULL) {
                cout << "Induk tidak ditemukan!\n";
            } else {
                cout << "Masukkan nilai anak: ";
                cin >> anakX;

                address_anak C = alokasiAnak(anakX);
                insertLastAnak(&(P->lanak), C);

                cout << "Anak " << anakX << " berhasil ditambahkan.\n";
            }

        } else if (pilihan == 3) {
            // Delete Induk
            int x;
            cout << "Masukkan nilai induk yang akan dihapus: ";
            cin >> x;

            delP(&L, x);
            cout << "Induk " << x << " dihapus (jika ada).\n";

        } else if (pilihan == 4) {
            // Delete Anak
            int indukX, anakX;
            cout << "Masukkan nilai induk: ";
            cin >> indukX;

            address P = findElm(L, indukX);
            if (P == NULL) {
                cout << "Induk tidak ditemukan!\n";
            } else {
                cout << "Masukkan nilai anak yang ingin dihapus: ";
                cin >> anakX;

                delPAnak(&(P->lanak), anakX);
                cout << "Anak " << anakX << " dihapus (jika ada).\n";
            }

        } else if (pilihan == 5) {
            // Print
            cout << "\n=== Isi Multilist ===\n";
            printInfo(L);
            cout << "=====================\n";
        }

    } while (pilihan != 0);

    cout << "Program selesai.\n";
    return 0;
}
