#include <bits/stdc++.h>

using namespace std;

#define ll long long

//O(N*M)

const ll maxN = 1001;
const ll INF = 1e9;
vector <ll> g[maxN];

vector <ll> d(maxN);
ll cnt[maxN];
bool in_queue[maxN];
int trace[maxN];
ll N,K;
int check;
ll cost[maxN][maxN];
ll cap[maxN][maxN];
vector <int> adj[maxN];

bool spfa(ll s) {
    memset(cnt,0,sizeof(cnt));
    memset(trace,-1,sizeof(trace));
    memset(in_queue,false,sizeof(in_queue));
    d.assign(N,INF);
    
    queue <ll> q;
    d[s] = 0;
    in_queue[s] = true;
    q.push(s);
    while (q.size()) {
        ll u = q.front();
        q.pop();
        in_queue[u] = false;
        for (auto v : g[u]) {
            if (d[u] != INF && d[u] + cost[u][v] < d[v]) {
                d[v] = d[u] + cost[u][v];
                trace[v] = u;
                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = true;
                    cnt[v]++;
                    if (cnt[v] > N) {
                        check = v;
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    K = INF;
    
    ll M;
    cin >> N >> M;
    
    for (ll i = 1; i <= M; ++i) {
        ll u,v,cp,w;
        cin >> u >> v >> cp >> w;
        g[u].push_back(u);
        g[v].push_back(v);
        cost[u][v] = w;
        cost[v][u] = -w;
        cap[u][v] = cp;
    }
    
    int flow = 0;
    int cost = 0;
    
    while (flow < K) {
        if (!spfa(1)) break;
        if (d[N] == INF) break;
        ll k = K - flow;
        int v = N;
        while(v != 1) {
            int u = trace[v]; 
            k = min(k,cap[u][v]);
            v = u;
        }
        flow += k;
        cost += k * d[N];
        v = N;
        while(v != 1) {
            int u = trace[v]; 
            cap[u][v] -= k;
            cap[v][u] += k;
            v = u;
        }    
    }
    cout << cost << endl;
    
    return 0;
}