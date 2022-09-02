//{ Driver Code Starts
// Initial Template for C++
//https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-os-with-xs
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
vector<pair<int,int>>dir{{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<char>>&ans,vector<vector<char>>&mat,int ind,int ind1,int n,int m,vector<vector<int>>&vis)
    {
        
        if(mat[ind][ind1]=='O')ans[ind][ind1]='O';
        vis[ind][ind1]=1;
        for(int i=0;i<4;i++){
            int in=dir[i].first+ind,in1=dir[i].second+ind1;
            if(in>=0&&in<n&&in1>=0&&in1<m){
               
                if(!vis[in][in1]&&mat[in][in1]=='O') //vis[in][in1]=1,
                dfs(ans,mat,in,in1,n,m,vis);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char>> ans(n, vector<char>(m, 'X'));
        vector<vector<int>>vis(n, vector<int>(m, 0));

        for (int i = 0; i < m; i++)
        {
            if(mat[0][i]=='O')dfs(ans, mat,0,i,n,m,vis);
        }
        for (int i = 0; i < m; i++)
        {
            if(mat[n-1][i]=='O')dfs(ans, mat,n-1,i,n,m,vis);
        }
        for (int i = 0; i < n; i++)
        {
            if(mat[i][m-1]=='O')dfs(ans, mat,i,m-1,n,m,vis);
        }
        for (int i = 0; i < n; i++)
        {
            if(mat[i][0]=='O')dfs(ans, mat,i,0,n,m,vis);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends