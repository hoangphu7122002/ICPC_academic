#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;
vector <int> g[maxN];
vector <int> L(2*maxN,0);
vector <int> visited(maxN,0);
vector <int> h(maxN,0);
vector <int> E(2*maxN,0); //EulerTour
vector <int> H(maxN,-1);
int timeBase = 1;

void dfs(int u){
    visited[u] = true;
    L[timeBase] = h[u];
    if (H[u] == -1) {
        H[u] = timeBase;
    }
    E[timeBase++] = u;
    for (auto v : g[u]) {
        if (visited[v]) continue;
        h[v] = h[u] + 1;
        dfs(v);
        L[timeBase] = h[u];
        E[timeBase++] = u;
    }
}

int main() {
    int N,M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i < timeBase; ++i) {
        cout << E[i] << " ";
    }
    cout << endl;
    for (int i = 1; i < timeBase; ++i) {
        cout << L[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= N; ++i) {
        cout << H[i] << " ";
    }
    cout << endl;
    return 0;
}