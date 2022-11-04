// p182-184 类模板案例：数组类封装
// 实现通用数组
// 需求分析见MyArray.hpp
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

	//利用好尾插法
	for (int i = 0; i < 5; i++) {
		arr.Push_Back(i);
	}

	cout << "arr的打印输出为：" << endl;
	
	printArray(arr);

	cout << "arr的容量：" << arr.GetCapacity() << endl;
	cout << "arr的大小：" << arr.GetSize() << endl;

	MyArray <int>arr1(arr);
	printArray(arr1);
	//尾删
	arr1.Pop_Back();
	cout << "arr1尾删后" << endl;
	cout << "arr1的容量：" << arr1.GetCapacity() << endl;
	cout << "arr1的大小：" << arr1.GetSize() << endl;

}

//测试自定义数据类型
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
		cout << "姓名：" << arr[i].m_name << "\t年龄：" << arr[i].m_age << endl;
	}
}

void test02() {
	MyArray<Person>arr(10);

	Person p1("孙悟空", 555);
	Person p2("红孩儿", 555);
	Person p3("猪八戒", 555);
	Person p4("唐三藏", 555);
	Person p5("沙悟净", 555);
	Person p6("白骨精", 555);
	Person p7("女儿国", 555);
	Person p8("白龙马", 555);
	Person p9("史蒂夫", 555);
	Person p10("甘道夫", 555);

	//将数据插入数组
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
	cout << "arr的容量：" << arr.GetCapacity() << endl;
	cout << "arr的大小：" << arr.GetSize() << endl;

}

int main() {
	//test01();
	test02();

	system("pause");
	return 0;
}


