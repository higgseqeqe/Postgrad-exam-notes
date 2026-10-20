#include <iostream>
using namespace std;
#define InitSize 10

// 静态分配
// #define Maxsize 10
//
// typedef struct {
//     int data[Maxsize];
//     int length;
// }SqList;
//
// void initList(SqList &L) {
//     for (int i=0; i<Maxsize; i++) {
//         L.data[i] = i;
//     }
//     L.length = 10;
// }
//
// int main() {
//     SqList L;
//     initList(L);
//     for (int i=0; i<Maxsize; i++) {
//         cout << L.data[i] << " ";
//     }
// }

// //动态分配
// using ElemType =int;
// typedef struct {
//     ElemType *data; //指针动态分配的表
//     int Maxsize;  //最大容量
//     int length;  //长度
// }Sqlist;
//
// void InitList(Sqlist &L) {
//     L.data = new ElemType[InitSize]{}; //初始化表里的元素为 0
//     L.Maxsize = InitSize; //定义最大容量为 10
//     L.length = 0;  //初始化长度为0
// }
//
// void IncreaseSize(Sqlist &L,int len) {
//     ElemType *p = L.data;
//     L.data = new ElemType[L.Maxsize + len]{};  //申请一块新的内存空间
//     for (int i = 0; i < L.length; ++i) {
//         L.data[i] = p[i];
//     }
//     L.Maxsize += len;
//     delete[] p; //顺序表扩容
// }
// int main() {
//     Sqlist L{};  //声明一个表
//     InitList(L); //初始化
//
//     L.data[0] = 100; //元素赋值
//     L.length=10; //设置长度
//
//     for (int i = 0; i < L.length; ++i) {
//         cout << L.data[i] << " ";
//     }
//     return 0;
// }

// 插入
#define Maxsize 10

typedef struct {
    int data[Maxsize];
    int length;
}SqList;

bool ListInsert(SqList &L, int i, int e){  // 传入 第i个元素 和修改元素e
    if (i<1 || i>L.length+1)
        return false;
    if (L.length>=Maxsize)
        return false;
    for(int j=L.length;j>=i;j--)    // 循环，从有效元素尾部遍历 直到j < i
        L.data[j]=L.data[j-1];     // 把元素往后移一位
    L.data[i-1]=e;            // 在i后插入 元素e
    L.length++;
    return true;
} // 插入操作

bool ListDelete(SqList &L, int i, int &e) {
    if (i<1 || i>L.length)
        return false;
    e=L.data[i-1];//将要被删除的元素赋值给 e
    for(int j=i;j<L.length;j++)//循环，从第i个元素起开始遍历，直到顺序表最大值
        L.data[j-1]=L.data[j]; //将后一个元素赋值给前一个元素
    L.length--;
    return true;
}//删除操作

void initList(SqList &L) {
    for (int i=0; i<Maxsize; i++) {
        L.data[i] = 0;
    }
    L.length = 0;
}

int main() {
    SqList L;
    initList(L);
    L.data[0] = 1;
    L.data[1] = 2;
    L.length=2;

    for (int i=0; i<L.length; i++) {
        cout << L.data[i] << " ";
    }

    cout << endl;
    ListInsert(L,1,3);


    for (int i=0; i<L.length; i++) {
        cout << L.data[i] << " ";
    }
    int e= 3;

    ListDelete(L,1,e);
    cout << endl;
    for (int i=0; i<L.length; i++) {
        cout << L.data[i] << " ";
    }

}
