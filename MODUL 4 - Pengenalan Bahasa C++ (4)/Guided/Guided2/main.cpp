#include "singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    address P1 = Nil, P2 = Nil, P3 = Nil, P4 = Nil, P5 = Nil;

    createList(L);

    P1 = alokasi(2);
    P2 = alokasi(0);
    P3 = alokasi(8);
    P4 = alokasi(12);
    P5 = alokasi(9);

    insertFirst(L, P1);
    insertFirst(L, P2);
    insertFirst(L, P3);
    insertFirst(L, P4);
    insertFirst(L, P5);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    delFirst(L);
    delLast(L);
    delAfter(L, P3, P4);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    deletList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;


    return 0;
}

