#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(stackTable s) {
    return s.top == -1;
}

bool isFull(stackTable s) {
    return s.top == MAX - 1;
}

void createStack(stackTable &s) {
    s.top = -1;
}

void push(stackTable &s, int angka) {
    if (!isFull(s)) {
        s.data[++s.top] = angka;
    }
}

void pop(stackTable &s) {
    if (!isEmpty(s)) {
        s.top--;
    }
}

void update(stackTable &s, int posisi) {
    if (posisi < 1 || posisi > s.top + 1) {
        cout << "Posisi tidak valid!\n";
        return;
    }
    cout << "Update nilai posisi ke-" << posisi << ": ";
    cin >> s.data[s.top - (posisi - 1)];
}

void view(stackTable s) {
    if (isEmpty(s)) {
        cout << "[TOP] (kosong)" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = 0; i <= s.top; i++) {
            cout << s.data[i] << " ";
        }
        cout << endl;
    }
}


void searchData(stackTable s, int data) {
    int posisi = 1;
    for (int i = s.top; i >= 0; i--) {
        if (s.data[i] == data) {
            cout << "Data ditemukan di posisi ke-" << posisi << endl;
            return;
        }
        posisi++;
    }
    cout << "Data tidak ditemukan!" << endl;
}

void balikStack(stackTable &s) {
    if (isEmpty(s)) return;
    int i = 0;
    int j = s.top;
    while (i < j) {
        int tmp = s.data[i];
        s.data[i] = s.data[j];
        s.data[j] = tmp;
        i++;
        j--;
    }
}

void pushAscending(stackTable &s, int angka) {
    if (isFull(s)) return;

    stackTable temp;
    createStack(temp);

    while (!isEmpty(s) && s.data[s.top] < angka) {
        temp.data[++temp.top] = s.data[s.top];
        s.top--;
    }

    s.data[++s.top] = angka;

    while (!isEmpty(temp)) {
        s.data[++s.top] = temp.data[temp.top];
        temp.top--;
    }
}
