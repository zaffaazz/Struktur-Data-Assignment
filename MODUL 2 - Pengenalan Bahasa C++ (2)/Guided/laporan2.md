# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (2)</h1>
<p align="center">Zaffa Azzahra </p>

## Dasar Teori
 C++ merupakan salah satu bahasa pemrograman yang dikembangkan oleh Bjarne Stroustrup pada tahun 1979. Awalnya C++ merupakan pengembangan dari bahasa C, kemudian ditambahkan fitur baru seperti pemrograman berorientasi objek \(OOP), sehingga lebih fleksibel dan banyak digunakan dalam pembutan sebuah aplikasi. Dalam mempelajari C++, ada beberapa struktur dasar yang harus diketahui:#include <iostream>  digunakan untuk mengakses input/output ,using namespace std digunakan agar kita tidak perlu menuliskan lagi awalan std:: setiap kali memanggil fungsi , int main() merupakan fungsi utama program, return 0 diakhir sebagai berentinya program, cout digunakan untuk menampilkan output ke layar, cin digunakan untuk menerima input dari pengguna. Selain itu, dasar lain yang penting dipahami dalam C++ adalah variabel dan tipe data seperti angka (int), pecahan (float), teks (string), karakter (char), dan logika (bool), Operator Aritmatika seperti +, -, *, /, % untuk melakukan operasi perhitungan, Percabangan ada  if, else, switch, Perulangan (Looping) seperti for, while. dan Array untuk menyimpan sekumpulan data dengan tipe yang sama.
## Guided 
### 1. [Procedur]

```C++
#include <iostream>
using namespace std;

void tulis (int x){
    for (int i =0; i < x; i++ ){
        cout << "Baris ke-: " << i+1 << endl;
    }
}
int main(){
    int jum;
    cout << "jumlah baris kata: ";
    cin >> jum;
    tulis(jum);
    return 0;
}
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Unguided 

### 1. [Soal]

```C++
#include <iostream>
using namespace std;

int main(){
int matriksA[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,9,8}
    };
int matriksB[3][3] = {
        {3,2,3},
        {4,9,6},
        {7,1,8}
    }; 
    cout <<  "Matriks 3x3:" << endl;
   for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        cout << matriksA[i][j] << "\t" ;
    }

    cout << "\t";
    for (int j = 0; j < 3; j++) {
        cout << matriksB[i][j] << "\t" ;
    }
    cout << endl;
   }
// penjumlahan
int C[3][3];
 for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = matriksA[i][j] + matriksB[i][j];
        }
    }
    cout << "\nHasil Penjumlahan Matriks (A + B):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    // pengurangan
 for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = matriksA[i][j] - matriksB[i][j];
        }
    }
    cout << "\nHasil Penjumlahan Matriks (A - B):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
    // perkalian 
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++)
                C[i][j] += matriksA[i][k] * matriksB[k][j];
        }
    cout << "\nHasil Perkalian Matriks (A x B):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << C[i][j] << "\t";
        cout << endl;
    }

    return 0;
}

```
#### Output:
<img width="961" height="390" alt="Image" src="https://github.com/user-attachments/assets/89098826-0423-488b-bdd4-120f50b5211c" />

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
