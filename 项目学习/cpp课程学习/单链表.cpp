#include <iostream>
using namespace std;
using ElemType = int;

struct LNode { //定义单链表结点类型
    ElemType data; //每个节点存放一个数据元素 数据域
    LNode* next; //指针指向下一个节点 指针域
};

//增加一个新的节点
using LinkList = LNode*;

// bool InitList(LinkList& L) {
//     L = nullptr;
//     return true;
// } 不带头节点的初始化

//带头节点的初始化

bool InitList(LinkList& L) {
    L = new(nothrow) LNode;
    if (L == nullptr) return false;
    L->next = nullptr;
    return true;
}
//头插法
bool ListInsert(LinkList& L, int i, ElemType e) {
    if (i<1)
        return false;
    LNode *p;
    int j=0;//当前p指向的是哪个节点
    p =L;
    while (p != nullptr && j<i-1) {
        p = p->next;
        j++;
    }
    if (p == nullptr)
        return false;
    LNode* s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;

}
//指定节点的后插操作 在p节点后插入元素 e

bool InsertNextNode(LNode *p, ElemType e) {
    if (p==nullptr)
        return false;
    LNode *s=new LNode;
    if (s== nullptr)
        return false;
    s->data = e;//用节点s保存数据元素e
    s->next = p->next; //s指向后继节点
    p->next = s; //将节点s连接到p
    return true;
}

//前插
bool InsertPriorNode (LinkList L,LNode *p,ElemType e) {
    if (p == nullptr)
        return false;
    LNode *s=new LNode;
    if (s== nullptr)
        return false;
    s->next = p->next; //把p的后继节点地址赋值给s的后继节点
    p->next = s; //p的节点指向s
    s->data = p->data; //将p中的元素赋值给s
    p->data = e;
    return true;
}

//按位序删除（带头节点）
bool ListDelete(LinkList L,int i,ElemType &e) {
    if (i<1)
        return false;
    LNode *p;
    int j= 0;//指向当前p记录的指针
    p = L;
    while (p != nullptr && j<i-1 ) {
        p = p->next;
        j++;
    }
    if (p == nullptr) //i值不合法
      return false;
    if (p->next == nullptr)//第i-1个节点后已无其他节点
        return false;
    LNode* q = p->next;
    e = q->data;
    p->next=q->next;
    delete q;
    return true;
}
//指定节点的插入
bool DeleteNode (LNode *p){
    if (p==nullptr)
        return false;

    LNode *q =p->next;
    p->data=p->next->data;
    p->next =q->next;
    delete q;
    return true;

}


int main() {

}
