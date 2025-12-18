# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (12)</h1>
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

<img width="1264" height="830" alt="Screenshot 2025-12-10 214309" src="https://github.com/user-attachments/assets/2df80b9f-517b-4864-a8ef-c0a32838452a" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/bf000b4b-5683-4d9c-89fd-29bd08a12207" />

## Kesimpulan
Program di atas menggunakan circular linked list, di mana setiap node saling terhubung membentuk lingkaran sehingga node terakhir menunjuk kembali ke node pertama. Penambahan data dilakukan menggunakan insertFirst, insertLast, dan insertAfter, sedangkan penghapusan dilakukan melalui deleteFirst, deleteLast, dan deleteAfter. Pencarian data dapat dilakukan dengan findElm, dan seluruh isi list dapat ditampilkan menggunakan printInfo.

## Unquided

### 2. [Soal]

```C++
// multilist.cpp
#include "multilist.h"
#include <stdio.h>

bool ListEmpty(listinduk L) {
    return (L.first == NULL);
}

bool ListEmptyAnak(listanak L) {
    return (L.first == NULL);
}

void CreateList(listinduk *L) {
    L->first = NULL;
    L->last = NULL;
}

void CreateListAnak(listanak *L) {
    L->first = NULL;
    L->last = NULL;
}

address alokasi(infotypeinduk X) {
    address P = (address) malloc(sizeof(struct elemen_list_induk));
    if (P != NULL) {
        P->info  = X;
        P->lanak.first = NULL;
        P->lanak.last  = NULL;
        P->next  = NULL;
        P->prev  = NULL;
    }
    return P;
}

address_anak alokasiAnak(infotypeanak X) {
    address_anak P = (address_anak) malloc(sizeof(struct elemen_list_anak));
    if (P != NULL) {
        P->info = X;
        P->next = NULL;
        P->prev = NULL;
    }
    return P;
}

void dealokasi(address P) {
    free(P);
}

void dealokasiAnak(address_anak P) {
    free(P);
}

address findElm(listinduk L, infotypeinduk X) {
    address P = L.first;
    while (P != NULL && P->info != X) {
        P = P->next;
    }
    return P;
}

address_anak findElmAnak(listanak L, infotypeanak X) {
    address_anak P = L.first;
    while (P != NULL && P->info != X) {
        P = P->next;
    }
    return P;
}

bool fFindElm(listinduk L, address P) {
    address Q = L.first;
    while (Q != NULL) {
        if (Q == P) return true;
        Q = Q->next;
    }
    return false;
}

bool fFindElmAnak(listanak L, address_anak P) {
    address_anak Q = L.first;
    while (Q != NULL) {
        if (Q == P) return true;
        Q = Q->next;
    }
    return false;
}

address findBefore(listinduk L, address P) {
    if (P == L.first) return NULL;
    return P->prev;
}

address_anak findBeforeAnak(listanak L, infotypeanak X, address_anak P) {
    if (P == L.first) return NULL;
    return P->prev;
}

void insertFirst(listinduk *L, address P) {
    if (ListEmpty(*L)) {
        L->first = P;
        L->last  = P;
    } else {
        P->next = L->first;
        L->first->prev = P;
        L->first = P;
    }
}

void insertAfter(listinduk *L, address P, address Prec) {
    if (Prec != NULL) {
        P->next = Prec->next;
        P->prev = Prec;

        if (Prec->next != NULL)
            Prec->next->prev = P;
        else
            L->last = P;

        Prec->next = P;
    }
}

void insertLast(listinduk *L, address P) {
    if (ListEmpty(*L)) {
        insertFirst(L, P);
    } else {
        L->last->next = P;
        P->prev = L->last;
        L->last = P;
    }
}

void insertFirstAnak(listanak *L, address_anak P) {
    if (ListEmptyAnak(*L)) {
        L->first = P;
        L->last  = P;
    } else {
        P->next = L->first;
        L->first->prev = P;
        L->first = P;
    }
}

void insertAfterAnak(listanak *L, address_anak P, address_anak Prec) {
    if (Prec != NULL) {
        P->next = Prec->next;
        P->prev = Prec;

        if (Prec->next != NULL)
            Prec->next->prev = P;
        else
            L->last = P;

        Prec->next = P;
    }
}

void insertLastAnak(listanak *L, address_anak P) {
    if (ListEmptyAnak(*L)) {
        insertFirstAnak(L, P);
    } else {
        L->last->next = P;
        P->prev = L->last;
        L->last = P;
    }
}

void delFirst(listinduk *L, address *P) {
    *P = L->first;

    if (L->first == L->last) {
        L->first = NULL;
        L->last  = NULL;
    } else {
        L->first = (*P)->next;
        L->first->prev = NULL;
    }
    (*P)->next = NULL;
}

void delLast(listinduk *L, address *P) {
    *P = L->last;

    if (L->first == L->last) {
        L->first = NULL;
        L->last  = NULL;
    } else {
        L->last = (*P)->prev;
        L->last->next = NULL;
    }
    (*P)->prev = NULL;
}

void delAfter(listinduk *L, address *P, address Prec) {
    *P = Prec->next;
    if (*P != NULL) {
        Prec->next = (*P)->next;
        if ((*P)->next != NULL)
            (*P)->next->prev = Prec;
        else
            L->last = Prec;

        (*P)->next = NULL;
        (*P)->prev = NULL;
    }
}

void delP(listinduk *L, infotypeinduk X) {
    address P = findElm(*L, X);
    if (P == NULL) return;

    address Q;

    if (P == L->first) {
        delFirst(L, &Q);
    } else if (P == L->last) {
        delLast(L, &Q);
    } else {
        delAfter(L, &Q, P->prev);
    }

    dealokasi(Q);
}

void delFirstAnak(listanak *L, address_anak *P) {
    *P = L->first;

    if (L->first == L->last) {
        L->first = NULL;
        L->last = NULL;
    } else {
        L->first = (*P)->next;
        L->first->prev = NULL;
    }
    (*P)->next = NULL;
}

void delLastAnak(listanak *L, address_anak *P) {
    *P = L->last;

    if (L->first == L->last) {
        L->first = NULL;
        L->last = NULL;
    } else {
        L->last = (*P)->prev;
        L->last->next = NULL;
    }
    (*P)->prev = NULL;
}

void delAfterAnak(listanak *L, address_anak *P, address_anak Prec) {
    *P = Prec->next;
    if (*P != NULL) {
        Prec->next = (*P)->next;
        if ((*P)->next != NULL)
            (*P)->next->prev = Prec;
        else
            L->last = Prec;

        (*P)->next = NULL;
        (*P)->prev = NULL;
    }
}

void delPAnak(listanak *L, infotypeanak X) {
    address_anak P = findElmAnak(*L, X);
    if (P == NULL) return;

    address_anak Q;

    if (P == L->first) {
        delFirstAnak(L, &Q);
    } else if (P == L->last) {
        delLastAnak(L, &Q);
    } else {
        delAfterAnak(L, &Q, P->prev);
    }

    dealokasiAnak(Q);
}

void printInfoAnak(listanak L) {
    address_anak P = L.first;
    while (P != NULL) {
        printf("%d ", P->info);
        P = P->next;
    }
}

void printInfo(listinduk L) {
    address P = L.first;
    while (P != NULL) {
        printf("Induk %d : ", P->info);
        printInfoAnak(P->lanak);
        printf("\n");
        P = P->next;
    }
}

int nbList(listinduk L) {
    int n = 0;
    address P = L.first;
    while (P != NULL) {
        n++;
        P = P->next;
    }
    return n;
}

int nbListAnak(listanak L) {
    int n = 0;
    address_anak P = L.first;
    while (P != NULL) {
        n++;
        P = P->next;
    }
    return n;
}

void delAll(listinduk *L) {
    address P = L->first;
    address Q;

    while (P != NULL) {

        // hapus semua anak memakai delPAnak
        while (P->lanak.first != NULL) {
            infotypeanak x = P->lanak.first->info;
            delPAnak(&P->lanak, x);
        }

        Q = P;
        P = P->next;

        dealokasi(Q);
    }

    L->first = NULL;
    L->last = NULL;
}

// main.cpp
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

```
#### Output :

<img width="1264" height="830" alt="Screenshot 2025-12-10 214309" src="https://github.com/user-attachments/assets/2df80b9f-517b-4864-a8ef-c0a32838452a" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/bf000b4b-5683-4d9c-89fd-29bd08a12207" />

## Kesimpulan
Program ini menggunakan multilist di mana setiap data induk punya list anak. Data bisa ditambah dengan insertFirst, insertLast, insertAfter dan dihapus dengan delFirst, deleteLast, deleteAfter. Pencarian dilakukan lewat findElm, dan seluruh data induk–anak dapat ditampilkan dengan printInfo.


## Referensi
[1] GeeksforGeeks, “Introduction to Multi Linked List,” GeeksforGeeks Blog. [Online]. Available: https://www.geeksforgeeks.org/dsa/introduction-to-multi-linked-list/
