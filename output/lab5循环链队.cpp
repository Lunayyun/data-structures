//2.编写一个程序，按升序对一个存有数值型数据的循环链队列进行排序。（设计性实验）
#include<iostream>
#include<cstdlib>
using namespace std;

typedef int ElemType;

//循环链队定义:只需要尾指针rear
typedef struct qnode{
    ElemType data;
    struct qnode *next;
}DataNode;
typedef struct{
    DataNode *rear;
}LinkQuNode;
//初始化循环链队
void InitQueue(LinkQuNode *&q){
    q=(LinkQuNode*)malloc(sizeof(LinkQuNode));
    q->rear=NULL;
}
//判空
bool QueueEmpty(LinkQuNode *q){
    return(q->rear==NULL);
}
//入队:从队尾插入
bool enQueue(LinkQuNode *&q,ElemType e){
    DataNode *p;
    p=(DataNode*)malloc(sizeof(DataNode));
    p->data=e;
    if(q->rear==NULL){//队空
        p->next=p;//p的next指向p
        q->rear=p;//队尾rear指向p
    }
    else{//队不空
        p->next=q->rear->next;//p的next指向队头
        q->rear->next=p;//原队尾结点的next指向p
        q->rear=p;//rear指向p
    }
    return true;
}
//出队：从队头删除
bool deQueue(LinkQuNode *&q,ElemType &e){
    DataNode *p;
    if(q->rear==NULL){//队空
        return false;
    }
    p=q->rear->next;//队头
    if(q->rear==q->rear->next){//队中只有一个结点
        q->rear=NULL;
    }
    else{//队中有多个结点
        p->next=q->rear->next;
    }
    e=p->data;
    free(p);
    return true;
}
//打印队列
void PrintQueue(LinkQuNode *q){
    DataNode *p;
    p=q->rear->next;//队头
    while(p!=q->rear){
        cout<<p->data<<endl;
        p=p->next;
    }
}
//排序循环链队
void SortQueue(LinkQuNode *&q){
    int n=1;
    for(DataNode *p=q->rear->next;p!=q->rear;p=p->next){
        n++;
    }
    //冒泡排序：相邻两个元素两两比较，逆序就交换
    for(int i=0;i<n-1;i++){//外层循环控制轮数:N个元素只用排N-1轮,每轮都从前往后依次比较相邻的两个，冒出一个最大值在末尾
        DataNode *p=q->rear->next;//每轮从队头开始比较
        for(int j=0;j<n-1-i;j++){//内层循环控制相邻比较：已经冒出的数（在末尾）不再参与比较
            DataNode *nextNode=p->next;//和相邻的下一个结点比较
            if (p->data > nextNode->data) {
                ElemType temp = p->data;//用临时变量存储，交换两个结点的值
                p->data = nextNode->data;
                nextNode->data = temp;
            }
            p=p->next;//指针后移，继续比较下一个结点
        }

    }

}

int main(){
    LinkQuNode *q;
    ElemType e;
    InitQueue(q);
    cout<<"循环链队是否非空："<<(QueueEmpty(q)?"是":"否")<<endl;
    enQueue(q,3);
    enQueue(q,1);
    enQueue(q,4);
    enQueue(q,2);
    cout<<"排序前的循环链队为："<<endl;
    PrintQueue(q);
    SortQueue(q);
    cout<<"排序后的循环链队为："<<endl;
    PrintQueue(q);
    return 0;
}