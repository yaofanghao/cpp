#include<iostream>
 
using namespace std;
 
typedef int ElemType;
 
#define MaxSize 5
 
typedef struct {
	int front, rear;
	ElemType data[MaxSize];
}SqQueue;
 
void InitQueue(SqQueue &Q);
bool QueueEmpty(SqQueue Q);
bool QueueFull(SqQueue Q);
bool EnQueue(SqQueue &Q, ElemType x);
bool DeQueue(SqQueue &Q, ElemType& x);
bool GetHead(SqQueue Q, ElemType& x);
 
void InitQueue(SqQueue &Q) {
	Q.front = Q.rear = 0;
}
 
bool QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear) return true;
	return false;
}
 
bool QueueFull(SqQueue Q) {
	if (Q.rear == MaxSize) return true;
	return false;
}
 
bool EnQueue(SqQueue &Q, ElemType x) {
	if (QueueFull(Q)) return false; //队满
	Q.data[Q.rear++] = x;
	return true;
}
 
bool DeQueue(SqQueue& Q, ElemType& x) {
	if (QueueEmpty(Q)) {
		return false;
	}
	x = Q.data[Q.front++];
	return true;
}
 
bool GetHead(SqQueue Q, ElemType& x) {
	if (QueueEmpty(Q)) {
		return false;
	}
	x = Q.data[Q.front];
	return true;
}
 
void test() {
 
	SqQueue Q;
	InitQueue(Q);
	for (int i = 1; i <= 5; i++) {
		EnQueue(Q, i);
	}
	if (!EnQueue(Q, 6)) {
		cout << "队列已满" << endl;
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