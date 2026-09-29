#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> parent, rankValue;

    DSU(int n)
    {
        parent.resize(n + 1);
        rankValue.assign(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = find(parent[node]);
    }

    bool unite(int a, int b)
    {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB)
        {
            return false;
        }

        if (rankValue[rootA] < rankValue[rootB])
        {
            swap(rootA, rootB);
        }

        parent[rootB] = rootA;

        if (rankValue[rootA] == rankValue[rootB])
        {
            rankValue[rootA]++;
        }

        return true;
    }
};

struct Edge
{
    int u, v, w;
};

int main()
{
    int n, k, m;
    cin >> n >> k >> m;

    DSU dsu(n);
    int components = n;

    for (int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v;

        if (dsu.unite(u, v))
        {
            components--;
        }
    }

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.w < b.w; });

    int totalCost = 0;

    for (const Edge &edge : edges)
    {
        if (components == 1)
        {
            break;
        }

        if (dsu.unite(edge.u, edge.v))
        {
            totalCost += edge.w;
            components--;
        }
    }

    cout << (components == 1 ? totalCost : -1) << '\n';

    return 0;
}
