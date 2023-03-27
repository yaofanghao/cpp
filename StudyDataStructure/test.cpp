#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void printVector(vector<int>& nums)
{
    for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
    {
        cout << *it << " ";
    }
    cout<<endl;    
}

// 2023.3.11 不需要考虑数组中超出新长度后面的元素 画图分析每一步即可理解
int removeDuplicates(vector<int>& nums) 
{
    int n = nums.size();
    int i=0,j=1;
    for(int j=1; j<n; j++)
    {
        cout<<"i="<<i<<endl;
        cout<<"j="<<j<<endl;
        if(nums[i]!=nums[j])
        {
            i++;
            nums[i] = nums[j];
        }        
        printVector(nums);
    }
    return ++i;
}

int main()
{
    vector<int> test = {0,0,1,1,1,2,2,3,3,4};
    int res = removeDuplicates(test);
    cout<<res<<endl;
}