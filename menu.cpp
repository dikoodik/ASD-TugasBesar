#include <iostream>
#include <conio.h>
#include "list_relasi.h"

void menupilihan()
{

    address_child PC = nil;
    address_child Pcari;
    infotype_child XC;
    infotype_child x;
    List_child LC;

    address_parent PP = nil;
    address_parent cariP;
    infotype_parent XP;
    infotype_parent xx;
    List_parent LP;

    address_relasi PR = nil;
    List_relasi LR;



    address_child caric;
    address_parent carip;


    createList(LR);
    createList(LC);
    createList(LP);
    int pil;

    do{
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

pilihmenu:
    cout<<"Pilih    : ";
    cin>>pil;
    switch(pil)
    {
    case 1:
        stuff_parent(&XP);
        insertngurut(LP,XP);
        break;
    case 2:
        stuff_child(&XC);
        insertngurut(LC,XC);
        break;
    case 3:
        printInfo(LP);
        cout<<"Press [ENTER] to continue.."<<endl;
        getche();
        goto pilihmenu;
    case 4:
        printInfo(LC);
        cout<<"Press [ENTER] to continue.."<<endl;
        getche();
        goto pilihmenu;
    case 5:
        cout<<"Masukkan ID Bioskop: "<<endl;
        cin>>xx.id;
        printsatuan(LP,xx);
        cout<<"Press [ENTER] to continue.."<<endl;
        getche();
        goto pilihmenu;
    case 6:
        cout<<"Masukkan ID Film: :"<<endl;
        cin>>x.id;
        printsatuan(LC,x);
        cout<<"Press [ENTER] to continue.."<<endl;
        getche();
        goto pilihmenu;
    case 7:
        cout<<"Merelasikan Bioskop dengan Film"<<endl;
        cout<<"Masukkan ID Bioskop: "<<endl;
        cin>>xx.id;
        cout<<"Masukkan ID Film: :"<<endl;
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
        cout<<"Press [ENTER] to continue.."<<endl;
        getche();
        goto pilihmenu;
    case 8:
        printInfo(LR);
        cout<<endl;
        cout<<"Press [ENTER] to continue.."<<endl;
        getche();
        goto pilihmenu;
    case 9:
        cout<<"Masukkan ID Bioskop: "<<endl;
        cin>>xx.id;
        cout<<"Masukkan ID Film: :"<<endl;
        cin>>x.id;
        carip = findElm(LP,xx);
        caric = findElm(LC,x);
        if(carip != nil && caric != nil)
        {
            PR=searchrelasi(LR,carip,caric);
            if(PR != nil)
            {
                cout<<"ID Bioskop: "<<info(carip).id<<" dengan ID Film : "<<info(caric).id<<" berelasi"<<endl;
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
        cout<<"Press [ENTER] to continue.."<<endl;
        getche();
        goto pilihmenu;
    case 10:
        cout<<"Masukkan ID Bioskop: "<<endl;
        cin>>xx.id;
        cout<<"Masukkan ID Film: :"<<endl;
        cin>>x.id;
        carip = findElm(LP,xx);
        caric = findElm(LC,x);
        if(carip != nil && caric != nil)
        {
            PR=searchrelasi(LR,carip,caric);
            if(PR != nil)
            {
                cout<<"ID Bioskop: "<<info(carip).id<<" dengan ID Film : "<<info(caric).id<<" berelasi"<<endl;
                deletebyrelasi(LR,PR);
                deleterelasi(LR,PR);
                cout<<"Relasi Berhasil Dihapus"<<endl;
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
        cout<<"Press [ENTER] to continue.."<<endl;
        getche();
        goto pilihmenu;

    case 11:
        cout<<"Masukkan ID Bioskop: "<<endl;
        cin>>xx.id;
        carip = deletebyIDPARENT(LP,xx);
        if(carip != nil)
        {
            cout<<"Bioskop ID : "<<info(carip).id<<" Berhasil dihapus "<<endl;
            PR = searchrelasiparent(LR, carip);
            dealokasi(carip);
            if(PR != nil)
            {
                deletebyrelasi(LR,PR);
                deleterelasi(LR,PR);
            }
            else
            {
                cout<<"List Tidak Berelasi"<<endl;
            }
        }
        else
        {
            cout<<"ID Tidak Ditemukan"<<endl;
        }
        cout<<"Press [ENTER] to continue.."<<endl;
        getche();
        goto pilihmenu;
    case 12:
        cout<<"Masukkan ID Film: :"<<endl;
        cin>>x.id;
        caric = deletebyIDCHILD(LC,x);
        if (caric != nil)
        {
            cout<<"Film ID : "<<info(caric).id<<" berhasil dihapus"<<endl;
            PR = searchrelasichild(LR,caric);
            dealokasi(caric);
            if(PR != nil)
            {
                deletebyrelasi(LR,PR);
                deleterelasi(LR,PR);
            }
            else
            {
                cout<<"List Tidak Berelasi"<<endl;
            }
        }
        else
        {
            cout<<"ID Tidak Ditemukan"<<endl;
        }
        cout<<"Press [ENTER] to continue.."<<endl;
        getche();
        goto pilihmenu;
    case 13:
        sortrelasi(LR);
        printInfo(LR);
        break;
    case 0:
        cout<<"Terima Kasih"<<endl;
        break;
    default:
        cout<<"wrong input"<<endl;
        cout<<"Press [ENTER] to continue.."<<endl;
        getche();
        goto pilihmenu;
    }
    cout<<"Press [ENTER] to continue.."<<endl;
    getche();
    cout<<endl;
}while(pil != 0);
}
