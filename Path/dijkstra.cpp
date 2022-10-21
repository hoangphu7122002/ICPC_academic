#include <bits/stdc++.h>

using namespace std;


#define oo 100000
#define ll long long
#define pii pair<int,int>
const int maxN = 1e5 + 1;

struct Edge {
    int v,w;
    Edge(int v,ll w) {
        this->v = v;
        this->w = w;
    }
};

vector <Edge> edges[maxN];
vector <int> trace(maxN,-1);
vector <int> D(maxN,oo);
vector <int> negCycle;
vector <bool> P(maxN,oo);
int N,M;

vector <int> trace_path(int S,int u) {
    if (u != S && trace[u] == -1) return vector <int> (0); //not have path
    
    vector <int> path;
    while (u != -1) {
        path.push_back(u);
        u = trace[u];
    }
    
    reverse(path.begin(),path.end());
    return path;
}

void bfs(int root) {
    D[root] = 0;
    priority_queue <pii,vector<pii>,greater<pii>> pq;
    pq.push({D[root],root});
    while (pq.size()) {
        auto t = pq.top();
        pq.pop();
        int u = t.second;
        int dist = t.first;
        if (P[u] == true) continue;
        P[u] = true;
        for (auto e : edges[u]) {
            int v = e.v;
            ll w = e.w;
            if (D[v] > D[u] + w) {
                D[v] = D[u] + w;
                pq.push({D[v],v});
                trace[v] = u;
            }
        }
    }
}

int main() {
    return 0;
}