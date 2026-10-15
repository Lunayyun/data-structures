//定义单链表，写带头结点 和不带头结点的初始化函数
#include <iostream>
#include <cstdlib>
using namespace std;

typedef int ElemType;
//定义单链表结点
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LinkNode;
//初始化带头结点的单链表
void InitList1(LinkNode *&L){
    L=(LinkNode*)malloc(sizeof(LinkNode));
    L->next=NULL;
}
//初始化不带头结点的单链表
void InitList2(LinkNode *&L){
    L=NULL;
}