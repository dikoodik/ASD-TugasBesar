#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include "list_relasi.h"
#include "list_child.h"
#include "list_parent.h"


#include <iostream>
using namespace std;


#define next(P) P -> next
#define first(L) L.first
#define child(P) P->child
#define parent(P) P->parent



typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi
{
    address_relasi next;
    address_child child;
    address_parent parent;
};

struct List_relasi
{
    address_relasi first;
};

void deletebyrelasi(List_relasi &L, address_relasi &P);
void deleterelasi(List_relasi &L, address_relasi &P);
address_relasi alokasi(address_parent P, address_child C);
void dealokasi(address_relasi &P);
void printInfo(List_relasi L);
void createList(List_relasi &L);
void insertFirst(List_relasi &L, address_relasi P);
void insertLast(List_relasi &L, address_relasi P);
void insertAfter(address_relasi Prec, address_relasi P);
void deleteFirst(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi&P);
void deleteAfter(address_relasi Prec, address_relasi &P);
address_relasi searchrelasi(List_relasi L, address_parent Q, address_child Z);
address_relasi searchrelasiparent(List_relasi L, address_parent &P);
#endif // LIST_RELASI_H_INCLUDED
