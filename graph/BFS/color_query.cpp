#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>

const int maxN = 100001;
vector <int> a(maxN);
map <pii,int> mp;
set <int> st[maxN];

struct DSU{
    int par[maxN];
    int rank[maxN];
    
    int root(int u) {
        if (par[u] == 0) return u;
        return par[u] = root(par[u]);
    }
    void combine(int u,int v) {
        for (auto ele : st[v]) {
            mp[{u,ele}] += mp[{v,ele}];
            st[u].insert(ele);
            // cout << u << v << ele << endl;
        }
    }
    
    void join(int u,int v) {
        u = root(u);
        v = root(v);
        if (u == v) return;
        if (rank[u] == rank[v]) rank[u]++;
        if (rank[u] < rank[v]) {
            par[u] = v;
            combine(v,u);
        }
        else {
            par[v] = u;
            combine(u,v);
        }
    }
} DS;

int main() {
    // freopen("A.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mp[{i,a[i]}] += 1;
        st[i].insert(a[i]);
    }
    for (int i = 0;i < q;++i) {
        int z, u,v;
        cin >> z >> u >> v;
        if (z == 1) {
            DS.join(u,v);
        }
        else {
            u = DS.root(u);
            cout << mp[{u,v}] << endl;
        }
    }
    return 0;
}