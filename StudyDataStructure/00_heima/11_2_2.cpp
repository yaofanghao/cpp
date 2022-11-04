// p171-181 
// ��ͨ������������ʽ����ת��
// ����ģ�壺
//     1���Զ������Ƶ�����������ʽ����ת������Ϊģ�岻֪�����Ƶ�Ϊ��һ��
//     2����ʾָ�����ͣ�������ʽ����ת��
// �������ģ�����ͨ���������Ե��ã����ȵ�����ͨ����
// �������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��

// ��ģ�壺
//     ��ʽ�� template <typename T> 
//            ��
// ��ģ��ͺ���ģ���������ģ��û���Զ��Ƶ�����
// ��Ա��������ʵ��

#include <iostream>
using namespace std;

// ��ģ��ʾ��
template <class T1, class T2>
class Person
{
    public:
    Person(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    T1 m_Name;
    T2 m_Age;

    void showPerson();
};

// ��Ա��������ʵ��
template <class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout << "name:" << m_Name << endl;
    cout << "age:" << m_Age << endl;
}

void test01()
{
    Person<string, int> p1("Hello", 20);
    p1.showPerson();
}

int main(){
    test01(); 
    return 0;
}