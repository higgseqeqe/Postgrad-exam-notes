//练习文件都是不看教程自己写的
#include <iostream>
using namespace std;
using ElemType =int;

struct LNode {
    ElemType data; //每个节点存放一个数据元素 数据域
    LNode* next; //指针指向下一个节点 指针域
};
using LinkList = LNode*;
//初始化链表
bool InitLinkedList(LinkList& L) {
    L= new(nothrow) LNode;
    if (L == nullptr)
        return false;
    L -> next = nullptr;
    return true;
}
// 链表的位插

bool InsertLinkedList(LinkList& L, int i, ElemType e) {
    if (i<1)
        return false;
    LNode *p;
    p=L;
    int j =0; //定义一个j记录指针p的指向
    while ( p!=nullptr &&  j<i-1) {
        p = p->next;
        j++;
    }
    //创建一个新的节点s
    if (p==nullptr)
        return false;
    LNode *s =new LNode;
    //先让s记录修改的值
    s->data = e;
    //让s指向后继节点
    s->next=p->next;
    //让前趋指向s节点
    p->next = s;
    //修改完成
    return true;

}