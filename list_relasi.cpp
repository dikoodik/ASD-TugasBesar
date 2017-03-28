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
void dealokasi(address_relasi &P)
{
    delete P;
}
void insertFirst(List_relasi &L, address_relasi P)
{
    if (first(L) == nil)
    {
        first(L) = P;
        next(P) = nil;
    }
    else
    {

        next(P) = first(L);
        first(L) = P;
    }
}


void insertLast(List_relasi &L, address_relasi P)
{
    if (first(L) == nil)
    {
        insertFirst(L,P);
    }
    else
    {
        address_relasi Q = first(L);
        while (next(Q) != nil)
        {
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

void insertAfter(List_relasi L,address_relasi &Prec, address_relasi &P)
{
    if(first(L) == nil)
    {

        insertFirst(L,P);
    }
    else
    {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}


void deleteFirst(List_relasi &L, address_relasi &P)
{
    if(first(L) != nil)
    {
        if(next(first(L)) == nil)
        {

            P = first(L);

            first(L) = nil;
        }
        else
        {
            P = first(L);

            first(L) = next(P);
            next(P) = nil;
        }
    }
    else
    {
        cout<<"List Kosong"<<endl;
    }
}

void deleteLast(List_relasi &L, address_relasi&P)
{
    if(first(L) != nil)
    {
        if(next(first(L)) == nil)
        {
            deleteFirst(L,P);
        }
        else
        {
            address_relasi Q = first(L);
            while(next(next(Q)) != nil)
            {
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = nil;
        }
    }

}

void deleteAfter(List_relasi &L, address_relasi Prec, address_relasi &P)
{
    if(first(L)!= nil)
    {
        if(next(P) == nil)
        {
            deleteLast(L,P);
        }
        else if (P == first(L))
        {
            deleteFirst(L,P);
        }
        else
        {
            next(Prec) = next(P);
            next(P) = nil;
        }

    }
    else
    {
        cout<<"List Kosong"<<endl;
    }
}

void deletebyrelasi(List_relasi &L, address_relasi &P)
{
    address_relasi Q;

    if(first(L) != nil)
    {
        if(P == first(L))
        {
            deleteFirst(L,P);

        }
        else if(next(P) == nil )
        {

            deleteLast(L,P);
        }
        else
        {
            Q = first(L);
            while (next(Q) != P)
            {
                Q = next(Q);
            }
            deleteAfter(L,Q,P);
        }

    }
    else
    {
        cout<<"List Kosong"<<endl;
    }
}


void printInfo(List_relasi L)
{
    address_relasi P = first(L);
    if(first(L) != nil)
    {
        while(P != nil)
        {
            cout<<"ID Studio        : "<<info(parent(P)).id<<endl;
            cout<<"Tipe Studio      : "<<info(parent(P)).tipe_studio<<endl;
            cout<<"Tipe Layar       : "<<info(parent(P)).tipe_layar<<endl;
            cout<<"Kapasitas        : "<<info(parent(P)).jumlah_kursi<<endl;
            cout<<"Kapasitas Tayang : "<<info(parent(P)).jumlah_film<<endl;
            cout<<endl;
            cout<<"<<--->>"<<endl;
            cout<<endl;
            cout<<"ID Film          : "<<info(child(P)).id<<endl;
            cout<<"Nama Film        : "<<info(child(P)).nama_film<<endl;
            cout<<"Durasi           : "<<info(child(P)).durasi_film<<endl;
            cout<<"Harga Tiket      : "<<info(child(P)).harga_tiket<<endl;
            cout<<"Kategori         : "<<info(child(P)).kategori<<endl;
            cout<<"Jam Tayang       : "<<info(child(P)).jam_tayang<<endl;
            cout<<endl;
            cout<<"Data Selanjutmya"<<endl;
            cout<<endl;
            P = next(P);
        }
    }
    else
    {
        cout<<"List Relasi kosong"<<endl;
    }
}

address_relasi searchrelasiparent(List_relasi L, address_parent &P)
{
    if(first(L) != nil)
    {
        address_relasi PR = first(L);
        while(next(PR) != nil && parent(PR) != P)
        {
            PR = next(PR);
        }
        if (parent(PR) == P)
        {
            return PR;
        }
        else
        {
            return nil;
        }
    }
    else
    {
        cout<<"List Kosong"<<endl;
        return nil;
    }
}

address_relasi searchrelasichild(List_relasi L, address_child P)
{
    if(first(L) != nil)
    {
        address_relasi PR = first(L);
        while(next(PR) != nil && child(PR) != P)
        {
            PR = next(PR);
        }
        if (child(PR) == P)
        {
            return PR;
        }
        else
        {
            return nil;
        }
    }
    else
    {
        return nil;
    }

}

address_relasi searchrelasi(List_relasi L, address_parent Q, address_child Z)
{
    if(first(L) != nil)
    {
        address_relasi P = first(L);
        while (next(P) != nil)
        {
            if(parent(P) != Q && child(P) != Z)
            {
                P = next(P);
            }
        }
        if(child(P) == Z && parent(P) == Q)
        {
            return P;
        }
        else
        {
            return nil;
        }
    }
    else
    {
        return nil;
        cout<<"List Kosong"<<endl;
    }
}

void deleterelasi(List_relasi &L, address_relasi &P)
{
    child(P) = nil;
    parent(P) = nil;
    dealokasi(P);

}

void sortrelasi(List_relasi &L)
{
    address_relasi P,P2,P3,P4;

    if(first(L) != nil)
    {
        P = first(L);
        if(next(first(L)) != nil)
        {
            if(info(parent(P)).id > info(next(parent(P))).id )
            {
                P2 = next(P);
                P3 = P;
                P = next(P);
                deleteFirst(L,P3);
                insertAfter(L,P2,P3);
            }
            else
            {
                while(next(P) != nil)
                {
                    if(info(parent(P)).id > info(next(parent(P))).id)
                    {
                        P2 = P;
                        P4 = next(P);
                        P = next(next(P));
                        P3 = first(L);
                        while (next(P3) != P)
                        {
                            P3 = next(P3);
                        }
                        deleteAfter(L,P3,P2);
                        insertAfter(L,P4,P2);
                    }
                    else if(info(parent(P)).id < info(next(parent(P))).id)
                    {
                        P2 = next(P);
                        P4 = P;
                        P3 = first(L);

                        P = next(next(P));

                        while(next(P3) != P4)
                        {
                            P3 = next(P3);
                        }
                        deleteAfter(L,P3,P4);
                        insertAfter(L,P2,P4);
                    }
                }
            }
        }
    }else
    {
        cout<<"List Kosong"<<endl;
    }


}
