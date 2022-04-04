#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        set<int> st;
        int N, m;
        cin >> N >> m;
        vector<node> edges;
        for (int i = 0; i < m; i++)
        {
            int u, v, wt;
            cin >> u >> v >> wt;
            edges.push_back(node(u, v, wt));
            st.insert(edges[i].u);
            st.insert(edges[i].v);
        }

        int src = edges[0].u;

        int inf = 10000000;
        vector<int> dist(inf, inf);

        dist[src] = 0;

        for (int i = 1; i <= N - 1; i++)
        {
            for (auto it : edges)
            {
                if (dist[it.u] + it.wt < dist[it.v])
                {
                    dist[it.v] = dist[it.u] + it.wt;
                }
            }
        }

        int fl = 0;
        for (auto it : edges)
        {
            if (dist[it.u] + it.wt < dist[it.v])
            {
                cout << "Negative Cycle";
                fl = 1;
                break;
            }
        }
        cout<<'\n';

        if (!fl)
        {
            for (auto &i : st)
            {
                cout << i << " " << dist[i] << "\n";
            }
        }
    }
    return 0;
}