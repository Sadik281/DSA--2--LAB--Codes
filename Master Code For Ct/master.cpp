#include <iostream>
#include <vector>
#include <queue>
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
};

struct Edge {
    int u, v;
    long long w;
};

long long kruskal(vector<Edge> edges, int n, bool maximum) {
    if (maximum) {
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.w > b.w;
        });
    }
    else {
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.w < b.w;
        });
    }

    DSU dsu(n);

    long long ans = 0;
    int cnt = 0;

    for (Edge e : edges) {
        if (dsu.unite(e.u, e.v)) {
            ans += e.w;
            cnt++;

            if (cnt == n - 1)
                break;
        }
    }

    if (cnt != n - 1)
        return -1;

    return ans;
}

long long prim(vector<vector<pair<int, long long>>> &graph, int n, bool maximum) {
    vector<long long> best(n, LLONG_MIN);
    vector<bool> used(n, false);

    best[0] = 0;

    long long ans = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!used[j]) {
                if (u == -1 || best[j] > best[u])
                    u = j;
            }
        }

        if (u == -1 || best[u] == LLONG_MIN)
            return -1;

        used[u] = true;
        ans += best[u];
        cnt++;

        for (auto x : graph[u]) {
            int v = x.first;
            long long w = x.second;

            if (!used[v]) {
                if (maximum) {
                    if (w > best[v])
                        best[v] = w;
                }
                else {
                    if (best[v] == LLONG_MIN || w < best[v])
                        best[v] = w;
                }
            }
        }
    }

    if (cnt != n)
        return -1;

    return ans;
}

long long completePrim(vector<int> &a, bool maximum) {
    int n = a.size();

    vector<long long> best(n, LLONG_MIN);
    vector<bool> used(n, false);

    best[0] = 0;

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!used[j]) {
                if (u == -1 || best[j] > best[u])
                    u = j;
            }
        }

        used[u] = true;
        ans += best[u];

        for (int v = 0; v < n; v++) {
            if (!used[v]) {

                long long w = a[u] ^ a[v];

                if (maximum) {
                    if (w > best[v])
                        best[v] = w;
                }
                else {
                    if (best[v] == LLONG_MIN || w < best[v])
                        best[v] = w;
                }
            }
        }
    }

    return ans;
}

void bfs(vector<vector<pair<int, long long>>> &graph, int start) {
    int n = graph.size();

    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (auto x : graph[u]) {
            int v = x.first;

            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void dfsUtil(vector<vector<pair<int, long long>>> &graph,
             int u,
             vector<bool> &visited) {

    visited[u] = true;

    cout << u << " ";

    for (auto x : graph[u]) {
        int v = x.first;

        if (!visited[v])
            dfsUtil(graph, v, visited);
    }
}

void dfs(vector<vector<pair<int, long long>>> &graph, int start) {
    int n = graph.size();

    vector<bool> visited(n, false);

    dfsUtil(graph, start, visited);
}

vector<long long> dijkstra(
    vector<vector<pair<int, long long>>> &graph,
    int start) {

    int n = graph.size();

    vector<long long> dist(n, LLONG_MAX);

    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {

        long long d = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        if (d != dist[u])
            continue;

        for (auto x : graph[u]) {

            int v = x.first;
            long long w = x.second;

            if (dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;

                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int components(vector<vector<pair<int, long long>>> &graph) {
    int n = graph.size();

    vector<bool> visited(n, false);

    int cnt = 0;

    for (int i = 0; i < n; i++) {

        if (!visited[i]) {

            cnt++;

            queue<int> q;

            q.push(i);
            visited[i] = true;

            while (!q.empty()) {

                int u = q.front();
                q.pop();

                for (auto x : graph[u]) {

                    int v = x.first;

                    if (!visited[v]) {

                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }

    return cnt;
}

int main() {

    int n, m;

    cin >> n >> m;

    vector<vector<pair<int, long long>>> graph(n);

    vector<Edge> edges;

    for (int i = 0; i < m; i++) {

        int u, v;
        long long w;

        cin >> u >> v >> w;

        u--;
        v--;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});

        edges.push_back({u, v, w});
    }

    long long minimumMST = kruskal(edges, n, false);

    long long maximumMST = kruskal(edges, n, true);

    long long minimumPrim = prim(graph, n, false);

    long long maximumPrim = prim(graph, n, true);

    return 0;
}