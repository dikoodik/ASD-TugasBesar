#include "list_relasi.h"

void createList(List_relasi &L)
{
    first(L) = nil;
}

address_relasi alokasi(address_parent P, address_child C)
{
    address_relasi Q = new elmlist_relasi;
    child(Q) = C;
    parent(Q) = P;
    next(Q) = NULL;
    return Q;
}

void insertFirst(List_relasi &L, address_relasi P)
{
    if (first(L) == nil){
        first(L) = P;
        next(P) = nil;
    }else{

    next(P) = first(L);
    first(L) = P;
    }
}


void insertLast(List_relasi &L, address_relasi P){
    if (first(L) == nil){
        insertFirst(L,P);
    }else{
        address_relasi Q = first(L);
        while (next(Q) != nil){
            Q = next(Q);
        }
            next(Q) = P;
            next(P) = nil;

    }

}

address_relasi findElm(List_relasi L, address_parent P, address_child C)
{
    address_relasi Q = first(L);
    while(Q != NULL)
    {
        if(parent(Q)==P && child(Q)== C)
        {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

void insertAfter(address_relasi &Prec, address_relasi P)
{
    next(P) = next(Prec);
    next(Prec) = P;
}

void printInfo(List_relasi L)
{
    address_relasi P = first(L);
    while(P !=NULL)
    {
        cout<<info(parent(P)).id<<endl;
        cout<<info(parent(P)).nama_bioskop<<endl;
        cout<<info(parent(P)).lokasi_bioskop<<endl;

        cout<<"<<--->>"<<endl;

        cout<<info(child(P)).id<<endl;
        cout<<info(child(P)).nama_film<<endl;
        cout<<info(child(P)).durasi_film<<endl;
        cout<<info(child(P)).harga_tiket<<endl;
        P = next(P);
    }
}
