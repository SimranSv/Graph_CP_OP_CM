#include "bits/stdc++.h"
using namespace std;
const int N = 1e5;
vector<int> adj[N + 1];
vector<int> vis(N + 1);

bool check(int i)
{
    queue<pair<int, int>> Q;
    int par = Q.front().second;
    int node = Q.front().first;
    Q.pop();

    Q.push({i, -1});

    for (auto &j : adj[i])
    {
        if (!vis[j])
        {
            Q.push({j, i});
            vis[j] = 1;
        }
        else
        {
            if (j != par)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int count = 0;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (check(i))
            {
                count++;
            }
        }
    }
    cout << count << '\n';
}