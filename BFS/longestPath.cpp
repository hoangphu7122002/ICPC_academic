#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;
vector <int> g[maxN];
vector <bool> visited(maxN,0);
vector <int> dist(maxN,0);

void dfs(int u) {
    visited[u] = true;
    for (auto v : g[u]) {
        if (!visited[v]) dfs(v); 
        if (dist[u] < dist[v] + 1) dist[u] = dist[v] + 1;
    }
}

int main(){
    int N,M;
    cin >> N >> M;
    
    int u,v;    
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            dist[i] = 0;
            dfs(i);
        }
    }
    
    cout << *max_element(dist.begin(),dist.end()) << endl;
    
    return 0;
}