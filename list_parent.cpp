#include "list_parent.h"

void createList(List_parent &L)
{
    /**
    MOHAMMAD IZZAULHAQ HUDA  - 1301160565
    **/

    first(L) = nil;
}
void dealokasi(address_parent &P)
{
    /**
    MOHAMMAD IZZAULHAQ HUDA  - 1301160565
    **/

    delete P;
}

void stuff_parent(infotype_parent *x)
{
    /**
    MOHAMMAD IZZAULHAQ HUDA  - 1301160565
    **/

    cout<<"ID Studio         : ";
    cin>>x->id;

    cout<<"Tipe Studio       : ";
    cin>>x->tipe_studio;

    cout<<"Tipe Layar        : ";
    cin>>x->tipe_layar;

    cout<<"Jumlah Kursi      : ";
    cin>>x->jumlah_kursi;

    cout<<"Maksimal Film     : ";
    cin>>x->jumlah_film;

}

address_parent alokasi(infotype_parent x)
{
    /**
    MOHAMMAD IZZAULHAQ HUDA  - 1301160565
    **/

    address_parent P;

    P = new elmlist_parent;
    info(P) = x;
    next(P) = nil;

    info(P).id = x.id;
    info(P).tipe_studio = x.tipe_studio;
    info(P).tipe_layar = x.tipe_layar;
    info(P).jumlah_kursi = x.jumlah_kursi;
    info(P).jumlah_film = x.jumlah_film;

    return P;
}

void insertFirst(List_parent &L, address_parent P)
{
    /**
    MOHAMMAD IZZAULHAQ HUDA  - 1301160565
    **/

    address_parent Q;

    if(first(L) == NULL)
    {
        first(L) = P;
        next(P) = P;
    }
    else
    {
        Q = first(L);
        while(next(Q) != first(L))
        {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void insertLast(List_parent &L, address_parent P)
{
    /**
    MOHAMMAD IZZAULHAQ HUDA  - 1301160565
    **/

    address_parent Q;

    if (first(L)==NULL)
        insertFirst(L,P);
    else
    {
        Q = first(L);
        while(next(Q) !=first(L))
            Q = next(Q);
        next(Q) = P;
        next(P)= first(L);
    }

}

void insertAfter(List_parent &L, address_parent Prec, address_parent P)
{
    /**
    MOHAMMAD IZZAULHAQ HUDA  - 1301160565
    **/

    if(Prec!=NULL)
    {
        if(next(Prec)==first(L))
        {
            insertLast(L,P);
        }
        else
        {
            next(P) = next(Prec);
            next(Prec) = P;
        }
    }
    else
    {
        cout<<"gagal insert after, prec null"<<endl;
    }

}

void deleteFirst(List_parent &L, address_parent &P)
{
    /**
    MOHAMMAD IZZAULHAQ HUDA  - 1301160565
    **/

    address_parent Q;
    if (first(L)==NULL)
        cout<<"No data"<<endl;
    else if(first(L)->next==first(L))
    {
        P = first(L);
        first(L)=NULL;
    }
    else
    {
        Q = first(L);
        P = first(L);
        while(Q->next!=first(L))
            Q = Q->next;
        Q->next=next(P);
        first(L)=next(P);
        next(P)=NULL;

    }


}

void deleteLast(List_parent &L, address_parent &P)
{
    /**
    MOHAMMAD IZZAULHAQ HUDA  - 1301160565
    **/

    address_parent Q;
    if (first(L)==NULL)
        cout<<"No data"<<endl;
    else if(first(L)->next==first(L))
    {
        P = first(L);
        first(L)=NULL;
    }
    else
    {
        Q = first(L);
        P = first(L);
        while(P->next!=first(L))
            P = P->next;
        while(Q->next!=P)
            Q = Q->next;
        Q->next = first(L);
        P->next = NULL;
    }
}
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P)
{
    /**
    MOHAMMAD IZZAULHAQ HUDA  - 1301160565
    **/

    if(first(L)!=NULL)
    {
        if(Prec!= NULL)
        {
            if(next(Prec)==first(L))
            {
                deleteFirst(L, P);
            }
            else
            {
                P = next(Prec);
                next(Prec) = next(P);
                next(P) = NULL;
            }
        }
        else
        {
            cout<<"Gagal Delete"<<endl;
        }
    }
    else
    {
        cout<<"List Kosong"<<endl;
    }


}


address_parent findElm(List_parent L, infotype_parent x)
{
    /**
    MOHAMMAD IZZAULHAQ HUDA  - 1301160565
    **/

    address_parent P;


    if(first(L) != nil)
    {
        P = first(L);
        while(info(P).id != x.id && next(P) != first(L))
        {
            P = next(P);
        }
    }

    if(info(P).id == x.id)
    {
        return P;
    }
    else
    {
        return nil;
    }
}

void printInfo(List_parent L)
{
    /**
    MOHAMMAD IZZAULHAQ HUDA  - 1301160565
    **/

    address_parent P;
    if (first(L) == nil)
    {
        cout<<"Tidak Ada Data"<<endl;
    }
    else
    {
        P = first(L);
        do
        {
            cout<<"ID Studio        : "<<info(P).id<<endl;
            cout<<"Tipe Studio      : "<<info(P).tipe_studio<<endl;
            cout<<"Tipe Layar       : "<<info(P).tipe_layar<<endl;
            cout<<"Kapasitas        : "<<info(P).jumlah_kursi<<endl;
            cout<<"Kapasitas Tayang : "<<info(P).jumlah_film<<endl;

            cout<<"-----"<<endl;
            P = next(P);
        }
        while (P != first(L));
    }
    cout<<endl;
}

void insertngurut(List_parent &L, infotype_parent x)
{
/**
    RIANDI KARTIKO           - 1301164300
**/
    address_parent P,P1,P2;
    P1 = findElm(L,x);
    if(P1 == nil)
    {
        P2 = alokasi(x);
        if(first(L) == nil)
        {
            insertFirst(L,P2);
        }
        else
        {
            P = first(L);
            if(x.id > info(P).id && x.id < info(next(P)).id)
            {
                insertAfter(L,P,P2);
            }
            else if(x.id < info(P).id)
            {
                insertFirst(L,P2);
            }
            else
            {
                while (next(P) != first(L) && info(next(P)).id < x.id)
                {
                    P = next(P);
                }
                if(next(P) == first(L))
                {
                    insertLast(L,P2);
                }
                else
                {
                    insertAfter(L,P,P2);
                }
            }
        }
    }
    else
    {
        cout<<"ID Sudah Digunakan"<<endl;
    }

}
void printsatuan(List_parent L, infotype_parent x)
{
    /**
    MOHAMMAD IZZAULHAQ HUDA  - 1301160565
    **/

    address_parent P;
    if (first(L) != nil)
    {
        P = findElm(L,x);
        if(P != nil)
        {

            cout<<"ID Studio        : "<<info(P).id<<" Ditemukan"<<endl;
            cout<<"Tipe Studio      : "<<info(P).tipe_studio<<endl;
            cout<<"Tipe Layar       : "<<info(P).tipe_layar<<endl;
            cout<<"Kapasitas        : "<<info(P).jumlah_kursi<<endl;
            cout<<"Kapasitas Tayang : "<<info(P).jumlah_film<<endl;

        }
        else
        {
            cout<<"ID Tidak Ditemukan"<<endl;
        }
    }
    else
    {
        cout<<"List Kosong"<<endl;
    }
}

void deletebyIDPARENT(List_parent &L, address_parent &P)
{
    /**
    MOHAMMAD IZZAULHAQ HUDA  - 1301160565
    **/


    if(first(L) != nil)
    {
        if(P == first(L))
        {
            deleteFirst(L,P);

        }
        else if(next(P) == first(L))
        {
            deleteLast(L,P);
        }
        else
        {
            address_parent Q = first(L);
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
