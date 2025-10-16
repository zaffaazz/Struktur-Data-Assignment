# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Zaffa Azzahra </p>

## Dasar Teori
 ADT adalah 
## Guided 

### 1. [ADT]

```C++
#include <iostream>
using namespace std;

int main(){
int angka1 = 10;
int angka2 = 20;

if (angka1 > angka2) {
    cout << "angka1 lebih besar dari angka2" << endl;
}else if (angka1 < angka2 ) {
    cout << "angka1 lebih kecil dari angka2" << endl;
}else {
     cout << "angka1 samadengan angka2" << endl; 
}

return 0;
}

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Unguided 

### 1. [Soal]

```C++
#include <iostream>
#include <string>
using namespace std;

struct dataMahasiswa {
    string nama;
    char nim[10];
    float uts, uas, tugas, nilaiakhir;
};

void mahasiswa(dataMahasiswa &m) {
    cout << "Masukkan nama: ";
    cin >> m.nama;
    cout << "Masukkan NIM: ";
    cin >> m.nim;
    cout << "Masukkan nilai UTS: ";
    cin >> m.uts;
    cout << "Masukkan nilai UAS: ";
    cin >> m.uas;
    cout << "Masukkan nilai Tugas: ";
    cin >> m.tugas;
}

float nilai_akhir(dataMahasiswa m) {
    return (0.3 * m.uts) + (0.4 * m.uas) + (0.3 * m.tugas);
}

int main() {
    dataMahasiswa mhs[10];
    int jum;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jum;

    if (jum > 10) jum = 10;

    for (int i = 0; i < jum; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        mahasiswa(mhs[i]);
        mhs[i].nilaiakhir = nilai_akhir(mhs[i]);
    }

    cout << "\n== Daftar Nilai ==" << endl;
    for (int i = 0; i < jum; i++) {
        cout << i + 1 << ". " << mhs[i].nama
             << " (" << mhs[i].nim << ") "
             << "Nilai Akhir: " << mhs[i].nilaiakhir << endl;
    }

    return 0;
}
```
#### Output:
<img width="961" height="390" alt="Image" src="https://github.com/user-attachments/assets/89098826-0423-488b-bdd4-120f50b5211c" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/e653bf9c-c74a-4a44-8fca-cfe02818258a" />

## Kesimpulan
Penjelasan diatas tentang sebuah program untuk menghitung nilai akhir ari data mahasiwa dengan array dan procedure. Arraynya sendiri hanya sampai 10 anak jadi apabila menginputkan lebih dari 10 maka program akan secara otomatis akan mengoutputkan 10 data saja, dengan menggunakan fungsi untuk mneghitung nlai akhir mahasiswa, lalu procedure untuk menginputkan data mahasiswa dari mulai nim, nama, nilai uts, uas, tugas.
### 2. [Soal]

```C++
#include <iostream>
using namespace std;

string angka(int n) {
    string satuan[] = {"nol", "satu", "dua", "tiga", "empat",
                       "lima", "enam", "tujuh", "delapan", "sembilan",
                       "sepuluh", "sebelas", "dua belas", "tiga belas",
                       "empat belas", "lima belas", "enam belas",
                       "tujuh belas", "delapan belas", "sembilan belas"};

    string puluhan[] = {"dua puluh", "tiga puluh", "empat puluh",
                        "lima puluh", "enam puluh", "tujuh puluh",
                        "delapan puluh", "sembilan puluh"};

    if (n < 20) {
        return satuan[n];
    } else if (n < 100) {
        int p = n / 10; // untuk mencari puluhan
        int s = n % 10; // untuk mencari satuan
        if (s == 0)
            return puluhan[p - 2]; // agar sesuai dengan index dari sting puluhan
        else 
            return puluhan[p - 2] +  " " + satuan[s]; 
    } else if (n == 100) {
        return "seratus";
    } else {
        return "Error";
    }
}

int main() {
    int a;
    cout << "Masukkan angka : ";
    cin >> a;

    if (a >= 0 && a <= 100) {
        cout << "= " << angka(a) << endl;
    } else {
        cout << "Error" << endl;
    }

    return 0;
}

```
#### Output:
<img width="954" height="259" alt="Image" src="https://github.com/user-attachments/assets/9eb428ae-c784-48de-b1b6-e1bcbc0314a8" />
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/b0a4bd78-aa98-4ece-a9a1-01507b3a7087" />

## Kesimpulan
Dari program diatas merupakan program dengan type data string dimana kita akan mengubah angka menejadi bilangan string dengan menggunakan bantuan array kita isi dengan huruf angka dari mulai satuan dan puluhan karena kita hanya mengubah angka dari 0-100 dan dengan bantuan operasi aritmatika yaitu pembagian untuk menggetahui puluhan atau angka awal bilangan tersebut dengan membagiya dengan angka 10 dan untuk mencari angka satuan dengan menggunakan modulus yaitu sisa pembagi dari bilangan n tapi ini jika bilangan n > 20 sampai n < 100 dan untuk f (s == 0) return puluhan[p - 2] ini jika yang dicari bilangan yang dibelakangnya nol jadi saya tulis p-2 karena agar sesuai dengan index yang sudah dibuat pada array itu index dari 0-9 jika saya tidak menuliskan dengan -2 maka program akan menghasilkan output berupa index 2 dibawahnya semisal kalo saya inputkan 20 maka outputnya 40, jadi saya -2 karena sesuai dengan index 20 yaitu index ke 0.

### 3. [Soal]

```C++
#include <iostream>
using namespace std;

void tampilArray(int A[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarPosisi(int A[3][3], int B[3][3], int baris, int kolom) {
    int temp = A[baris][kolom];
    A[baris][kolom] = B[baris][kolom];
    B[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int *ptr1, *ptr2;
    int x = 10, y = 20;

    ptr1 = &x;
    ptr2 = &y;

    cout << "Array A:\n";
    tampilArray(A);
    cout << "\nArray B:\n";
    tampilArray(B);

    cout << "\nMenukar elemen\n";
    tukarPosisi(A, B, 1, 2);

    cout << "\nArray A setelah ditukar:\n";
    tampilArray(A);
    cout << "\nArray B setelah ditukar:\n";
    tampilArray(B);

    cout << "\nNilai sebelum tukar pointer:\n";
    cout << "x = " << x << ", y = " << y << endl;

    tukarPointer(ptr1, ptr2);

    cout << "\nNilai setelah tukar pointer:\n";
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}

```
#### Output:
<img width="895" height="168" alt="Image" src="https://github.com/user-attachments/assets/14bac072-b604-49f1-a3f5-9a8400aaff76" />
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/c6a168e6-e9f9-497a-8e08-cbcaaaefdb4e" />

## Kesimpulan
Program diatas menjelaskan tentang sebuah program untuk mencetak sebuah segitiga terbalik dengan mengggunakan lopp pada lopp yang pertama akan mencetak baris sesuai dengan inputanya, Loop yang kedua untuk mencetak spasi di awal baris agar pola segitiga yang dihasilkan menjadi rata ke kanan, 
Loop yang ketiga digunakan untuk mencetak angka secara menurun dari nilai i sampai 1, lalu meninputkan bintang dibagian tengah, lalau Loop yang keempat digunakan untuk mencetak angka secara naik dari 1 sampai i. Jadi pada program diatas menjelsakan bagaimana cara looping atau perulangan terjadi sampai terbentuk sebuah segitiga

## Referensi
[1] A. Ma’arif, Dasar Pemrograman Bahasa C++. Yogyakarta: Universitas Ahmad Dahlan, 2022. [Online]. Available: https://eprints.uad.ac.id/32726/
[2] Petani Kode, “Tutorial Pemrograman C++ untuk Pemula”. [Online]. Available: https://www.petanikode.com/tutorial/c++/
