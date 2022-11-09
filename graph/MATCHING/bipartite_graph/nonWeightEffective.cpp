#include <bits/stdc++.h>

using namespace std;

#define oo 1000000
int M,N;
const int maxN = 50001;
vector <int> mx(maxN,0);
vector <int> my(maxN,0);
vector <int> g[maxN];
vector <bool> choose(maxN,0);
vector <int> dist(maxN);
int count_ = 0;

int numV;
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

void konig() {
    queue <int> que;
    for (int i = 1; i <= M; ++i) if (!mx[i]) que.push(i);
    for (int i = 1; i <= N; ++i) if (!my[numV - i]) que.push(numV - i);
    while (que.size()) {
        int u = que.front();
        que.pop();
        for (auto v : g[u]) {
            if (!choose[v]) {
                choose[v] = true;
                if (!mx[v]) que.push(mx[v]);
                if (!my[v]) que.push(my[v]);
            }  
        }
    }
    for (int i = 1; i <= M; ++i)
        if (mx[i] && !choose[mx[i]] && !choose[i]) choose[i];
}

int main() {
    cin >> M >> N;
    numV = M + N;
    int u,v;
    
    while(cin >> u >> v) {
        g[u].push_back(numV - v);
        g[numV - v].push_back(u);
    }
    
    
    match();
    for (int x = 1; x <= M; ++x) {
        
    }
    cout << count_ << endl;
    return 0;
}