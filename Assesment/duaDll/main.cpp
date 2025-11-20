#include "dbl.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    createList(L);

    Song S;
    
    Song A = {"Senja di Kota", "Nona Band", 210, 150, 4.2};
    Song B = {"Langkahmu", "Delta", 185, 320, 4.8};
    Song C = {"Hujan Minggu", "Arka", 240, 90, 3.9};

    insertLast(L, A);
    insertLast(L, B);
    insertLast(L, C);

    cout << "\n--- LIST SETELAH INSERT ---\n";
    viewList(L);
    cout << endl;

    deleteLast(L, S);

    cout << "--- LIST SETELAH deleteLast ---\n";
    viewList(L);
    cout << endl;

  
    cout << "--- UPDATE POSISI KE-2 ---\n";
    updateAtPosition(L, 2);

    cout << "--- LIST SETELAH UPDATE ---\n";
    viewList(L);
    cout << endl;

    
    address P = L.head;
    int pos = 1;
    while (P != Nil && pos < 2) {
        P = P->next;
        pos++;
    }

    Song Sbefore = {"Senandung", "Mira", 175, 120, 4.0};
    insertBefore(L, P, Sbefore);

    cout << "--- LIST SETELAH insertBefore POS 2 ---\n";
    viewList(L);
    cout << endl;
    cout << "--- UPDATE BEFORE POSISI KE-2 ---\n";
    updateBefore(L, P);

    cout << "--- LIST SETELAH updateBefore ---\n";
    viewList(L);
    cout << endl;

    P = L.head;
    pos = 1;
    while (P != Nil && pos < 3) {
        P = P->next;
        pos++;
    }

    deleteBefore(L, P, S);

    cout << "--- LIST SETELAH deleteBefore POS 3 ---\n";
    viewList(L);
    cout << endl;

    cout << "--- SEARCHING POPULARITY SCORE (150 - 300) ---\n";
    searchByPopularityRange(L, 150.0, 300.0);
    cout << endl;

    return 0;
}