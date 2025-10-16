#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    mahasiswa m;
    inputMhs(m);
    cout << "Rata-rata nilai: " << rata2(m) << endl;
    return 0;
}
