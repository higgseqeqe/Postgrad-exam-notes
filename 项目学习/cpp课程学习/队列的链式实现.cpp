#include <iostream>
using namespace std;
using ElemType=int;

typedef struct LinkNode{   //链式队列节点
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front,*rear;
}LinkQueue;