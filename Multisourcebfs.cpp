#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
const ll inf = 1e9 + 7;
const ll N = 1e3 + 10;
ll n, m;
vector<vector<ll>> v(N, vector<ll>(N));
vector<vector<ll>> vis(N, vector<ll>(N));
vector<vector<ll>> lvl(N, vector<ll>(N));

vector<pair<ll, ll>> validind = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {0, -1}, {0, 1}, {-1, 0}, {1, 0}};
bool isvalid(ll x, ll y)
{
    if (x >= 0 && y >= 0 && x < n && y < m)
        return true;
    return false;
}
void bfs(ll maxi)
{
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            lvl[i][j] = inf;
        }
    }
    queue<pair<ll, ll>> q;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (v[i][j] == maxi)
            {
                q.push({i, j}), lvl[i][j] = 0;
            }
        }
    }
    ll mm = 0;
    while (!q.empty())
    {
        pair<ll, ll> ind = q.front();
        ll i = ind.first;
        ll j = ind.second;
        q.pop();
        for (auto &u : validind)
        {
            ll x = u.first + i;
            ll y = u.second + j;
            if (isvalid(x, y))
            {

                if (lvl[i][j] + 1 < lvl[x][y])
                {
                    lvl[x][y] = lvl[i][j] + 1;
                    q.push({x, y});
                }
                mm = max(mm, lvl[i][j]);
            }
        }
    }

    cout << mm << '\n';
}
void solve()
{

    cin >> n >> m;
    ll maxi = 0;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> v[i][j];
            maxi = max(maxi, v[i][j]);
        }
    }
    bfs(maxi);
}
int main()
{
    ll t;
    // t=1
    cin >> t;
    while (t--)
        solve();
}