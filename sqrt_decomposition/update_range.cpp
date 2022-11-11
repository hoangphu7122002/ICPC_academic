#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;
const int BLOCK_SIZE = 400;

int lazy[maxN / BLOCK_SIZE + 2][maxN];
int a[maxN];
int N;
int S;

void init() {
    int n_blocks = (N + BLOCK_SIZE - 1) / BLOCK_SIZE;
    for (int i = 0; i < n_blocks; ++i) {
        for (int j = 1; j <= 100; ++j) lazy[i][j] = j;
    }
}

void doLazy(int id) {
    int L = id * BLOCK_SIZE;
    int R = min(N - 1,(id+1)*BLOCK_SIZE - 1);
    for (int i = L; i <= R; ++i) a[i] = lazy[id][a[i]];
    for (int i = 1; i <= 100; ++i) lazy[id][i] = i;
}

//trai phai phan du ben khac
void manualUpdate(int L, int R, int oval, int nval) {
    int id = R / BLOCK_SIZE;
    doLazy(id);
    for (int i = L; i <= R; ++i) {
        if (a[i] == oval) a[i] = nval;
    }
}

void blockUpdate(int id, int oval, int nval) {
    for (int i = 1; i <= 100; ++i) {
        if (lazy[id][i] == oval) {
            lazy[id][i] = nval;
        }
    }
}

void update(int l, int r, int oval, int nval) {
    int blockL = l / BLOCK_SIZE;
    int blockR = r / BLOCK_SIZE;
    
    if (blockL == blockR) {
        manualUpdate(l,r,oval,nval);
    }
    for (int i = blockL + 1; i < blockR; ++i) 
        blockUpdate(i,oval,nval);
    manualUpdate(l,(blockL + 1) * BLOCK_SIZE - 1,oval,nval);
    manualUpdate(blockR * BLOCK_SIZE,r,oval,nval);
}

int main() {
    return 0;
}