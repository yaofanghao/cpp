// p189-196
// string容器基本概念
// 运算符重载 
// 赋值 assign
// 添加 append 略
// 查找 find 替换 replace
// 比较 compare
// 字符存取 str.at(i)
// 插入 insert 删除 delete 略
// 子串获取 substr 略


#include <iostream>
using namespace std;
#include <string>

void test01(){
    string s1;
    const char* str = "hello world";
    string s2(str);
    cout << "s2 = " << s2 << endl;
    string s3(s2);
    cout << "s3 = " << s3 << endl;
}

void test02(){
    string str3;
    str3.assign("this is assign");
    cout << "str3 = " << str3 << endl;  

    int pos = str3.find("ass");
    if (pos == -1)
    {
        cout << "do not find ass" << endl;
    }
    else
    {
        cout << "pos = " << pos << endl;  // pos = 8
    }

    string str4 = str3.replace(1,3,"replace");  
    cout << "str4 = " << str4 << endl;  // treplace is assign
}

void test03()
{
    string str1 = "abc";
    string str2 = "def";
    if (str1.compare(str2)==0)
    {
        cout << "str1 = str2 " << endl;
    }
    else if (str1.compare(str2)<0)
    {
        cout << "str1 < str2 " << endl;
    }
    else 
    {
        cout << "str1 > str2 " << endl;
    }
}

void test04()
{
    string str = "hello";
    for (int i=0; i<str.size(); i++)
    {
        cout << str[i] << " ";
    }
     cout << endl;
    for (int i=0; i<str.size(); i++)
    {
        cout << str.at(i) << " ";
    }
}


int main() {
	test01();
    test02();
    test03();
    test04();

	system("pause");
	return 0;
}