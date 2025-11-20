#ifndef DBL_H
#define DBL_H
#define Nil NULL
#include <iostream>
using namespace std;

struct Song {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating; 
};

typedef struct Node *address;

struct Node {
    Song info;
    address prev;
    address next;
};

struct List {
    address head;
    address tail;
};
bool isEmpty(List L);
void createList(List &L);
address allocate(Song S);
void deallocate(address P);

void insertFirst(List &L, Song S);
void insertLast(List &L, Song S);
void insertAfter(List &L, address Q, Song S);
void insertBefore(List &L, address Q, Song S);

void deleteFirst(List &L, Song &S);
void deleteLast(List &L, Song &S);
void deleteAfter(List &L, address Q, Song &S);
void deleteBefore(List &L, address Q, Song &S);

void updateAtPosition(List &L, int posisi);
void updateBefore(List &L, address Q);

void viewList(List L);

float getPopularityScore(Song S);

void searchByPopularityRange(List L, float minScore, float maxScore);

#endif