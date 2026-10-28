//定义一个线性表，顺序存储写一个插入数据的函数，并用函数调用
#include<iostream>
#include<cstdlib>
using namespace std;

#define MaxSize 50
typedef int ElemType;

//创建线性表
typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;
//初始化线性表
void InitList(SqList *&L){
    L=(SqList *)malloc(sizeof(SqList));
    L->length=0;
}
//插入数据
bool ListInsert(SqList *&L,int i,ElemType e){
    if(i<1||i>L->length+1){
        return false;
    }
    else{
        for(int j=L->length;j>=i;j--){
            L->data[j]=L->data[j-1];
        }
        L->data[i-1]=e;
        L->length++;
        return true;
    }
}
//打印线性表
void PrintList(SqList *L){
    for(int i=0;i<L->length;i++){
        cout<<L->data[i]<<endl;
    }
}
//主函数测试
int main(){
    int i,e;
    SqList *L;
    InitList(L);

    cout<<"请输入插入位置i的数值e"<<endl;
    cin>>i>>e;
    if(ListInsert(L,i,e)){
        cout<<"插入成功"<<endl;
        PrintList(L);
    }
    else{
        cout<<"插入失败"<<endl;
    }
    return 0;
}

