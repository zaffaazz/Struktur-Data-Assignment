# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Zaffa Azzahra </p>

## Dasar Teori
Single Linked List adalah struktur data dinamis yang terdiri dari node-node berisi data dan pointer ke node berikutnya dan node terakhir menunjukan ke NULL. Didalamnya terdapat fitur-fitur seperti penambahan (insert) dan penghapusan (delete) data dengan mudah tanpa perlu menggeser elemen seperti pada array.
## Ungided 

### 1. [SLL]

```C++
#ifndef LISH_H
#define LiSH_H
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    string nim;
    int umur;
};
// dekralasi isi data 
typedef mahasiswa dataMahasiswa;
typedef struct node *address; // alamat addres pada pointer

struct node{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{
    address first;
};
// smua procedure da func yang dipakai
bool isEmpty (linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Guided

### 1. [Soal]

```C++
// singlylist.h
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;
 
// dekralasi isi data 
typedef int nilai;
typedef struct node *address; // alamat addres pada pointer

struct node{
    nilai isidata;
    address next;
};

struct List{
    address first;
};

bool isEmpty (List L);
void createList(List &L);
address alokasi(int nilai);
void dealokasi(address &node);
void printList(List L);
void insertFirst(List &L, address nodeBaru);
void insertAfter(List &L, address nodeBaru, address Prev);
void insertLast(List &L, address nodeBaru);

#endif

// singlylist.cpp
#include "singlylist.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(List L) {
    if(L.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(List &L) {
    L.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(int nilai) { 
    address nodeBaru = new node; 
    nodeBaru-> isidata = nilai;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(List &L, address nodeBaru) {
    nodeBaru->next = L.first; 
    L.first = nodeBaru;
}

void insertAfter(List &L, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(List &L, address nodeBaru) {
    if (isEmpty(L)) {
        L.first = nodeBaru;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(List L) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = L.first;
        cout << "Isi list: ";
        while (nodeBantu != Nil) {
            cout << nodeBantu->isidata << " ";
            nodeBantu = nodeBantu->next;
        }
        cout << endl;
    }
}

// main.cpp
#include "singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    address P1 = Nil, P2 = Nil, P3 = Nil, P4 = Nil, P5 = Nil;

    createList(L);

    P1 = alokasi(2);
    P2 = alokasi(0);
    P3 = alokasi(8);
    P4 = alokasi(12);
    P5 = alokasi(9);

    insertFirst(L, P1);
    insertFirst(L, P2);
    insertFirst(L, P3);
    insertFirst(L, P4);
    insertFirst(L, P5);

    printList(L);

    return 0;
}
```
#### Output:

<img width="526" height="82" alt="Image" src="https://github.com/user-attachments/assets/128ed43b-9ab1-4b24-83ba-f761709f2468" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/89fbb333-5152-4704-affa-d11451eb9eb1" />

## Kesimpulan
Penjelasan di atas adalah sebuah program dengan menggunakan single linked list, dimana program tersebut menambahkan (insert) sebuah node ke dalam list satu per satu hingga akhir, dengan menggunakan insertFirst, insertAfter, atau insertLast setiap node baru dapat ditambahkan diawal, ditengah, atau diakhir list, dan setiap node terhubung melalui pointer ke node berikutnya, kemudian Seluruh data dalam list dapat ditampilkan menggunakan fungsi printList yang akan mengoutputkan node-node yang telah dibuat.
### 2. [Soal]

```C++
// singlylist.h
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;
 
// dekralasi isi data 
typedef int nilai;
typedef struct node *address; // alamat addres pada pointer

struct node{
    nilai isidata;
    address next;
};

struct List{
    address first;
};

bool isEmpty (List L);
void createList(List &L);
address alokasi(int nilai);
void dealokasi(address &node);
void printList(List L);
void insertFirst(List &L, address nodeBaru);
void insertAfter(List &L, address nodeBaru, address Prev);
void insertLast(List &L, address nodeBaru);

void delFirst(List &L);
void delLast (List &L);
void delAfter(List &L,address nodeBaru, address Prev);
int nbList(List L);
void deletList(List &L);

#endif
// singlylist.cpp
#include "singlylist.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(List L) {
    if(L.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(List &L) {
    L.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(int nilai) { 
    address nodeBaru = new node; 
    nodeBaru-> isidata = nilai;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(List &L, address nodeBaru) {
    nodeBaru->next = L.first; 
    L.first = nodeBaru;
}

void insertAfter(List &L, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(List &L, address nodeBaru) {
    if (isEmpty(L)) {
        L.first = nodeBaru;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(List &L){
    address nodeHapus;
    if (isEmpty(L) == false) {
        nodeHapus = L.first;
        L.first = L.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(List &L){
    address nodeHapus, nodePrev;
    if(isEmpty(L) == false){
        nodeHapus = L.first;
        if(nodeHapus->next == Nil){
            L.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(List &L, address nodeHapus, address nodePrev){
    if(isEmpty(L) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(List L) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = L.first;
        cout << "Isi list: ";
        while (nodeBantu != Nil) {
            cout << nodeBantu->isidata << " ";
            nodeBantu = nodeBantu->next;
        }
        cout << endl;
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(List L) {
    int count = 0;
    address nodeBantu = L.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deletList(List &L){
    address nodeBantu, nodeHapus;
    nodeBantu = L.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    L.first = Nil; 
    cout << "List sudah terhapus!" << endl;
} 
// main.cpp
#include "singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    address P1 = Nil, P2 = Nil, P3 = Nil, P4 = Nil, P5 = Nil;

    createList(L);

    P1 = alokasi(2);
    P2 = alokasi(0);
    P3 = alokasi(8);
    P4 = alokasi(12);
    P5 = alokasi(9);

    insertFirst(L, P1);
    insertFirst(L, P2);
    insertFirst(L, P3);
    insertFirst(L, P4);
    insertFirst(L, P5);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    delFirst(L);
    delLast(L);
    delAfter(L, P3, P4);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    deletList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;


    return 0;
}

```
#### Output:
<img width="445" height="209" alt="Image" src="https://github.com/user-attachments/assets/3919cc7f-aeea-4508-ad92-58b2715e615a" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/fa63e69f-28ec-475e-af2c-7414e7c56e9f" />

## Kesimpulan
Penjelasan di atas adalah sebuah program dengan menggunakan single linked list, di mana program tersebut menambahkan (insert) sebuah node ke dalam list satu per satu hingga akhir, dengan menggunakan insertFirst, insertAfter, atau insertLast setiap node baru dapat ditambahkan diawal, ditengah, atau diakhir list, dan setiap node terhubung melalui pointer ke node berikutnya, kemudian Seluruh data dalam list dapat ditampilkan menggunakan fungsi printList yang akan mengoutputkan node-node yang telah dibuat. Lalu program diatas juga ada procedure untuk menghapus(delete) sebuah node pada list dengan menggunkaan delFirst, delAfter, delLast, atau deletlist, Setiap node yang terhubung dalam sebuah pointer akan terhapus sesuai dengan node yang kita inginkan.

## Referensi
[1] Trivusi, "Struktur Data — Linked List", Trivusi (blog), Jul. 2022. [Online]. Available: https://www.trivusi.web.id/2022/07/struktur-data-linked-list.html#google_vignette.
