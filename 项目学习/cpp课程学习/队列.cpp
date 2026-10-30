#include <iostream>
using namespace std;
using ElemType=int;
#define Maxsize 10

typedef struct {
    ElemType data[Maxsize];
    int front,rear;  //队头指针和队尾指针
}SqQueue;

void InitSqQueue(SqQueue &q) {
    q.rear=q.front=0;
}
bool QueueEmpty(SqQueue q) {
    return q.rear==q.front;
}

bool EnQueue(SqQueue &q,ElemType x) {
    if ((Q.rear+1)%MaxSize ==Q.front) //队满判断
        return false;
    q.data[q.rear]=x; //将X插入队尾
    q.rear=(q.rear+1)%Maxsize;//将队尾指针后移
    return true;
}