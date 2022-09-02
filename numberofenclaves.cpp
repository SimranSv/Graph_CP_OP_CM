//{ Driver Code Starts
// Initial Template for C++
//https://practice.geeksforgeeks.org/problems/number-of-enclaves/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-enclaves
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++



class Solution
{
public:
    vector<pair<int, int>> dir{{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    void dfs(vector<vector<int>> &grid, int in, int in1, int &ans, int n, int m, vector<vector<int>> &vis)
    {

        if (grid[in][in1] == 1 && vis[in][in1] == 0)
        {
             vis[in][in1] = 1;
           
          //  cout << in << " " << in1 << '\n';
            --ans;
        }
       
        //  cout << ans << "\n";

        for (auto &i : dir)
        {
            int ind = i.first + in, ind1 = i.second + in1;
            if (ind >= 0 && ind < n && ind1 >= 0 && ind1 < m)
            {
                if (!vis[ind][ind1])
                {
                    vis[ind][ind1] = 1;

                    if (grid[ind][ind1] == 1)
                    {
                        --ans;
                        //cout << ind << " " << ind1 << '\n';

                        dfs(grid, ind, ind1, ans, n, m, vis);
                    } 
                }
                //  vis[ind][ind1] = 1;
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        // cout<<n<<" "<<m<<'\n';
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    ans++;
            }
        }
        // cout<<ans<<" ";
        for (int i = 0; i < m; i++)
        {
            if (grid[0][i] == 1)
            {
                if (!vis[0][i])
                {
                    //     vis[0][i] = 1;
                    //    // ans--;
                    dfs(grid, 0, i, ans, n, m, vis);
                }
            }
            //}
        }
        for (int i = 0; i < m; i++)
        {

            if (grid[n - 1][i] == 1)
            {
                if (!vis[n - 1][i])
                {
                    // vis[n - 1][i] = 1;
                    // ans--;
                    dfs(grid, n - 1, i, ans, n, m, vis);
                }
            }
            //}
        }
        for (int i = 0; i < n; i++)
        {

            if (grid[i][0] == 1)
            {
                if (!vis[i][0])
                {
                    // vis[i][0] = 1;
                    // // ans--;
                    dfs(grid, i, 0, ans, n, m, vis);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {

            if (grid[i][m - 1] == 1)
            {
                if (!vis[i][m - 1])
                {
                    // vis[i][m - 1] = 1;
                    // ans--;
                    dfs(grid, i, m - 1, ans, n, m, vis);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends