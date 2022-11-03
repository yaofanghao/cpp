// p171-184 
// 普通函数：可以隐式类型转换
// 函数模板：
//     1、自动类型推导，不可以隐式类型转换。因为模板不知道该推导为哪一类
//     2、显示指定类型，可以隐式类型转换
// 如果函数模板和普通函数都可以调用，优先调用普通函数
// 如果函数模板可以产生更好的匹配，优先调用函数模板

// 类模板：
//     格式： template <typename T> 
//            类
// 类模板和函数模板的区别：类模板没有自动推导参数

#include <iostream>
using namespace std;

// 类模板示例
template <class NameType, class AgeType>
class Person
{
    public:
    Person(NameType name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    NameType m_Name;
    AgeType m_Age;
};

void test01()
{
    Person<string, int> p1("名称", 20);
}

int main(){
    test01(); 
    return 0;
}