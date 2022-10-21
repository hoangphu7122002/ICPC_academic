#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6 + 1;

//O(N + M)

int n,m;
bool joint[maxN]; //check Khop-vertex
int timeDFS = 0;
int bridge = 0;
int low[maxN],num[maxN];
vector <int> g[maxN];

void dfs(int u,int pre){
    int child = 0; //child of direct traversal
    num[u] = low[u] = ++timeDFS;
    for (int v : g[u]) {
        if (v == pre) continue;
        //v not traversal
        if (!num[v]) {
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if (low[v] == num[v]) bridge++; //save u,v is CAU-edge
            child++;
            if (u == pre) { //root
                if (child > 1) joint[u] = true;
            }
            else if (low[v] >= num[u]) {
                joint[u] = true;                
            }
        }
        else {
            low[u] = min(low[u],num[v]);
        }
    }
}

int main() {
     cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) 
        if (!num[i]) dfs(i, i);

    int cntJoint = 0;
    for (int i = 1; i <= n; i++) cntJoint += joint[i];

    cout << cntJoint << ' ' << bridge;
    return 0;
}