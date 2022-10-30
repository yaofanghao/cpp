// p118-120 友元
// 允许类外特殊的函数或类对私有属性访问
    // 1、全局函数做友元
    // 2、类做友元 --略，未学习 参考讲解见 https://blog.csdn.net/weixin_46098577/article/details/116596183
    // 3、成员函数做友元 --略，未学习

#include <iostream>
using namespace std;

class Building{
    
    friend void Friend(Building *building);  // 说明该全局函数做友元
    
    public:
    string m_SittingRoom;
    Building(){
        m_SittingRoom = "keting";
        m_BedRoom = "woshi";
    }

    private:
    string m_BedRoom;
};

// class FriendClass{

// };

void Stranger(Building *building){
    cout<<"go to "<<building->m_SittingRoom<<endl;  // 可以访问
    // cout<<"go to "<<building->m_BedRoom<<endl;  // 不可以访问，报错
}

void Friend(Building *building){
    cout<<"go to "<<building->m_SittingRoom<<endl;  // 可以访问
    cout<<"go to "<<building->m_BedRoom<<endl;  // 可以访问，因为声明了friend（友元）
}

int main(){
    Building build1;
    Stranger(&build1);
    Friend(&build1);
    
    return 0;
}