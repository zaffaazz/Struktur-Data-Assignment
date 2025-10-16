#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Masukkan NIM: ";
    cin >> m.nim;
    cout << "Masukkan nilai1: ";
    cin >> m.nilai1;
    cout << "Masukkan nilai2: ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return (m.nilai1 + m.nilai2) / 2.0;
}
