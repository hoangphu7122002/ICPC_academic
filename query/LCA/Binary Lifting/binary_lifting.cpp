#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;
vector <int> edge[maxN];
vector <int> p(maxN,0);
vector <int> h(maxN,0);
int n;

//O(Q * N)

void dfs(int u,int par = -1) {
    for (auto v : edge[u]) {
        if (v == par) continue;
        p[v] = u;
        h[v] = h[u] + 1;
        dfs(v,u);
    }
}

//find naive ancestor_k
int ancestor_k_1(int u,int k) {
    while (k >= 1) {
        u = p[u];
        k--;
    }
    return u;
}

//find 2 ancestor_k
vector <int> p2(maxN,0);
void preprocess_k_2() {
    for (int i = 1; i <= n; ++i) {
        p2[i] = p[p[i]];
    }
}

int ancestor_k_2(int u,int k) {
    while (k >= 2) {
        u = p2[u];
        k -= 2;
    }
    while (k >= 1) {
        u = p[u];
        k -= 1;
    }
    return u;
}

//find 4 ancestor_k
vector <int> p4(maxN,0);
void preprocess_k_4() {
    for (int i = 1; i <= n; ++i) {
        p4[i] = p2[p2[i]];
    }
}

int ancestor_k_4(int u,int k) {
    while (k >= 4) {
        u = p4[u];
        k -= 4;
    }
    if (k >= 2) {
        u = p2[u];
        k -= 2;
    }
    if (k >= 1) {
        u = p[u];
        k -= 1;
    }
    return u;
}

//spare_table_ancestor_k
int pk[maxN][17];
void preprocess_k() {
    for (int u = 1; u <= n; ++u) pk[u][0] = p[u];
    for (int j = 1; j < 17; j++) {
        for (int u = 1; u <= n; ++u) {
            pk[u][j] = pk[pk[u][j - 1]][j - 1];
        }
    }           
}

int ancestor_k(int u,int k) {
    for (int j = 16; j >= 0; --j)
        if (k >= (1 << j)) u = pk[u][j], k -= 1 << j;
    return u;
}

int ancestor_k_1(int u,int k) {
    for (int j = 0; (1 << j) <= k; ++j)
        if (k >> j & 1) u = pk[u][j];
    return u;
}