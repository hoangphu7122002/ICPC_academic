#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define oo 1e6

const int maxN = 1e5 + 1;
vector <pii> g[maxN]; //u has par(v,c)
vector <int> dist(maxN,0);

int N,M;

int prim(int s) {
    int count = 0;
    dist.resize(N + 1);
    fill(dist.begin(),dist.end(),oo);
    priority_queue <pii,vector<pii>,greater<pii>> pq;
    dist[s] = 0;
    pq.push({dist[s],s});
    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if (w != dist[u]) {
            continue;
        }
        count += w;
        dist[u] = -oo; //mark xet roi
        for (auto vc : g[u]) {
            int v = vc.first;
            int c = vc.second;
            if (dist[v] > c) {
                dist[v] = c;
                pq.push({dist[v],v});
            }
        }
    }
    return count;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    cout << prim(1) << endl;
    return 0;
}