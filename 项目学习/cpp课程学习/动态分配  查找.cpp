#include <iostream>
using namespace std;
#define byte win_byte_avoid_conflict
#include <windows.h>
#undef byte
//动态分配
#define InitSize 10

using ElemType =int;
typedef struct {
    ElemType *data; //指针动态分配的表
    int Maxsize;  //最大容量
    int length;  //长度
}Sqlist;

void InitList(Sqlist &L) {
    L.data = new ElemType[InitSize]{}; //初始化表里的元素为 0
    L.Maxsize = InitSize; //定义最大容量为 10
    L.length = 0;  //初始化长度为0
}

ElemType GetElem(Sqlist &L, int i) {
    return L.data[i-1];//查找第i个元素的数据
}
// 按值查找
int LocateElem(Sqlist L, ElemType e) {
    for (int i=0;i<L.length;i++) {
        if (L.data[i] == e)
            return i+1;  //数组下标为元素值等于e，返回其为序i+1
    }
}

void IncreaseSize(Sqlist &L,int len) {
    ElemType *p = L.data;
    L.data = new ElemType[L.Maxsize + len]{};  //申请一块新的内存空间
    for (int i = 0; i < L.length; ++i) {
        L.data[i] = p[i];
    }
    L.Maxsize += len;
    delete[] p; //顺序表扩容
}
int main() {
    SetConsoleOutputCP(CP_UTF8);
    Sqlist L{};  //声明一个表
    InitList(L); //初始化

    L.data[0] = 100; //元素赋值
    L.length=10; //设置长度

    L.data[1]=5;
    L.data[2]=8;
    L.data[3]=4;
    L.data[4]=9;

    int num1=9;
    int i=LocateElem(L,num1);
    cout<< "查找到的下标为" <<i<<endl;
    return 0;
}