#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll maxN = 2e5 + 1;
vector <ll> a(maxN);
vector <ll> st(4*maxN);

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
    
    st[id] = min(st[2 * id],st[2 * id + 1]);
}

ll query(ll id,ll l,ll r,ll u,ll v) {
    if (u > r || l > v) {
        return -1;
    }
    if (u <= l && r <= v) return st[id];
    ll mid = (l + r)/2;
    return min(query(2*id,l,mid,u,min(v,mid)),query(2*id+1,mid+1,r,max(u,mid+1),v));
}

int main() {
    // freopen("input.txt","r",stdin);
    ll N,q;
    cin >> N >> q;
    // for (ll i = 1; i <= N; ++i) {
    //     cin >> a[i];
    // }
    while(q--) {
        ll x,y,k;
        cin >> x >> y >> k;

    }
    ll p;
    cin >> p;
    while(p--) {
        ll u,v;
        cin >> u >> v;
        cout << query(1,1,N,u,v) << endl;
    }
    
    // for (ll i = 1; i <= 4*N; ++i) {
    //     cout << st[i] << " ";
    // }
    return 0;
}