#include<iostream>
 
using namespace std;
 
typedef int ElemType;
 
#define MaxSize 10
 
typedef struct {
	ElemType data[MaxSize];
	int top0;
	int top1;
}ShStack;
 
void InitStack(ShStack& S);
bool StackEmpty(ShStack S);
bool StackFull(ShStack S);	//判断栈是否满了
bool Push0(ShStack& S, ElemType x);
bool Push1(ShStack& S, ElemType x);
bool Pop0(ShStack& S, ElemType& x);
bool Pop1(ShStack& S, ElemType& x);
bool GetTop0(ShStack S, ElemType& x);
bool GetTop1(ShStack S, ElemType& x);
bool DestoryStack0(ShStack& S);
bool DestoryStack1(ShStack& S);
 
void InitStack(ShStack& S) {
	S.top0 = -1;
	S.top1 = MaxSize;
}
 
bool StackEmpty(ShStack S) {
	if (S.top0 == -1 && S.top1 == MaxSize) {
		return true;
	}
	return false;
}
 
bool StackFull(ShStack S) {
	if (S.top0 + 1 == S.top1) return true;
	return false;
}
 
bool Push0(ShStack& S, ElemType x) {
	if (StackFull(S) ){
		return false;
	}
	S.data[++S.top0] = x;
	return true;
}
 
bool Push1(ShStack& S, ElemType x) {
	if (StackFull(S) ){
		return false;
	}
	S.data[--S.top1] = x;
	return true;
}
 
bool Pop0(ShStack& S, ElemType& x) {
	if (S.top0 == -1) return false;
	x = S.data[S.top0--];
	return true;
}
 
bool Pop1(ShStack& S, ElemType& x) {
	if (S.top1 == MaxSize) return false;
	x = S.data[S.top1++];
	return true;
}
 
bool GetTop0(ShStack S, ElemType& x) {
	if (S.top0 == -1) return false;
	x = S.data[S.top0];
	return true;
}
 
bool GetTop1(ShStack S, ElemType& x) {
	if (S.top1 == MaxSize) return false;
	x = S.data[S.top1];
	return true;
}
 
void test() {
 
	ShStack S;
	InitStack(S);
	for (int i = 1; i <= 5; i++) {
		Push0(S, i);
	}
	for (int i = 1; i <= 5; i++) {
		Push1(S, i);
	}
	ElemType x;
	GetTop0(S, x);
	cout << x << endl;
 
	GetTop1(S, x);
	cout << x << endl;
 
	bool f = Push0(S, 6);
	if (f) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
 
	f = Push1(S, 6);
	if (f) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
 
	while (Pop0(S,x)) {
		cout << x << endl;
	}
	while (Pop1(S, x)) {
		cout << x << endl;
	}
}
 
int main() {
 
	test();
	return 0;
}