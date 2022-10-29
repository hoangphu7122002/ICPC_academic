#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;
vector <int> g[maxN];
vector <int> par(maxN,-1);
vector <int> child_first(maxN);
vector <bool> visited(maxN,0);
stack <int> stk;

int find(int u) {
    if (par[u] == u) return u;
    return par[u] = find(par[u]);
}

void dfs(int u) {
    visited[u] = true;
    par[u] = u;
    stk.push(u);
    
    for (auto v : g[u]) {
        if (visited[v]) {
            v = find(child_first[v]);
            while (stk.size() && stk.top() != v) {
                par[find(stk.top())] = v;
                stk.pop();
            }
        }
    }
    
    for (auto v : g[u]) {
        if (!visited[v]) {
            child_first[u] = v;
            dfs(v);
        }
    }
    
    if (stk.top() == u) stk.pop();
}

int main() {
    int N,M;
    cin >> N >> M;
    
    for (int i = 0; i < M; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    
    dfs(1);
    cout << "=================" << endl;
    for (int i = 1; i <= N; ++i) {
        cout << i << " " << par[i] << endl;
    }
    cout << "=================" << endl;
    
    return 0;
}