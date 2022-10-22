#include<iostream> 
using namespace std;
 
typedef int ElemType;
 
#define MaxSize 50
 
typedef struct {
	ElemType data[MaxSize];
	int top;
}SqStack;
 
void InitStack(SqStack &S);
bool StackEmpty(SqStack S);
bool Push(SqStack& S, ElemType x);
bool Pop(SqStack& S, ElemType &x);
bool GetTop(SqStack S, ElemType& x);
bool DestoryStack(SqStack& S);
 
void InitStack(SqStack& S) {
	S.top = -1;
}
 
bool StackEmpty(SqStack S) {
	if (S.top == -1) {
		return true;
	}
	return false;
}
 
bool Push(SqStack& S, ElemType x) {
	if (S.top == MaxSize - 1) {
		return false;
	}
	S.data[++S.top] = x;  // 先加再放入
	return true;
}
 
bool Pop(SqStack& S, ElemType& x) {
	if (S.top == -1) return false;
	x = S.data[S.top--];  // 先使用值再减
	return true;
}
 
bool GetTop(SqStack S, ElemType& x) {
	if (S.top == -1) return false;
	x = S.data[S.top];
	return true;
}
 
void test() {
 
	SqStack S;
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