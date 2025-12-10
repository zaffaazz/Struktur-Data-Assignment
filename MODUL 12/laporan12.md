# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Zaffa Azzahra </p>

## Dasar Teori
Multi-Linked List (MLL) adalah struktur data di mana setiap node dapat memiliki lebih dari satu pointer (bukan hanya satu next), sehingga memungkinkan satu elemen data terhubung ke banyak elemen lain melalui beberapa jalur
## quided

### 1. [MLL]

```C++
#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Inisialisasi List
    listInduk L;
    createListInduk(L);
    cout << "=== MENU RESTORAN DIBUAT ===" << endl << endl;

    // 2. Membuat Data Parent (Kategori Makanan)
    // Kita simpan pointer-nya agar mudah memasukkan anak nanti
    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);
    
    cout << endl;

    // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu
    
    // --> Isi Kategori Makanan Berat (K01)
    NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
    insertFirstChild(Kat1->L_Anak, Mkn1);

    NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
    insertLastChild(Kat1->L_Anak, Mkn2);

    // --> Isi Kategori Minuman (K02)
    NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
    insertLastChild(Kat2->L_Anak, Min1);
    
    NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
    insertFirstChild(Kat2->L_Anak, Min2);

    // --> Isi Kategori Dessert (K03)
    NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
    insertLastChild(Kat3->L_Anak, Des1);
    cout << endl;

    cout << "=== TAMPILAN AWAL MENU ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    // 4. Test Pencarian (Find)
    cout << "=== TEST PENCARIAN ===" << endl;
    findParentByID(L, "K02"); // Cari Kategori Minuman
    cout << "---------------------------" << endl;
    findChildByID(L, "M01");  // Cari Nasi Goreng
    cout << "---------------------------" << endl;
    findChildByID(L, "X99");  // Cari data ngawur (harus not found)
    cout << "---------------------------" << endl;
    cout << endl;

    // 5. Test Update Data
    cout << "=== TEST UPDATE ===" << endl;
    // Update Nama Kategori (Parent)
    // Mengubah "Dessert" menjadi "Makanan Penutup"
    updateDataParentByID(L, "K03", "Makanan Penutup");
    cout << "---------------------------" << endl;
    
    // Update Data Makanan (Child)
    // Mengubah "Nasi Goreng Spesial" jadi "Nasgor Gila", harga naik jadi 28000
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
    cout << "---------------------------" << endl;
    
    cout << "\n=== SETELAH UPDATE ===" << endl;
    // Kita cek apakah data berubah
    printListInduk(L); // Cek nama kategori saja
    cout << endl;
    printListAnak(L, Kat1); // Cek list anak di kategori 1
    cout << endl;

    // 6. Test Penghapusan (Delete)
    cout << "=== TEST DELETE ===" << endl;
    
    // Hapus Child: Hapus Jus Alpukat (D02) dari Minuman
    cout << "> Menghapus Child D02..." << endl;
    deleteFirstChild(Kat2->L_Anak); 
    
    // Hapus Parent: Hapus Kategori Dessert/Makanan Penutup (K03)
    // DeleteLastParent akan menghapus elemen terakhir (K03)
    cout << "> Menghapus Parent Terakhir (K03)..." << endl;
    deleteLastParent(L); 

    cout << "\n=== TAMPILAN AKHIR MENU ===" << endl;
    printStrukturMLL(L);

    return 0;
}
Kode di atas digunakan untuk mencetak teks "ini adalah file code uguided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Unquided

### 1. [Soal]

```C++
// circularlist.h
#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <iostream>
#include <string>
using namespace std;

struct infotype {
    string Nama;
    string Nim;
    char Jenis_kelamin;
    float Ipk;
};

struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertFirst(List &L, address P);
void insertAfter(List &L, address Prec, address P);
void insertLast(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteLast(List &L, address &P);

address findElm(List L, infotype x);
void printInfo(List L);

#endif
// circularlist.cpp
#include "circularlist.h"
#include <iostream>
#include <string>

using namespace std;

void createList(List &L) {
    L.First = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        P->next = P;  
    } else {
        address last = L.First;
        while (last->next != L.First) {
            last = last->next;
        }
        P->next = L.First;
        last->next = P;
        L.First = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        P->next = P;
    } else {
        address last = L.First;
        while (last->next != L.First) {
            last = last->next;
        }
        last->next = P;
        P->next = L.First;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.First != NULL) {
        address last = L.First;

        while (last->next != L.First) {
            last = last->next;
        }

        P = L.First;

        if (last == L.First) {  
            L.First = NULL;
        } else {
            last->next = P->next;
            L.First = P->next;
        }
        P->next = NULL;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != NULL && Prec->next != L.First) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = NULL;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First != NULL) {
        address prev = NULL;
        address last = L.First;

        while (last->next != L.First) {
            prev = last;
            last = last->next;
        }

        P = last;

        if (prev == NULL) { 
            L.First = NULL;
        } else {
            prev->next = L.First;
        }

        P->next = NULL;
    }
}

address findElm(List L, infotype x) {
    if (L.First == NULL) return NULL;

    address P = L.First;
    do {
        if (P->info.Nim == x.Nim) {
            return P;
        }
        P = P->next;
    } while (P != L.First);

    return NULL;
}

void printInfo(List L) {
    if (L.First == NULL) {
        cout << "List kosong\n";
    } else {
        address P = L.First;
        do {
            cout << "Nama          : " << P->info.Nama << endl;
            cout << "NIM           : " << P->info.Nim << endl;
            cout << "Jenis Kelamin : " << P->info.Jenis_kelamin << endl;
            cout << "IPK           : " << P->info.Ipk << endl;
            cout << "          " << endl;
           P = P->next;
        } while (P != L.First);
    }
}
// main.cpp
#include "circularlist.h"
#include <iostream>
using namespace std;

address createData(string nama, string nim, char jenis_kelamin, float ipk) {
    infotype x;
    x.Nama = nama;
    x.Nim = nim;
    x.Jenis_kelamin = jenis_kelamin;
    x.Ipk = ipk;
    return alokasi(x);
}

int main() {
    List L;
    address P1, P2;
    infotype x;

    createList(L);

    cout << "Coba insert first, last, dan after" << endl;

    P1 = createData("Danu", "04", 'L', 4.0);
    insertFirst(L, P1);

    P1 = createData("Fahmi", "06", 'L', 3.45);
    insertLast(L, P1);

    P1 = createData("Bobi", "02", 'L', 3.71);
    insertFirst(L, P1);

    P1 = createData("Ali", "01", 'L', 3.3);
    insertFirst(L, P1);

    P1 = createData("Gita", "07", 'P', 3.75);
    insertLast(L, P1);

    x.Nim = "07";
    P1 = findElm(L, x);
    P2 = createData("Cindi", "03", 'P', 3.5);
    insertAfter(L, P1, P2);

    x.Nim = "02";
    P1 = findElm(L, x);
    P2 = createData("Hilmi", "08", 'P', 3.3);
    insertAfter(L, P1, P2);

    x.Nim = "04";
    P1 = findElm(L, x);
    P2 = createData("Eli", "05", 'P', 3.4);
    insertAfter(L, P1, P2);

    printInfo(L);

    return 0;
}

```
#### Output :

<img width="1203" height="680" alt="Image" src="https://github.com/user-attachments/assets/3edf4532-e6ed-4090-9030-5821c3cf984e" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/16a02230-73d3-4cd4-aa02-fbc0a3af7908" />

## Kesimpulan
Program di atas menggunakan circular linked list, di mana setiap node saling terhubung membentuk lingkaran sehingga node terakhir menunjuk kembali ke node pertama. Penambahan data dilakukan menggunakan insertFirst, insertLast, dan insertAfter, sedangkan penghapusan dilakukan melalui deleteFirst, deleteLast, dan deleteAfter. Pencarian data dapat dilakukan dengan findElm, dan seluruh isi list dapat ditampilkan menggunakan printInfo.

## Referensi
[1] Dicoding, “Struktur Data Queue: Pengertian, Fungsi dan Jenis-jenisnya”, Dicoding Blog. [Online]. Available: https://www.dicoding.com/blog/struktur-data-queue-pengertian-fungsi-dan-jenisnya/