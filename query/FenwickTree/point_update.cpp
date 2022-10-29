#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll maxN = 2e5 + 1;
ll bit[maxN];
ll prefix[maxN];
ll a[maxN];
ll N;

void computePrefixSum() {
    for (ll i = 1; i <= N; ++i) prefix[i] = prefix[i - 1] + a[i];
}

void updatePoll(ll u, ll v) {
    ll idx = u;
    while (idx <= N) {
        bit[idx] += v;
        idx += (idx & (-idx));
    }
}

void updateRange(ll l,ll r, ll v) {
    updatePoll(l,v);
    updatePoll(r+1,-v);
}

ll get(ll u) {
    ll idx = u;
    ll ans = 0;
    while (idx > 0) {
        ans += bit[idx];
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
        ll que,k,b,u;
        cin >> que;
        if (que == 1){
            cin >> k >> b >> u;
            updateRange(k,b,u);    
        }
        else {
            cin >> k;
            cout << a[k] + get(k) << endl;
        }
    }
    
    return 0;
}