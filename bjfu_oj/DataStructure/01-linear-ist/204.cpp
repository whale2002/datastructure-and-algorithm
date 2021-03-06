#include<iostream>
#include<string>
#include<iomanip>  //保留两位小数必须要用到的头文件
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

typedef struct{
	string no;
	string name;
	double price;
}Book;
typedef struct{
	Book *elem;
	int length;
}SqList;

int Init(SqList &L)
{
	L.elem = new Book[MAXSIZE];
	if(!L.elem)   exit(OVERFLOW);  //异常处理
	L.length = 0;
	return OK;
}
int Input(SqList &L)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		cin >> L.elem[i].no >> L.elem[i].name >> L.elem[i].price;
		if(L.elem[i].no=="0" && L.elem[i].name=="0" && L.elem[i].price==0)
			return OK;
		else 
			L.length++;
	}
	return OK;
}
int Output(SqList &L)
{
	cout << L.length << endl;
	for (int i = 0; i < L.length; ++i)
		cout << L.elem[i].no << " " << L.elem[i].name << " " << fixed << setprecision(2)
		<< L.elem[i].price << endl;
	return OK;
}

int main()
{
	SqList L;
	Init(L);
	Input(L);
	Output(L);
	return 0;
}

