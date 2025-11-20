#ifndef LIST_H
#define LIST_H

#include <iostream>
#define Nil NULL

using namespace std;

struct product {
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen;  
};

typedef product dataProduct;
typedef struct node *address;

struct node {
    dataProduct isidata;
    address next;
};

struct linkedlist {
    address head;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string Nama, string SKU, int Jumlah, float HargaSatuan, float DiskonPersen);
void dealokasi(address &node);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(address prev, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(address prev);
void printList(linkedlist List);
int viewList(linkedlist List);
void updateAfter(linkedlist, address prev);
void FindNodeByFinalPriceRange(linkedlist list, float hargaAwal, float hargaAkhir);
void FindMaxHargaAkhir (linkedlist List);

#endif