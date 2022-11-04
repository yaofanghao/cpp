// 11_4.cpp���õ���ģ��
// ���������
//  class MyArray
//  private 
//         ����
//         ����
//         ��С
//  public
//         ���캯����������
//         ��������
//         operator=
//         �����±귽ʽ���������е�Ԫ��
//         β�巨
//         βɾ��
//         ��ȡ��������
//         ��ȡ�����С
//         ����

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
	//�вι���
	MyArray(int capacity) {
		cout << "�вι���" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddr = new T[this->m_Capacity];
	}

	//��������
	MyArray(const MyArray& arr) {
		cout << "��������" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//���
		this->pAddr = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddr[i] = arr.pAddr[i];
		}
	}

	//operator=
	MyArray& operator=(const MyArray& arr) {
		cout << "���" << endl;
		//���ж�ԭ���Ƿ�������
		if (this->pAddr != NULL) {
			delete[] this->pAddr;
			this->pAddr = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//���
		this->pAddr = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddr[i] = arr.pAddr[i];
		}

		return *this;
	}

	//β�巨
	void Push_Back(const T& val) {
		//�ж������ʹ�С
		if (this->m_Capacity == this->m_Size) {
			cout << "�����Ѿ�����" << endl;
			return;
		}
		this->pAddr[this->m_Size] = val;
		this->m_Size++;
	}

	//βɾ��
	void Pop_Back() {
		if (this->m_Size == 0) {
			cout << "����Ϊ��" << endl;
			return;
		}
		this->m_Size--;
	}

	//ͨ���±����	a[0] = 99
	T& operator[](int index) {
		return this->pAddr[index];
	}

	//��������
	int GetCapacity() {
		return this->m_Capacity;
	}

	//���ش�С
	int GetSize() {
		return this->m_Size;
	}

	~MyArray() {
		if (this->pAddr != NULL) {
			//cout << "��������" << endl;
			delete[] this->pAddr;
			this->pAddr = NULL;
		}
	}
};
