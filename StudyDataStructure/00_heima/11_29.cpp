// p237-242 仿函数的基本概念
// 一元谓词、二元谓词
// 算术仿函数
// 关系仿函数
// 逻辑仿函数
//

// https://blog.csdn.net/qq_43685399/article/details/108611198

#include<vector>		
#include<algorithm>		
#include<functional>	//内建函数对象
#include<iostream>
using namespace std;

//绑定适配器 bind1st bind2nd 
//普通的一元函数对象(仿函数)
class MyPrint {
public:
	void operator()(int v) {
		cout << v << " ";
	}
};
//可以进行绑定的二元函数对象
//继承的父类，前两个模板参数是里面函数的参数类型，最后一个是函数的返回值类型
class MyPrintS : public binary_function<int, int, void> {
public:
	void operator()(int v, int addnum) const {
		cout << "v+addnum:" << v + addnum
			 << " 第一个参数:" << v 
			 << " 第二个参数:" << addnum << endl;
	}
};
void test01() {

	vector<int> v;
	for (int i = 0; i < 5; i++) {
		v.push_back(i);
	}
	//由于for_each是一元的，因此传入的函数对象也要是一元的
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	//绑定适配器  将一个二元函数对象转变为一元函数对象
	int addNum = 100;
	cout << "bind1st:" << endl;
	for_each(v.begin(), v.end(), bind1st(MyPrintS(), addNum));
	cout << "bind2nd:" << endl;
	for_each(v.begin(), v.end(), bind2nd(MyPrintS(), addNum));
	
	//bind1st 和 bind2nd 的区别
	//bind1st，将addNum绑定为函数对象的第一个参数
	//bind2nd，将addNum绑定为函数对象的第二个参数
}

//取反适配器 not1
//普通的一元谓词
struct MyGreater5 {
	bool operator()(int v) {
		return v > 5;
	}
};
//可以使用适配器的一元谓词
struct MyGreater5S : public unary_function<int, bool> {
	bool operator()(int v) const {
		return v > 5;
	}
};
void test02() {

	vector<int> v;
	for (int i = 1; i < 11; i++) {
		v.push_back(i);
	}

	cout << "元素：";
	for_each(v.begin(), v.end(), MyPrint());

	//查找第一个大于5的值
	vector<int>::iterator it;
	it = find_if(v.begin(), v.end(), MyGreater5());
	cout << "\n第一个大于5的数：" << *it << endl;

	//取反查找第一个小于5的值
	it = find_if(v.begin(), v.end(), not1(MyGreater5S()));
	cout << "第一个小于5的数：" << *it << endl;

}

//not1 和 not2 的区别
//not1 是对一元谓词取反
//not2 是对二元谓词取反

//取反适配器 not2
//普通的二元谓词
//这里直接用struct主要是懒得yongclass还得写public
struct MyCompare {
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};
//可以使用适配器的二元谓词
//继承的父类，前两个模板参数是里面函数的参数类型，最后一个是函数的返回值类型
struct MyCompareS : public binary_function<int, int, bool> {
	bool operator()(int v1, int v2) const {
		return v1 > v2;
	}
};
void test03() {

	vector<int> v;
	for (int i = 0; i < 5; i++) {
		v.push_back(i);
	}
	cout << "排序前:" << endl;
	for_each(v.begin(), v.end(), MyPrint());

	sort(v.begin(), v.end(), MyCompare());
	cout << "\n排序后:" << endl;
	for_each(v.begin(), v.end(), MyPrint());

	sort(v.begin(), v.end(), not2(MyCompareS()));
	cout << "\n取反排序后:" << endl;
	for_each(v.begin(), v.end(), MyPrint());
}

//ptr_fun 函数对象适配器
//普通函数
void MyPrint02(int v) {
	cout << v << " ";
}
void test04() {

	vector<int> v;
	for (int i = 0; i < 5; i++) {
		v.push_back(i);
	}

	//使用普通函数进行输出
	cout << "直接调用普通函数：" << endl;
	MyPrint02(5);

	//用ptr_fun将普通函数转化为函数对象
	cout << "\n转化为函数对象后调用for_each：" << endl;
	for_each(v.begin(), v.end(), ptr_fun(MyPrint02));
	
}

//mem_fun 和 mem_dun_ref 成员函数适配器
class Person {
public:
	Person(int id, int age):id(id), age(age){}
	void show() {
		cout << "id:" << id << " age:" << age << endl;
	}
public:
	int id;
	int age;
};
void test05() {

	vector<Person> v1;
	Person p1(1, 20), p2(2, 21), p3(3, 18);
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);

	//使用类自己提供的打印函数来打印容器中的类对象
	//容器中存放的是对象，使用mem_fun_ref来调用类的函数
	cout << "使用mem_fun_ref:" << endl;
	for_each(v1.begin(), v1.end(), mem_fun_ref(&Person::show));

	vector<Person*> v2;
	v2.push_back(&p1);
	v2.push_back(&p2);
	v2.push_back(&p3);

	//容器中存放的是对象指针，使用mem_fun来调用类的函数
	cout << "\n使用mem_fun:" << endl;
	for_each(v2.begin(), v2.end(), mem_fun(&Person::show));
}

//简单测试
int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	test05();

	cout << endl << endl;
	return 0;
}