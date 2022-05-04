//https://www.spoj.com/problems/BITMAP/
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
const ll inf = 1e18 + 7;
vector<pair<ll, ll>> traversal = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
ll n, m;
bool isvalid(ll x, ll y)
{
    if (x >= 0 && y >= 0 && x < n && y < m)
        return 1;
    else
        return 0;
}
void solve()
{

    cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll>(m));
    vector<vector<ll>>dis(n, vector<ll>(m));
    queue<pair<ll, ll>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dis[i][j] = inf;
        }
    }
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        for (int j = 0; j < m; j++)
        {
             v[i][j]=(s[j]-'0');
            if (v[i][j] == 1)
            {
                q.push({i, j});
                dis[i][j] = 0;
               
            }
        }
    }
    while (!q.empty())
    {
        pair<ll, ll> pp;
        pp = q.front();
        q.pop();
        ll nx = pp.first;
        ll ny = pp.second;
        for (auto &i : traversal)
        {
            if (isvalid(nx + i.first, ny + i.second))
            {
                
                if (dis[nx][ny] + 1 < dis[nx + i.first][ny + i.second])
                {
                    dis[nx + i.first][ny + i.second] = dis[nx][ny] + 1;
                    q.push({nx + i.first, ny + i.second});
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << '\n';
    }
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();
}