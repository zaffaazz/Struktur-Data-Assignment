#include "multilist.h"
#include <stdio.h>

bool ListEmpty(listinduk L) {
    return (L.first == NULL);
}

bool ListEmptyAnak(listanak L) {
    return (L.first == NULL);
}

void CreateList(listinduk *L) {
    L->first = NULL;
    L->last = NULL;
}

void CreateListAnak(listanak *L) {
    L->first = NULL;
    L->last = NULL;
}

address alokasi(infotypeinduk X) {
    address P = (address) malloc(sizeof(struct elemen_list_induk));
    if (P != NULL) {
        P->info  = X;
        P->lanak.first = NULL;
        P->lanak.last  = NULL;
        P->next  = NULL;
        P->prev  = NULL;
    }
    return P;
}

address_anak alokasiAnak(infotypeanak X) {
    address_anak P = (address_anak) malloc(sizeof(struct elemen_list_anak));
    if (P != NULL) {
        P->info = X;
        P->next = NULL;
        P->prev = NULL;
    }
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
    while (P != NULL && P->info != X) {
        P = P->next;
    }
    return P;
}

address_anak findElmAnak(listanak L, infotypeanak X) {
    address_anak P = L.first;
    while (P != NULL && P->info != X) {
        P = P->next;
    }
    return P;
}

bool fFindElm(listinduk L, address P) {
    address Q = L.first;
    while (Q != NULL) {
        if (Q == P) return true;
        Q = Q->next;
    }
    return false;
}

bool fFindElmAnak(listanak L, address_anak P) {
    address_anak Q = L.first;
    while (Q != NULL) {
        if (Q == P) return true;
        Q = Q->next;
    }
    return false;
}

address findBefore(listinduk L, address P) {
    if (P == L.first) return NULL;
    return P->prev;
}

address_anak findBeforeAnak(listanak L, infotypeanak X, address_anak P) {
    if (P == L.first) return NULL;
    return P->prev;
}

void insertFirst(listinduk *L, address P) {
    if (ListEmpty(*L)) {
        L->first = P;
        L->last  = P;
    } else {
        P->next = L->first;
        L->first->prev = P;
        L->first = P;
    }
}

void insertAfter(listinduk *L, address P, address Prec) {
    if (Prec != NULL) {
        P->next = Prec->next;
        P->prev = Prec;

        if (Prec->next != NULL)
            Prec->next->prev = P;
        else
            L->last = P;

        Prec->next = P;
    }
}

void insertLast(listinduk *L, address P) {
    if (ListEmpty(*L)) {
        insertFirst(L, P);
    } else {
        L->last->next = P;
        P->prev = L->last;
        L->last = P;
    }
}

void insertFirstAnak(listanak *L, address_anak P) {
    if (ListEmptyAnak(*L)) {
        L->first = P;
        L->last  = P;
    } else {
        P->next = L->first;
        L->first->prev = P;
        L->first = P;
    }
}

void insertAfterAnak(listanak *L, address_anak P, address_anak Prec) {
    if (Prec != NULL) {
        P->next = Prec->next;
        P->prev = Prec;

        if (Prec->next != NULL)
            Prec->next->prev = P;
        else
            L->last = P;

        Prec->next = P;
    }
}

void insertLastAnak(listanak *L, address_anak P) {
    if (ListEmptyAnak(*L)) {
        insertFirstAnak(L, P);
    } else {
        L->last->next = P;
        P->prev = L->last;
        L->last = P;
    }
}

void delFirst(listinduk *L, address *P) {
    *P = L->first;

    if (L->first == L->last) {
        L->first = NULL;
        L->last  = NULL;
    } else {
        L->first = (*P)->next;
        L->first->prev = NULL;
    }
    (*P)->next = NULL;
}

void delLast(listinduk *L, address *P) {
    *P = L->last;

    if (L->first == L->last) {
        L->first = NULL;
        L->last  = NULL;
    } else {
        L->last = (*P)->prev;
        L->last->next = NULL;
    }
    (*P)->prev = NULL;
}

void delAfter(listinduk *L, address *P, address Prec) {
    *P = Prec->next;
    if (*P != NULL) {
        Prec->next = (*P)->next;
        if ((*P)->next != NULL)
            (*P)->next->prev = Prec;
        else
            L->last = Prec;

        (*P)->next = NULL;
        (*P)->prev = NULL;
    }
}

void delP(listinduk *L, infotypeinduk X) {
    address P = findElm(*L, X);
    if (P == NULL) return;

    address Q;

    if (P == L->first) {
        delFirst(L, &Q);
    } else if (P == L->last) {
        delLast(L, &Q);
    } else {
        delAfter(L, &Q, P->prev);
    }

    dealokasi(Q);
}

void delFirstAnak(listanak *L, address_anak *P) {
    *P = L->first;

    if (L->first == L->last) {
        L->first = NULL;
        L->last = NULL;
    } else {
        L->first = (*P)->next;
        L->first->prev = NULL;
    }
    (*P)->next = NULL;
}

void delLastAnak(listanak *L, address_anak *P) {
    *P = L->last;

    if (L->first == L->last) {
        L->first = NULL;
        L->last = NULL;
    } else {
        L->last = (*P)->prev;
        L->last->next = NULL;
    }
    (*P)->prev = NULL;
}

void delAfterAnak(listanak *L, address_anak *P, address_anak Prec) {
    *P = Prec->next;
    if (*P != NULL) {
        Prec->next = (*P)->next;
        if ((*P)->next != NULL)
            (*P)->next->prev = Prec;
        else
            L->last = Prec;

        (*P)->next = NULL;
        (*P)->prev = NULL;
    }
}

void delPAnak(listanak *L, infotypeanak X) {
    address_anak P = findElmAnak(*L, X);
    if (P == NULL) return;

    address_anak Q;

    if (P == L->first) {
        delFirstAnak(L, &Q);
    } else if (P == L->last) {
        delLastAnak(L, &Q);
    } else {
        delAfterAnak(L, &Q, P->prev);
    }

    dealokasiAnak(Q);
}

void printInfoAnak(listanak L) {
    address_anak P = L.first;
    while (P != NULL) {
        printf("%d ", P->info);
        P = P->next;
    }
}

void printInfo(listinduk L) {
    address P = L.first;
    while (P != NULL) {
        printf("Induk %d : ", P->info);
        printInfoAnak(P->lanak);
        printf("\n");
        P = P->next;
    }
}

int nbList(listinduk L) {
    int n = 0;
    address P = L.first;
    while (P != NULL) {
        n++;
        P = P->next;
    }
    return n;
}

int nbListAnak(listanak L) {
    int n = 0;
    address_anak P = L.first;
    while (P != NULL) {
        n++;
        P = P->next;
    }
    return n;
}

void delAll(listinduk *L) {
    address P = L->first;
    address Q;

    while (P != NULL) {

        // hapus semua anak memakai delPAnak
        while (P->lanak.first != NULL) {
            infotypeanak x = P->lanak.first->info;
            delPAnak(&P->lanak, x);
        }

        Q = P;
        P = P->next;

        dealokasi(Q);
    }

    L->first = NULL;
    L->last = NULL;
}
