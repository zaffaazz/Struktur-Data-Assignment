# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Zaffa Azzahra </p>

## Dasar Teori
Graph adalah jenis struktur data umum yang susunan datanya tidak berdekatan satu sama lain (non-linier). Graph terdiri dari kumpulan simpul berhingga untuk menyimpan data dan antara dua buah simpul terdapat hubungan saling keterkaitan.
## quided

### 1. [GRAPH]

```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    //hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A'); //BFS
    PrintDFS(G, 'A'); //DFS
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL){
        cout << "Node E berhasil terhapus" << endl;
    } else {
        cout << "Node E tidak berhasil terhapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    PrintBFS(G, 'A'); //BFS
    PrintDFS(G, 'A'); //DFS

    return 0;
}

Kode di atas digunakan untuk mencetak teks "ini adalah file code uguided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## unquided

### 1. [Soal]

```C++
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    adrNode start = FindNode(G, 'A');

    ResetVisited(G);
    cout << "BFS Traversal: ";
    PrintBFS(G, start);
    cout << endl;

    ResetVisited(G);
    cout << "DFS Traversal: ";
    PrintDFS(G, start);
    cout << endl;

    return 0;
}
```

#### Output:

<img width="1177" height="161" alt="Image" src="https://github.com/user-attachments/assets/091e8a93-b75f-42da-bf8e-f26c8ac9cb75" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/16a02230-73d3-4cd4-aa02-fbc0a3af7908" />

## Kesimpulan
Program ini menerapkan ADT Graph menggunakan adjacency list untuk menyimpan hubungan antar node. Dan melakukan proses penelusuran BFS dilakukan dengan bantuan queue, dan DFS menggunakan stack atau rekursi dan juga penanda visited digunakan agar setiap node hanya dikunjungi satu kali selama traversal.

## Referensi
[1] Trivusi, “Struktur Data Graph: Pengertian, Jenis, dan Contohnya”, Trivusi Blog. [Online]. Available: https://www.trivusi.web.id/2022/07/struktur-data-graph.html