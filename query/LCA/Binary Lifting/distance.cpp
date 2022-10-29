#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;
vector <int> edge[maxN];
int w[maxN][maxN];
vector <int> par(maxN,0);
vector <int> h(maxN,0);
vector <int> dist(maxN,0);
int n;

void dfs(int u,int p =-1) {
    for (auto v : edge[u]) {
        if (v == p) continue;
        par[v] = u;
        h[v] = h[u] + 1;
        dist[v] = dist[u] + w[u][v];
        dfs(v,u);
    }
}

int up[maxN][17];
void preprocess_k() {
    for (int u = 1; u <= n; ++u) up[u][0] = par[u];
    for (int j = 1; j < 17; j++) {
        for (int u = 1; u <= n; ++u) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }
    }           
}
int ancestor_u_v(int u,int v) {
    //h[ancestor_i[u]] = h[v]
    int k = h[u] - h[v];
    for (int j = 0; (1 << j) <= k; ++j)
        if (k >> j & 1) u = up[u][j];
    return u;
}

int LCA(int u,int v) {
    if (u == v) {
        return u;
    }
    if (h[u] < h[v]) swap(u,v);
    //find ancestor u so: h[ancestor_i[u]] = h[v]
    u = ancestor_u_v(u,v);
    int k = __lg(h[u]);
    for (int j = k; j >= 0; j--) {
        if (up[u][j] != up[v][j]) u = up[u][j], v = up[v][j];
    }
    return up[u][0];
}

int distanceK(int u,int v) {
    int p = LCA(u,v);
    return dist[u] + dist[v] - dist[p];
}

