#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    return (List.head == Nil);
}

void createList(linkedlist &List) {
    List.head = Nil;
}

address alokasi(string Nama, string SKU, int Jumlah, float HargaSatuan, float DiskonPersen) {
    address nodeBaru = new node;
    nodeBaru->isidata.Nama = Nama;
    nodeBaru->isidata.SKU = SKU;
    nodeBaru->isidata.Jumlah = Jumlah;
    nodeBaru->isidata.HargaSatuan = HargaSatuan;
    nodeBaru->isidata.DiskonPersen = DiskonPersen;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.head;
    List.head = nodeBaru;
}

void insertAfter(address prev, address nodeBaru) {
    if (prev != Nil) {
        nodeBaru->next = prev->next;
        prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.head = nodeBaru;
    } else {
        address p = List.head;
        while (p->next != Nil) {
            p = p->next;
        }
        p->next = nodeBaru;
    }
}


void delFirst(linkedlist &List) {
    if (!isEmpty(List)) {
        address p = List.head;
        List.head = p->next;
        dealokasi(p);
        cout << "Node pertama berhasil dihapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List) {
    if (!isEmpty(List)) {
        address p = List.head;
        address prev = Nil;

        if (p->next == Nil) {
            List.head = Nil;
            dealokasi(p);
        } else {
            while (p->next != Nil) {
                prev = p;
                p = p->next;
            }
            prev->next = Nil;
            dealokasi(p);
        }
        cout << "Node terakhir berhasil dihapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delAfter(address prev) {
    if (prev != Nil && prev->next != Nil) {
        address p = prev->next;
        prev->next = p->next;
        dealokasi(p);
        cout << "Node setelah berhasil dihapus!" << endl;
    } else {
        cout << "Node prev tidak valid!" << endl;
    }
}


void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address p = List.head;
        while (p != Nil) {
            cout << "Nama : " << p->isidata.Nama
                 << ", SKU : " << p->isidata.SKU
                 << ", Jumlah : " << p->isidata.Jumlah
                 << ", HargaSatuan : " << p->isidata.HargaSatuan
                 << ", DiskonPersen : " << p->isidata.DiskonPersen
                 << endl;
            p = p->next;
        }
    }
}

int viewList(linkedlist List) {
    int count = 0;
    address p = List.head;
    while (p != Nil) {
        count++;
        p = p->next;
    }
    return count;
}


void updateAfter(linkedlist, address prev) {
    if (prev != Nil && prev->next != Nil) {
        address p = prev->next;

        cout << "Nama : ";
        cin >> p->isidata.Nama;
        cout << "SKU : ";
        cin >> p->isidata.SKU;
        cout << "Jumlah : ";
        cin >> p->isidata.Jumlah;
        cout << "HargaSatuan : ";
        cin >> p->isidata.HargaSatuan;
        cout << "DiskonPersen : ";
        cin >> p->isidata.DiskonPersen;

        cout << "Data berhasil diperbarui!" << endl;

    } else {
        cout << "Node prev tidak valid!" << endl;
    }
}


void FindNodeByFinalPriceRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
        return;
    }

    address p = list.head;
    int posisi = 0;
    bool found = false;

    cout << "--- Produk dalam range harga akhir "
         << hargaAwal << " - " << hargaAkhir << " ---" << endl;

    while (p != Nil) {
        posisi++;

        float hs = p->isidata.HargaSatuan;
        float d = p->isidata.DiskonPersen;
        float finalPrice = hs * (1 - d / 100);

        if (finalPrice >= hargaAwal && finalPrice <= hargaAkhir) {
            cout << "Posisi : " << posisi << endl;
            cout << "Nama : " << p->isidata.Nama << endl;
            cout << "SKU : " << p->isidata.SKU << endl;
            cout << "Jumlah : " << p->isidata.Jumlah << endl;
            cout << "Harga Satuan : " << hs << endl;
            cout << "Diskon : " << d << "%" << endl;
            cout << "Harga Akhir : " << finalPrice << endl;
            cout << "-----------------------------------" << endl;

            found = true;
        }

        p = p->next;
    }

    if (!found) {
        cout << "Tidak ada produk dalam range tersebut." << endl;
    }
}
void FindMaxHargaAkhir(linkedlist list) {
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
        return;
    }

    address nodeBantu = list.head;
    address maxNode = list.head;

    float maxHargaAkhir =
        list.head->isidata.HargaSatuan *
        (1 - (list.head->isidata.DiskonPersen / 100));

    while (nodeBantu != Nil) {
        float hargaAkhir =
            nodeBantu->isidata.HargaSatuan *
            (1 - (nodeBantu->isidata.DiskonPersen / 100));

        if (hargaAkhir > maxHargaAkhir) {
            maxHargaAkhir = hargaAkhir;
            maxNode = nodeBantu;
        }

        nodeBantu = nodeBantu->next;
    }

    cout << "--- Produk Dengan Harga Akhir Tertinggi ---" << endl;
    cout << "Nama : " << maxNode->isidata.Nama << endl;
    cout << "SKU : " << maxNode->isidata.SKU << endl;
    cout << "Jumlah : " << maxNode->isidata.Jumlah << endl;
    cout << "Harga Satuan : " << maxNode->isidata.HargaSatuan << endl;
    cout << "Diskon : " << maxNode->isidata.DiskonPersen << endl;
    cout << "Harga Akhir : " << maxHargaAkhir << endl;
    cout << "-------------------------------------------" << endl;
}