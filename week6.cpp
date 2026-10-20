//顺序表定义 单链表双链表定义 双链表插入
#include <iostream>
#include<cstdlib>
using namespace std;

typedef int ElemType;
#define MaxSize 50
//顺序表定义
typedef struct{
    ElemType data[MaxSize];//值
    int length;//初始长度
}SqList;
//单链表定义
typedef struct LNode{
    ElemType data;//值
    struct LNode *next;//指针
}LinkNode;
//双链表定义
typedef struct DNode{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
}DLinkNode;
//双链表插入
bool InsertList(DLinkNode *&L,int i,ElemType e){
    int j=1;
    DLinkNode *p=L->next,*s;
    while(p!=L&&j<i-1){
        j++;
        p=p->next;
    }
    if(p==L){
        return false;
    }
    else{
        s=(DLinkNode*)malloc(sizeof(DLinkNode));
        s->data=e;
        s->next=p->next;
        s->prior=p;
        p->next=s;
        p->next->prior=s;
        return true;
    }