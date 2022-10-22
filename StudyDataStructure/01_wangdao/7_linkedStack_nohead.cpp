#include<iostream>
 
using namespace std;
 
typedef int ElemType;
 
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}*LiStack,LinkNode;
 
 
bool InitStack(LiStack& S);
bool StackEmpty(LiStack S);
bool Push(LiStack& S, ElemType x);
bool Pop(LiStack& S, ElemType& x);
bool GetTop(LiStack S, ElemType& x);
bool DestoryStack(LiStack& S);
 
bool InitStack(LiStack& S) {
	S = (LiStack)malloc(sizeof(LinkNode));
	if (S == NULL) return false;
	S->next = NULL;
	return true;
}
 
bool StackEmpty(LiStack S) {
	if (S->next == NULL) return true;
	return false;
}
 
bool Push(LiStack& S, ElemType x) {
	LinkNode* p;
	p = (LinkNode*)malloc(sizeof(LinkNode));
	if (p == NULL) return false;
	p->data = x;
	p->next = S->next;
	S->next = p;
	return true;
}
 
bool Pop(LiStack& S, ElemType& x) {
	if (StackEmpty(S)) return false;
	LinkNode* p = S->next;
	S->next = p->next;
	x = p->data;
	free(p);
	return true;
}
 
bool GetTop(LiStack S, ElemType& x) {
	if (StackEmpty(S)) return false;
	x = S->next->data;
	return true;
}
 
bool DestoryStack(LiStack& S) {
	while (S->next != NULL) {
		LinkNode* p = S->next;
		S->next = p->next;
		free(p);
	}
	free(S);
	return true;
}
 
void test() {
 
	LiStack S;
	InitStack(S);
	for (int i = 0; i <= 5; i++) {
		Push(S, i);
	}
	ElemType x;
	GetTop(S, x);
	cout << x << endl;
	while (!StackEmpty(S)) {
		Pop(S, x);
		cout << x << endl;
	}
}
 
int main() {
		
	test();
	return 0;
}