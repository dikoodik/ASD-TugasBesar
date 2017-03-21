#include "list_parent.h"

void createList(List_parent &L){
    first(L) = nil;
}

void stuff_parent(infotype_parent *x){
    cout<<"ID               : "<<endl;
    cin>>x->id;
    cout<<endl;
    cout<<"Nama Bioskop     : "<<endl;
    cin>>x->nama_bioskop;
    cout<<endl;
    cout<<"Lokasi Bioskop   : "<<endl;
    cin>>x->lokasi_bioskop;
}

address_parent alokasi(infotype_parent x){
    address_parent P;

    P = new elmlist_parent;
    info(P) = x;
    next(P) = nil;

    info(P).id = x.id;
    info(P).nama_bioskop = x.nama_bioskop;
    info(P).lokasi_bioskop = x.lokasi_bioskop;

    return P;
}

void insertFirst(List_parent &L, address_parent P) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_parent L
    *      next dari last elemen menunjuk ke first elemen
    */
    address_parent Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}
