#include <bits/stdc++.h>

using namespace std;

#define oo 1000000
int M,N;
const int maxN = 50001;
vector <int> mx(maxN,0);
vector <int> my(maxN,0);
vector <int> g[maxN];
vector <int> dist(maxN);
int count_ = 0;

bool bfs() {
    queue <int> Q;
    for (int u = 1; u <= M; ++u) {
        if (!mx[u]) {
            dist[u] = 0;
            Q.push(u);
        } else dist[u] = oo;
    }
    
    bool found = false;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto v : g[u]) {
            if (!my[v]) {
                found = true;
                break;
            } else if (dist[my[v]]==oo) {
                dist[my[v]] = dist[u] + 1;
                Q.push(my[v]);
            }
        }
    }
    return found;
}

bool dfs(int u) {
    if (dist[u] == oo) return false;
    for (auto v : g[u]) {
        if (!my[v] || (dist[my[v]] == dist[u] + 1 && dfs(my[v]))) {
            mx[u] = v;
            my[v] = u;
            return true;
        } 
    }
    return false;
}

void match() {
    while (bfs()) {
        for (int u = 1; u <= M; ++u) {
            if (!mx[u]) count_ += dfs(u);
        }
    }
}

int main() {
    cin >> M >> N;
    int P;
    cin >> P;
    while(M--) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    match();
    for (int x = 1; x <= M; ++x) {
        
    }
    cout << count_ << endl;
    return 0;
}