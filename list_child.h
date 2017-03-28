#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <conio.h>
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
    string durasi_film;
    string harga_tiket;
    string kategori;
    string jam_tayang;
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
void dealokasi(address_child &P);
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
void deletebyIDCHILD(List_child &L, address_child &P);
void insertngurut(List_child &L, infotype_child x);
void printsatuan(List_child L, infotype_child x);
void deletechild(List_child &L, infotype_child x);
#endif // LIST_CHILD_H_INCLUDED
