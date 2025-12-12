#include "mll.h"
#include <iostream>
using namespace std;

int main() {

    // 1. Inisialisasi List
    listInduk L;
    createListInduk(L);
    cout << "=== MENU RESTORAN DIBUAT ===\n\n";

    // 2. Membuat Data Parent (Kategori Makanan)
    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);

    cout << endl;

    // 3. Memasukkan Data Child ke Kategori Tertentu

    // Kategori Makanan Berat
    insertFirstChild(Kat1->L_Anak, alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000));
    insertLastChild(Kat1->L_Anak, alokasiNodeChild("M02", "Ayam Bakar Madu", 30000));

    // Kategori Minuman
    insertLastChild(Kat2->L_Anak, alokasiNodeChild("D01", "Es Teh Manis", 5000));
    insertFirstChild(Kat2->L_Anak, alokasiNodeChild("D02", "Jus Alpukat", 15000));

    // Kategori Dessert
    insertLastChild(Kat3->L_Anak, alokasiNodeChild("S01", "Puding Coklat", 10000));

    cout << "\n=== TAMPILAN AWAL MENU ===\n";
    printStrukturMLL(L);
    cout << endl;

    // 4. Test Pencarian
    cout << "=== TEST PENCARIAN ===\n";
    findParentByID(L, "K02");
    cout << "---------------------------\n";
    findChildByID(L, "M01");
    cout << "---------------------------\n";
    findChildByID(L, "X99"); // Tidak ada
    cout << "---------------------------\n\n";

    // 5. Test Update Data
    cout << "=== TEST UPDATE ===\n";

    // Update Parent
    updateDataParentByID(L, "K03", "Makanan Penutup");

    // Update Child
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);

    cout << "\n=== SETELAH UPDATE ===\n";
    printListInduk(L);
    cout << endl;
    printListAnak(L, Kat1);
    cout << endl;

    // 6. Test Hapus
    cout << "=== TEST DELETE ===\n";

    cout << "> Menghapus Child D02 pada kategori Minuman...\n";
    deleteFirstChild(Kat2->L_Anak);

    cout << "> Menghapus Parent Terakhir (K03)...\n";
    deleteLastParent(L);

    cout << "\n=== TAMPILAN AKHIR MENU ===\n";
    printStrukturMLL(L);

    return 0;
}
