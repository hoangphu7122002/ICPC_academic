#include <bits/stdc++.h>

//query: (u,x) to find v is largest ancestor of u so: d

using namespace std;

const int maxN = 1e5 + 1;
vector <int> edge[maxN];
int w[maxN][maxN];
vector <int> par(maxN,0);
vector <int> f(maxN,0);
vector <int> h(maxN,0);
int n;

void dfs(int u,int p =-1) {
    for (auto v : edge[u]) {
        if (v == p) continue;
        par[v] = u;
        h[v] = h[u] + 1;

        dfs(v,u);
    }
}

int up[maxN][17];
void preprocess_k() {
    for (int u = 1; u <= n; ++u) up[u][0] = par[u];
    for (int j = 1; j < 17; j++) {
        for (int u = 1; u <= n; ++u) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }
    }           
}

int dist_ancestor_k(int u,int k) {
    int sum = 0;
    for (int j = 0; (1 << j) <= k; ++j)
        if (k >> j & 1) {
            sum += dist[u][j];
            u = up[u][j];
        }
    return u;
}

int dist[maxN][17];
void distance() {
    for (int u = 1; u <= n; ++u){
        if (par[u] == -1) continue;
        dist[u][0] = w[par[u]][u];
    }
    for (int j = 1; j <= 16; ++j) {
        for (int u = 1; u <= n; ++u) {
            dist[u][j] += dist[up[u][j - 1]][ j - 1];
        }
    }
}

int solve1(int u,int x) {
    int lo = 0;
    int hi = h[u];
    int mid, ans = 0;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (dist_ancestor_k(u, mid) <= x) {
            ans = mid;    
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return dist_ancestor_k(u,ans);
}

int solve(int u, int x) {
    int now_dist = 0, k = 0;
    for (int j = __lg(h[u]); j >= 0; --j) {
        // nếu khoảng cách từ u ban đầu đến tổ tiên thứ (k + 2^j) <= x
        if (h[u] >= (1 << j) && now_dist + dist[u][j] <= x) {
            now_dist += dist[u][j];
            k |= 1 << j;
            u = up[u][j];
        }
    }
    return u;
}
