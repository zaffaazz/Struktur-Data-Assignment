#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;

    BinTree tree;
    createTree(tree);       

    insertNode(tree, alokasi(1));
    insertNode(tree, alokasi(2));
    insertNode(tree, alokasi(6));
    insertNode(tree, alokasi(4));
    insertNode(tree, alokasi(5));
    insertNode(tree, alokasi(3));
    insertNode(tree, alokasi(6));
    insertNode(tree, alokasi(7));

    cout << "\nInOrder = ";
    inOrder(tree);

    cout << "\nKedalaman   : " << hitungKedalaman(tree, 0) << endl;
    cout << "Jumlah Node : " << hitungNode(tree) << endl;
    cout << "Total Info  : " << hitungTotal(tree) << endl;

    cout << "\nPostOrder = ";
    postOrder(tree);

    cout << "\nPre-Order = ";
    preOrder(tree);

    return 0;
}
