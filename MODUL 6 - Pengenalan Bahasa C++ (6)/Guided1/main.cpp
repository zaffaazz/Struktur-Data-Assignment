#include "doublylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    createList(L);

    address P;
    string nopol, warna;
    int thnBuat;

    for(int i = 0; i < 4; i++) {
        cout << "Masukkan nomor polisi: ";
        cin >> nopol;
        
        bool found = false;
        address C = L.first;
        while(C != Nil){
            if(C->info.nopol == nopol){
                found = true;
                break;
            }
            C = C->next;
        }

        if(found){
            cout << "Nomor polisi sudah terdaftar" << endl;
            continue;
        }

        cout << "Masukkan warna kendaraan: ";
        cin >> warna;
        cout << "Masukkan tahun kendaraan: ";
        cin >> thnBuat;

        P = alokasi(nopol, warna, thnBuat);
        insertFirst(L, P);  
    }

    
    cout << "\nDATA LIST AWAL" << endl;
    printInfo(L);

    cout << "Masukkan Nomor Polisi yang dicari: ";
    string cari;
    cin >> cari;
    address F = findElm(L, cari);
    if(F != Nil){
        cout << "\nData ditemukan:" << endl;
        cout << "Nomor Polisi: " << F->info.nopol << endl;
        cout << "Warna       : " << F->info.warna << endl;
        cout << "Tahun       : " << F->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    cout << "\nMasukkan Nomor Polisi yang akan dihapus: ";
    string hapus;
    cin >> hapus;
    address H = findElm(L, hapus);

    if(H != Nil){
        if(H == L.first){
            deleteFirst(L, H);
        } else if(H == L.last){
            deleteLast(L, H);
        } else {
            deleteAfter(L, H->prev, H);
        }
        cout << "Data dengan nomor polisi " << hapus << " berhasil dihapus." << endl;
    } else {
        cout << "Data dengan nomor polisi " << hapus << " tidak ditemukan." << endl;
    }

    cout << "\nDATA LIST TERBARU" << endl;
    printInfo(L);

    return 0;
}
