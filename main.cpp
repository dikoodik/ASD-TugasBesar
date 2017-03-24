#include <iostream>
#include "list_relasi.h"
using namespace std;

address_child PC = nil;
address_child Pcari;
infotype_child XC;

List_child LC;

address_parent PP = nil;
address_parent cariP;
infotype_parent XP;

List_parent LP;

address_relasi PR = nil;
List_relasi LR;



void mainmenu();

void mainmenu(){
    cout<<"----TUBES ASD----"<<endl;
    cout<<"----JADWAL FILM DI BIOSKOP----"<<endl;
    cout<<endl;

    cout<<"(1.) Input Data Bioskop"<<endl;

}


int main()
{

infotype_child x;
infotype_parent xx;
    createList(LC);
    createList(LP);
//    stuff_parent(&XP);
//    cariP = findElm(LP,XP);
//    if(cariP == nil){
//        insertngurut(LP,XP);
//    }else{
//        cout<<"ID Sudah Ada"<<endl;
//
//    }








    stuff_child(&XC);

    Pcari = findElm(LC,XC);
    if(Pcari == nil){
        insertngurut(LC,XC);

    }else{
        cout<<"ID Sudah Ada!!"<<endl;
    }

    printInfo(LC);

    stuff_parent(&XP);

    cariP = findElm(LP,XP);
    if(cariP == nil){
        insertngurut(LP,XP);

    }else{
        cout<<"ID Sudah Ada!!"<<endl;
    }
    printInfo(LP);
    cout<<"Child: "<<endl;
    cin>>x.id;
    address_child nyari = findElm(LC,x);
    cout<<"Parent: "<<endl;
    cin>>xx.id;
    address_parent nyari1 = findElm(LP,xx);
    address_relasi fix = alokasi(nyari1,nyari);

    insertFirst(LR,fix);
    printInfo(LR);
//   stuff_parent(&XP);
//   cariP = find




}
