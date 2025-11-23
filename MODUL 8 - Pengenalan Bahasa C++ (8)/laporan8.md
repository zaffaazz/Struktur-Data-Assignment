# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Zaffa Azzahra </p>

## Dasar Teori
Double Linked List adalah struktur data dinamis yang terdiri dari node-node yang menyimpan data serta pointer ke node sebelumnya dan node berikutnya, di mana node pertama memiliki prev = NULL dan node terakhir memiliki next = NULL. Struktur ini memungkinkan operasi penambahan (insert) dan penghapusan (delete) dilakukan dengan lebih mudah karena cukup mengatur pointer tanpa perlu menggeser elemen seperti pada array.
## Ungided

### 1. [QUEUE]

```C++
#include "queue.h"
using namespace std;

void CreateQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}


Kode di atas digunakan untuk mencetak teks "ini adalah file code uguided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Guided

### 1. [Soal]

```C++
// queue.cpp
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAKSIMAL - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    for (int i = Q.head; i < Q.tail; i++) {
        Q.info[i] = Q.info[i + 1];
    }
    Q.tail--;

    if (Q.tail < 0) {
        Q.head = Q.tail = -1;
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t| ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}

```
#### Output :

<img width="1206" height="393" alt="Image" src="https://github.com/user-attachments/assets/3885654e-5ad5-47e8-b5d4-78717555c9bd" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/16a02230-73d3-4cd4-aa02-fbc0a3af7908" />

## Kesimpulan
Program di atas menggunakan queue berbasis array biasa, di mana data disimpan secara berurutan dan operasi penghapusan dilakukan dengan menggeser elemen maju satu posisi. Penambahan elemen dilakukan melalui enqueue, penghapusan dengan dequeue, serta pengecekan kondisi antrian menggunakan isEmptyQueue dan isFullQueue. Seluruh isi antrian dapat ditampilkan menggunakan printInfo.

### 2. [Soal]

```C++
// queue2.cpp
#include "queue2.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q){
    return (Q.head == -1);
}

bool isFullQueue(Queue Q){
    return ((Q.tail + 1) % MAKSIMAL == Q.head);
}

void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "Queue penuh\n";
    } else {
        if(isEmptyQueue(Q)){
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAKSIMAL;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q){
    if(isEmptyQueue(Q)){
        cout << "Queue kosong\n";
        return -1;
    }

    infotype x = Q.info[Q.head];

    if(Q.head == Q.tail){
        Q.head = Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAKSIMAL;
    }

    return x;
}

void printInfo(Queue Q){
    cout << Q.head << " - " << Q.tail << "\t| ";

    if(isEmptyQueue(Q)){
        cout << "empty queue\n";
        return;
    }

    int i = Q.head;
    while(true){
        cout << Q.info[i] << " ";
        if(i == Q.tail) break;
        i = (i + 1) % MAKSIMAL;
    }
    cout << endl;
}

```

#### Output:

<img width="1208" height="428" alt="Image" src="https://github.com/user-attachments/assets/6ab486e9-32cb-49a6-817d-2d222185b265" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/16a02230-73d3-4cd4-aa02-fbc0a3af7908" />

## Kesimpulan
Program di atas menggunakan circular queue, yaitu antrean yang memanfaatkan array melingkar sehingga elemen tidak perlu digeser saat ada penghapusan. Baik head maupun tail bergerak menggunakan operasi modulo sehingga indeks dapat kembali ke awal ketika mencapai batas array. Data dimasukkan dengan enqueue, dihapus dengan dequeue, dan kondisi antrean dicek melalui isEmptyQueue serta isFullQueue. Seluruh isi antrean dapat ditampilkan menggunakan printInfo.

### 3. [Soal]

```C++
// main.cpp
#include "queue3.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % MAKSIMAL == Q.head);
}

void enqueue(Queue &Q, int x) {
    if(isFullQueue(Q)) {
        cout << "Queue penuh\n";
        return;
    }

    if(isEmptyQueue(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAKSIMAL;
    }

    Q.info[Q.tail] = x;
}

int dequeue(Queue &Q) {
    if(isEmptyQueue(Q)) {
        cout << "Queue kosong\n";
        return -1;
    }

    int x = Q.info[Q.head];

    if(Q.head == Q.tail) {
        Q.head = Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAKSIMAL;
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t| ";

    if(isEmptyQueue(Q)) {
        cout << "empty queue\n";
        return;
    }

    int i = Q.head;
    while(true) {
        cout << Q.info[i] << " ";
        if(i == Q.tail) break;
        i = (i + 1) % MAKSIMAL;
    }
    cout << endl;
}

```
#### Output :

<img width="1184" height="372" alt="Image" src="https://github.com/user-attachments/assets/91c79cd7-0136-41f7-aa1b-da68f5710ca5" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/16a02230-73d3-4cd4-aa02-fbc0a3af7908" />

## Kesimpulan
Program di atas menggunakan Queue Circular Array, yaitu proses penyisipan dan penghapusan dapat dilakukan tanpa memindahkan elemen di dalam array dan semua operasi hanya menggeser pointer head dan tail data disimpan dalam array melingkar dengan indeks head dan tail yang bergerak menggunakan operasi modulo. Data ditambahkan dengan enqueue, dihapus dengan dequeue, dan dicek kondisinya dengan isEmptyQueue serta isFullQueue serta seluruh isi antrean dapat dilihat melalui printInfo.

## Referensi
[1] Programiz, “Doubly Linked List (With code)”, Programiz. [Online]. Available: https://www.programiz.com/dsa/doubly-linked-list
