#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include "list_relasi.h"
#include "list_child.h"
#include "list_parent.h"


#include <iostream>
using namespace std;

#define next(P) P -> next
#define first(L) L.first
#define child(P) P->child
#define parent(P) P->parent



#endif // LIST_RELASI_H_INCLUDED
