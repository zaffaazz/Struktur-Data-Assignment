#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED

#include <stdbool.h>
#include <stdlib.h>
#define Nil NULL
typedef int infotypeanak;
typedef int infotypeinduk;

typedef struct elemen_list_induk *address;
typedef struct elemen_list_anak  *address_anak;

struct elemen_list_anak {
    infotypeanak info;
    address_anak next;
    address_anak prev;
};

struct listanak {
    address_anak first;
    address_anak last;
};


struct elemen_list_induk {
    infotypeinduk info;
    listanak lanak;     
    address next;
    address prev;
};

struct listinduk {
    address first;
    address last;
};

bool ListEmpty(listinduk L);
bool ListEmptyAnak(listanak L);
void CreateList(listinduk *L);
void CreateListAnak(listanak *L);
address alokasi(infotypeinduk X);
address_anak alokasiAnak(infotypeanak X);
void dealokasi(address P);
void dealokasiAnak(address_anak P);
address findElm(listinduk L, infotypeinduk X);
address_anak findElmAnak(listanak L, infotypeanak X);
bool fFindElm(listinduk L, address P);
bool fFindElmAnak(listanak L, address_anak P);
address findBefore(listinduk L, address P);
address_anak findBeforeAnak(listanak L, infotypeanak X, address_anak P);
void insertFirst(listinduk *L, address P);
void insertAfter(listinduk *L, address P, address Prec);
void insertLast(listinduk *L, address P);
void insertFirstAnak(listanak *L, address_anak P);
void insertAfterAnak(listanak *L, address_anak P, address_anak Prec);
void insertLastAnak(listanak *L, address_anak P);
void delFirst(listinduk *L, address *P);
void delLast(listinduk *L, address *P);
void delAfter(listinduk *L, address *P, address Prec);
void delP(listinduk *L, infotypeinduk X);
void delFirstAnak(listanak *L, address_anak *P);
void delLastAnak(listanak *L, address_anak *P);
void delAfterAnak(listanak *L, address_anak *P, address_anak Prec);
void delPAnak(listanak *L, infotypeanak X);
void printInfo(listinduk L);
int  nbList(listinduk L);
void printInfoAnak(listanak L);
int  nbListAnak(listanak L);
void delAll(listinduk *L);

#endif
