// 9.4 p99- 类和对象-封装

#include <iostream>

using namespace std;

#define PI 3.14

class Circle
{
    public:
    // 属性
    int radius;
    double calculateZC(){
        return 2*PI*radius;
    }

    // 行为
    void showZC(int radius){
        cout<<radius<<endl;
    }

    private:


};


int main(){

    Circle cl;
    cl.radius = 100;
    cl.showZC(cl.radius);


    return 0;
}