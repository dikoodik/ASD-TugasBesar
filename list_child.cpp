#include "list_child.h"

void createList(List_child &L) {
    first(L) = NULL;
    last(L) = NULL;
}

void stuff_child(infotype_child *x){
    cout<<"ID          : "<<endl;
    cin>>x->id;
    cout<<endl;
    cout<<"Nama Film   : "<<endl;
    cin>>x->nama_film;
    cout<<endl;
    cout<<"Durasi Film : "<<endl;
    cin>>x->durasi_film;
    cout<<endl;
    cout<<"Harga Tiket : "<<endl;
    cin>>x->harga_tiket;
    cout<<endl;
}

address_child alokasi(infotype_child x){
    address_child P;

    P = new elmlist_child;
    info(P) = x;
    next(P) = nil;
    prev(P) = nil;

    info(P).id = x.id;
    info(P).nama_film = x.nama_film;
    info(P).durasi_film = x.durasi_film;
    info(P).harga_tiket = x.harga_tiket;

    return P;
}


void insertFirst(List_child &L, address_child P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void printInfo(List_child L) {
    address_child P = first(L);
    while(P !=NULL) {
        cout<<"->"<<info(P).id<<endl;
        cout<<"->"<<info(P).nama_film<<endl;
        cout<<"->"<<info(P).durasi_film<<endl;
        cout<<"->"<<info(P).harga_tiket<<endl;
        P = next(P);
    }
}

address_child findElm(List_child L, infotype_child x) {
    address_child P = first(L);
    while(P != nil) {
        if(info(P).id == x.id) {
            cout<<"Ditemukan"<<endl;
            return P;
        }
        P = next(P);
    }
    return NULL;
}
