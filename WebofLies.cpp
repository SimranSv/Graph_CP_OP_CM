//Simran Vedpathak
//CF
//https://codeforces.com/problemset/problem/1548/A

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
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        v[min(x, y)]++;
    }
    ll q;
    cin >> q;
    ll count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i])
        {
            count++;
        }
    }
    while (q--)
    {
        ll ug;
        ll x, y;
        cin >> ug;
        if (ug == 3)
            cout << n - count << '\n';
        if (ug == 1)
        {

            cin >> x >> y;
             v[min(x, y)]++;
            if (v[min(x, y)]==1)
            {
                count++;
                continue;
            }
           
        }
        else if (ug == 2)
        {

            cin >> x >> y;
            v[min(x, y)]--;
            if (!v[min(x, y)])
            {
                count--;
                continue;
            }
        }
    }
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
