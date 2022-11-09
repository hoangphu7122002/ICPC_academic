#include <bits/stdc++.h>

using namespace std;

const int maxN = 101;

int n, m;
vector <int> g[maxN];
int start, target;
int c[maxN][maxN];
int f[maxN][maxN];
int trace[maxN];

bool bfs(int start, int target) {
    queue <int> que;
    memset(trace,0,sizeof(trace));
    trace[start] = -1;
    que.push(start);
    while (que.size()) {
        int u = que.front();
        que.pop();
        if (u == target) return true;
        for (auto v : g[u]) {
            if (trace[v] == 0 && f[u][v] < c[u][v]) {
                trace[v] = u;
                que.push(u);
            }
        }
    }
    return false;
}

int min_cut(bool tracing = false) {
    int r = 0;
    
    for (int u = 1; u <= n; ++u) {
        for (auto v : g[u]) {
            if (trace[u] && !trace[v]) {
                r += c[u][v];
            }    
            if (tracing) cout << u << " " << v << endl;
        }
    }
    
    return r;
}

int answer() {
    int r = 0;
    for (auto v : g[start]) {
        r += f[start][v];
    }
    return r;
}

void enlarge() {
    int delta = maxN;
    for (int i = target; i != start; i = trace[i]) 
        delta = min(delta,c[trace[i]][i] - f[trace[i]][i]);
    for (int i = target; i != start; i = trace[i]) {
        f[trace[i]][i] += delta;
        f[i][trace[i]] -= delta;
    } 
}

int main() {
    memset(c,0,sizeof(c));
    memset(f,0,sizeof(f));
    
    start = 1;
    target = n;
    
    for (int i = 1; i <= m; ++i) {
        int p,q,w;
        cin >> p >> q >> w;
        g[p].push_back(q);
        g[q].push_back(p);
        c[p][q] = w;
        c[q][p] = 0;
    }
    
    while (bfs(start,target)) {
        enlarge();
    }
    
    cout << answer() << endl;
    
    return 0;
}