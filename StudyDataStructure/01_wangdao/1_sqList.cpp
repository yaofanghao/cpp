// p7-11 顺序表 sequence list

#include<stdlib.h>
#include<stdio.h>
#include<iostream> 
using namespace std; 
#define InitSize 10  //定义最大长度 
 
// 静态分配
//typedef struct {
//	int data[InitList];
//	int length;
//}SqlList;
 
//动态分配
typedef struct {
	int *data;
	int length;	//当前长度
	int MaxSize;//最大长度
}SqlList;
 
//初始化顺序表
void InitList(SqlList &L) {
	L.data = (int *)malloc(InitSize * sizeof(int));
	L.length = 0;
	L.MaxSize = InitSize;
}
 
//增加顺序表的长度
void IncreaseSize(SqlList &L, int len) {
	int* p = L.data;
	L.data = (int*)malloc((L.MaxSize + len) * sizeof(int));
	for (int i = 0; i < L.length; i++) {
		L.data[i] = p[i];
	}
	L.MaxSize += len;
	free(p);
}
 
//插入元素，在位序i的位置插入元素e
bool ListInsert(SqlList& L, int i, int e) {
	if (i<1 || i>L.length + 1) return false;	//i的范围是否有效
	if (L.length >= L.MaxSize) return false;	//当前存储空间已满，不能插入
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}
 
//删除操作，删除位序i个位置上的元素,e是删除的元素
bool ListDelete(SqlList& L, int i, int& e) {
	if (i<1 || i>L.length) return false;
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++) {
		L.data[j-1] = L.data[j];
	}
	L.length--;
	return true; 
}
 
//按位查找  返回位序i的元素
int GetElem(SqlList L, int i) {
	if (i<1 || i>L.length) return -1;
	return L.data[i - 1];
}
 
//查找第一个元素值等于e的元素，并返回其位序
int LocateElem(SqlList L, int e) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) return i + 1;
	}
	return -1;
}
 
//删除值位于s和t之间的数
bool Delete_s_t(SqlList& L, int s, int t) {
	if (L.length == 0 || s >= t) return false;
	int k = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i]<s || L.data[i]>t) {
			L.data[k++] = L.data[i];
		}
	}
	L.length = k;
	return true;
}
 
int main() {
		
	SqlList L;
	InitList(L);
	ListInsert(L, 1, 1);
	ListInsert(L, 2, 6);
	ListInsert(L, 3, 3);
	ListInsert(L, 4, 8);
	ListInsert(L, 5, 2);
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << " ";
	}
	cout << endl;
	Delete_s_t(L, 2, 3);
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << " ";
	}
	cout << endl;
 
	return 0;
}