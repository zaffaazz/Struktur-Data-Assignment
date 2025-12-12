#include "multilist.h"
#include <iostream>
using namespace std;


bool ListEmpty(listinduk L) {
    return (L.first == Nil);
}

bool ListEmptyAnak(listanak L) {
    return (L.first == Nil);
}

void CreateList(listinduk *L) {
    L->first = Nil;
    L->last = Nil;
}

void CreateListAnak(listanak *L) {
    L->first = Nil;
    L->last = Nil;
}


address alokasi(infotypeinduk X) {
    address P = (address) malloc(sizeof(elemen_list_induk));
    P->info = X;
    P->next = Nil;
    P->prev = Nil;
    CreateListAnak(&P->lanak);
    return P;
}

address_anak alokasiAnak(infotypeanak X) {
    address_anak P = (address_anak) malloc(sizeof(elemen_list_anak));
    P->info = X;
    P->next = Nil;
    P->prev = Nil;
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
    while (P != Nil && P->info != X) {
        P = P->next;
    }
    return P;
}

address_anak findElmAnak(listanak L, infotypeanak X) {
    address_anak P = L.first;
    while (P != Nil && P->info != X) {
        P = P->next;
    }
    return P;
}

bool fFindElm(listinduk L, address P) {
    address Q = L.first;
    while (Q != Nil) {
        if (Q == P) return true;
        Q = Q->next;
    }
    return false;
}

bool fFindElmAnak(listanak L, address_anak P) {
    address_anak Q = L.first;
    while (Q != Nil) {
        if (Q == P) return true;
        Q = Q->next;
    }
    return false;
}

address findBefore(listinduk L, address P) {
    if (L.first == P) return Nil;
    address Q = L.first;
    while (Q->next != P) {
        Q = Q->next;
    }
    return Q;
}

address_anak findBeforeAnak(listanak L, infotypeanak X, address_anak P) {
    if (L.first == P) return Nil;
    address_anak Q = L.first;
    while (Q->next != P) {
        Q = Q->next;
    }
    return Q;
}

void insertFirst(listinduk *L, address P) {
    if (ListEmpty(*L)) {
        L->first = L->last = P;
    } else {
        P->next = L->first;
        L->first->prev = P;
        L->first = P;
    }
}

void insertAfter(listinduk *L, address P, address Prec) {
    if (Prec == L->last) {
        insertLast(L, P);
    } else {
        P->next = Prec->next;
        P->prev = Prec;
        Prec->next->prev = P;
        Prec->next = P;
    }
}

void insertLast(listinduk *L, address P) {
    if (ListEmpty(*L)) {
        L->first = L->last = P;
    } else {
        P->prev = L->last;
        L->last->next = P;
        L->last = P;
    }
}


void insertFirstAnak(listanak *L, address_anak P) {
    if (ListEmptyAnak(*L)) {
        L->first = L->last = P;
    } else {
        P->next = L->first;
        L->first->prev = P;
        L->first = P;
    }
}

void insertAfterAnak(listanak *L, address_anak P, address_anak Prec) {
    if (Prec == L->last) {
        insertLastAnak(L, P);
    } else {
        P->next = Prec->next;
        P->prev = Prec;
        Prec->next->prev = P;
        Prec->next = P;
    }
}

void insertLastAnak(listanak *L, address_anak P) {
    if (ListEmptyAnak(*L)) {
        L->first = L->last = P;
    } else {
        P->prev = L->last;
        L->last->next = P;
        L->last = P;
    }
}


void delFirst(listinduk *L, address *P) {
    *P = L->first;

    if (L->first == L->last) {
        L->first = L->last = Nil;
    } else {
        L->first = (*P)->next;
        L->first->prev = Nil;
        (*P)->next = Nil;
    }
}

void delLast(listinduk *L, address *P) {
    *P = L->last;

    if (L->first == L->last) {
        L->first = L->last = Nil;
    } else {
        L->last = (*P)->prev;
        L->last->next = Nil;
        (*P)->prev = Nil;
    }
}

void delAfter(listinduk *L, address *P, address Prec) {
    *P = Prec->next;

    if (*P == L->last) {
        delLast(L, P);
    } else {
        Prec->next = (*P)->next;
        (*P)->next->prev = Prec;
        (*P)->next = (*P)->prev = Nil;
    }
}

void delP(listinduk *L, infotypeinduk X) {
    address P = findElm(*L, X);
    if (P == Nil) return;

    address Q;
    if (P == L->first) delFirst(L, &Q);
    else if (P == L->last) delLast(L, &Q);
    else delAfter(L, &Q, P->prev);

    delAllAnak(&Q->lanak);
    dealokasi(Q);
}

void delFirstAnak(listanak *L, address_anak *P) {
    *P = L->first;

    if (L->first == L->last) {
        L->first = L->last = Nil;
    } else {
        L->first = (*P)->next;
        L->first->prev = Nil;
        (*P)->next = Nil;
    }
}

void delLastAnak(listanak *L, address_anak *P) {
    *P = L->last;

    if (L->first == L->last) {
        L->first = L->last = Nil;
    } else {
        L->last = (*P)->prev;
        L->last->next = Nil;
        (*P)->prev = Nil;
    }
}

void delAfterAnak(listanak *L, address_anak *P, address_anak Prec) {
    *P = Prec->next;

    if (*P == L->last) {
        delLastAnak(L, P);
    } else {
        Prec->next = (*P)->next;
        (*P)->next->prev = Prec;
        (*P)->next = (*P)->prev = Nil;
    }
}

void delPAnak(listanak *L, infotypeanak X) {
    address_anak P = findElmAnak(*L, X);
    if (P == Nil) return;

    address_anak Q;
    if (P == L->first) delFirstAnak(L, &Q);
    else if (P == L->last) delLastAnak(L, &Q);
    else delAfterAnak(L, &Q, P->prev);

    dealokasiAnak(Q);
}

void delAll(listinduk *L) {
    address P;
    while (L->first != Nil) {
        delFirst(L, &P);
        delAllAnak(&P->lanak);
        dealokasi(P);
    }
}

void delAllAnak(listanak *L) {
    address_anak P;
    while (L->first != Nil) {
        delFirstAnak(L, &P);
        dealokasiAnak(P);
    }
}

void printInfo(listinduk L) {
    address P = L.first;
    while (P != Nil) {
        cout << "Induk: " << P->info << endl;
        printInfoAnak(P->lanak);
        P = P->next;
    }
}

void printInfoAnak(listanak L) {
    address_anak P = L.first;
    cout << "   Anak: ";
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

int nbList(listinduk L) {
    int n = 0;
    address P = L.first;
    while (P != Nil) {
        n++;
        P = P->next;
    }
    return n;
}

int nbListAnak(listanak L) {
    int n = 0;
    address_anak P = L.first;
    while (P != Nil) {
        n++;
        P = P->next;
    }
    return n;
}
