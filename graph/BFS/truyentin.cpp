#include <bits/stdc++.h>

using namespace std;

const int maxN = 801;
vector <int> g[maxN];
vector <int> visited(maxN,0);
vector <int> mark(maxN,0);

void dfs(int u){
    visited[u] = true;
    for (auto v : g[u]) {
        if (visited[v]) continue;
        dfs(v);
    }
}

int main() {
    int N,M;
    cin >> N >> M;
    
    for (int i = 0; i < M; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            mark[i] = true;
            dfs(i);
        }
    }
    
    
    int count = 0;
    visited.clear();
    visited.resize(maxN,false);
    // for (int i = 1; i <= N; ++i) {
    //     cout << i << " " << mark[i] << " " << visited[i] << endl;
    // }
    
    for (int i = N; i >= 1; --i) {
        if (mark[i] == true && !visited[i]) {
            count++;
            dfs(i);
        }
    }
    cout << count;
    
    return 0;
}