#include <bits/stdc++.h>

using namespace std;

#define ll long long 

const ll maxN = 1e5 + 1;
vector <ll> a[maxN];
vector <ll> st[4*maxN];

//O(NLogN)
void build(ll id, ll l, ll r) {
    if (r < l) return;
    if (l == r) {
        st[id] = a[l];
        return;
    }
    ll mid = (l +  r) / 2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    
    merge(st[2*id].begin(),st[2*id].end(),st[2*id+1].begin(),st[2*id+1].end(),back_inserter(st[id]));
}

//O(LogN*logN)
ll query(ll id,ll l,ll r,ll u,ll v,ll k) {
    if (u > r || l > v) {
        return 0;
    }
    if (u <= l && r <= v) {
        ll res = st[id].size() - (upper_bound(st[id].begin(),st[id].end(),k) - st[id].begin()); 
        if (res > 0) return res;
        return 0;
    }
    ll mid = (l + r)/2;
    return query(2*id,l,mid,u,v,k) + query(2*id+1,mid+1,r,u,v,k);
}

int main() {
    ll N;
    cin >> N;
    for (ll i = 1; i <= N; ++i) {
        ll t;
        cin >> t;
        a[i].push_back(t);
    }
    build(1,1,N);
    ll q;
    cin >> q;
    while (q--) {
        ll u,v,k;
        cin >> u >> v >> k;
        cout << query(1,1,N,u,v,k) << endl;
    }
    return 0;
}