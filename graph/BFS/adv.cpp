#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>

const int maxN = 2001;
vector <int> par(maxN,0);

struct DSU {
    int root(int v) {
        if (par[v] <= 0) return v;
        return par[v] = root(par[v]);
    }
    void join(int u,int v) {
        if (par[u] == par[v]) par[u]--; 
        if (par[u] > par[v]) swap(u,v);
        par[v] = u;
    }
} DS;  

int main() {
    int N, M;
    cin >> N >> M;
    int res = M;
    int u,v;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        int x = DS.root(u);
        int y = DS.root(v);
        if (x != y) {
            DS.join(x,y);
            res--;
        }
    }
    
    cout << res << endl;
    
    return 0;
}