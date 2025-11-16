# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Zaffa Azzahra </p>

## Dasar Teori
Stack adalah struktur data linear yang mengikuti prinsip Last In First Out (LIFO) artinya, elemen yang terakhir dimasukkan ke dalam stack akan menjadi elemen yang pertama dikeluarkan. 
## Unguided

### 1. [STUCK]

```C++
// stack.cpp
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
// stack.h
#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack); 
void createStack (stack &listStack);
address alokasi (int angka);
void dealokasi (address &node);

void push(stack &listStack, address nodeBaru); 
void pop(stack &listStack); 
void update (stack &listStack, int posisi);
void view(stack listStack);
void searchData (stack listStack, int data);

#endif
// main.cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);
    
    return 0;
}

Kode di atas digunakan untuk mencetak teks "ini adalah file code unguided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Guided

### 1. [Soal]

```C++

// stack.h
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

struct stackBuah {
    string Buah[10];
    int top; // -1 = kosong
};

bool isEmpty(stackBuah s);
bool isFull(stackBuah s);
void createStack(stackBuah &s);

void push(stackBuah &s, string buah);
void pop(stackBuah &s);
void update(stackBuah &s, int posisi);
void view(stackBuah s);
void searchData(stackBuah s, string buah);

#endif
// stack.cpp
#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(stackBuah s){
    return s.top == -1;
}

bool isFull(stackBuah s){
    return s.top == 9;   // karena Buah[10]
}

void createStack(stackBuah &s){
    s.top = -1;
}

void push(stackBuah &s, string buah){
    if(isFull(s)){
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.Buah[s.top] = buah;
        cout << "Buah \"" << buah << "\" berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackBuah &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        string val = s.Buah[s.top];
        s.top--;
        cout << "Buah \"" << val << "\" berhasil dihapus dari stack!" << endl;
    }
}

void update(stackBuah &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    if(posisi <= 0){
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    // Hitung index array sebenarnya
    int idx = s.top - (posisi - 1);

    if(idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }

    cout << "Update data pada posisi ke-" << posisi << endl;
    cout << "Masukkan nama buah baru: ";
    cin >> s.Buah[idx];
    cout << "Data berhasil diupdate!" << endl << endl;
}

void view(stackBuah s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; --i){
            cout << s.Buah[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackBuah s, string buah){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << "Mencari buah \"" << buah << "\"..." << endl;

    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; --i){
        if(s.Buah[i] == buah){
            cout << "Buah \"" << buah << "\" ditemukan pada posisi ke-" << posisi << endl << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Buah \"" << buah << "\" tidak ditemukan didalam stack!" << endl << endl;
    }
}
// main.cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    stackBuah s;
    createStack(s);

    push(s, "Apel");
    push(s, "Jeruk");
    push(s, "Mangga");
    push(s, "Pisang");
    push(s, "Anggur");
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    update(s, 2);
    update(s, 1);
    update(s, 4); 
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, "Pear");
    searchData(s, "Nanas");

    return 0;
}

```
#### Output:

<img width="1022" height="811" alt="Image" src="https://github.com/user-attachments/assets/e5ce300f-d48c-44d4-a169-17fb7788f28e" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/4581ea62-8dbb-4114-9b81-d803bef54505" />

## Kesimpulan
Program di atas merupakan program tentang stack dengan menggunakan array  maksimal 10 elemen.Jika pengguna memasukkan lebih dari 10 data, maka program hanya akan menyimpan 10 data teratas karena kondisi stack penuh. Program ini menggunakan fungsi untuk mengecek apakah stack kosong atau penuh, serta procedure untuk melakukan operasi seperti menambah data (push), menghapus data (pop), memperbarui data (update), menampilkan isi stack (view), dan mencari data tertentu (search).
### 2. [Soal]

```C++
// stack.h
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

const int MAX = 10;

struct stackTable {
    int data[MAX];
    int top;
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);

void printInfo(stackTable s);
void balikStack(stackTable &s);

#endif
// stack.cpp
#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(stackTable s) {
    return s.top == -1;
}

bool isFull(stackTable s) {
    return s.top == MAX - 1;
}

void createStack(stackTable &s) {
    s.top = -1;
}

void push(stackTable &s, int angka) {
    if (!isFull(s)) {
        s.top++;
        s.data[s.top] = angka;
    }
}

void pop(stackTable &s) {
    if (!isEmpty(s)) {
        s.top--;
    }
}

void printInfo(stackTable s) {
    cout << "[TOP] ";
    for (int i = s.top; i >= 0; i--) {
        cout << s.data[i] << " ";
    }
    cout << endl;
}

void balikStack(stackTable &s) {
    stackTable temp;
    createStack(temp);

    while (!isEmpty(s)) {
        temp.top++;
        temp.data[temp.top] = s.data[s.top];
        s.top--;
    }

    s = temp;
}
// main.cpp
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    stackTable S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    printInfo(S);

    return 0;
}

```
#### Output:
<img width="998" height="228" alt="Image" src="https://github.com/user-attachments/assets/d21924f6-74be-4592-b023-293dca8ea50b" />
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/6c996a42-5967-4a98-b621-07073bd371f7" />

## Kesimpulan
Program di atas merupakan program stack dengan menggunakan array maksimal 10 elemen. Stack dibuat menggunakan struktur stackTable yang menyimpan data integer serta variabel top sebagai penanda posisi elemen paling atas.Jika pengguna menambahkan data lebih dari 10 elemen, maka penambahan tidak dilakukan karena kondisi stack dianggap penuh, Program ini menyediakan fungsi untuk mengecek apakah stack kosong atau penuh, serta procedure untuk melakukan operasi dasar seperti menambah elemen (push), menghapus elemen paling atas (pop), menampilkan isi stack dari atas ke bawah (printInfo), dan membalik urutan isi stack (balikStack) dengan menggunakan stack sementara. Pada fungsi main, beberapa operasi push dan pop dilakukan untuk menunjukkan cara kerja stack tersebut, kemudian ditampilkan hasilnya sebelum dan sesudah proses pembalikan data.

### 3. [Soal]

```C++
// stack.h
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

const int MAX = 10;

struct stackTable {
    int data[MAX];
    int top;
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);
void balikStack(stackTable &s);
void pushAscending(stackTable &s, int angka);

#endif
// stack.cpp

   #include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(stackTable s) {
    return s.top == -1;
}

bool isFull(stackTable s) {
    return s.top == MAX - 1;
}

void createStack(stackTable &s) {
    s.top = -1;
}

void push(stackTable &s, int angka) {
    if (!isFull(s)) {
        s.data[++s.top] = angka;
    }
}

void pop(stackTable &s) {
    if (!isEmpty(s)) {
        s.top--;
    }
}

void update(stackTable &s, int posisi) {
    if (posisi < 1 || posisi > s.top + 1) {
        cout << "Posisi tidak valid!\n";
        return;
    }
    cout << "Update nilai posisi ke-" << posisi << ": ";
    cin >> s.data[s.top - (posisi - 1)];
}

void view(stackTable s) {
    if (isEmpty(s)) {
        cout << "[TOP] (kosong)" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = 0; i <= s.top; i++) {
            cout << s.data[i] << " ";
        }
        cout << endl;
    }
}

void searchData(stackTable s, int data) {
    int posisi = 1;
    for (int i = s.top; i >= 0; i--) {
        if (s.data[i] == data) {
            cout << "Data ditemukan di posisi ke-" << posisi << endl;
            return;
        }
        posisi++;
    }
    cout << "Data tidak ditemukan!" << endl;
}

void balikStack(stackTable &s) {
    if (isEmpty(s)) return;
    int i = 0;
    int j = s.top;
    while (i < j) {
        int tmp = s.data[i];
        s.data[i] = s.data[j];
        s.data[j] = tmp;
        i++;
        j--;
    }
}

void pushAscending(stackTable &s, int angka) {
    if (isFull(s)) return;

    stackTable temp;
    createStack(temp);

    while (!isEmpty(s) && s.data[s.top] < angka) {
        temp.data[++temp.top] = s.data[s.top];
        s.top--;
    }

    s.data[++s.top] = angka;

    while (!isEmpty(temp)) {
        s.data[++s.top] = temp.data[temp.top];
        temp.top--;
    }
}
// main.cpp
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    stackTable S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    cout << "[TOP] ";
    view(S);
    
    cout << "balik stack" << endl;
    balikStack(S);

    cout << "[TOP] ";
    view(S);

    return 0;
}

```
#### Output:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/498e4fec-d992-4f50-8f27-2c19b155343b" />
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="997" height="826" alt="Image" src="https://github.com/user-attachments/assets/ab1bb275-8235-4cb9-b101-b980d46db39a" />

## Kesimpulan
Program di atas merupakan program stack dengan menggunakan array berkapasitas maksimal 10 elemen.Program ini menyediakan fungsi untuk mengecek apakah stack kosong atau penuh, serta procedure untuk melakukan operasi dasar seperti menambah elemen (push), menghapus elemen paling atas (pop), memperbarui data (update), menampilkan isi stack (view), mencari data tertentu (searchData), dan membalik urutan elemen dalam stack (balikStack). Program ini juga memiliki fitur pushAscending yang memungkinkan penambahan elemen secara terurut naik dengan bantuan stack sementara. Pada bagian main, beberapa data dimasukkan menggunakan metode ascending, lalu isi stack ditampilkan sebelum dan sesudah proses pembalikan.

### 4. [Soal]

```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

const int MAX = 10;

struct stackTable {
    int data[MAX];
    int top;
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);

void printInfo(stackTable s);
void balikStack(stackTable &s);
void getInputStream(stackTable &s);

#endif
// stack.cpp
#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(stackTable s) {
    return s.top == -1;
}

bool isFull(stackTable s) {
    return s.top == MAX - 1;
}

void createStack(stackTable &s) {
    s.top = -1;
}

void push(stackTable &s, int angka) {
    if (!isFull(s)) {
        s.top++;
        s.data[s.top] = angka;
    }
}

void pop(stackTable &s) {
    if (!isEmpty(s)) {
        s.top--;
    }
}

void printInfo(stackTable s) {
    cout << "[TOP] ";
    for (int i = s.top; i >= 0; i--) {
        cout << s.data[i] << " ";
    }
    cout << endl;
}

void balikStack(stackTable &s) {
    stackTable temp;
    createStack(temp);

    while (!isEmpty(s)) {
        push(temp, s.data[s.top]);
        pop(s);
    }

    s = temp;
}

void getInputStream(stackTable &s) {
    cout << "Masukkan angka : ";
    char c = cin.get(); 

    while (c != '\n') {
        if (isdigit(c)) {
            int val = c - '0';
            push(s, val);
        }
        c = cin.get();   
    }
}
 // main.cpp
 #include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    stackTable S;
    createStack(S);

    getInputStream(S);
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```
#### Output:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/498e4fec-d992-4f50-8f27-2c19b155343b" />
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="997" height="826" alt="Image" src="https://github.com/user-attachments/assets/ab1bb275-8235-4cb9-b101-b980d46db39a" />

## Kesimpulan
Program di atas merupakan program stack dengan menggunakan array berkapasitas maksimal 10 elemen. Didalamnya terdaat fungsi untuk mengecek apakah stack kosong atau penuh, serta procedure untuk melakukan operasi dasar seperti menambah elemen (push), menghapus elemen paling atas (pop), dan menampilkan isi stack dari atas ke bawah (printInfo). Program ini juga memiliki fitur balikStack yang digunakan untuk membalik urutan elemen di dalam stack dengan bantuan stack sementara. Selain itu, terdapat procedure getInputStream yang memungkinkan pengguna memasukkan angka secara langsung melalui input karakter, lalu setiap digit numeric secara otomatis dimasukkan ke dalam stack. Pada fungsi main, program membaca input angka dari user, menampilkannya dalam bentuk stack, kemudian membalik urutannya dan menampilkan hasil akhirnya.

## Referensi
[1]Parewa Labs. Stack Data Structure and Implementation in Python, Java and C/C++. Programiz. Tersedia secara daring di: https://www.programiz.com/dsa/stack 
[2] OpenGenus. Sort a Stack Using Another Stack. Tersedia secara daring di: https://iq.opengenus.org/sort-stack-using-stack
