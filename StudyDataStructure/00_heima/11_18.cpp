// p197-203 vector容器的常用操作
// 构造
// 赋值
// 容量、大小 empty capacity size resize
// 插入 删除 push_back pop_back insert erase
// 存取 at(i) front back
// 互换容器 swap
// 预留空间 reserve

#include <iostream>
using namespace std;
#include <vector>

void printVector(vector<int>&v)
{
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// vector容器构造方式
void test01()
{
    // 1、默认构造，无参构造
    vector<int>v1;  
    for (int i=0; i<10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    // 2、区间方式构造
    vector<int>v2(v1.begin(), v1.end());
    printVector(v2);

    // 3、elem方式构造
    vector<int>v3(10, 100); // （个数，赋值）
    printVector(v3);

    // 4、拷贝构造
    vector<int>v4(v3);
    printVector(v4);

}

// vector容器赋值方式
void test02()
{
    // 1、遍历
    vector<int>v1;  
    for (int i=0; i<10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    // 2、operator= 方式
    vector<int>v2;
    v2 = v1;
    printVector(v2);

    // 3、assign方式
    vector<int>v3;
    v3.assign(v1.begin(),v2.end());
    printVector(v3);

}

// 容量、大小
void test03()
{
    vector<int>v1;  
    for (int i=0; i<10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    if (v1.empty()) { cout << "vector is empty" << endl; }
    else { 
        cout << "vector is not empty" << endl;
        cout << "capacity:" << v1.capacity() << endl;
        cout << "size" << v1.size() << endl;
    }

    v1.resize(15); // resize 可以重新指定大小
    printVector(v1);
}

// 插入、删除
void test04()
{
    vector<int>v1;  
    for (int i=0; i<10; i++)
    {
        v1.push_back(i);  // 尾插
    }    
    v1.pop_back();  // 尾删
    v1.insert(v1.begin(), 100);  // 头插
    v1.insert(v1.begin(), 2, 1000);  // 头插2个1000
    v1.erase(v1.begin());  // 头删
    v1.erase(v1.begin(), v1.end()); // 全删
    v1.clear(); // 全删
}

// 存取 
void test05()
{
    vector<int>v1;  
    for (int i=0; i<10; i++)
    {
        v1.push_back(i); 
    }
    
    // 1、数组方式访问
    for (int i=0; i<v1.size(); i++)
    {
        cout << v1[i] << " ";
    }

    // 2、at方式访问
    for (int i=0; i<v1.size(); i++)
    {
        cout << v1.at(i) << " ";
    }

    cout << v1.front() << endl;  // 获取第一个元素
    cout << v1.back() << endl;  // 获取最后一个元素
}

// 互换容器 
void test06()
{
    vector<int>v1;  
    for (int i=0; i<10; i++)
    {
        v1.push_back(i); 
    }
    vector<int>v2;  
    for (int i=10; i>0; i--)
    {
        v2.push_back(i); 
    }
    printVector(v1);
    printVector(v2);

    v1.swap(v2);  // 交换容器，非常方便
    printVector(v1);
    printVector(v2);

}

// 预留空间
void test07()
{
    vector<int> v1;

    // // 开辟内存空间
    // int num = 0;
    // int *p = NULL;
    // for (int i=0; i<10000; i++)
    // {
    //     v1.push_back(i);
    //     if (p != &v1[0])
    //     {
    //         p = &v1[0]; // 每次重新找一块内存，开辟新的内存空间
    //         num++;        
    //     }
    // }
    // cout << "num= " << num << endl;  // num= 5

    // 由于上一种方式分配内存次数很多，因此直接使用reserve预留空间，只需要一次
    v1.reserve(1000);
}

int main() {
	// test01();
    // test02();
    // test03();
    // test04();
    // test05();
    test06();
    test07();
	system("pause");
	return 0;
}