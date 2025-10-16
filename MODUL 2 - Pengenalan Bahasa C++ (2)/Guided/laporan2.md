# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (2)</h1>
<p align="center">Zaffa Azzahra </p>

## Dasar Teori
 C++ merupakan salah satu bahasa pemrograman yang dikembangkan oleh Bjarne Stroustrup pada tahun 1979. Awalnya C++ merupakan pengembangan dari bahasa C, kemudian ditambahkan fitur baru seperti pemrograman berorientasi objek \(OOP), sehingga lebih fleksibel dan banyak digunakan dalam pembutan sebuah aplikasi.Dalam pemrograman C++ terdapat salah satu struktur data yaitu array dan procedur, array sendiri adalah struktur data yang digunakan untuk menyimpan sekumpulan nilai dengan tipe data yang sama di dalam satu variabel, Sedangkan procedur adalah bagian dari program (subprogram) yang berisi sekumpulan perintah untuk melakukan suatu tugas tertentu, tetapi tidak mengembalikan nilai, dalam C++, prosedur disebut dengan void yang artinya fungsi tersebut hanya menjalankan sebuah perintah.
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

    // hasil
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

    // hasil
    cout << "\nHasil Pengurangan Matriks (A - B):" << endl;
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
        // hasil
    cout << "\nHasil Perkalian Matriks (A x B):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << C[i][j] << "\t";
        cout << endl;
    }

    return 0;
}

```
#### Output:
<img width="1295" height="510" alt="Image" src="https://github.com/user-attachments/assets/9f722f95-6926-4ea5-9057-af70801704e3" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/10cec66c-d3ca-4cbc-82fd-c6362b1a8c22" />

## Kesimpulan
Program diatas menjelaskan tentang penjumlahan, pengurangan, perkalian dua buah matriks 3x3 dimana dalam porgram tersebut menggunakan array 2 dimensi untuk membuat sebuah matriks 3x3 dana menggunakan perulangan untuk meghitung operasi aritmatika tersebut. Pada program diatas terdapat dekralasi C[3][3] untuk menyimpan hasil dari operasi aritmatika dua matriks.Selanjutnya pada perulangan terapat dekralasi i disini untuk menghitung  baris dalam sebuah matriks dan j untuk menghitung kolom pada matriks, namum untuk menghitung perkalian antara dua matriks terdapat dekralasi k untuk menghitung hasil kali antara elemen baris ke-i dari matriks A dengan elemen kolom ke-j dari matriks B, kemudian dijumlahkan.
### 2. [Soal]

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int*y, int*z){
    int temp;
    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}
void tukarRef(int &x, int &y, int &z) {
    int temp;
    temp = x;
    x = y;
    y = z;
    z = temp;
}
int main(){
    int a = 20, b =30, c = 40;
    int *ptr;
    ptr = &a;

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in ptr (address of a): " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;

    tukar (&a,&b,&c);
    cout << "After swaping, value of a=" << a << " and b=" << b << " and c=" << c << endl;
   
   cout << "\n=== Bagian Reference ===" << endl;
    int& ref=a;
    cout << "Nilai a: " << a << endl;
    cout << "Alamat a(&a): " << &a << endl;
    cout << "Nilai ref (alias a): " << ref << endl;
    cout << "Alamat ref (&ref): " << &ref << endl;

    ref = 50;
    cout << "\nSetelah ref=50; " << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai ref: " << ref << endl;

    tukar (&a,&b,&c);
    cout << "Setelah tukar (reference): a=" << a << ", b=" << b << ", c=" << c << endl;

    return 0;
}

```
#### Output:
<img width="1303" height="502" alt="Image" src="https://github.com/user-attachments/assets/3bec4cc9-426b-48b8-993c-18d49231c221" />
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/3a1c9fdd-ca1c-4230-958d-078d2909354b" />

## Kesimpulan
Program diatas menjelaskan tentang sebuah subprogram yaitu procedur untuk mencari pointer dan refrence dan menukar nilai dalam tiga buah variabel, dimana pointer sendiri digunakan untuk mencari sebuah alamat memeory dalam sebuah program pada program diatas mencari alamat memrory program nilai a tersimpan dan menukar nilai a,, b, c, sedangkan refrence menukar value antara ketinganya dan pada program diatas nilai a diganti menjadi 50.

### 3. [Soal]

```C++
#include <iostream>
using namespace std;
 
int cariMaksimum(int arr[], int n){
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
int cariMinimum(int arr[], int n){
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}
void hitungRataRata(int arr[], int n){
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    float rata = total / n;
    cout << "Nilai rata-rata: " << rata << endl;
}
int main(){
    int n =10;
    int pilihan;
    int arrA[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    cout << "Array 1 Dimensi:"<< endl;
    for (int i = 0; i < 10; i++){
        cout << "arrA[" << i << "] = "<< arrA[i] << endl;
    }
do{
cout << "\n--- Menu Program Array ---\n";
cout << "1. Tampilkan isi array\n";
cout << "2. Cari nilai maksimum\n";
cout << "3. Cari nilai minimum\n";
cout << "4. Hitung nilai rata - rata\n";
cout << "5. Keluar\n";
cout << "Pilih menu (1-5): ";
cin >> pilihan;

    switch (pilihan) {
            case 1:
                cout << "Isi array: ";
                for (int i = 0; i < n; i++) {
                    cout << arrA[i] << " ";
                }
                cout << endl;
                break;

            case 2:
                cout << "Nilai maksimum: " << cariMaksimum(arrA, n) << endl;
                break;

            case 3:
                cout << "Nilai minimum: " << cariMinimum(arrA, n) << endl;
                break;

            case 4:
                hitungRataRata(arrA, n);
                break;

            case 5:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 5);

    return 0;
}


```
#### Output:
<img width="1381" height="784" alt="Image" src="https://github.com/user-attachments/assets/3507f314-36f3-4b56-90b4-96b44bd384f3" />
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/0e3b99f5-984b-481c-82d0-11d53584e145" />

## Kesimpulan
Program diatas menjelaskan tentang sebuah program untuk mencari nilai maksimum, minumum, dan rata-rata dalam sebuah array 1 dimensi, dimana program diatas menggunkaan function untuk mencari nilai maksimum dan minimum dan procedur untuk mencari rata-rata. Pada program ini juga menggunakan switch case untuk membuat tampilan untuk memlilih pilihan untuk menampilkan nilai maksimum, minimum, rata-rata

## Referensi
[1] “How to get largest and smallest number in an Array?”, GeeksforGeeks. [Online]. Available: https://www.geeksforgeeks.org/how-to-get-largest-and-smallest-number-in-an-array/
[2] “C++ Program to Perform Matrix Multiplication”, Tutorialspoint. [Online]. Available: https://www.tutorialspoint.com/cplusplus-program-to-perform-matrix-multiplication
