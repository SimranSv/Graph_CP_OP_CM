#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define FAST                          \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
#define readInputFile                 \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout);
const ll N = 1e5 + 10;
const ll inf = 1e8 + 10;
vector<pair<ll, ll>> pre = {{-1, -2}, {1, -2}, {2, -1}, {-2, -1}, {2, 1}, {-2, 1}, {1, 2}, {-1, 2}};
bool is_valid(ll x, ll y)
{
    if (x >= 0 && y >= 0 && x < 8 && y < 8)
        return true;
    return false;
}
ll getx(string s)
{
    return s[0] - 'a';
}
ll gety(string s)
{
    return s[1] - '1';
}
void solve()
{
    string s, des;
    cin >> s >> des;
    ll n = 8;
    ll x = getx(s);
    ll y = gety(s);
    ll desx = getx(des);
    ll desy = gety(des);
    queue<pair<ll, ll>> Q;
    Q.push({x, y});

    int vis[n][n], lvl[n][n];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            lvl[i][j] = 0;
            vis[i][j] = 0;
        }
    }
    while (!Q.empty())
    {
        pair<ll, ll> ans = Q.front();
        ll x_s = ans.first;
        ll y_s = ans.second;
        Q.pop();

        for (auto &j : pre)
        {
            if (is_valid(x_s + j.first, y_s + j.second))
            {
                if (!vis[x_s + j.first][y_s + j.second])
                {
                    Q.push({x_s + j.first, y_s + j.second});
                    vis[x_s + j.first][y_s + j.second] = 1;
                    lvl[x_s + j.first][y_s + j.second] += lvl[x_s][y_s] + 1;
                }
            }
        }
        if (lvl[desx][desy] != 0)
        {
            cout << lvl[desx][desy] << '\n';
            break;
        }
    }
}
int main()
{
    FAST;
    ll t;
    cin >> t;
    while (t--)
        solve();
}