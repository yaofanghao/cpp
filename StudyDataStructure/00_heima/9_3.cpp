// 学习时间：9.3
// p57-63 指针

#include <iostream>
using namespace std;

int main(){

    // 野指针
    int *p = (int*) 0x1100; 

    // const 
    // 常量指针
    // 指针的指向可以修改，指向的值不可修改。
    // 只读
    int a = 10;
    const int *p = &a;

    // 指针常量
    // 指针的指向不可修改，指向的值可以修改。
    int * const p = &a;


    // 指针和数组
    int arr[3] = {1,2,3};
    int *p = arr;


    return 0;
}