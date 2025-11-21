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
