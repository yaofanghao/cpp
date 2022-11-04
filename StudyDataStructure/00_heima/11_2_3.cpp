// p182-184 ��ģ�尸�����������װ
// ʵ��ͨ������
// ���������MyArray.hpp
#include <iostream>
using namespace std;
#include <string>
#include  "MyArray.hpp"

void printArray(MyArray<int>& arr) {
	for (int i = 0; i < arr.GetSize(); i++) {
		cout << arr[i] << endl;
	}
}

void test01() {
	MyArray<int>arr(5);

	//���ú�β�巨
	for (int i = 0; i < 5; i++) {
		arr.Push_Back(i);
	}

	cout << "arr�Ĵ�ӡ���Ϊ��" << endl;
	
	printArray(arr);

	cout << "arr��������" << arr.GetCapacity() << endl;
	cout << "arr�Ĵ�С��" << arr.GetSize() << endl;

	MyArray <int>arr1(arr);
	printArray(arr1);
	//βɾ
	arr1.Pop_Back();
	cout << "arr1βɾ��" << endl;
	cout << "arr1��������" << arr1.GetCapacity() << endl;
	cout << "arr1�Ĵ�С��" << arr1.GetSize() << endl;

}

//�����Զ�����������
class Person {
public:
	Person(){}
	Person(string name, int age) {
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;
};

void PrintPersonArray(MyArray<Person>& arr) {
	for (int i = 0; i < arr.GetSize(); i++) {
		cout << "������" << arr[i].m_name << "\t���䣺" << arr[i].m_age << endl;
	}
}

void test02() {
	MyArray<Person>arr(10);

	Person p1("�����", 555);
	Person p2("�캢��", 555);
	Person p3("���˽�", 555);
	Person p4("������", 555);
	Person p5("ɳ��", 555);
	Person p6("�׹Ǿ�", 555);
	Person p7("Ů����", 555);
	Person p8("������", 555);
	Person p9("ʷ�ٷ�", 555);
	Person p10("�ʵ���", 555);

	//�����ݲ�������
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	arr.Push_Back(p6);
	arr.Push_Back(p7);
	arr.Push_Back(p8);
	arr.Push_Back(p9);
	arr.Push_Back(p10);

	PrintPersonArray(arr);
	cout << "arr��������" << arr.GetCapacity() << endl;
	cout << "arr�Ĵ�С��" << arr.GetSize() << endl;

}

int main() {
	//test01();
	test02();

	system("pause");
	return 0;
}

