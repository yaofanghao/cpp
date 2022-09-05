// https://www.runoob.com/cplusplus/cpp-this-pointer.html
// p115 this指针
// 1、解决名称冲突
// 2、返回对象本身用 *this

#include <iostream>
using namespace std;

class Person{
    public:
    Person(int age){
        this->age = age; // this指向的是 被调用成员函数所属的对象 解决名称冲突
    }
    int age;

    Person& PersonAddage(Person &p){
        this->age += p.age; 
        return *this; //
    }
};

int main(){

    Person p1(18);
    cout<<"p1 age is "<<p1.age<<endl; // 18

    Person p2(20);
    p2.PersonAddage(p1);
    cout<<"p1 age add p2 age is "<<p2.age<<endl; // 20+18=38

    p2.PersonAddage(p1).PersonAddage(p1); // 链式编程
    cout<<"p1 age add p2 age is "<<p2.age<<endl; // 20+18+18=56?

    return 0;
}