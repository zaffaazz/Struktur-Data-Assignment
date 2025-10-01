# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Zaffa Azzahra </p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

## Guided 

### 1. [Nama Topik]

```C++
#include <iostream>
using namespace std;

int main(){
    float a;
    float b;

    cout << "masukan angka: ";
    cin >> a;
    cout << "masukan angka: ";
    cin >> b;

    
    cout << "a+b = " << (a+b) <<endl;
    cout << "a-b = " << (a-b) <<endl;
    cout << "a*b = " << (a*b) <<endl;
    cout << "a/b = " << (a/b) <<endl;

    return 0;
}

```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Unguided 

### 1. [Soal]

```C++
#include <iostream>
using namespace std;

int main(){
    float a;
    float b;

    cout << "masukan angka: ";
    cin >> a;
    cout << "masukan angka: ";
    cin >> b;

    cout << "a+b = " << (a+b) <<endl;
    cout << "a-b = " << (a-b) <<endl;
    cout << "a*b = " << (a*b) <<endl;
    cout << "a/b = " << (a/b) <<endl;

    return 0;
}
```
#### Output:
<img width="961" height="390" alt="Image" src="https://github.com/user-attachments/assets/2fe09fe9-f80d-4995-89db-69df6039e8a2" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/d74eca32-2d6b-483c-8c90-a648936c4d31" />

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

### 1. [Soal]

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

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
