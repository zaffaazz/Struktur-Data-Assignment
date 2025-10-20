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