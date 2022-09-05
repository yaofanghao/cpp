// p99-105 类和对象-封装
    // 访问权限有三种：
        // public 类内、外都可以访问
        // protected 只有类内可访问，子类可以访问父类
        // private 只有类内可访问，子类不可以访问父类
    // class 和 struct 的区别：class默认权限private；struct默认权限public

// p106 构造函数和析构函数
    // 构造：初始化
        // 构造函数：
        // 1、按照参数分类：无参（默认）构造，有参构造
        // 2、按照类型分类：普通构造，拷贝构造
    // 析构：清理，不可以有参数
    // 如果不写，编译器会自动空的实现

// p107 拷贝构造函数
    // Cube( const Cube &p){} 拷贝出一份一样的
    // 有参构造函数的调用方法：
        // 1、括号法 
        // 2、显示法
        // 3、隐式转换法
        
// p108 拷贝构造函数的调用时机
    // 1、使用一个已经创建完毕的对象初始化一个新对象
    // 2、值传递的方式给函数参数传值
    // 3、值方式返回局部对象

#include <iostream>
using namespace std;

class Person
{
    public: 
    int num;

    Person(){
        cout<<"default constructor"<<endl;
    } //构造

    Person(int a){
        cout<<"parameter constructor"<<endl;
        num = a; 
    } //有参构造

    Person( const Person &p){
        cout<<"copy constructor"<<endl;
        num = p.num;
    } //拷贝构造

    ~Person(){
        cout<<"destructor"<<endl;
    } //析构
};

int main(){

    Person p1;
    Person p2(10);
    Person p3(p2);

    Person p4 = Person(20); // 显示法
    Person(10); // 匿名对象。当前行执行结束后，系统立即回收掉该匿名对象

    Person p5 = 30; // 隐式转换法。相当于 Cube c5 = Cube(10);

    cout<<"p2:"<<p2.num<<endl;
    cout<<"p3:"<<p3.num<<endl;  // c2的值也赋值给了c2
    cout<<"p4:"<<p4.num<<endl;
    cout<<"p5:"<<p5.num<<endl;

    return 0;
}