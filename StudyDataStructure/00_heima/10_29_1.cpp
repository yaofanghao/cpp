// p135-136 多态
// 静态多态
//     早绑定：编译阶段确定函数地址
// 动态多态
//     晚绑定：运行阶段确定函数地址
//     子类重写父类的虚函数

#include <iostream>
using namespace std;

class Animal{
    public:
    // 晚绑定
    virtual void speak(){
        cout << "animal say" <<endl;
    }
};

class Cat : public Animal{
    public:
    void speak(){
        cout << "cat say" <<endl;
    }
};

void doSpeak(Animal &animal){
    animal.speak();
}

void test01(){
    Cat cat;
    doSpeak(cat);
}

int main(){
    test01(); // cat say
    return 0;
}