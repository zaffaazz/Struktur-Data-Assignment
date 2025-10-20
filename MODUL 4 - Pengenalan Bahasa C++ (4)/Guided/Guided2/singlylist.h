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