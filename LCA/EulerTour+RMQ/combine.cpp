#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;
const int inf = 1e5 + 1;
int st[4 * maxN];
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

void build(int id,int l,int r) {
    if (l == r) {
        st[id] = l;
        return;
    }
    int mid = l + r >> 1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    
    if (L[st[2*id]] <= L[st[2*id+1]]) 
        st[id] = st[2*id];
    else st[id] = st[2*id + 1];
}

int get(int id,int l,int r,int u,int v) {
    if (l > v || r < u) return -1;
    if (l >= u && r <= v) return st[id];
    int mid = l + r >> 1;
    int get1 = get(2 * id,l,mid,u,v);
    int get2 = get(2 * id+1,mid+1,r,u,v);
    if (get1 == -1) return st[id] = get2;
    if (get2 == -1) return st[id] = get1;
    if (L[get1] <= L[get2]) return st[id] = get1;
    else return st[id] = get2;
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
    build(1,1,timeBase);
    cout << "timeBase: " << timeBase << endl;
    int Q;
    cin >> Q;
    int i = 1;
    while (Q--) {
        int u,v;
        cin >> u >> v;
        cout << H[u] << " " << H[v] << endl;
        if (H[u] > H[v]) swap(u,v);
        cout << get(1,1,timeBase,H[u],H[v]) << endl;
        cout << i << " " << E[get(1,1,timeBase,H[u],H[v])] << endl;
        i++;
    } 
    return 0;
}