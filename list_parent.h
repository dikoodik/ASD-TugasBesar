/**
    MOHAMMAD IZZAULHAQ HUDA  - 1301160565
**/


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
    string tipe_studio;
    string tipe_layar;
    string jumlah_kursi;
    string jumlah_film;
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
void dealokasi(address_parent &P);
void createList(List_parent &L);
void insertFirst(List_parent &L, address_parent P);
void insertAfter(List_parent &L, address_parent Prec, address_parent P);
void insertLast(List_parent &L, address_parent P);
void deleteFirst(List_parent &L, address_parent &P);
void deleteLast(List_parent &L, address_parent &P);
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P);
address_parent findElm(List_parent L, infotype_parent x);
void insertngurut(List_parent &L, infotype_parent x);
void printInfo(List_parent L);
void printsatuan(List_parent L, infotype_parent x);
void deletebyIDPARENT(List_parent &L, address_parent &P);

#endif // LIST_PARENT_H_INCLUDED
