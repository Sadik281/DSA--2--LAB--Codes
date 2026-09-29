#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    double probability;
};



int main() {
   

    int n, e, s, t;
    cin >> n >> e >> s >> t;

    vector<vector<Edge>> graph(n + 1);

    for (int i = 0; i < e; i++) {
        int u, v, r;
        cin >> u >> v >> r;
        graph[u].push_back({v, r / 1000.0});
    }

    vector<double> best(n + 1, 0.0);
    priority_queue<pair<double, int>> pq;

    best[s] = 1.0;
    pq.push({1.0, s});

    while (!pq.empty()) {
        double currentProbability = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (currentProbability < best[node]) {
            continue;
        }

        if (node == t) {
            break;
        }

        for (const Edge& edge : graph[node]) {
            double nextProbability = currentProbability * edge.probability;

            if (nextProbability > best[edge.to]) {
                best[edge.to] = nextProbability;
                pq.push({nextProbability, edge.to});
            }
        }
    }

    if (best[t] == 0.0) {
        cout << -1 << '\n';
    } else {
        cout << fixed << setprecision(6) << best[t] << '\n';
    }

    return 0;
}
