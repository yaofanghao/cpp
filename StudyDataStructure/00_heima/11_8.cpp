// p185-188
// vector容器基本概念
// vector容器的嵌套

#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

class Person
{
    public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

void myPrint(int val)
{
    cout << val << endl;
}

void test01()
{
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    vector<int>::iterator itBegin = v.begin(); // 指向容器中第一个元素
    vector<int>::iterator itEnd = v.end(); // 指向容器中最后一个元素的下一个

    // 调用algorithm库遍历容器元素，回调算法
    for_each(v.begin(), v.end(), myPrint);

    // auto方法遍历容器元素，c++11的新写法
    for (auto num : v){
        cout << num << "\n";
    }
    cout << endl;
}

void test02()
{
    vector<Person> w;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    cout << "test02" << endl;
    w.push_back(p1);
    w.push_back(p2);
    w.push_back(p3);
    w.push_back(p4);
    
    // 遍历容器
    for(vector<Person>::iterator it = w.begin(); it != w.end(); it++)
    {
        cout << "name: " << (it)->m_Name << endl;
    }
}

int main() {
	test01();
    test02();
	system("pause");
	return 0;
}
