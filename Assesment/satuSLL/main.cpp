#include "list.h"
#include <iostream>
using namespace std;

int main(){
    linkedlist List;
    createList(List);

    address nodeA, nodeB, nodeC;

    nodeA = alokasi("Pulpen", "A001", 20, 2500, 0);
    nodeB = alokasi("Buku Tulis", "A002", 15, 5000, 10);
    nodeC = alokasi("Penghapus", "A003", 30, 1500, 0);

    insertLast(List, nodeA);
    insertLast(List, nodeB);
    insertLast(List, nodeC);

    cout << "--- ISI LIST SETELAH INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node: " << viewList(List) << endl << endl;

    updateAfter(List, nodeA);

    cout << "--- SETELAH UPDATE ---" << endl;
    printList(List);
    cout << endl;

    FindNodeByFinalPriceRange(List, 2000, 7000);
    FindMaxHargaAkhir(List);

    delLast(List);

    cout << "--- SETELAH DELETE ---" << endl;
    printList(List);
    
    
    
    return 0;
}