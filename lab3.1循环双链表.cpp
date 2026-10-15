#include<iostream>
#include<cstdlib>
using namespace std;
//实验1.编写一个程序，实现循环双链表的存储结构及各种基本运算，具体包括以下功能。（验证性实验）
//初始化循环链表L
//依次采用尾插法插入元素a,b,c,d,e
//输出循环链表L
//输出循环链表L的长度
//判定循环链表L是否为空
//输出循环链表L的第3个元素
//输出元素a的位置
//在第4个位置插入元素f
//删除第3个位置的元素并输出
//以上功能函数定义在一个cpp或者.h文件中，主函数所在的cpp通过引用方式引入
typedef char ElemType;

// 双向链表结点
typedef struct DNode {
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
} DLinkNode;

// 初始化循环双链表
void InitDLinkNode(DLinkNode *&L) {
    L = (DLinkNode *)malloc(sizeof(DLinkNode));// 创建头结点
    L->prior = L;
    L->next = L;
}
// 尾插法创建循环双链表，元素顺序为 abcde
void CreatListR(DLinkNode *&L, ElemType a[],int n) {
	DLinkNode *s,*r;//初始化过就不用在malloc了
	r= L;
	for (int i = 0; i < n; i++) {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));//创建s的内存空间
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = L;
	L->prior = r;
}
// 输出循环双链表
void DispList(DLinkNode *L) {
	DLinkNode *p = L->next;
	while (p != L) {
		cout << p->data;
		p = p->next;
	}
}
// 返回循环双链表长度
int ListLength(DLinkNode *L) {
	int sum = 0;
	DLinkNode *p = L->next;
	while (p != L) {
		sum++;
		p = p->next;
	}
	return sum;
}
// 判断循环双链表是否为空
bool ListEmpty(DLinkNode *L) {
    return (L->next == L);
}

// 按位查找元素
bool GetElem(DLinkNode *L, int i, ElemType &e) {
    int j = 0;
    DLinkNode *p = L;
    while (j < i && p != L) {
        j++;
        p = p->next;
    }//j=i时跳出循环
    if (p == L) {
        return false;
    } else {
        e = p->data;
        return true;
    }
}

// 按值查找元素，返回位置
int LocateElem(DLinkNode *L, ElemType e) {
    int i =1;
    DLinkNode *p = L->next;
    while (p != L && p->data != e) {
        i++;
        p = p->next;
    }
    if (p == L) {
        return 0;
    } else {
        return i;
    }
}

// 在第 i 个位置插入元素 e
bool ListInsert(DLinkNode *&L, int i, ElemType e) {
    int j = 0;
    DLinkNode *p = L, *s;
    while (p != L && j < i - 1) {//找到第i-1个结点
        j++;
        p = p->next;
    }
    if (p == L) {
        return false;
    } else {
        s = (DLinkNode *)malloc(sizeof(DLinkNode));
        s->data = e;
        s->next = p->next;
        p->next->prior = s;
        p->next = s;
        s->prior = p;
        return true;
    }
}

// 删除第 i 个元素
bool DeleteList(DLinkNode *&L, int i, ElemType &e) {
    int j = 0;//用于遍历到i-1
    DLinkNode *p = L, *s;
    while (j < i - 1 && p != L) {
        j++;
        p = p->next;
    }
    if (p == L) {
        return false;
    } else {
        s = p->next;
        e = s->data;
        p->next = s->next;
        s->next->prior = p;
		free(s);
        return true;
    }
}

int main() {
    DLinkNode *L;
    ElemType a[] = { 'a', 'b', 'c', 'd', 'e' };
    ElemType e;
    InitDLinkNode(L);
    CreatListR(L, a, 5);
    cout << "循环双链表为:";
    DispList(L);
    cout << " 长度为" << ListLength(L) << endl;
    cout << "是否为空：" << (ListEmpty(L) ? "是" : "否") << endl;

    if (GetElem(L, 3, e)) {
        cout << "第3个元素为:" << e << endl;
    }

    cout << "元素a的位置:" << LocateElem(L, 'a') << endl;

    if (ListInsert(L, 4, 'f')) {
        cout << "插入'f'后，循环双链表为：";
        DispList(L);
        cout << endl;
    }

    if (DeleteList(L, 3, e)) {
        cout << "删除第3个元素后,循环双链表为：";
        DispList(L);
        cout << endl;
        cout << "删除的元素为：" << e << endl;
    }
    return 0;
}
