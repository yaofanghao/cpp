// p127-130 继承
// 父类（基类） -> 子类（派生类）
    // 公共继承：父类所有 子类中不变；
    // 保护继承：父类中公共 变为 子类中保护 ； 其他不变；
    // 私有继承：父类所有 都变为 子类中私有；
// 继承中的对象模型:
    // 父类中所有非静态成员属性都会被子类继承下去
    // 可用 sizeof 检验
// 构造和析构顺序：
    // 父类构造 - 子类构造 - 子类析构 - 父类析构

#include <iostream>
using namespace std;

// 父类
class BaseFunc{
    public:
    void header(){
        cout << "this is head" << endl;
    }
    void footer(){
        cout << "this is foot" << endl;
    }
    int m_A;

    protected:
    int m_B;

    private:
    int m_C;
};

// 子类的实现
class Java : public BaseFunc{
    public:
    void content(){
        cout << "Java speical" << endl; 
    }
    void func(){
        m_A = 10; // 公共 
        m_B = 20; // 保护
        // m_C = 30; // 这句报错，因为在父类中私有
    }
};

class Java2 : protected BaseFunc{
    public:
    void func(){
        m_A = 10; // 保护
        m_B = 20; // 保护
        // m_C = 30; // 这句报错，因为在父类中私有
    }
};

class Java3 : private BaseFunc{
    public:
    void func(){
        m_A = 10; // 私有
        m_B = 20; // 私有
        // m_C = 30; // 这句报错，因为在父类中私有
    }         
};

void test01(){
    cout << "Java" << endl;
    BaseFunc base;
    Java jaPublic;
    Java2 jaProtect;
    Java3 jaPrivate;
    jaPublic.header();
    jaPublic.content();

    jaPublic.m_A = 100;
    // jaPublic.m_B = 200; // 这句报错，因为是保护权限
    // jaProtect.m_A = 100; // 这句报错，因为是保护权限
    // jaProtect.m_B = 200; // 这句报错，因为是保护权限
    // jaPrivate.m_A = 100; // 这句报错，因为是私有权限
    // jaPrivate.m_B = 100; // 这句报错，因为是私有权限

    cout << "size of base = " << sizeof(base) << endl; // 12 
    cout << "size of Java3 = " << sizeof(jaPrivate) << endl; // 12 表明父类中所有非静态成员属性都会被子类继承下去
}

int main(){
    test01();
    return 0;
}