// Coming back to CP soon guys...
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define stll set<ll>
#define msgll multiset<ll, greater<>>
#define msll multiset<ll>
#define pll pair<ll, ll>
#define mpll map<ll, ll>
#define vpll vector<pair<ll, ll>>
#define ss second
#define ff first
#define read(n, x)             \
    for (ll i = 0; i < n; i++) \
    {                          \
        ll k;                  \
        cin >> k;              \
        x.pb(k);               \
    }
#define rep(i, j, k) for (ll i = j; i < k; i++)
#define st(v) sort(v.begin(), v.end())
#define sz(x) (ll) x.size()
#define no cout << "No\n";
#define yes cout << "Yes\n";
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const ll mod = 1e9 + 7;
const ll N = 2e5 + 10;
ll expo(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b = b >> 1;
    }
    return res;
}
double eps = 1e-6;
// Remove fastio and use endl in Interactive problems
void Letsgo()
{
    ll n = 7;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vll vis(7);
    vector<pair<int, int>> mst;
    vector<pair<int, int>> adj[7];
    // adj[0].pb({1, -1});
    adj[4].pb({3, 5});
    adj[4].pb({1, 1});
    adj[4].pb({2, 3});
    adj[1].pb({2, 2});
    adj[3].pb({2, 3});
    adj[3].pb({6, 8});
    adj[2].pb({6, 7});
    adj[5].pb({4, 9});
    adj[5].pb({1, 4});

    adj[3].pb({4, 5});
    adj[1].pb({4, 1});
    adj[2].pb({4, 3});
    adj[2].pb({1, 2});
    adj[2].pb({3, 3});
    adj[6].pb({3, 8});
    adj[6].pb({2, 7});
    adj[4].pb({5, 9});
    adj[1].pb({5, 4});

    //{weight,{node1,node2}}
    // edge between node1 and node2

    pq.push({0, {1, -1}});

    int sum = 0;

    while (!pq.empty())
    {
        int val = pq.top().ff;
        int node1 = pq.top().ss.ff;
        int node2 = pq.top().ss.ss;
        
         pq.pop();
        if (!vis[node1])
        {
            sum += val;           
            vis[node1] = 1;
            for (auto &i : adj[node1])
            {

                pq.push({i.ss, {i.ff, node1}});
               
            }
            if(node2!=-1)
             mst.push_back({node1,node2});
        }
    }
    rep(i,0,sz(mst)){
        cout<<mst[i].ff<<" "<<mst[i].ss<<'\n';
    }
    cout << sum << '\n';
}
int main()
{
    FAST;

    ll n = 1, i = 0;
    // cin >> n;

    while (n--)
    {
        Letsgo();
    }
}
// Working hard to get what is mine