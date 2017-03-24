#include "list_parent.h"

void createList(List_parent &L)
{
    first(L) = nil;
}
void dealokasi(address_parent &P)
{
    delete P;
}

void stuff_parent(infotype_parent *x)
{
    cout<<"ID               : "<<endl;
    cin>>x->id;
    cout<<endl;
    cout<<"Nama Bioskop     : "<<endl;
    cin>>x->nama_bioskop;
    cout<<endl;
    cout<<"Lokasi Bioskop   : "<<endl;
    cin>>x->lokasi_bioskop;
    cout<<"Tipe Studio      : "<<endl;
    cin>>x->tipe_studio;

}

address_parent alokasi(infotype_parent x)
{
    address_parent P;

    P = new elmlist_parent;
    info(P) = x;
    next(P) = nil;

    info(P).id = x.id;
    info(P).nama_bioskop = x.nama_bioskop;
    info(P).lokasi_bioskop = x.lokasi_bioskop;
    info(P).tipe_studio = x.tipe_studio;

    return P;
}

void insertFirst(List_parent &L, address_parent P)
{
    /**
    * IS : List_parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_parent L
    *      next dari last elemen menunjuk ke first elemen
    */
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
    address_parent Q;
    if (first(L)==NULL)
        insertFirst(L,P);
    else
    {
        Q = first(L);
        while(next(Q) !=first(L))
            Q = next(Q);
        next(Q) = P;
        next(P)=first(L);
    }

}

void insertAfter(List_parent &L, address_parent Prec, address_parent P)
{
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
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P)
{
    if(first(L)!=NULL)
    {
        if(Prec!=NULL)
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
            cout<<"gagal delete after"<<endl;
        }
    }
    else
    {
        cout<<"gagal delete after, list kosong"<<endl;
    }


}

address_parent deletebyIDPARENT(List_parent &L, infotype_parent x)
{
    address_parent P,P2;
    P = findElm(L,x);

    if(P!= nil)
    {
        if(P == first(L))
        {
            deleteFirst(L,P);

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
        cout<<"ID Tidak Ditemukan"<<endl;
    }



}
address_parent findElm(List_parent L, infotype_parent x)
{
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
            cout<<"ID       : "<<info(P).id<<endl;
            cout<<"Nama     : "<<info(P).nama_bioskop<<endl;
            cout<<"Lokasi   : "<<info(P).lokasi_bioskop<<endl;
            cout<<"Tipe     : "<<info(P).tipe_studio<<endl;
            cout<<"-----"<<endl;
            P = next(P);
        }
        while (P != first(L));
    }
    cout<<endl;
}

void insertngurut(List_parent &L, infotype_parent x)
{
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

}
void printsatuan(List_parent L, infotype_parent x)
{
    address_parent P;
    if (first(L) != nil)
    {
        P = findElm(L,x);
        if(P != nil)
        {

            cout<<"ID       : "<<info(P).id<<" Ditemukan"<<endl;
            cout<<"Nama     : "<<info(P).nama_bioskop<<endl;
            cout<<"Lokasi   : "<<info(P).lokasi_bioskop<<endl;
            cout<<"Tipe     : "<<info(P).tipe_studio<<endl;

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
