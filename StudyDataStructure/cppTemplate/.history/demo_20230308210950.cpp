#include<stdlib.h>
#include<stdio.h>
#include<iostream> 
using namespace std;

template<typename T>
T square (T x)
{
    return x*x;
}

int main()
{
    cout << square(5) << endl;
    cout << square(5.5) << endl;
}