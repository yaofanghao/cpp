#include<iostream>
#include<algorithm>
 
using namespace std;
 
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, *LinkList;
//struct LNode*  == LinkList
//强调节点  用LNode
//强调链表  用LinkList
 
//按位查找，返回第i个元素（带头节点）
LNode* GetElem(LinkList L, int i) {
	if (i < 0) return NULL;
	int j = 0;
	LNode* p = L;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	return p;
}
 
//按值查找，找到数据域等于e的节点
LNode* LocateElem(LinkList L, int e) {
	LNode* p = L->next;
	while (p && p->data!=e) {
		p = p->next;
	}
	return p;
}
 
//统计单链表的长度
int Length(LinkList L) {
	int len = 0;
	LNode* p = L;
	while (p->next) {
		len++;
		p = p->next;
	}
	return len;
}
 
//后插操作，在节点p之后插入元素e
bool InsertNextNode(LNode *p, int e) {
	if (!p) return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (!s) return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
 
//带头节点的插入操作，在第i个位置插入元素e
bool ListInsert(LinkList& L, int i, int e) {
	if (i < 1) return false;
	LNode* p = GetElem(L, i - 1);
	if (!p) return false;
	return InsertNextNode(p, e);
}
 
//不带头节点的插入操作，在第i个位置插入元素e
bool NoHead_ListInsert(LinkList& L, int i, int e) {
	if (i < 1) return false;
	if (i == 1) {
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = L;
		L = s;
		return true;
	}
	LNode* p;
	p = L;
	int j = 1;	//当前p指向的是第几个节点，没有头节点，所以从1开始
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p) return false;
	return InsertNextNode(p, e);
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
	if ( !p || !s ) return false;
	s->next = p->next;
	p->next = s;
	swap(s->data , p->data);
	return true;
}
 
//删除位序i的节点，e是i节点的值
bool ListDelete(LinkList& L, int i, int& e) {
	if (i < 1) return false;
	LNode* p = GetElem(L, i - 1);
	if (!p || !(p->next)) return false;
	LNode* q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
	return true;
}
 
//删除指定节点P
bool DeleteNode(LNode* p) {
	if (p->next == NULL) return false;
	//下面这段代码有bug，不能删除最后一个节点，因此要是删除最后一个节点的话要重新进行操作
	LNode* q = p->next;
	p->data = q->data;
	p->next = q->next;
	free(q);
	return true;
}
 
bool InitList(LinkList& L) {
	L = (LNode* )malloc(sizeof(LNode));//分配一个头节点
	if (!L) return false;
	L->next = NULL;
	return true;
}
 
//尾插法，带头结点
LinkList List_TailInsert(LinkList& L) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	LNode* s, * r = L;	//r表示表尾指针
	int x;
	while (cin >> x) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return L;
}
 
//头插法，带头结点
LinkList List_HeadInsert(LinkList& L) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	LNode* s;
	int x;
	while (cin >> x) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
	}
	return L;
}
 
void print(LinkList L) {
	LNode* s = L;
	while (s->next!=NULL) {
		s = s->next;
		cout << s->data << " ";
	}
	cout << endl;	
}
 
int main() {
 
	LinkList L;
	//List_HeadInsert(L);
	//cout << "头插法的结果" << endl;
	//print(L);
	List_TailInsert(L);
	cout << "尾插法的结果" << endl;
	print(L);
	cout << "链表的第2个元素："<< GetElem(L, 2)->data << endl;
	cout << "链表的长度："<< Length(L) << endl;
	int e;
	ListDelete(L, 3, e);
	cout << "删除的第3个元素是：" << e << endl;
	cout << "当前的链表" << endl;
	print(L);
	ListInsert(L, 3, e);
	cout << "插入的第3个元素是：" << e << endl;
	cout << "当前的链表" << endl;
	print(L);
	LNode* s = LocateElem(L, 5);
	
	return 0;
}