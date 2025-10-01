# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Zaffa Azzahra </p>

## Dasar Teori
 
bebufo

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
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/db7c4c01-a601-4a62-b795-ed2462f2ec3c" />

## Kesimpulan
Penjelasan diatas tentang bagaimana bilangan float (koma) bisa dihitung dalam operasi aritmatika dengan format type data float dan sesuai dengan program yang sudah dibuat akan diproses dengan menggunakan kode yang tersedia yaitu ada pembagian, pengurangan, pembagian, perkalian, tapi dalam kode diatas apabila bilangan dibagi 0 maka outputnya adalah "inf" karena bilangan apapun yang dibagi 0 = infinity.

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

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    for (int i = n; i >= 0; i--) {
        for (int s = 0; s < (n - i); s++) {
            cout << "  ";
        }
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << "* ";
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl; 
    }

    return 0;
}

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
