// p143-146 文件操作
// fstream头文件 
// 写ofs、读ifs 文本文件
// 写、读 二进制文件 binary -- 略

#include <iostream>
#include <fstream> // 创建头文件
#include <string>
using namespace std;

// 写文件
void Write(){
    ofstream ofs;
    ofs.open("10-30-test.txt", ios::out); //  写法:void open(const std::string &_Str, std::ios_base::openmode _Mode, int _Prot)
    ofs << "10-30.cpp test" << endl; 
    ofs << "write to txt" << endl; 
    ofs.close();    
}

// 读文件
void Read(){
    ifstream ifs;
    ifs.open("10-30-test.txt", ios::in); 
    if (!ifs.is_open()){
        cout << "error!" << endl;
        return;
    }
    
    // 读取方式1--但是空格变为了回车
    // char buf[1024] = {0};
    // while (ifs >> buf){
    //     cout << buf << endl;
    // }

    // 读取方式2--可以
    // char buf[1024] = {0};
    // while ( ifs.getline(buf, sizeof(buf))){
    //     cout << buf << endl;
    // }

    // 读取方式3--可以
    string buf;
    while ( getline(ifs, buf)){
        cout << buf << endl;
    }
}

int main(){
    Write();
    Read();
    return 0;
}