#include <bits/stdc++.h>

using namespace std;

#define ll long long

//O(N*M)

const ll maxN = 1e5 + 1;
const ll INF = 1e9;
struct Edge {
    ll v;
    ll w;
};
vector <Edge> g[maxN];

vector <ll> d(maxN);
ll cnt[maxN];
bool in_queue[maxN];
int trace[maxN];
ll N;
int check;

bool spfa(ll s) {
    queue <ll> q;
    d[s] = 0;
    in_queue[s] = true;
    q.push(s);
    while (q.size()) {
        ll u = q.front();
        q.pop();
        in_queue[u] = false;
        for (auto edge : g[u]) {
            ll v = edge.v;
            ll w = edge.w;
            if (d[u] != INF && d[u] + w < d[v]) {
                d[v] = d[u] + w;
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
    memset(cnt,0,sizeof(cnt));
    memset(trace,-1,sizeof(trace));
    memset(in_queue,false,sizeof(in_queue));
    
    ll M,start;
    cin >> N >> M >> start;
    d.assign(N,INF);
    
    for (ll i = 1; i <= M; ++i) {
        ll u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
    }
    
    if (!spfa(start)) {
        cout << "here" << endl;
        int u = check;
        cout << check << endl;
        for (int i = 0; i < N; ++i) {
            u = trace[u];
        }
        vector <int> negCycle;
        negCycle.push_back(u);
        for (int v = trace[u]; v != u; v = trace[v]) {
            negCycle.push_back(v);
        }
        reverse(negCycle.begin(),negCycle.end());
        for (auto ele : negCycle) {
            cout << ele << " ";
        }
    }
    // for (ll i = 0; i < N; ++i) {
    //     cout << d[i] << " ";
    // }
    
    return 0;
}