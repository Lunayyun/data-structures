
//week3 homework 线性表运算
#include <iostream>
#include <cstdlib>
using namespace std;

#define MaxSize 50//最大容量
typedef int ElemType;//元素类型

typedef struct{
    ElemType data[MaxSize];
    int length;//顺序表当前元素个数
}SqList;

//创建顺序表:SqList *&L指针的引用
void CreatList(SqList *&L,ElemType a[],int n){
    int i;
    int k;
    L=(SqList*)malloc (sizeof(SqList));
    while(i<n){
        L->data[k]=a[i];
        k++;
        i++;
    }
    L->length=k;
}

//初始化
void InitList(SqList *&L){
    L=(SqList*)malloc(sizeof(SqList));//分配顺序表空间
    L->length=0;
}

//销毁:回收空间
void DestroyList(SqList *&L){
    free(L);
}

//判断是否为空表
bool ListEmpty(SqList* L){
    if (L->length=0){
        return true;
    }
    else{
        return false;
    }
}

//求长度
int ListLength(SqList *L){
    return (L->length);
}

//输出
void DispList(SqList *L){
    if(L->length==0){
        return;//表为空    
    }
    else{
        for(int i=0;i<L->length;i++){
            cout<<L->data[i]<<endl;
        }
    }
}

//求某元素的值
bool GetElem(SqList*L,int i,ElemType &e){
    if (i<1||i>L->length){
        return false;
    }
    else{
        e=L->data[i];
        return true;
    }
}

//按值查找
int LocateElem(SqList* L,ElemType e){
    for(int i=0;i<L->length;i++){
        if(L->data[i]==e){
            return i+1;
        }
        else{
            return 0;
        }
    }
}

//插入
bool ListInsert(SqList *&L,int i,int e){
    if(i<1||i>L->length)
    return false;
    for(int j=L->length;j>=i;j--){
        L->data[j]=L->data[j-1];//将i后面的元素向前移
    }
    L->data[i-1]=e;
    L->length++;
}

//删除
bool ListDelete(SqList *&L,int i,int &e){
    if(i<1||i>L->length)
    return false;
    e=L->data[i-1];//将被删除的元素赋给e
    for(int j=0;j<L->length;j++){
        L->data[j]= L->data[j+1];
    }
    L->length--;
    return true;
}

// main 测试调用
int main(){
    SqList *L;//定义顺序表L
    ElemType e;//定义元素e

    //1.初始化
    InitList(L);
   
    //插入元素
    ListInsert(L,1,10);
    DispList(L);

    //判空
    ListEmpty(L);

    //求长度
    ListLength(L);

    //按位取第2个元素
    GetElem(L,2,e);

    //7.按值查找20
    LocateElem(L,20);

    //在第2位插入99
    ListInsert(L,2,99);
    DispList(L);

    //9.删除第3个元素
    ListDelete(L,3,e);
    DispList(L);

    //2.销毁
    DestroyList(L);
    return 0;
}