#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

#define nil NULL


struct stuff_child
{
    int id;
    string nama_film;
    double durasi_film;
    double harga_tiket;
};
typedef stuff_child infotype_child;
typedef struct elmlist_child *address_child;


struct elmlist_child
{
    infotype_child info;
    address_child next;
    address_child prev;
};

struct List_child
{
    address_child first;
    address_child last;
};


void stuff_child(infotype_child *x);
address_child alokasi(infotype_child x);
void printInfo(List_child L);
address_child findElm(List_child L, infotype_child x);
void createList(List_child &L);
void insertFirst(List_child &L, address_child P);
void insertLast(List_child &L, address_child P);
void insertAfter(address_child Prec, address_child P);
void deleteFirst(List_child &L, address_child &P);
void deleteLast(List_child &L, address_child &P);
void deleteAfter(address_child Prec, address_child &P);
#endif // LIST_CHILD_H_INCLUDED
