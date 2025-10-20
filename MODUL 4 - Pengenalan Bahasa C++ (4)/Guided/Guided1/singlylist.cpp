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