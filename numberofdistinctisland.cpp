//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands
// } Driver Code Ends
// User function Template for C++

int n, m;
class Solution
{
public:
    vector<pair<int, int>> dir{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void dfs(int in, int in1, vector<vector<int>> &grid, vector<vector<int>> &vis, int base1, int base2, vector<pair<int, int>> &v)
    {
        if (!vis[in][in1])
        {
            v.push_back({base1 - in, base2 - in1});
            vis[in][in1] = 1;
        }
        for (auto &i : dir)
        {
            int ind = in + i.first;
            int ind1 = in1 + i.second;
            if (ind >= 0 && ind < n && ind1 >= 0 && ind1 < m)
            {
                if (!vis[ind][ind1])
                {
                    vis[ind][ind1] = 1;
                    if (grid[ind][ind1])
                    {
                        v.push_back({base1 - ind, base2 - ind1});
                        dfs(ind, ind1, grid, vis, base1, base2, v);
                    }
                }
            }
        }
    }
    int countDistinctIslands(vector<vector<int>> &grid)
    {

        n = grid.size();
        m = grid[0].size();
        set<vector<pair<int, int>>> ans;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {
                int base1 = i, base2 = j;
                if (!vis[i][j] && grid[i][j])
                {
                    vector<pair<int, int>> v;
                  //  cout<<i<<" "<<j<<'\n';
                   
                    
                    dfs(i, j, grid, vis, base1, base2, v);
                    ans.insert(v);
                }
            }
        }
        return ans.size();
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends