#include <bits/stdc++.h>

using namespace std;

#define oo 100002;
#define ll long long

//O(|f|*E)
//sometime BFS more effective than DFS

const ll maxN = 1001;
vector <ll> g[maxN];
vector <ll> trace(maxN,-1);
vector <ll> visited(maxN,0);
ll f[maxN][maxN];
ll c[maxN][maxN];

void bfs(int source) {

    queue <int> q;
    q.push(source);
    visited[source] = true;
    
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto v: g[u]) {
            if (visited[v]) continue;
            if (c[u][v] - f[u][v] <= 0) continue;
            visited[v] = true;
            trace[v] = u;
            q.push(v);
        }
    }
}

bool find_augment_from_to(ll source,ll sink) {
    fill(visited.begin(),visited.end(),0);
    bfs(source);
    return visited[sink];
}

ll increase_flow(ll source, ll sink) {
    ll minCapacity = oo;
    ll u = sink;
    
    //find minimum capacity through in flow
    while (u != source) {
        ll prev = trace[u];   
        minCapacity = min(minCapacity,c[prev][u] - f[prev][u]);
        u = prev;
    }
    
    //increase flow
    while (sink != source) {
        ll prev = trace[sink];
        f[prev][sink] += minCapacity;
        f[sink][prev] -= minCapacity;
        sink = prev;
    }
    
    return minCapacity;
}

ll max_flow(ll source, ll sink) {
    ll res = 0;
    while (find_augment_from_to(source,sink)) {
        res += increase_flow(source,sink);
        // cout << "res: " << res << endl;
    }
    return res;
}

ll N,M;

int main() {
    cin >> N >> M;
    ll s,t;
    cin >> s >> t;
    memset(f,0,sizeof(f));
    memset(c,0,sizeof(f));
    for (ll i = 0; i < M; ++i) {
        ll u,v,c_;
        cin >> u >> v >> c_;
        g[u].push_back(v);
        g[v].push_back(u);
        c[u][v] = c_;
        c[v][u] = 0;
    }
    
    cout << max_flow(s,t) << endl;
    return 0;
}