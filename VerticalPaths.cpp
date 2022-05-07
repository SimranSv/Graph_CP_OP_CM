//Simran Vedpathak
//https://codeforces.com/contest/1675/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
const ll mod = 1e9 + 7;
ll id;
void dfs(ll leaf, vector<ll> adj[],vector<ll>ans[])
{
    ans[id].pb(leaf); 

    for (auto &i : adj[leaf])
    {
       
            dfs(i, adj,ans);
            if(adj[i].size()==0)
              ++id;
        
    }
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> adj[n + 1];
    vector<ll> ans[n+1];
    vector<ll> vis(n + 1);
    ll root=0;
     if(n==1){
        int x;
        cin>>x;
         cout<<1<<'\n'<<1<<'\n'<<1<<'\n';
         return;
    } 
    cout<<'\n';
   
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if(i!=x)adj[x].pb(i);
        else root=i;
    }
     
    id=0;
    dfs(root, adj,ans);
     cout<<id<<'\n';
    for(int i=0;i<=n;i++){
       
        if(ans[i].size()){
            cout<<ans[i].size()<<'\n';
            for(auto &j:ans[i]){
                cout<<j<<" ";
            }
            cout<<'\n';
        }
    }
     
    cout << "\n";
}
int main()
{
    FAST;
    ll n;
    cin >> n;
    while (n--)solve();
}