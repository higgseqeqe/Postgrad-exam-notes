#include <iostream>
using namespace std;
using ElemType = int;


typedef struct DNode {
    ElemType data;
    struct DNode *prior,*next;
} DNode, *LinkList;

bool InsertNextDNode(DNode *p,DNode *s) {
    if (p == nullptr || s == nullptr)
        s->next = p->next;
    if (p->next != nullptr)
        p->next->prior=s;
    s->prior=p;
    p->next=s;
    return true;

}