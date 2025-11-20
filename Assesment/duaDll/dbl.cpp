#include "dbl.h"
#include <iostream>
using namespace std;

bool isEmpty(List L) {
    return (L.head == Nil && L.tail == Nil);
}

void createList(List &L) {
    L.head = Nil;
    L.tail = Nil;
}

address allocate(Song S) {
    address P = new Node;
    P->info = S;
    P->prev = Nil;
    P->next = Nil;
    return P;
}

void deallocate(address P) {
    delete P;
}


void insertFirst(List &L, Song S) {
    address P = allocate(S);

    if (isEmpty(L)) {
        L.head = P;
        L.tail = P;
    } else {
        P->next = L.head;
        L.head->prev = P;
        L.head = P;
    }
}

void insertLast(List &L, Song S) {
    address P = allocate(S);

    if (isEmpty(L)) {
        L.head = P;
        L.tail = P;
    } else {
        L.tail->next = P;
        P->prev = L.tail;
        L.tail = P;
    }
}

void insertAfter(List &L, address Q, Song S) {
    if (Q == Nil) return;

    address P = allocate(S);

    P->next = Q->next;
    P->prev = Q;

    if (Q->next != Nil) {
        Q->next->prev = P;
    } else {
        L.tail = P;
    }

    Q->next = P;
}

void insertBefore(List &L, address Q, Song S) {
    if (Q == Nil) return;

    address P = allocate(S);

    P->prev = Q->prev;
    P->next = Q;

    if (Q->prev != Nil) {
        Q->prev->next = P;
    } else {
        L.head = P;
    }

    Q->prev = P;
}

void deleteFirst(List &L, Song &S) {
    if (isEmpty(L)) return;

    address P = L.head;
    S = P->info;

    if (L.head == L.tail) {
        L.head = Nil;
        L.tail = Nil;
    } else {
        L.head = L.head->next;
        L.head->prev = Nil;
    }
    deallocate(P);
}

void deleteLast(List &L, Song &S) {
    if (isEmpty(L)) return;

    address P = L.tail;
    S = P->info;

    if (L.head == L.tail) {
        L.head = Nil;
        L.tail = Nil;
    } else {
        L.tail = L.tail->prev;
        L.tail->next = Nil;
    }
    deallocate(P);
}

void deleteAfter(List &L, address Q, Song &S) {
    if (Q == Nil || Q->next == Nil) return;

    address P = Q->next;
    S = P->info;

    Q->next = P->next;

    if (P->next != Nil) {
        P->next->prev = Q;
    } else {
        L.tail = Q;
    }

    deallocate(P);
}

void deleteBefore(List &L, address Q, Song &S) {
    if (Q == Nil || Q->prev == Nil) return;

    address P = Q->prev;
    S = P->info;

    Q->prev = P->prev;

    if (P->prev != Nil) {
        P->prev->next = Q;
    } else {
        L.head = Q;
    }

    deallocate(P);
}

void updateAtPosition(List &L, int posisi) {
    if (isEmpty(L)) return;

    address P = L.head;
    int i = 1;

    while (P != Nil && i < posisi) {
        P = P->next;
        i++;
    }

    if (P == Nil) return;

    cout << "Masukkan judul baru: ";
    cin >> P->info.Title;
    cout << "Masukkan artist baru: ";
    cin >> P->info.Artist;
    cout << "Masukkan durasi baru: ";
    cin >> P->info.DurationSec;
    cout << "Masukkan play count baru: ";
    cin >> P->info.PlayCount;
    cout << "Masukkan rating baru: ";
    cin >> P->info.Rating;

    cout << "Data berhasil diupdate!" << endl;
}

void updateBefore(List &L, address Q) {
    if (Q == Nil || Q->prev == Nil) return;

    address P = Q->prev;

    cout << "Update data node sebelum Q" << endl;

    cout << "Judul baru: ";
    cin >> P->info.Title;
    cout << "Artist baru: ";
    cin >> P->info.Artist;
    cout << "Durasi baru: ";
    cin >> P->info.DurationSec;
    cout << "Play count baru: ";
    cin >> P->info.PlayCount;
    cout << "Rating baru: ";
    cin >> P->info.Rating;

    cout << "Node sebelum Q berhasil diupdate!" << endl;
}

void viewList(List L) {
    if (isEmpty(L)) {
        cout << "Playlist kosong." << endl;
        return;
    }

    address P = L.head;
    int i = 1;

    while (P != Nil) {
        cout << i << ". ";
        cout << P->info.Title << " - " << P->info.Artist
             << " (" << P->info.DurationSec << " sec, play "
             << P->info.PlayCount << ", rating " << P->info.Rating << ")" << endl;

        P = P->next;
        i++;
    }
}


float getPopularityScore(Song S) {
    return 0.8 * S.PlayCount + 20.0 * S.Rating;
}

void searchByPopularityRange(List L, float minScore, float maxScore) {
    if (isEmpty(L)) {
        cout << "Playlist kosong." << endl;
        return;
    }

    address P = L.head;
    bool found = false;

    while (P != Nil) {
        float score = getPopularityScore(P->info);
        if (score >= minScore && score <= maxScore) {
            cout << P->info.Title << " - " << P->info.Artist
                 << " | Score: " << score << endl;
            found = true;
        }
        P = P->next;
    }

    if (!found) {
        cout << "Tidak ada lagu dengan Popularity Score dalam range tersebut." << endl;
    }
}