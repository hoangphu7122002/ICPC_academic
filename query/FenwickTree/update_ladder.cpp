#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll maxN = 2e5 + 1;
int bit1[maxN];
int bit2[maxN];
ll prefix[maxN];
ll a[maxN];
ll N;

void computePrefixSum() {
    for (ll i = 1; i <= N; ++i) prefix[i] = prefix[i - 1] + a[i];
}

void updatePoll(int* b, ll u, ll v) {
    ll idx = u;
    while (idx <= N) {
        b[idx] += v;
        idx += (idx & (-idx));
    }
}

void updateRange(int* b,ll l,ll r, ll v) {
    updatePoll(b,l,v);
    updatePoll(b,r+1,-v);
}

ll get(int* b1,int* b2,ll u) {
    ll idx = u;
    ll ans = 0;
    while (idx > 0) {
        ans += b1[idx];
        ans += b2[idx] * idx;
        idx -= (idx & (-idx));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> N;
    ll Q;
    cin >> Q;
    for (ll i = 1; i <= N; ++i) cin >> a[i];
    while(Q--) {
        int i,u,v;
        int que;
        cin >> que;
        if (que == 1) {
            cin >> u >> v;
            updateRange(bit1,u,v,-(u-1));
            updateRange(bit2,u,v,1);
        }
        else {
            cin >> i;
            cout << a[i] + get(bit1,bit2,i) << endl;
        }
    }
    
    return 0;
}