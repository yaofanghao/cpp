// rear指向队尾指针后一个位置and增设tag判断
// tag用于判断队列已满or已空
#include<iostream>
 
using namespace std;
 
typedef int ElemType;
 
#define MaxSize 5
 
typedef struct {
	int front, rear;
	int tag;
	ElemType data[MaxSize];
}SqQueue;
 
void InitQueue(SqQueue& Q);
bool QueueEmpty(SqQueue Q);
bool QueueFull(SqQueue Q);
bool EnQueue(SqQueue& Q, ElemType x);
bool DeQueue(SqQueue& Q, ElemType& x);
bool GetHead(SqQueue Q, ElemType& x);
int GetSize(SqQueue Q);  //返回队列元素的个数
 
void InitQueue(SqQueue& Q) {
	Q.front = Q.rear = Q.tag = 0;
}
 
bool QueueEmpty(SqQueue Q) {
	if (Q.tag == 0 && Q.front == Q.rear) return true;
	return false;
}
 
bool QueueFull(SqQueue Q) {
	if (Q.tag == 1 && Q.front == Q.rear) return true;
	return false;
}
 
bool EnQueue(SqQueue& Q, ElemType x) {
	if (QueueFull(Q)) return false; //队满
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;
	Q.tag = 1;
	return true;
}
 
bool DeQueue(SqQueue& Q, ElemType& x) {
	if (QueueEmpty(Q)) {
		return false;
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	Q.tag = 0;
	return true;
}
 
bool GetHead(SqQueue Q, ElemType& x) {
	if (QueueEmpty(Q)) {
		return false;
	}
	x = Q.data[Q.front];
	return true;
}
 
int GetSize(SqQueue Q) {
	return (Q.rear - Q.front + MaxSize) % MaxSize;
}
 
void test() {
 
	SqQueue Q;
	InitQueue(Q);
 
 
	for (int i = 1; i <= 5; i++) {
		bool f = EnQueue(Q, i);
		if (!f) cout << i << endl;
	}
 
	ElemType x;
	DeQueue(Q, x);
	cout << x << endl;
	DeQueue(Q, x);
	cout << x << endl;
	EnQueue(Q, 1);
	EnQueue(Q, 2);
	cout << Q.front << " " << Q.rear << endl;
	if (!EnQueue(Q, 6)) {
		cout << "队列已满" << endl;
	}
 
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