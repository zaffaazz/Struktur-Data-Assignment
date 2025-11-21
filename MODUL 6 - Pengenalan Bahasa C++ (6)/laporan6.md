# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Zaffa Azzahra </p>

## Dasar Teori
Double Linked List adalah struktur data dinamis yang terdiri dari node-node yang menyimpan data serta pointer ke node sebelumnya dan node berikutnya, di mana node pertama memiliki prev = NULL dan node terakhir memiliki next = NULL. Struktur ini memungkinkan operasi penambahan (insert) dan penghapusan (delete) dilakukan dengan lebih mudah karena cukup mengatur pointer tanpa perlu menggeser elemen seperti pada array.
## Ungided

### 1. [DLL]

```C++
#include <iostream> 
using namespace std; 
#define Nil NULL 

typedef int infotype; // Definisikan tipe data infotype sebagai integer untuk menyimpan informasi elemen
typedef struct elmlist *address; // Definisikan tipe address sebagai pointer ke struct elmlist

struct elmlist { 
    infotype info; // Deklarasikan field info untuk menyimpan data elemen
    address next;   
    address prev; 
}; 

struct List { 
    address first; 
    address last;
}; 

address alokasi(infotype x) { // Definisikan fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P->info = x; P->next = Nil; P->prev = Nil; return P; // Set nilai info, next, prev, dan kembalikan pointer
} 
void dealokasi(address &P) { delete P; P = Nil; } // Definisikan fungsi dealokasi untuk mengosongkan memori elemen
void insertFirst(List &L, address P) { 
    P->next = L.first; P->prev = Nil; // Set pointer next P ke first saat ini dan prev ke Nil
    if (L.first != Nil) L.first->prev = P; else L.last = P; // Jika list tidak kosong, update prev first; jika kosong, set last ke P
    L.first = P; // Update first list menjadi P
}

void printInfo(List L) { 
    address P = L.first; while (P != Nil) { cout << P->info << " "; P = P->next; } cout << endl; // Loop melalui list dan cetak info setiap elemen
} 
void deleteFirst(List &L, address &P) { 
    P = L.first; L.first = L.first->next; // Set P ke first dan update first ke next-nya
    if (L.first != Nil) L.first->prev = Nil; else L.last = Nil; // Jika list tidak kosong, set prev first baru ke Nil; jika kosong, set last ke Nil
    P->next = Nil; P->prev = Nil; // Kosongkan pointer next dan prev P
}

void deleteLast(List &L, address &P) { 
    P = L.last; L.last = L.last->prev; // Set P ke last dan update last ke prev-nya
    if (L.last != Nil) L.last->next = Nil; else L.first = Nil; // Jika list tidak kosong, set next last baru ke Nil; jika kosong, set first ke Nil
    P->prev = Nil; P->next = Nil; // Kosongkan pointer prev dan next P
} 
    
void deleteAfter(List &L, address &P, address R) { 
    P = R->next; R->next = P->next; // Set P ke next R dan update next R ke next P
    if (P->next != Nil) P->next->prev = R; else L.last = R; // Jika ada next P, update prev-nya ke R; jika tidak, set last ke R
    P->prev = Nil; P->next = Nil; // Kosongkan pointer prev dan next P
} 

int main() { 
    List L; L.first = Nil; L.last = Nil; 
    insertFirst(L, alokasi(1)); insertFirst(L, alokasi(2)); insertFirst(L, alokasi(3)); // Sisipkan elemen 1, 2, 3 di awal list
    printInfo(L);
    address P; deleteFirst(L, P); dealokasi(P); // Deklarasikan P, hapus first, dealokasi P
    deleteAfter(L, P, L.first); dealokasi(P); // Hapus setelah first, dealokasi P
    printInfo(L); 
    return 0; 
}
Kode di atas digunakan untuk mencetak teks "ini adalah file code uguided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Guided

### 1. [Soal]

```C++
// doublylist.h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void createList(List &L);
address alokasi(string nopol, string warna, int thnBuat);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address P, address Prec);

address findElm(List L, string nopol);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address &Prec, address &P);

#endif


// doublylist.cpp
#include "doublylist.h"
#include <iostream>
using namespace std;

bool isEmpty(List &L) {
    return (L.first == Nil);
}

void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(string nopol, string warna, int thnBuat) {
    address P = new ElmList;
    P->info.nopol = nopol;
    P->info.warna = warna;
    P->info.thnBuat = thnBuat;

    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}


void insertFirst(List &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast(List &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertAfter(List &L, address P, address Prec) {
    if (Prec != Nil) {
        P->next = Prec->next;
        P->prev = Prec;

        if (Prec->next != Nil)
            Prec->next->prev = P;
        else
            L.last = P;  // Prec adalah elemen terakhir

        Prec->next = P;
    }
}

address findElm(List L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P; // ditemukan
        }
        P = P->next;
    }
    return Nil; // tidak ditemukan
}

void deleteFirst(List &L, address &P) {
    if (isEmpty(L)) {
        P = Nil;
    } else if (L.first == L.last) {  
        // hanya 1 elemen
        P = L.first;
        L.first = Nil;
        L.last = Nil;
    } else {
        P = L.first;
        L.first = L.first->next;
        L.first->prev = Nil;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (isEmpty(L)) {
        P = Nil;
    } else if (L.first == L.last) { 
        P = L.last;
        L.first = Nil;
        L.last = Nil;
    } else {
        P = L.last;
        L.last = L.last->prev;
        L.last->next = Nil;
        P->prev = Nil;
    }
}

void deleteAfter(List &L, address &Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;

        Prec->next = P->next;

        if (P->next != Nil)
            P->next->prev = Prec;
        else
            L.last = Prec;  

        P->next = Nil;
        P->prev = Nil;
    }
}


void printInfo(List L) {
    cout << "\nDATA LIST 1\n\n";

    address P = L.first;
    while (P != Nil) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl << endl;

        P = P->next;
    }
}

// main.cpp
#include "doublylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    createList(L);

    address P;
    string nopol, warna;
    int thnBuat;

    for(int i = 0; i < 4; i++) {
        cout << "Masukkan nomor polisi: ";
        cin >> nopol;
        
        bool found = false;
        address C = L.first;
        while(C != Nil){
            if(C->info.nopol == nopol){
                found = true;
                break;
            }
            C = C->next;
        }

        if(found){
            cout << "Nomor polisi sudah terdaftar" << endl;
            continue;
        }

        cout << "Masukkan warna kendaraan: ";
        cin >> warna;
        cout << "Masukkan tahun kendaraan: ";
        cin >> thnBuat;

        P = alokasi(nopol, warna, thnBuat);
        insertFirst(L, P);  
    }

    
    cout << "\nDATA LIST AWAL" << endl;
    printInfo(L);

    cout << "Masukkan Nomor Polisi yang dicari: ";
    string cari;
    cin >> cari;
    address F = findElm(L, cari);
    if(F != Nil){
        cout << "\nData ditemukan:" << endl;
        cout << "Nomor Polisi: " << F->info.nopol << endl;
        cout << "Warna       : " << F->info.warna << endl;
        cout << "Tahun       : " << F->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    cout << "\nMasukkan Nomor Polisi yang akan dihapus: ";
    string hapus;
    cin >> hapus;
    address H = findElm(L, hapus);

    if(H != Nil){
        if(H == L.first){
            deleteFirst(L, H);
        } else if(H == L.last){
            deleteLast(L, H);
        } else {
            deleteAfter(L, H->prev, H);
        }
        cout << "Data dengan nomor polisi " << hapus << " berhasil dihapus." << endl;
    } else {
        cout << "Data dengan nomor polisi " << hapus << " tidak ditemukan." << endl;
    }

    cout << "\nDATA LIST TERBARU" << endl;
    printInfo(L);

    return 0;
}

```
#### Output nomer 1:

<img width="1203" height="680" alt="Image" src="https://github.com/user-attachments/assets/3edf4532-e6ed-4090-9030-5821c3cf984e" />

#### Output nomer 2:

<img width="1177" height="161" alt="Image" src="https://github.com/user-attachments/assets/091e8a93-b75f-42da-bf8e-f26c8ac9cb75" />

#### Output nomer 3:

<img width="1184" height="372" alt="Image" src="https://github.com/user-attachments/assets/91c79cd7-0136-41f7-aa1b-da68f5710ca5" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/16a02230-73d3-4cd4-aa02-fbc0a3af7908" />

## Kesimpulan
Program di atas merupakan Program yang menggunakan Double Linked List, di mana setiap node menyimpan data kendaraan dan memiliki pointer next dan prev sehingga terhubung dua arah. Program dapat menambahkan data menggunakan insertFirst, mencari data dengan findElm, serta menghapus data menggunakan deleteFirst, deleteLast, atau deleteAfter. Setiap operasi cukup mengatur pointer antar-node tanpa perlu menggeser elemen seperti pada array. Seluruh isi list dapat ditampilkan menggunakan fungsi printInfo yang mencetak semua node dari awal hingga akhir.

## Referensi
[1] Programiz, “Doubly Linked List (With code)”, Programiz. [Online]. Available: https://www.programiz.com/dsa/doubly-linked-list
