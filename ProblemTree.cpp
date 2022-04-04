/*
in given Query V, Print Subtree Sum of V
& even Number no's in Subtree
of V*/

#include "bits/stdc++.h"
using namespace std;
#define ll long long
const ll N = 1e5 + 10;

void dfs(int i, int par, vector<int> adj[], vector<int> &sum, vector<int> &even)
{
    sum[i] = i;
    if (i % 2 == 0)
        even[i]++;
    for (auto &j : adj[i])
    {
        if (j == par)
            continue;

        dfs(j, i, adj, sum, even);

        sum[i] += sum[j];

        even[i] += even[j];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> sum(N, 0), even(N, 0);
    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, adj, sum, even);
    cout << "Taking Sum Bruh\n";

    for (int i = 1; i <= n; i++)
    {
        cout << "Sum " << i << " " << sum[i] << '\n';
    }

    cout << "Even Number's count bruh\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "Total EvenNo's " << i << " " << even[i] << '\n';
    }
}