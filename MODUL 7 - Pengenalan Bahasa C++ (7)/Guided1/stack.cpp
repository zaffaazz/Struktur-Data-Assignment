#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(stackBuah s){
    return s.top == -1;
}

bool isFull(stackBuah s){
    return s.top == 9;   // karena Buah[10]
}

void createStack(stackBuah &s){
    s.top = -1;
}

void push(stackBuah &s, string buah){
    if(isFull(s)){
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.Buah[s.top] = buah;
        cout << "Buah \"" << buah << "\" berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackBuah &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        string val = s.Buah[s.top];
        s.top--;
        cout << "Buah \"" << val << "\" berhasil dihapus dari stack!" << endl;
    }
}

void update(stackBuah &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    if(posisi <= 0){
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    // Hitung index array sebenarnya
    int idx = s.top - (posisi - 1);

    if(idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }

    cout << "Update data pada posisi ke-" << posisi << endl;
    cout << "Masukkan nama buah baru: ";
    cin >> s.Buah[idx];
    cout << "Data berhasil diupdate!" << endl << endl;
}

void view(stackBuah s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; --i){
            cout << s.Buah[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackBuah s, string buah){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << "Mencari buah \"" << buah << "\"..." << endl;

    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; --i){
        if(s.Buah[i] == buah){
            cout << "Buah \"" << buah << "\" ditemukan pada posisi ke-" << posisi << endl << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Buah \"" << buah << "\" tidak ditemukan didalam stack!" << endl << endl;
    }
}
