#include <bits/stdc++.h>

using namespace std;

//O(N^2)

const int maxN = 50001;
int M,N;
vector <int> g[maxN];
vector <int> visited(maxN,0);
vector <int> assign(maxN,0);

int t = 0;
bool dfs(int u) {
    if (visited[u] != t) visited[u] = t;
    else return false;
    for (auto v : g[u]) {
        if (!assign[v] || dfs(assign[v])) {
            assign[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    int E;
    cin >> M >> N >> E;
    int x,y;
    while (cin >> x >> y) {
        g[x].push_back(y);
    }
    int count = 0;
    for (int i = 1; i <= M; ++i) {
        t++;
        count += dfs(t);
    }
    cout << count << endl;
    // for (int i = 1; i <= N; ++i) {
    //     int j = assign[i];
    //     if (j != 0) cout << j << " " << i << endl;
    // }
    return 0;
}