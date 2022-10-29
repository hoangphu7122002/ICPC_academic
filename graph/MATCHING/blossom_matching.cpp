#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;
vector <int> g[maxN];
vector <int> match(maxN,-1);
vector <int> aux(maxN,-1);
vector <int> label(maxN,0);
vector <int> parent(maxN,0);
vector <int> orig(maxN,0);
queue <int> q; //for bfs
int M,N;

int time_ = 0;

int lca(int x,int y) {
    for (time_++; ; swap(x,y)) {
        if (x == -1) continue;
        if (aux[x] == time_) return x;
        aux[x] = time_;
        x = (match[x] == -1 ? -1: orig[parent[match[x]]]);
    }
    return -1;
}

void augment(int v) {
    while (v != -1) {
        int pv = parent[v], nv = match[pv];
        match[v] = pv; match[pv] = v; v = nv;
    }
}

void blossom(int v,int w, int a) {
    while (orig[v] != a) {
        parent[v] = w;
        w = match[v];
        if (label[w] == 1) {
            label[w] = 0;
            q.push(w);
        }
        orig[v] = orig[w] = a;
        v = parent[w];
    }
}

bool bfs(int root) {
    fill(label.begin(),label.end(),-1);
    iota(orig.begin(),orig.end(),0);
    q = queue<int>();
    label[root] = 0;
    q.push(root);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (label[v] == -1) {
                label[v] = 1;
                parent[v] = u;
                
                if (match[v] == -1) {
                    augment(v);
                    return true;
                }
                label[match[v]] = 0;
                q.push(match[v]);
            }  
            else if (label[v] == 0 && orig[v] != orig[u]) {
                int a = lca(orig[v],orig[u]);
                blossom(v,u,a);
                blossom(u,v,a);   
            }
        }
    }
    return false;
}

int get_match() {
    for (int i = 0; i < N; ++i) {
        if (match[i] == -1) bfs(i);
    }
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (match[i] >= 0) ++count;
    }
    return count/2;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    cout << get_match() << endl;
    for (int i = 0; i < N; ++i) {
        if (match[i] >= 0) {
            cout << match[i] << " " << i << endl;
            match[match[i]] = -1;
        }
    }
    
    return 0;
}