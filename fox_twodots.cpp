//https://codeforces.com/contest/510/problem/B
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
const ll INF = 1e9 + 7;
const ll N = 1e5 + 10;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
char v[51][51];
bool vis[51][51];
vector<pair<ll, ll>> traversal={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
ll n, m;
bool isvalid(ll x, ll y)
{
    if ((x >= 0 && y >= 0 )&& (x < n && y < m))
        return true;
    else
        return false;
}
void dfs(ll st, ll st1, ll par, ll par2)
{
    vis[st][st1] = 1;
    for (auto &i : traversal)
    {
      
        if (isvalid(st + i.first, st1 + i.second))
        {
            if (st + i.first == par && st1 + i.second == par2)continue;
            if (v[st + i.first][st1 + i.second] != v[st][st1])continue;  
            if (!vis[st + i.first][st1 + i.second])                            
            dfs(st + i.first, st1 + i.second, st, st1);
            else
            {
                cout << "Yes\n";
                exit(0);
            }
        }
    }
    
}
void solve()
{
   
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
           // cout<<v[i][j];
            if (!vis[i][j])
                dfs(i, j, -1, -1);
        }
      
    }
    cout << "No\n";
}
int main()
{
    FAST;
    ll t;
    t = 1;

    while (t--)
    {
        solve();
    }
}