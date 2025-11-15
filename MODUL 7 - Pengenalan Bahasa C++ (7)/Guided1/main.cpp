#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    stackBuah s;
    createStack(s);

    // Push buah ke stack
    push(s, "Apel");
    push(s, "Jeruk");
    push(s, "Mangga");
    push(s, "Pisang");
    push(s, "Anggur");
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    // Pop dua kali
    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    // Posisi dihitung dari TOP (1 = elemen paling atas)
    update(s, 2);
    update(s, 1);
    update(s, 4); // contoh posisi tidak valid
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    // Pencarian data
    searchData(s, "Pear");
    searchData(s, "Nanas");

    return 0;
}
