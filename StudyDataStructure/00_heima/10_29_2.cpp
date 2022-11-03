// p137-142
// 纯虚函数 抽象类
    // 有了纯虚函数的类称为抽象类
    // 抽象类无法实例化
// 虚析构 纯虚析构

#include <iostream>
using namespace std;

class Base{
    public:
    virtual void func() = 0; // 纯虚函数写法

};

class Son :public Base{
    public:
    virtual void func() {
        cout << "son func" << endl;
    }; // 子类必须重写父类的纯虚函数
};

void test01(){
    // Base b; // 报错，无法实例化抽象类
    Son s; // 可以实例化
    s.func();
}

int main(){
    test01(); 
    return 0;
}