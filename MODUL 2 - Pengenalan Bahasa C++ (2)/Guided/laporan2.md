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
Penjelasan diatas tentang bagaimana bilangan float (koma) bisa dihitung dalam operasi aritmatika dengan format type data float dan sesuai dengan program yang sudah dibuat akan diproses dengan menggunakan kode yang tersedia yaitu ada pembagian, pengurangan, pembagian, perkalian, tapi dalam kode diatas apabila bilangan dibagi 0 maka outputnya adalah "inf" karena bilangan apapun yang dibagi 0 = infinity.

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
Dari program diatas merupakan program dengan type data string dimana kita akan mengubah angka menejadi bilangan string dengan menggunakan bantuan array kita isi dengan huruf angka dari mulai satuan dan puluhan karena kita hanya mengubah angka dari 0-100 dan dengan bantuan operasi aritmatika yaitu pembagian untuk menggetahui puluhan atau angka awal bilangan tersebut dengan membagiya dengan angka 10 dan untuk mencari angka satuan dengan menggunakan modulus yaitu sisa pembagi dari bilangan n tapi ini jika bilangan n > 20 sampai n < 100 dan untuk f (s == 0) return puluhan[p - 2] ini jika yang dicari bilangan yang dibelakangnya nol jadi saya tulis p-2 karena agar sesuai dengan index yang sudah dibuat pada array itu index dari 0-9 jika saya tidak menuliskan dengan -2 maka program akan menghasilkan output berupa index 2 dibawahnya semisal kalo saya inputkan 20 maka outputnya 40, jadi saya -2 karena sesuai dengan index 20 yaitu index ke 0.

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
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/c6a168e6-e9f9-497a-8e08-cbcaaaefdb4e" />

## Kesimpulan
Program diatas menjelaskan tentang sebuah program untuk mencetak sebuah segitiga terbalik dengan mengggunakan lopp pada lopp yang pertama akan mencetak baris sesuai dengan inputanya, Loop yang kedua untuk mencetak spasi di awal baris agar pola segitiga yang dihasilkan menjadi rata ke kanan, 
Loop yang ketiga digunakan untuk mencetak angka secara menurun dari nilai i sampai 1, lalu meninputkan bintang dibagian tengah, lalau Loop yang keempat digunakan untuk mencetak angka secara naik dari 1 sampai i. Jadi pada program diatas menjelsakan bagaimana cara looping atau perulangan terjadi sampai terbentuk sebuah segitiga

## Referensi
[1] A. Ma’arif, Dasar Pemrograman Bahasa C++. Yogyakarta: Universitas Ahmad Dahlan, 2022. [Online]. Available: https://eprints.uad.ac.id/32726/
[2] Petani Kode, “Tutorial Pemrograman C++ untuk Pemula”. [Online]. Available: https://www.petanikode.com/tutorial/c++/
