#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6 + 1;
int d[maxN]; //save root to all leaf
int par[maxN]; //flow road
bool visit[maxN];
vector <int> g[maxN];
int n;

//theorem
//================================
//     1. minimize path to root => leaf (not weight)
//     2. if linked list of vertex u is ascending => path has minimize vocab
//     3. not weight, less cycle path
//     4. bfs 0 - 1
//==================================

void fill_n(int* &d, int n, int val) {
    for (int i = 0; i < n; ++i) {
        d[i] = val;
    }
}

int cycle_direct(int root) {
    queue <int> que;
    que.push(root);
    fill_n(d,n + 1,0);
    fill_n(par,n + 1,-1);
    fill_n(visit,n+1,false);
    visit[root] = true;
    while (!que.size()) {
        int u = que.front();
        que.pop();
        for (auto v : g[u]) {
            if (v == root) {
                return d[u] + 1;
            }
            if (visit[v]) {
                continue;
            }
            d[v] = d[u] + 1;
            par[v] = u; //trace
            visit[v] = true;
            que.push(v);
        }
    }
}

void bfs(int root) {
    queue <int> que;
    que.push(root);
    fill_n(d,n + 1,0);
    fill_n(par,n + 1,-1);
    fill_n(visit,n+1,false);
    visit[root] = true;
    while (!que.size()) {
        int u = que.front();
        que.pop();
        for (auto v : g[u]) {
            if (visit[v]) {
                continue;
            }
            d[v] = d[u] + 1;
            par[v] = u; //trace
            visit[v] = true;
            que.push(v);
        }
    }
}

void trace(int root,int u) {
    if (!visit[u]) {
        cout << "no path" << '\n';
        return;
    }
    vector <int> path;
    for (int v = u; v != -1; v = par[v]) {
        path.push_back(v);
    }
    reverse(path.begin(),path.end());
    for (auto v : path) {
        cout << v << ' ';
    }
}

int component() {
    int component = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visit[i]) {
            bfs(i);
            component++;
        }
    }
    return component;
}

