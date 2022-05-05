// https://codeforces.com/contest/1627/problem/C
// Simran Vedpathak
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define vll vector<ll>
#define ff first
#define ss second
#define pb push_back
const ll N = 1e5 + 10;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
const ll mod = 1e9 + 7;
#define ll long long
#define vi vector < int >

vi pri = {2,5};
void dfs(int i, vector < vi > &adj, vi &ans, int par, int ind, map < pair<int,int>, int> &m){
    ans[ m[{i,par}]] = pri[ind];
    for (auto &x : adj[i]){
        if (x == par) continue;
        dfs(x,adj, ans,i, 1 - ind,m);
    }
}
 
void solve()
{ 
    int n;
    cin >> n;
    vector < vi > adj(n);
    int u, v;
    map < pair<int,int > , int > m;
    for (int i= 0; i < n - 1; i++){
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        m[{u,v}] = i;
        m[{v,u}] = i;
    }
    int node ;
    for (int i = 0; i < n; i++){
        if (adj[i].size() > 2){
            cout << -1 << endl;
            return;
        }
        if (adj[i].size() == 1) node = i;
    }
    vector < int > ans(n - 1);
    dfs(adj[node][0], adj, ans,node, 0,m);
 //   cout<<'\n';
  //  for (auto &x : m)cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<'\n'; 
     for (auto &x : ans) cout << x << " ";
     cout << endl;
}

int main()
{
    FAST;

    ll t;
    // t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}