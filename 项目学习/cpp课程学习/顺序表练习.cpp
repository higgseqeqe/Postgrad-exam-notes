#define byte win_byte_avoid_conflict
#include <windows.h>
#undef byte
#include <iostream>
using namespace std;

#define MAXSIZE 10


typedef struct {
    int data[MAXSIZE];
    int length;
}SqList;

void initList(SqList &L) {
    for (int i=0; i<MAXSIZE; i++)
        L.data[i]=0;
    L.length=0;
}

//查找操作
int GetElem(SqList &L, int i) {
    return L.data[i-1];
}

//插入操作
bool ListInsert(SqList &L, int i, int e) {
    if (i<1||i>L.length+1)
        return false;
    if (L.length>=MAXSIZE)
        return false;
    for (int j=L.length; j>=i; j--)
        L.data[j]=L.data[j-1];
    L.data[i-1]=e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i, int &e) {
    if (i<1||i>L.length)
        return false;
    e =L.data[i-1];
    for (int j=i; j<L.length; j++)
        L.data[j-1]=L.data[j];
    L.length--;
    return true;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SqList L;
    initList(L);
    L.data[0]=1;
    L.data[1]=2;
    L.data[2]=3;
    L.data[3]=4;
    L.data[4]=5;
    L.length=5;
    for (int i=0; i<L.length; i++)
        cout << L.data[i] << " ";
    cout << endl;
    ListInsert(L,3,99);
    for (int i=0; i<L.length; i++)
        cout << L.data[i] << " ";
    cout << endl;
    int e =0;
    ListDelete(L,3,e);
    for (int i=0; i<L.length; i++)
        cout << L.data[i] << " ";
    cout << endl;

    cout << e << endl;

    //查找
    int num =1;
    int num2 =GetElem(L,num);
    cout << "查找到的数字为" <<num2 << " ";

}