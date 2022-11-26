// p204-214 deque容器的常用操作（双端数组）
// 不难，类似于之前学习的容器

#include<iostream>
using namespace std;
#include<deque>
#include<string>
#include<algorithm>

void printDeque(const deque<int> &d) {
	// deque也可通过at方式访问容器里边的元素
	/*for (int i = 0; i < d.size(); i++) {
		cout << d.at(i) << "  ";
	}
	cout << endl;*/

	// 注意：如果传入的是 const deque<int> &d,这时候d为只读状态
	// 此时要修改deque<int>::iterator
	// 变为deque<int>::const_iterator
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << "    ";
	}
	cout << endl;
}

void test01() {
	// 1.默认构造
	deque<int>d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	cout << "默认构造函数：" << endl;
	printDeque(d1); cout << endl;

	// 2.区间构造
	deque<int>d2(d1.begin(), d1.end());
	cout << "区间构造:" << endl;
	printDeque(d2); cout << endl;

	// 3.n个元素
	deque<int>d3(10,666);
	cout << "传入10个666" << endl;
	printDeque(d3);
	cout << endl;

	// 4.拷贝构造
	deque<int>d4(d3);
	cout << "拷贝上一个容器：" << endl;
	printDeque(d3); cout << endl;
}

// deque容器赋值操作
void test02() {
	deque<int>d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	cout << "d1里的元素如下：" << endl;
	printDeque(d1);
	// 1.重载等号方式
	deque<int>d2;
	d2 = d1;
	cout << "重载=号的方式给d2赋值" << endl;
	printDeque(d2);
	cout << endl;

	// 2.assign函数（区间）
	deque<int>d3;
	d3.assign(d2.begin(),d2.end()-3);
	cout << "assign函数(区间)的方式给d3赋值：" << endl;
	printDeque(d3);
	cout << endl;
	
	// 3.assign函数(N个元素）
    deque<int>d4;
	d4.assign(10,666);
	cout << "assign函数(N个元素)的方式给d4赋值：" << endl;
	printDeque(d4);
	cout << endl;
}

// deque容器的大小操作
// deque容器没有容量限制，可以无限制开辟缓冲区，中控器再加个地址就行
void test03() {
	deque<int>q1;
	for (int i = 0; i < 10; i++)
	{
		q1.push_back(i);
	}
	if (q1.empty() == 0) {
		cout << "此时容器不为空" << endl;
	}
	if (q1.empty() == 1) {
		cout << "此时容器为空" << endl;
	}

	// 2.查看元素个数
	cout << "容器中元素的个数：" << q1.size() << endl;
	cout << endl;
	// 3.修改长度
	q1.resize(5);
	cout << "指定长度为5后容器中元素的个数：" << q1.size() << endl;
	cout << "容器中的元素如下：" << endl;
	printDeque(q1); cout << endl;
	q1.resize(15,666);
	cout << "指定长度为15，多的用666来补充后容器中元素的个数：" << q1.size() << endl;
	cout << "容器中的元素如下：" << endl;
	printDeque(q1); 

}

// deque容器的插入和删除
//  两端操作
void test04() {
	deque<int>d1;
    // 尾插法
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	cout << "通过尾插法构建d1:" << endl;
	printDeque(d1); cout << endl;

	// 头插法
	deque<int>d2;
	cout << endl;
	for (int i = 0; i < 10; i++) {
		d2.push_front(i);
	}
	cout << "通过头插法构建d2:" << endl;
	printDeque(d2); cout << endl;

	// 尾删法
	cout << endl;
	d1.pop_back();
	cout << "尾删法后d1=";
	printDeque(d1); cout << endl;

	// 头删法
	cout << endl;
	d2.pop_front();
	cout << "头删法后d2=";
	printDeque(d2); cout << endl<<endl;

}

// 指定位置操作
void test05() {
	// 1.insert(pos,elem)
	deque<int>d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	d1.insert(d1.begin() + 6, 666);
	cout << "在d1.begint()+6前插入数据666" << endl;
	printDeque(d1); cout << endl;
	// 2.insert(pos,n,elem)
	d1.insert(d1.begin(), 2, 555);
	cout << "在d1.begin()前插入2个555" << endl;
	printDeque(d1); cout << endl;

	// 3.insert(pos,beg,end)在pos位置插入[beg,end)区间的数据，无返回值
	deque<int>d2;
	cout << endl;
	for (int i = 10; i < 20; i++) {
		d2.push_front(i);
	}
	cout << "d2的元素如下：" << endl;
	printDeque(d2);
	d2.insert(d2.begin()+3,d2.begin(),d2.end());
	cout << "在d2.begint()+3前插入[d2.begin(),d2.end())的值" << endl;
	printDeque(d2); 
	cout << "此时容器的容量为：" << d2.size() << endl;
	cout << endl;
	
	// 4.erase(beg,end)
	deque<int>::iterator it = d2.begin();
	d2.erase(it+2,it+6);
	cout << "删除从[d2.begin()+2到d2.begint()+6)处的4个数据" << endl;
	printDeque(d2); 
	cout << "此时容器的容量为：" << d2.size() << endl;
	cout << endl;

	// 5.erase(pos)
	d2.erase(d2.begin()+ 8);
	cout << "删除d2.begint()+8处的数据" << endl;
	printDeque(d2); cout << endl;

	// 6.clear
	d2.clear();
	cout << "执行d2.clear()后" << endl;
	if (d2.empty() == 0) {
		cout << "此时容器不为空" << endl;
	}
	if (d2.empty() == 1) {
		cout << "此时容器为空" << endl;
	}
	cout << endl;
}

// 排序算法
void test06() {
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(200);
	d1.push_back(5);
	d1.push_back(30);
	d1.push_back(0);
	cout << "排序前：" << endl;
	printDeque(d1);
	// 注意不是d1.sort
	// sort函数不属于任何容器，它是STL标准模板库提供的
	sort(d1.begin(), d1.end());
	cout << "排序后:" << endl;
	printDeque(d1);
}

int main() {
	test01();
	system("pause");
	return 0;
}
