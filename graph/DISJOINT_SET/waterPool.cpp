#include <bits/stdc++.h>

using namespace std;

#define pii pair<ll,ll>
#define oo 1e6
#define ll long long

const ll maxN = 1e5 + 1;
vector <pii> g[maxN]; //u has par(v,c)
vector <ll> dist(maxN,0);

ll N,M;

ll prim(ll s) {
    ll count = 0;
    dist.resize(N + 1);
    fill(dist.begin(),dist.end(),oo);
    priority_queue <pii,vector<pii>,greater<pii>> pq;
    dist[s] = 0;
    pq.push({dist[s],s});
    while (!pq.empty()) {
        ll u = pq.top().second;
        ll w = pq.top().first;
        pq.pop();
        
        if (w != dist[u]) {
            continue;
        }
        
        count += w;
        dist[u] = -oo; //mark xet roi
        for (auto vc : g[u]) {
            ll v = vc.first;
            ll c = vc.second;
            if (dist[v] > c) {
                dist[v] = c;
                pq.push({dist[v],v});
            }
        }
    }
    return count;
}

int main() {
    cin >> N;
    
    for (ll i = 1; i <= N; ++i) {
        ll d;
        
        cin >> d;
        g[0].push_back({i,d});
    }
    for (ll i = 1; i <= N; ++i) {
        for (ll j = 1; j <= N; ++j) {
            ll w;
            cin >> w;
            if (i == j) continue;
            g[i].push_back({j,w});
        }
    }
    cout << prim(0) << endl;
    return 0;
}