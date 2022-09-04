// 学习时间：9.4
// p110 深拷贝和浅拷贝--重难点
// 浅拷贝：简单的赋值拷贝
    // 存在的问题：堆区的内存重复释放
    // 解决办法：深拷贝
// 深拷贝：在堆区重新申请空间

#include <iostream>
using namespace std;

class Person
{
    public: 
    int m_Age;
    int *m_Height;

    Person(){
        cout<<"default constructor"<<endl;
    } //构造

    Person(int age, int height){
        cout<<"parameter constructor"<<endl;
        m_Age = age;
        m_Height = new int(height);
    } //有参构造

    Person( const Person &p){
        cout<<"copy constructor"<<endl;
        m_Age = p.m_Age;
    } //拷贝构造

    ~Person(){
        if(!m_Height){
            delete m_Height;
            m_Height = NULL;
        } // 将堆区开辟的数据释放
        cout<<"destructor"<<endl;
    } //析构
};

int main(){

    Person p1(18,180);
    cout << "p1:" << p1.m_Age << endl;   
    cout << "p1Height:" << *p1.m_Height << endl;  // 18

    Person p2(p1);
    cout << "p2:" << p2.m_Age << endl;
    cout << "p2Height:" << *p2.m_Height << endl;  // 18  


    return 0;
}