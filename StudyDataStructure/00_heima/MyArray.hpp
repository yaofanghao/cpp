// 11_4.cpp调用的类模板
// 需求分析：
//  class MyArray
//  private 
//         数组
//         容量
//         大小
//  public
//         构造函数（容量）
//         拷贝构造
//         operator=
//         利用下标方式访问数组中的元素
//         尾插法
//         尾删法
//         获取数组容量
//         获取数组大小
//         析构

#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray {
private:
	T* pAddr;
	int m_Capacity;
	int m_Size;

public:
	//有参构造
	MyArray(int capacity) {
		cout << "有参构造" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddr = new T[this->m_Capacity];
	}

	//拷贝构造
	MyArray(const MyArray& arr) {
		cout << "拷贝构造" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//深拷贝
		this->pAddr = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddr[i] = arr.pAddr[i];
		}
	}

	//operator=
	MyArray& operator=(const MyArray& arr) {
		cout << "深拷贝" << endl;
		//先判断原来是否有数据
		if (this->pAddr != NULL) {
			delete[] this->pAddr;
			this->pAddr = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//深拷贝
		this->pAddr = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddr[i] = arr.pAddr[i];
		}

		return *this;
	}

	//尾插法
	void Push_Back(const T& val) {
		//判断容量和大小
		if (this->m_Capacity == this->m_Size) {
			cout << "数组已经满了" << endl;
			return;
		}
		this->pAddr[this->m_Size] = val;
		this->m_Size++;
	}

	//尾删法
	void Pop_Back() {
		if (this->m_Size == 0) {
			cout << "数组为空" << endl;
			return;
		}
		this->m_Size--;
	}

	//通过下标访问	a[0] = 99
	T& operator[](int index) {
		return this->pAddr[index];
	}

	//返回容量
	int GetCapacity() {
		return this->m_Capacity;
	}

	//返回大小
	int GetSize() {
		return this->m_Size;
	}

	~MyArray() {
		if (this->pAddr != NULL) {
			//cout << "析构函数" << endl;
			delete[] this->pAddr;
			this->pAddr = NULL;
		}
	}
};
