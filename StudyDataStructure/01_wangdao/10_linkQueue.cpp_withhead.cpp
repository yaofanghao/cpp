#include<iostream>
 
using namespace std;
 
typedef int ElemType;
 
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode;
 
typedef struct {
	LinkNode* front, * rear;
}LinkQueue;
 
 
void InitQueue(LinkQueue& Q);
bool QueueEmpty(LinkQueue Q);
bool EnQueue(LinkQueue& Q, ElemType x);
bool DeQueue(LinkQueue& Q, ElemType& x);
bool GetHead(LinkQueue Q, ElemType& x);
 
void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}
 
bool QueueEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) return true;
	return false;
}
 
bool EnQueue(LinkQueue& Q, ElemType x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = Q.rear->next;
	Q.rear->next = s;
	Q.rear = s;
	return true;
}
 
bool DeQueue(LinkQueue& Q, ElemType& x) {
	if (QueueEmpty(Q)) return false;
	LinkNode* q = Q.front->next;
	x = q->data;
	Q.front->next = q->next;
	if (Q.rear == q) {
		Q.rear = Q.front;
	}
	free(q);
	return true;
}
 
bool GetHead(LinkQueue Q, ElemType& x) {
	if (QueueEmpty(Q)) return false;
	x = Q.front->next->data;
	return true;
}
 
void test() {
 
	LinkQueue Q;
	InitQueue(Q);
	for (int i = 1; i <= 5; i++) {
		EnQueue(Q, i);
	}
	ElemType x;
	GetHead(Q, x);
	cout << x << endl << endl;
	while (!QueueEmpty(Q)) {
 
		DeQueue(Q, x);
		cout << x << endl;
	}
 
}
 
int main() {
		
	test();
	return 0;
}