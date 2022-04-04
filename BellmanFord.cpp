#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
const ll INF = 1e9 + 7;
const ll N = 1e5 + 10;

ll n, m;

struct edge
{
    int a, b, cost;
};

void solve(ll v, ll n, ll m, vector<edge> e, set<int> st)
{

    vector<int> d(N, INF);

    d[v] = 0;
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < m; ++j)
            if (d[e[j].a] < INF)
            {
                d[e[j].b] = min(d[e[j].b], d[e[j].a] + e[j].cost);
                st.insert(e[i].a);
                st.insert(e[i].b);
            }
    for (ll j = 0; j < m; j++)
    {
        if (d[e[j].a] < INF)
        {
            if (d[e[j].a] + e[j].cost < d[e[j].b])
            {
                cout << "Negative Cycle\n";
                return;
            }
        }
    }
    for (auto &i : st)
    {
        cout << i << " " << d[i] << "\n";
    }
    //  for (ll j = 0; j < m; j++)
    // {
    //     cout<<e[j].a<<" "<<d[e[j].a]<<'\n';
    // }
    cout << '\n';
}
int main()
{
    vector<edge> e(N);
    ll t;
    cin >> t;
    set<int> st;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> e[i].a >> e[i].b >> e[i].cost;
        }
        ll k = e[0].a;
        solve(k, n, m, e, st);
    }
}