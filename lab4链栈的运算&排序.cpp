//1.编写一个程序，实现链栈的各种基本运算的算法，具体包括以下功能。（验证性实验）
//初始化链栈q
//判断链栈q是否非空
//一次入栈元素a，b，c
//出栈一个元素，输出该元素
//依次入栈元素的d、e、f
//输出出栈序列
//以上功能函数定义在一个cpp或者.h文件中，主函数所在的cpp通过引用方式引入
#include<iostream>
#include<cstdlib>
using namespace std;

typedef char ElemType;
//定义
typedef struct linknode {
	ElemType data;
	struct linknode *next;
}LinkStNode;
//初始化
void InitStack(LinkStNode *&s) {
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;
}
//判断栈是否为空
bool StackEmpty(LinkStNode *s) {
	return (s->next == NULL);
}
//入栈
void Push(LinkStNode *&s, ElemType e) {
	LinkStNode *p;
	p = (LinkStNode*)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
}
//出栈
bool Pop(LinkStNode *&s, ElemType &e) {
	LinkStNode *p;
	if (s->next == NULL)
		return false;
	else {
		p = s->next;
		e = p->data;
		s->next = p->next;
		free(p);
		return true;
	}
}
//打印栈栈顶到栈底
void PrintStack(LinkStNode *s) {
	LinkStNode *p = s->next;
	while (p != NULL) {
		cout << p->data << endl;
		p = p->next;
	}
} 

//对字符栈排序：使栈底到栈顶为升序
void SortStack(LinkStNode *&s){
	LinkStNode *temp;//定义一个临时栈
	InitStack(temp);
	char x;//取出的元素x
	int step=1;
	while(StackEmpty(s)==false){
		Pop(s,x);//取出s中的元素x
		while(StackEmpty(temp)==false){
			char top;
			Pop(temp,top);//取出temp中的栈顶元素top
			if(top<x){//如果top<x，则将top放回s中
				Push(s,top);
			}
			else{//如果top>=x，则将top放回temp中，并退出循环
				Push(temp,top);
				break;
			}
		}
		Push(temp,x);//将x放入temp中
		cout<<"第"<<step<<"步排序结果为："<<endl;
		PrintStack(temp);
		step++;
	}
	//将temp中的所有元素（顶到底：大到小）放回s中，变为小到大
	while(StackEmpty(temp)==false){
		Pop(temp,x);
		Push(s,x);
	}
	free(temp);//释放临时栈的空间
}
int main() {
	LinkStNode *q;
	InitStack(q);
	// 判断链栈是否非空
    cout << "链栈是否非空：" << (StackEmpty(q) ? "是" : "否") << endl;
	Push(q, 'a');
	Push(q, 'b');
	Push(q, 'c');
	cout << "入栈abc："<<endl;
	PrintStack(q);

	ElemType e;
    if (Pop(q, e)) {
        cout << "出栈元素：" << e << endl;
    }

	Push(q, 'd');
	Push(q, 'e');
	Push(q, 'f');
	cout << "入栈def："<<endl;
	PrintStack(q);

	SortStack(q);

    cout << "排序后（栈顶到栈底）：" << endl;
    PrintStack(q);
	return 0;
}