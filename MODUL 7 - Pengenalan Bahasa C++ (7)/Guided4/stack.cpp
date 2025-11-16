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
        s.top++;
        s.data[s.top] = angka;
    }
}

void pop(stackTable &s) {
    if (!isEmpty(s)) {
        s.top--;
    }
}

void printInfo(stackTable s) {
    cout << "[TOP] ";
    for (int i = s.top; i >= 0; i--) {
        cout << s.data[i] << " ";
    }
    cout << endl;
}

void balikStack(stackTable &s) {
    stackTable temp;
    createStack(temp);

    while (!isEmpty(s)) {
        push(temp, s.data[s.top]);
        pop(s);
    }

    s = temp;
}

void getInputStream(stackTable &s) {
    cout << "Masukkan angka : ";
    char c = cin.get(); 

    while (c != '\n') {
        if (isdigit(c)) {
            int val = c - '0';
            push(s, val);
        }
        c = cin.get();   
    }
}
