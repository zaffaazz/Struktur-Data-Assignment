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
