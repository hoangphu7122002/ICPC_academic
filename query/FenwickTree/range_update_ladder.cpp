#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 1;
int bit1[maxN];
int bit2[maxN];
int a[maxN];
int prefix[maxN];
int N,Q;

void computePrefixSum() {
    for (int i = 1; i <= N; ++i) prefix[i] = prefix[i - 1] + a[i];
}

void updatePoint(int* b, int u,int v) {
    int idx = u;
    while (idx <= N) {
        b[idx] += v;
        idx += (idx & (-idx));
    }
}

void updateRange(int l,int r,int v) {
    updatePoint(bit1,l,(N - l + 1) * v);
    updatePoint(bit1,r+1,-1 * (N - r) * v);
    updatePoint(bit2,l,v);
    updatePoint(bit2,r+1,-v);
}

int get(int* b,int u) {
    int idx = u;
    int ans = 0;
    while (idx > 0) {
        ans += b[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

int prefixSum(int u) {
    return get(bit1,u) - get(bit2,u) * (N - u);
}

int rangeSum(int l,int r) {
    return prefixSum(r) - prefixSum(l - 1);
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> N;
    cin >> Q;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    computePrefixSum();
    while (Q--) {
        int que,u,v,k;
        cin >> que;
        if (que == 1) {
            cin >> u >> v >> k;
            updateRange(u,v,k);
        }
        else {
            cin >> u >> v;
            cout << rangeSum(u,v) + (prefix[v] - prefix[u - 1]) << endl;
        }
    }
    return 0;
}