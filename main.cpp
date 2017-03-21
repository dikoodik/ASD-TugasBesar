#include <iostream>
#include "list_relasi.h"
using namespace std;

address_child PC = nil;
infotype_child XC;
List_child LC;

address_parent PP = nil;
infotype_parent XP;
List_parent LP;

address_relasi PR = nil;

List_relasi LR;
int main()
{
//    cout << "Hello world!" << endl;
    createList(LC);
    createList(LP);
    createList(LR);

    stuff_child(&XC);
    stuff_parent(&XP);

    PC = alokasi(XC);
    PP = alokasi(XP);
    insertFirst(LC,PC);
    insertFirst(LP,PP);

    PR = alokasi(PP,PC);
    insertFirst(LR,PR);

    printInfo(LR);


    return 0;
}
