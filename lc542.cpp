// 力扣第542题
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 2023.4.5 BFS
// 尝试遍历BFS 会超时，未解决该问题
class Solution {
public:
    const int dx[4] = {1, 0, 0, -1};
    const int dy[4] = {0, 1, -1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> res = vector<vector<int>>(n, vector<int>(m, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                res[i][j] = bfs(mat, i, j);
                cout<<"res["<<i<<","<<j<<"] is" << res[i][j]<<endl;
            }
        }
        return res;
    }

    int bfs(vector<vector<int>>& mat, int i, int j)
    {
        if(mat[i][j]==0) return 0;
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>>& visited = vector<vector<bool>>(n, vector<bool>(m, false));        
        int count=1;
        queue<pair<int, int>> que;
        que.emplace(i, j);
        visited[i][j] = true;
        while(!que.empty())
        {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            for(int i=0; i<4; i++)
            {
                int mx = x+dx[i];
                int my = y+dy[i];
                if(mx<0 || mx>=n || my<0 || my>=m) continue;                
                if(!visited[mx][my] && mat[mx][my]!=0)
                {
                    que.emplace(mx,my);
                    visited[mx][my] = true;
                    count++;                    
                }
                cout<<"mx="<<mx<<",my="<<my<<endl;
            }            
        } 
        return count;
    }
};


int main()
{
    Solution sol;
    vector<vector<int>> test = {{0,0,0},{0,1,0},{1,1,1}};
    vector<vector<int>> res = sol.updateMatrix(test);
    for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[0].size();++j)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}