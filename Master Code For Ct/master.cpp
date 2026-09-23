#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];

        return true;
    }

    int size(int x) {
        return sz[find(x)];
    }
};

struct Edge {
    int u, v;
    long long w;
};

long long kruskalMin(int n, vector<Edge> edges) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    DSU dsu(n);
    long long ans = 0;

    for (Edge e : edges) {
        if (dsu.unite(e.u, e.v))
            ans += e.w;
    }

    return ans;
}

long long kruskalMax(int n, vector<Edge> edges) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w > b.w;
    });

    DSU dsu(n);
    long long ans = 0;

    for (Edge e : edges) {
        if (dsu.unite(e.u, e.v))
            ans += e.w;
    }

    return ans;
}

long long primMin(vector<vector<pair<int, long long>>> &g) {
    int n = g.size();

    vector<long long> best(n, LLONG_MAX);
    vector<bool> used(n, false);

    best[0] = 0;

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!used[j] && (u == -1 || best[j] < best[u]))
                u = j;
        }

        if (u == -1 || best[u] == LLONG_MAX)
            return -1;

        used[u] = true;
        ans += best[u];

        for (auto x : g[u]) {
            int v = x.first;
            long long w = x.second;

            if (!used[v] && w < best[v])
                best[v] = w;
        }
    }

    return ans;
}

long long primMax(vector<vector<pair<int, long long>>> &g) {
    int n = g.size();

    vector<long long> best(n, -1);
    vector<bool> used(n, false);

    best[0] = 0;

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!used[j] && (u == -1 || best[j] > best[u]))
                u = j;
        }

        if (u == -1 || best[u] == -1)
            return -1;

        used[u] = true;
        ans += best[u];

        for (auto x : g[u]) {
            int v = x.first;
            long long w = x.second;

            if (!used[v] && w > best[v])
                best[v] = w;
        }
    }

    return ans;
}

long long completePrimMax(vector<int> &a) {
    int n = a.size();

    vector<long long> best(n, -1);
    vector<bool> used(n, false);

    best[0] = 0;

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!used[j] && (u == -1 || best[j] > best[u]))
                u = j;
        }

        used[u] = true;
        ans += best[u];

        for (int v = 0; v < n; v++) {
            if (!used[v]) {
                long long w = a[u] ^ a[v];

                if (w > best[v])
                    best[v] = w;
            }
        }
    }

    return ans;
}

int gridId(int r, int c, int cols) {
    return r * cols + c;
}

void connectGrid(vector<vector<int>> &grid, DSU &dsu) {
    int r = grid.size();
    int c = grid[0].size();

    int dr[] = {1, 0};
    int dc[] = {0, 1};

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {

            if (grid[i][j] == 0)
                continue;

            for (int k = 0; k < 2; k++) {
                int ni = i + dr[k];
                int nj = j + dc[k];

                if (ni < r && nj < c && grid[ni][nj] == 1) {
                    dsu.unite(
                        gridId(i, j, c),
                        gridId(ni, nj, c)
                    );
                }
            }
        }
    }
}