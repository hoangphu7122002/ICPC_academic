#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u,v,w;
    Edge(int u,int v,int w) : u(u),v(v),w(w) {};
};
vector <Edge> edges;
int N,M, totalWeight = 0;

struct DSU {
    vector <int> par;
    void init(int n) {
        par.resize(n + 1,0);
        for (int i = 1; i <= n; ++i) {
            par[i] = i;
        }
    }
    
    int find(int n) {
        if (par[n] == n) return n;
        return par[n] = find(par[n]);
    }
    
    bool join(int u,int v) {
        u = par[u];
        v = par[v];
        if (u == v) return false;
        par[v] = u;
        return true;
    }
} dsu;

int main () {
    cin >> N >> M;
    for (int i = 1; i <= M; ++i) {
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }
    
    sort(edges.begin(),edges.end(),[](Edge &x, Edge &y){
        return x.w < y.w;
    });
    
    dsu.init(N);
    
    for (auto e : edges) {
        if (!dsu.join(e.u,e.v)) continue;
        totalWeight += e.w;
    }   
    
    cout << totalWeight << endl;
    
    return 0;
}