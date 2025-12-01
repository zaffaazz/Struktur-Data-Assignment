#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

using namespace std;

typedef struct BST *node;

struct BST{
    int angka;
    node left;
    node right;
};

typedef node BinTree;

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

int hitungNode(BinTree tree);
int hitungKedalaman(BinTree tree, int start);  
int hitungTotal(BinTree tree);

#endif