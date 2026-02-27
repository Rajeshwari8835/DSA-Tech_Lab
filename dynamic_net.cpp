#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    vector<int> disc, low;
    vector<bool> visited;
    int timer;

public:
    Graph(int v) {
        V = v;
        adj.resize(V);
        disc.resize(V);
        low.resize(V);
        visited.resize(V, false);
        timer = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int parent) {
        visited[u] = true;
        disc[u] = low[u] = timer++;

        for(int v : adj[u]) {
            if(v == parent) continue;

            if(!visited[v]) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                if(low[v] > disc[u])
                    cout << "Bridge: " << u << " - " << v << endl;
            }
            else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    void findBridges() {
        for(int i = 0; i < V; i++)
            if(!visited[i])
                dfs(i, -1);
    }
};