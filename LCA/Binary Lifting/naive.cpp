#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;
vector <int> edge[maxN];
vector <int> p(maxN,0);
vector <int> h(maxN,0);

//O(Q * N)

void dfs(int u,int par = -1) {
    for (auto v : edge[u]) {
        if (v == par) continue;
        p[v] = u;
        h[v] = h[u] + 1;
        dfs(v,u);
    }
}

void lca(int u,int v) {
    if (h[u] < h[v]) swap(u,v);
    while (h[u] > h[v]) {
        u = p[u];
    }
    
    while (u != v) {
        u = p[u];
        v = p[v];
    }
}