//1.编写一个程序，实现顺序队列的各种基本运算的算法，具体包括以下功能。（验证性实验）
//初始化顺序队列q
//判断顺序队列q是否非空
//一次入队元素1，2，3
//出队一个元素，输出该元素
//依次入队元素的4、5、6
//输出出队序列
#include<iostream>
#include<cstdlib>
using namespace std;

typedef int ElemType;
#define MaxSize 50
//顺序队列定义
typedef struct{
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;
//初始化顺序队列
void InitQueue(SqQueue *&q){
    q=(SqQueue*)malloc(sizeof(SqQueue));
    q->front=q->rear=0;
}
//判空
bool QueueEmpty(SqQueue *q){
    return(q->front==q->rear);
}
//入队
bool enQueue(SqQueue *&q,ElemType e){
    if(q->rear==MaxSize-1){
        return false;
    }
    else{
        q->rear++;
        q->data[q->rear]=e;
        return true;
    }
}
//出队
bool deQueue(SqQueue *&q,ElemType &e){
    if(q->front==q->rear){
        return false;
    }
    else{
        q->front++;
        e=q->data[q->front];
        return true;
    }
}
//打印队列
void PrintQueue(SqQueue *q){
    for(int i=q->front;i<q->rear;i++){
        cout<<q->data[i+1]<<endl;
    }
}

int main(){
    SqQueue *q;
    ElemType e;
    InitQueue(q);
    cout<<"顺序队列是否非空："<<(QueueEmpty(q)?"是":"否")<<endl;
    enQueue(q,1);
    enQueue(q,2);
    enQueue(q,3);
    //出队
    deQueue(q,e);
    cout<<"出队元素为："<<e<<endl;
    enQueue(q,4);
    enQueue(q,5);
    enQueue(q,6);
    cout<<"出队序列为：";
    PrintQueue(q);
    return 0;
}