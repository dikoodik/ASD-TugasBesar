#include <iostream>
#include <conio.h>
#include "list_relasi.h"
#include "list_child.h"
#include "list_parent.h"
#include "aplikasi.h"

using namespace std;

address_child PC = nil;
infotype_child XC;
infotype_child x;
List_child LC;

address_parent PP = nil;

infotype_parent XP;
infotype_parent xx;
List_parent LP;

address_relasi PR = nil;
List_relasi LR;
address_relasi deleteP;
address_relasi deleteC;


address_child caric;
address_parent carip;





void menupilihan()
{
/**
    RIANDI KARTIKO           - 1301164300
**/

    createList(LR);
    createList(LC);
    createList(LP);
    int pil;

    do
    {
        cout<<"-----------TUBES ASD----------"<<endl;
        cout<<"----JADWAL FILM DI BIOSKOP----"<<endl;
        cout<<endl;
        cout<<"(1.) Insert Bioskop "<<endl;
        cout<<"(2.) Insert Jadwal Film "<<endl;
        cout<<"(3.) Lihat Daftar Bioskop "<<endl;
        cout<<"(4.) Lihat Daftar Film "<<endl;
        cout<<"(5.) Search Bioskop"<<endl;
        cout<<"(6.) Search Film"<<endl;
        cout<<"(7.) Relasikan Bioskop <-> film"<<endl;
        cout<<"(8.) Lihat Relasi "<<endl;
        cout<<"(9.) Cari Relasi "<<endl;
        cout<<"(10.) Putus Relasi "<<endl;
        cout<<"(11.) Hapus Bioskop "<<endl;
        cout<<"(12.) Hapus Film "<<endl;
        cout<<"(13.) Sort Relasi "<<endl;
        cout<<"(0.) EXIT "<<endl;

        cout<<endl;

        cout<<"Pilih    : ";
        cin>>pil;
        cout<<endl;
        switch(pil)
        {
        case 1:
            insert_parent();
            break;
        case 2:
            insert_child();
            break;
        case 3:
            view_parent();
            break;
        case 4:
            view_child();
            break;
        case 5:
            search_parent();
            break;
        case 6:
            search_child();
            break;
        case 7:
            relasikan();
            break;
        case 8:
            view_relasi();
            break;
        case 9:
            search_relasi();
            break;
        case 10:
            putus_relasi();
            break;
        case 11:
            delete_parent();
            break;
        case 12:
            delete_child();
            break;
        case 13:
            sortrelasi(LR);
            printInfo(LR);
            break;
        case 0:
            cout<<"Terima Kasih"<<endl;
            cout<<"RIANDI KARTIKO           - 1301164300"<<endl;
            cout<<"RIFKI MIFATHUR SUTOMO    - 1301164225"<<endl;
            cout<<"MOHAMMAD IZZAULHAQ HUDA  - 1301160565"<<endl;
            break;
        default:
            cout<<"Wrong Input"<<endl;
            break;

        }
        cout<<"Press [ENTER] to continue.."<<endl;
        getche();
        system("cls");
        cout<<endl;
    }
    while(pil != 0);
}

void insert_child()
{
/**
    RIFKI MIFATHUR SUTOMO    - 1301164225
**/


    stuff_child(&XC);
    insertngurut(LC,XC);
}
void view_child()
{
/**
    RIFKI MIFATHUR SUTOMO    - 1301164225
**/

    printInfo(LC);

}

void insert_parent()
{
    /**
    MOHAMMAD IZZAULHAQ HUDA  - 1301160565
    **/

    stuff_parent(&XP);
    insertngurut(LP,XP);

}

void view_parent()
{
    /**
    MOHAMMAD IZZAULHAQ HUDA  - 1301160565
    **/

    printInfo(LP);
}

void search_parent()
{
    /**
    MOHAMMAD IZZAULHAQ HUDA  - 1301160565
    **/

    cout<<"Masukkan ID Bioskop: ";
    cin>>xx.id;
    printsatuan(LP,xx);
}

void search_child()
{
/**
    RIFKI MIFATHUR SUTOMO    - 1301164225
**/

    cout<<"Masukkan ID Film: : ";
    cin>>x.id;
    printsatuan(LC,x);
}

void relasikan()
{
/**
    RIANDI KARTIKO           - 1301164300
**/

    cout<<"Merelasikan Bioskop dengan Film"<<endl;
    cout<<"Masukkan ID Bioskop  : ";
    cin>>xx.id;
    cout<<"Masukkan ID Film:    : ";
    cin>>x.id;
    carip = findElm(LP,xx);
    caric = findElm(LC,x);
    if(carip != nil && caric != nil)
    {
        PR = alokasi(carip,caric);
        insertLast(LR,PR);
        cout<<"ID Bioskop : "<<info(carip).id<<" dengan id Film : "<<info(caric).id<<" berhasil direlasikan "<<endl;
    }
    else
    {
        cout<<"ID Film / Bioskop Tidak Ditemukan!!"<<endl;
    }
}

void view_relasi()
{
/**
    RIANDI KARTIKO           - 1301164300
**/

    printInfo(LR);
}

void search_relasi()
{
/**
    RIANDI KARTIKO           - 1301164300
**/

    cout<<"Masukkan ID Bioskop: ";
    cin>>xx.id;
    cout<<"Masukkan ID Film: : ";
    cin>>x.id;
    carip = findElm(LP,xx);
    caric = findElm(LC,x);
    if(carip != nil && caric != nil)
    {
        PR=searchrelasi(LR,carip,caric);
        if(PR != nil)
        {
            cout<<"ID Bioskop: "<<info(carip).id<<" dengan ID Film : "<<info(caric).id<<" berelasi"<<endl;

            cout<<"ID Studio        : "<<info(carip).id<<endl;
            cout<<"Tipe Studio      : "<<info(carip).tipe_studio<<endl;
            cout<<"Tipe Layar       : "<<info(carip).tipe_layar<<endl;
            cout<<"Kapasitas        : "<<info(carip).jumlah_kursi<<endl;
            cout<<"Kapasitas Tayang : "<<info(carip).jumlah_film<<endl;
            cout<<endl;
            cout<<"-----"<<endl;
            cout<<endl;
            cout<<"ID               : "<<info(caric).id<<endl;
            cout<<"Judul            : "<<info(caric).nama_film<<endl;
            cout<<"Durasi           : "<<info(caric).durasi_film<<endl;
            cout<<"Harga            : "<<info(caric).harga_tiket<<endl;
            cout<<"Kategori         : "<<info(caric).kategori<<endl;
            cout<<"Jam              : "<<info(caric).jam_tayang<<endl;
        }
        else
        {
            cout<<"ID Bioskop: "<<info(carip).id<<" dengan ID Film : "<<info(caric).id<<" tidak berelasi"<<endl;
        }
    }
    else
    {
        cout<<"ID Bioskop / Film Tidak Ditemukan"<<endl;
    }

}

void putus_relasi()
{
/**
    RIANDI KARTIKO           - 1301164300
**/

    cout<<"Masukkan ID Bioskop  : ";
    cin>>xx.id;
    cout<<"Masukkan ID Film:    : ";
    cin>>x.id;
    carip = findElm(LP,xx);
    caric = findElm(LC,x);
    if(carip != nil && caric != nil)
    {
        if(first(LR) != nil)
        {
            PR = first(LR);
            while(PR != nil)
            {
                if(parent(PR) == carip && child(PR) == caric)
                {
                    child(PR) = nil;
                    parent(PR) = nil;
                    deletebyrelasi(LR,PR);
                    dealokasi(PR);
                    cout<<"ID Bioskop: "<<info(carip).id<<" dengan ID Film : "<<info(caric).id<<" Berhasil Dihapus"<<endl;
                }
                else
                {
                    PR = next(PR);
                }
            }
        }
        else
        {
            cout<<"List Relasi Kosong"<<endl;
        }
    }
    else
    {
        cout<<"ID Bioskop / ID Film Tidak Ditemukan"<<endl;
    }

}
void delete_parent()
{
/**
    RIANDI KARTIKO           - 1301164300
**/

    cout<<"Masukkan ID Bioskop: ";
    cin>>xx.id;
    carip = findElm(LP,xx);

    if(carip != nil)
    {
        PR = first(LR);
        while (PR != nil)
        {
            if(parent(PR) == carip)
            {
                deleteP = PR;
                PR = next(PR);
                parent(deleteP) = nil;
                child(deleteP) = nil;
                deletebyrelasi(LR,deleteP);
            }
            else
            {
                PR = next(PR);
            }
        }
        deletebyIDPARENT(LP,carip);
        dealokasi(carip);
    }
    else
    {
        cout<<"ID Tidak Ditemukan"<<endl;
    }
}

void delete_child()
{
/**
    RIANDI KARTIKO           - 1301164300
**/

    cout<<"Masukkan ID Film: ";
    cin>>x.id;
    caric = findElm(LC,x);

    if(caric != nil)
    {
        PR = first(LR);
        while (PR != nil)
        {
            if(child(PR) == caric)
            {
                deleteC = PR;
                PR = next(PR);
                parent(deleteC) = nil;
                child(deleteC) = nil;
                deletebyrelasi(LR,deleteC);

            }
            else
            {
                PR = next(PR);
            }
        }
        deletebyIDCHILD(LC,caric);
        dealokasi(caric);
    }
    else
    {
        cout<<"ID Tidak Ditemukan"<<endl;
    }
}
