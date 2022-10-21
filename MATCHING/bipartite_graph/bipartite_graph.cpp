#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;
vector <int> g[maxN];
vector <int> color(maxN);
vector <int> visited(maxN,0);
int N,M;

bool invalid = false;

void dfs(int u) {
    visited[u] = true;
    for (auto v : g[u]) {
        if (visited[v]) {
            if (color[v] == color[u]) invalid = true;
            return;
        }
        color[v] = -color[u];
        dfs(v);
    }
}

int main() {
    cin >> N >> M;
    
    while (M--) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            color[i] = 1;
            dfs(i);
            if (invalid == true) {
                break;
            }
        }
    }
    if (invalid == true) cout << "not bipartite_graph" << endl;
    else cout << "do something" << endl;
    
    return 0;
}