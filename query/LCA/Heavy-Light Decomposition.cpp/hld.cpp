#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;
vector <int> chainHead(maxN,0);
vector <int> chainInd(maxN,0);
vector <int> posInBase(maxN,0);
vector <int> g[maxN];
vector <int> par(maxN,-1);
vector <int> visited(maxN,0);
vector <int> nChild(maxN,0);
int N,M;

void dfs(int u) {
    visited[u] = true;
    nChild[u] += g[u].size();
    for (auto v : g[u]) {
        if (visited[v]) continue;
        par[v] = u;
        dfs(v);
        nChild[u] += nChild[v];
    }
}

int nChain = 1; //number of chain
int nBase = 1;

void hld(int u) {
    //chuoi dau
    if (chainHead[nChain] == 0) chainHead[nChain] = u;
    chainInd[u] = nChain; //danh dau, u thuoc nChain
    posInBase[u] = ++nBase;
    int mVtx = -1;
    for (auto v : g[u]) {
        if (v != par[u]) {
            if (mVtx == -1 || nChild[v] > nChild[mVtx]) {
                mVtx = v;
            }           
        }
    }
    if (mVtx > -1) hld(mVtx);
    for (auto v : g[u]) {
        if (v != par[u] && v != mVtx) {
            nChain++;
            hld(v);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    hld(1);
    for (int i = 1; i <= N; ++i) {
        cout << chainInd[i] << " ";
    }
    return 0;
}