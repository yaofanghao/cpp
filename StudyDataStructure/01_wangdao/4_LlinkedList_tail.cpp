#include<iostream>
#include<algorithm>
 
using namespace std;
 
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;
//struct LNode*  == LinkList
//强调节点  用LNode
//强调链表  用LinkList
 
bool InitList(LinkList& L) {
	L = (LNode*)malloc(sizeof(LNode));//分配一个头节点
	if (L == NULL) return false;
	L->next = L;
	return true;
}
 
//按位查找，返回第i个元素（带头节点）
LNode* GetElem(LinkList L, int i) {
	if (i < 0) return NULL;
	if (i == 0) return L->next;
	int j = 1;
	LNode* p = L->next->next;
	while (p != L->next && j < i) {
		p = p->next;
		j++;
	}
	if (p == L->next) return NULL;
	return p;
}
 
//按值查找，找到数据域等于e的节点
LNode* LocateElem(LinkList L, int e) {
	LNode* p = L->next->next;
	while (p != L->next && p->data != e) {
		p = p->next;
	}
	if (p->data == e) return p;
	return NULL;
}
 
//统计单链表的长度
int Length(LinkList L) {
	int len = 0;
	LNode* p = L;
	while (p->next != L) {
		len++;
		p = p->next;
	}
	return len;
}
 
//后插操作，在节点p之后插入元素e
bool InsertNextNode(LinkList& L, LNode* p, int e) {
	if (!p) return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (!s) return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	if (p == L) L = s;
	return true;
}
 
//带头节点的插入操作，在第i个位置插入元素e
bool ListInsert(LinkList& L, int i, int e) {
	if (i < 1) return false;
	LNode* p = GetElem(L, i - 1);
	if (!p) return false;
	return InsertNextNode(L, p, e);
}
 
 
//前插操作，在p节点前插入元素e
bool InsertPriorNode(LNode* p, int e) {
	if (!p) return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (!s) return false;
	s->next = p->next;
	p->next = s;
	s->data = p->data;
	p->data = e;
	return true;
}
 
//前插操作，在节点p之前插入节点s
bool InsertPriorNode(LNode* p, LNode* s) {
	if (!p || !s) return false;
	s->next = p->next;
	p->next = s;
	swap(s->data, p->data);
	return true;
}
 
//删除位序i的节点，e是i节点的值
bool ListDelete(LinkList& L, int i, int& e) {
	if (i < 1) return false;
	LNode* p = GetElem(L, i - 1);
	if (p == NULL || p == L) return false;
	if (p->next == L) {
		L = p;
	}
	LNode* q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
	return true;
}
 
 
//删除指定节点P
bool DeleteNode(LinkList& L, LNode* p) {
	LNode* q = p->next;
	p->data = q->data;
	p->next = q->next;
 
	if (L == p) {		//尾节点
		q = p;
		while (q->next != p) {
			q = q->next;
		}
		L = q;
	}
	//free(q)；   不能这样写，因为指针之间的赋值是指向同一块区域，就比如L和q就是指向相同的区域
	return true;
}
 
//尾插法，带头结点
LinkList List_TailInsert(LinkList& L) {
	InitList(L);
	LNode* s, * r = L;	//r表示表尾指针
	int x;
	while (cin >> x) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
	}
	r->next = L;
	L = r;
	return L;
}
 
//头插法，带头结点
LinkList List_HeadInsert(LinkList& L) {
	InitList(L);
	LNode* s, * r = L;
	int x;
	bool isFirst = true;
	while (cin >> x) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		if (isFirst) {
			r = s;
			isFirst = false;
		}
	}
	r->next = L;
	L = r;
	return r;
}
 
bool Empty(LinkList L) {
	if (L->next == L) {
		return true;
	}
	return false;
}
 
//判断是否为表尾节点
bool isTail(LinkList L, LNode* p) {
	if (p == L) return true;
	return false;
}
 
void print(LinkList L) {
	LNode* s = L->next->next;
	while (s != L->next) {
 
		cout << s->data << " ";
		s = s->next;
	}
	cout << endl;
}
 
int main() {
 
	LinkList L;
	//List_HeadInsert(L);
	//cout << "头插法的结果" << endl;
	//print(L);
	List_TailInsert(L);
	cout << L->data << endl;
	cout << "尾插法的结果" << endl;
	print(L);
	cout << "链表的第1个元素：" << GetElem(L, 1)->data << endl;
	cout << "链表的第5个元素：" << GetElem(L, 5)->data << endl;
	cout << "链表的长度：" << Length(L) << endl;
	int e;
 
	ListDelete(L, 5, e);
	cout << "删除的第5个元素是：" << e << endl;
	cout << "当前的链表" << endl;
	print(L);
	ListInsert(L, 5, e);
	cout << "插入的第5个元素是：" << e << endl;
	cout << "当前的链表" << endl;
	print(L);
 
	ListDelete(L, 1, e);
	cout << "删除的第1个元素是：" << e << endl;
	cout << "当前的链表" << endl;
	print(L);
	ListInsert(L, 1, e);
	cout << "插入的第1个元素是：" << e << endl;
	cout << "当前的链表" << endl;
	print(L);
 
	LNode* s = LocateElem(L, 5);
	DeleteNode(L, s);
	print(L);
 
	return 0;
}
/*
输入样例：
1 2 3 4 5
*/