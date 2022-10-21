#include <bits/stdc++.h>

using namespace std;


#define oo 100000
#define ll long long
const int maxN = 1e5 + 1;

struct Edge {
    int u,v,w;
    Edge(int u,int v,ll w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

vector <Edge> edges;
vector <int> trace(maxN,-1);
vector <int> D(maxN,oo);
vector <int> negCycle;
int N,M;

void bellmanFord(int S) {
    D[S] = 0;
    for (int i = 1; i < N; ++i) {
        for (auto e : edges) {
            int u = e.u;
            int v = e.v;
            ll w = e.w;
            if (D[u] != oo && D[v] > D[u] + w) {
                D[v] = D[u] + w;
                trace[v] = u;
            }
        }
    }
}

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


bool findNegativeCycle() {
    int negStart = -1; //root start
    for (auto e : edges) {
        int u = e.u;
        int v = e.v;
        long long w = e.w;
        //have continue optimize
        if (D[u] != oo && D[v] > D[u] + w) {
            D[v] = -oo; 
            trace[v] = u;
            negStart = v; // đã tìm thấy -INF
        }
    }
    if (negStart == -1) return false;
    int u = negStart;
    for (int i = 0; i < N; ++i) {
        u = trace[u]; //
    }
    
    negCycle = vector <int> (1,u);
    int v = trace[u];
    while (v != u) {
        negCycle.push_back(v);
        v = trace[v];
    }
    
    reverse(negCycle.begin(), negCycle.end());
    return true;
}

int main() {
    return 0;
}