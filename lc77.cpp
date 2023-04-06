// 力扣第77题 回溯法 组合
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void printVector(vector<int> &temp)
    {		
        for (int j = 0; j < temp.size();++j) cout << temp[j] << " ";
		cout << endl;  
    }
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path; // 用来存放符合条件结果
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) 
        {
            result.push_back(path);
            return;
        }
        for (int i=startIndex; i<=n-(k-path.size())+1; i++) // 剪枝优化
        {
            path.push_back(i); // 处理节点 
            cout<<"startIndex = "<<startIndex<<endl;
            printVector(path);
            backtracking(n, k, i + 1); // 递归
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }

public:
    vector<vector<int>> combine(int n, int k) 
    {
        result.clear(); // 可以不写
        path.clear();   // 可以不写
        backtracking(n, k, 1);
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> res;
    res = sol.combine(5,3);
    return 0;
}