#include <bits/stdc++.h>

using namespace std;

const int maxN  = 100010;

int n, m, q;
int timeDfs = 0;
int low[maxN], num[maxN], tail[maxN];
int depth[maxN], p[maxN][20];
bool joint[maxN];
vector <int> g[maxN];

/* Tính mảng p */
void calP() {
    p[1][0] = 1;
    for (int j = 1; j <= 19; j++)
        for (int i = 1; i <= n; i++)
            p[i][j] = p[p[i][j - 1]][j - 1];
}

/* Tìm tổ tiên của đỉnh u là con trực tiếp của đỉnh par */
int findParent(int u, int par) {
    for (int i = 19; i >= 0; i--)
        if (depth[p[u][i]] > depth[par]) u = p[u][i];
    return u;
}

/* Tìm khớp cầu */
void dfs(int u, int pre) {
    int child = 0;
    num[u] = low[u] = ++timeDfs;
    for (int v : g[u]){
        if (v == pre) continue;
        if (!num[v]) {
            child++;
            p[v][0] = u;
            depth[v] = depth[u] + 1;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (u == pre) {
                if (child > 1) joint[u] = true;
            }
            else if (low[v] >= num[u]) joint[u] = true;
        }
        else low[u] = min(low[u], num[v]);
    }
    tail[u] = timeDfs;
}

/* Kiểm tra xem đỉnh u có nằm trong cây con DFS gốc root hay không? */
bool checkInSubtree(int u, int root) {
    return num[root] <= num[u] && num[u] <= tail[root];
}

/* Xử lí truy vấn 1 */
bool solve1(int a, int b, int g1, int g2) {
    /* Vì ta coi g2 là con trực tiếp của g1 nên khi g1 là con của g2, 
    ta phải đổi chỗ 2 giá trị g1 và g2 cho nhau */
    if (num[g1] > num[g2]) swap(g1, g2); 

    /* Kiểm tra nếu cạnh (g1, g2) không phải là cầu */
    if (low[g2] != num[g2]) return true;

    if (checkInSubtree(a, g2) && !checkInSubtree(b, g2)) return false;
    if (checkInSubtree(b, g2) && !checkInSubtree(a, g2)) return false;
    return true;
}

/* Xử lí truy vấn 2 */
bool solve2(int a, int b, int c) {
    if (!joint[c]) return true;
    int pa = 0, pb = 0;
    if (checkInSubtree(a, c)) pa = findParent(a, c);
    if (checkInSubtree(b, c)) pb = findParent(b, c);

    if (!pa && !pb) return true; 
    if (pa == pb) return true; 
    if (!pa && low[pb] < num[c]) return true; 
    if (!pb && low[pa] < num[c]) return true;
    if (pa && pb && low[pa] < num[c] && low[pb] < num[c]) return true;

    return false;
}