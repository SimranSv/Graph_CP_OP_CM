#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define vll vector<ll>
const ll mod = 1e9 + 7;
ll n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
const int N = 1e5 + 10;
//vector<vector<ll>> vis(N, vector<ll>(N));
ll vis[1010][1010]={{0,0}};
char st[1010][1010];
bool isValid(ll x, ll y)
{
    if (x < 1 || y > m || x > n || y < 1)
        return false;
    if (vis[x][y] == 1||st[x][y]=='#')
        return false;

    return true;
}
void dfs(ll x, ll y)
{
    // for grids,check up down right and left
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
        {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}
void solve()
{

    cin >> n >> m;
    ll count = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            cin >> st[i][j];
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (st[i][j] == '.' && !vis[i][j])
            {
                count++;
                dfs(i, j);
            }
        }
    }
    cout << count << '\n';
}
int main()
{
    ll t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
}
