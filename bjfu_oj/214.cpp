#include<iostream>
#include<string>
#include<iomanip>  //保留两位小数必须要用到的头文件
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef struct{
	string no;
	string name;
	double price;
}Book;
typedef struct LNode{
	Book book;
	struct LNode *next; 
}LNode, *LinkList;

int Init(LinkList L)
{
	
	L->next = NULL;
	return OK;
}
int Input(LinkList L)
{
	LNode *p;
	p = L;
	string no, name;
	float price;
	while(cin>>no>>name>>price)
	{
		if(no=="0"&&name=="0"&&price==0)
			break;
		else
		{
			LinkList q = new LNode;
			q->book.no = no;
			q->book.name = name;
			q->book.price = price;
			p->next = q;
			p = q;
		}
	}
	return OK;
}
int Length(LinkList L)
{
	int length = 0;
	LNode *p = L;
	while(p->next)
	{
		length++;
		p = p->next;
	}
	cout << length << endl;
	return OK;
}
int Output(LinkList L)
{
	LNode *p = L;  //p指向头结点
	while(p->next)
	{
		cout << p->next->book.no << " " << p->next->book.name << " " << fixed <<  setprecision(2) << p->next->book.price << endl;
		p = p->next;
	}
	return OK;
}

int main()
{
	LinkList L;
	L = new LNode;
	Init(L);
	Input(L);
	Length(L);
	Output(L);
	return 0;
}
