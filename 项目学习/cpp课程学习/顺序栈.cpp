#include <iostream>
using namespace std;
#define MaxSize 10
using ElemType = int;

typedef struct {
    ElemType data[MaxSize];
    int top;
}SqStack;
//初始化栈
void InitStack(SqStack &s) {
    S.top=-1;
}
//判断栈是否为空
bool StackEmpty(SqStack &s) {
    if (s.top==-1)
        return true;
    return false;

}

//新元素入栈
bool Push(SqStack &s, ElemType e) {
    if (s.top==MaxSize-1)//栈满 报错
        return false;
    S.top++;
    S.data[S.top]=e;
    return true;
}

//元素出栈
bool Pop(SqStack &s, ElemType &e) {
    if (s.top==-1)
        return false;
    x=S.data[s.top];
    S.top--;
    return true;
}

//读取栈顶元素
bool GetTop(SqStack &s, ElemType &e) {
    if (s.top==-1)
        return false;
    x=S.data[s.top];
    return true;
}