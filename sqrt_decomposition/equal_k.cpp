#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;
const int BLOCK_SIZE = 400;

int cnt[maxN / BLOCK_SIZE + 2][maxN];
int a[maxN];
int N;
int S;

void preprocess() {
    for (int i = 0; i < N; ++i) {
        ++cnt[i / BLOCK_SIZE][a[i]];
    }
}

void update(int u, int v) {
    int id = u / BLOCK_SIZE;
    --cnt[id][a[u]];
    a[u] = v;
    ++cnt[id][a[u]];
}

//O(Q*sqrt(N))
int query(int l, int r, int k) {
    int blockL = (l + BLOCK_SIZE - 1) / BLOCK_SIZE;
    int blockR = r / BLOCK_SIZE;
    if (blockL >= blockR) return count(a + l,a + r + 1,k);
    int sum = 0;
    
    //inBlock
    for (int i = blockL; i < blockR; ++i) {
        sum += cnt[i][k];
    }

    //left
    int LIM = blockL * BLOCK_SIZE;
    for (int i = l; i < LIM; ++i) {
        if (a[i] == k) sum += a[i];
    }
    LIM = blockR * BLOCK_SIZE;
    for (int i = LIM; i <= r; ++i) {
        if (a[i] == k) sum += a[i];
    }
    return sum;
}

int main() {
    cin >> N;
    S = sqrt(N + 0.0);
    
    return 0;
}