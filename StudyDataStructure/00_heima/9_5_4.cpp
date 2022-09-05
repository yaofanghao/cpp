// p116 空指针访问成员函数

// p117 const修饰成员函数、对象 常函数 常对象
// 成员函数后加const，修饰的是this指针

#include <iostream>
using namespace std;

class Person{
    public:
    void showClassName()
    {
        cout<<"this is Person clas"<<endl;
    }

    // const修饰
    void showPersonAge() const
    {
        // this->m_Age = 100; // const修饰后这句会报错
        if(!this)
        {
            return;
        } // 解决空指针报错的问题
        cout<<"age = "<<m_Age<<endl;
    }

    int m_Age;
};

int main(){

    Person p1;
    p1.m_Age = 20;
    p1.showClassName();
    p1.showPersonAge();

    // 报错原因：无中生有，传入空指针
    // Person * p = NULL;
    // p->showClassName();
    // p->showPersonAge();

    return 0;
}
