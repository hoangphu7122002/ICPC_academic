#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;
const int logMaxN = 1e2 + 1;
int M[maxN][logMaxN];
int A[maxN];
int M,N;

void ST() {
    for (int i = 0; i < N; ++i) {
        M[i][0] = i;
    }    
    for (int j = 1; 1 << j <= N; ++j) {
        for (int i = 0; i + (1<<j) - 1 < N; ++i) {
            if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]]) {
                M[i][j] = M[i][j - 1];
            }
            else {
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
            }
        }
    }
}

int RMQ(int i,int j) {
    int k = log2(j - i + 1);
    if (A[M[i][k]] <= A[M[j - 1<<k + 1][k]]) {
        return M[i][k];
    }
    return M[j - 1<<k + 1][k];
}

int main() {
    ST();
        
    return 0;
}