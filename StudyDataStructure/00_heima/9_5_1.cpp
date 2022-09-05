// p112 类对象作为类成员--乱七八糟，没听懂--略，后续补充
// p113 类和对象
// 静态成员变量
    // 1、所有对象共享同一份数据
    // 2、编译阶段分配内存
    // 3、类内声明，类外初始化操作
// 静态成员函数
    // 1、所有对象共享同一个函数
    // 2、静态成员函数只能访问静态成员变量

#include <iostream>
#include <string>
using namespace std;

class Person{
    public:
    static int m_A; // 静态成员变量类内声明
    static void func(); // 静态成员函数
    int m_C; // 非静态成员变量

    private:
    static int m_B;
};

int Person::m_A = 100; // 静态成员变量类外初始化
int Person::m_B = 300; //
void Person::func(){
    cout<<"static func ok"<<endl;
    m_B = 1000; // 静态成员函数 可以访问 非静态成员变量
    // m_C = 2000; // 静态成员函数 不可以访问 非静态成员变量。这句会报错
} // 静态成员函数类外初始化

int main(){
    Person p;
    cout<<p.m_A<<endl; // 100
    // cout<<p.m_B<<endl; // 无法访问私有变量，这句会报错

    Person p2;
    p2.m_A = 200;
    cout<<p2.m_A<<endl; // 200 说明静态成员是共享的数据，共享一块内存

    p2.func();


    return 0;
}