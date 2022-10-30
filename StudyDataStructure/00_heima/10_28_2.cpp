// p131-134  用处不大，实际开发中尽量避免“同名”和“多继承” 
// 同名成员处理：
    // 访问子类同名成员，直接访问
    // 访问父类同名成员，加作用域，如 s.Base::m_A
// 多继承语法
    // 一个类继承多个类  
    // 需要加作用域区分不同类的同名成员
// 菱形继承 -- 虚继承方法 略

#include <iostream>
#include <string.h>
using namespace std;

class Base{
    public:
    Base(){
        m_A = 100;
    }
    int m_A = 100;
};

class Son : public Base{
    public:
    Son(){
        m_A = 200;
    }
    int m_A = 200;
};

void test01(){
    Son s;
    cout << "Son m_A = " << s.m_A <<endl; // 100
    cout << "Base m_A = " << s.Base::m_A <<endl; // 200  加作用域调用父类成员
}

int main(){
    test01();
    return 0;
}