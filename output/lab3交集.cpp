// 实验2.编写一个程序，基于单链表实现集合的交运算，假设集合A={c a e h},集合B={f h b g d a},将结果输出到屏幕上。（设计性实验）
#include<iostream>
#include<cstdlib>
using namespace std;

typedef char ElemType;

// 单链表结点
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LinkNode;

// 初始化
void InitList(LinkNode *&L) {
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
}

// 获取单链表长度
int ListLength(LinkNode *L) {
    int sum = 0;
    LinkNode *p = L->next;
    while (p != NULL) {
        sum++;
        p = p->next;
    }
    return sum;
}

// 按值查找元素
bool LocateElem(LinkNode *L, ElemType e) {
    LinkNode *p = L->next;
    while (p != NULL) {
        if (p->data == e) {
            return true;
        }
        p = p->next;
    }
    return false;
}

// 按位查找元素
bool GetElem(LinkNode *L, int i, ElemType &e) {
    int j = 1;
    LinkNode *p = L->next;
    while (j < i && p != NULL) {
        j++;
        p = p->next;
    }
    if (p == NULL) {
        return false;
    } else {
        e = p->data;
        return true;
    }
}

// 在第 i 个位置插入元素 e
bool ListInsert(LinkNode *&L, int i, ElemType e) {
    int j = 0;
    LinkNode *p = L, *s;

    while (p != NULL && j < i - 1) {
        j++;
        p = p->next;
    }
    if (p == NULL) {
        return false;
    } else {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }
}
//交集运算：它遍历 A 的每个元素
//对每个元素调用 LocateElem(B, e)
//如果在 B 中出现，则把它插入到 C 中
//这里用 ListInsert(C, ListLength(C)+1, e) 表示尾插到结果链表里
void Intersection(LinkNode *A, LinkNode *B, LinkNode *&C) {
	int i;
	ElemType e;
	InitList(C);

	for(i=1;i<=ListLength(A);i++){
		GetElem(A,i,e);
		if(LocateElem(B,e)){
			ListInsert(C,ListLength(C)+1,e);
		}
	}
}
// 打印链表
void PrintList(LinkNode *L)
{
    LinkNode *p = L->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 销毁链表，释放内存
void DestroyList(LinkNode *&L) {
    LinkNode *p = L, *q;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    L = NULL;
}

int main() {
    LinkNode *A, *B, *C;
    ElemType a[] = { 'c', 'a', 'e', 'h' };
    ElemType b[] = { 'f', 'h', 'b', 'g', 'd', 'a' };

    InitList(A);
    InitList(B);

    // 把数组元素依次尾插进入链表A
    for (int i = 0; i < 4; i++) {
        ListInsert(A, i + 1, a[i]);
    }

    // 把数组元素依次尾插进入链表B
    for (int i = 0; i < 6; i++) {
        ListInsert(B, i + 1, b[i]);
    }

    cout << "集合A：";
    PrintList(A);

    cout << "集合B：";
    PrintList(B);

    Intersection(A, B, C);

    cout << "集合A与集合B的交集为：";
    PrintList(C);

    DestroyList(A);
    DestroyList(B);
    DestroyList(C);

    return 0;
}


