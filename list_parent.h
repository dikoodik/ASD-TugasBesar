#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define nil NULL


struct stuff_parent
{
    int id;
    string nama_bioskop;
    string lokasi_bioskop;
};

typedef stuff_parent infotype_parent;
typedef struct elmlist_parent *address_parent;

struct elmlist_parent
{
    infotype_parent info;
    address_parent next;
};

struct List_parent
{
    address_parent first;
};

void stuff_parent(infotype_parent *x);
address_parent alokasi(infotype_parent x);
void createList(List_parent &L);
void insertFirst(List_parent &L, address_parent P);
void insertAfter(List_parent &L, address_parent Prec, address_parent P);
void insertLast(List_parent &L, address_parent P);
void deleteFirst(List_parent &L, address_parent &P);
void deleteLast(List_parent &L, address_parent &P);
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P);
#endif // LIST_PARENT_H_INCLUDED
