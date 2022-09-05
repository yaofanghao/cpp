// p114 成员变量和成员函数分开存储
// 空对象占用内存为1
// 是为了区分空对象占内存的位置
// 使得每个空对象有独一无二的内存位置
// 只有非静态成员变量属于类的对象，其他都不属于

#include <iostream>
using namespace std;

class Person{
};

class Person2{
    int test;
};

class Person3{
    int test; // 非静态成员变量，属于类的对象
    static int test2; // 静态成员变量，不属于类的对象
};
int Person3::test2 = 10;

int main(){

    Person p;
    cout<<"size of p is "<<sizeof(p)<<endl; // size of p is 1 空对象占用内存为1

    Person2 p2;
    cout<<"size of p2 is "<<sizeof(p2)<<endl; // size of p2 is 4 因为其中int占4位

    Person3 p3;
    cout<<"size of p3 is "<<sizeof(p3)<<endl; // size of p3 is 4 因为静态成员变量test2不属于类对象

    return 0;
}