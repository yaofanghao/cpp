// p121-126 运算符重载
// 对内置数据类型是不可能改变运算方式的
    // 1、加号 operator+
    // 2、左移 用全局函数实现 operator<< 用处不大
    // 3、递增
    // 4、赋值
    // 5、关系运算符
    // 6、函数调用

#include <iostream>
#include <string.h>
using namespace std;

class Person{
    public:
    
    // 加号运算符重载 
    Person operator+(Person &p){
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    }  

    int m_A;
    int m_B;
};

// 左移运算符重载 用全局函数实现
// 含义：operator(cout,p) 本质上是 cout<<p
ostream & operator<<(ostream &cout,Person &p){
    cout<< "m_A = "<<p.m_A<<endl;
    cout<< "m_B = "<<p.m_B<<endl;
    return cout;    
}

void test01(){
    Person p1;
    p1.m_A = 10;
    p1.m_B = 20;
    Person p2;
    p2.m_A = 30;
    p2.m_B = 40;

    Person p3 = p1 + p2;  // 使用加号运算符重载
    // Person p3 = p1.operator+(p2);  // 与上一写法等同
    cout<<"p3.m_A = "<<p3.m_A<<endl;
    cout<<"p3.m_B = "<<p3.m_B<<endl;   

    // operator<<()

}

int main(){
    test01();
    return 0;
}