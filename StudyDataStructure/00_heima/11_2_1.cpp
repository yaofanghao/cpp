// p167-170 模板的基本概念
// 格式： template <typename T> 
// 1、自动类型推导
// 2、显示指定类型

#include <iostream>
using namespace std;

template <typename T> // 模板定义，T是通用数据类型; typename可以替换成class
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 模板的应用示例：数组排序
template <class T>
void mySort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max = i;
        for (int j=i+1; j < len; j++)
        {
            if(arr[max] < arr[j])
            {
                max = j;
            }
        }
        if (max != i)
        {
            mySwap(arr[max], arr[i]);
        }        
    }
}

template <typename T>
void printArr(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] ;
    }
    cout << endl;
}


int main()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    // 使用模板的两种方式
    // 1、自动类型推导，必须推导出一致的类型，否则错误
    mySwap(a, b);
    // mySwap(a, c); // 报错
    cout << a << endl;
    cout << b << endl;

    // 2、显示指定类型
    mySwap<int>(a, b);
    cout << a << endl;
    cout << b << endl;

    char charArr[] = "badcfe";
    int num = sizeof(charArr) / sizeof(char);
    mySort(charArr, num);
    printArr(charArr, num);  // fedcba

    int intArr[] = {7,4,6,2,3,8,1};
    int num2 = sizeof(intArr) / sizeof(int);
    mySort(intArr, num);
    printArr(intArr, num);  // 8764321


    system("pause");
    return 0;
}