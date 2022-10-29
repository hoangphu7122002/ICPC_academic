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
    
    st[id] = st[2 * id] + st[2 * id + 1];
}

void update(ll id,ll l,ll r, ll i,ll val) {
    if (i < l || i >  r) return;
    if (l == r) {
        st[id] = val;
        return;
    }
    ll mid = (l + r)/2;
    if (i <= mid) update(2*id,l,mid,i,val);
    else update(2*id+1,mid+1,r,i,val);
    st[id]=st[2*id] + st[2*id+1];
}

ll query(ll id,ll l,ll r,ll u,ll v) {
    if (u > r || l > v) {
        return 0;
    }
    if (u <= l && r <= v) return st[id];
    ll mid = (l + r)/2;
    return query(2*id,l,mid,u,min(v,mid)) + query(2*id+1,mid+1,r,max(u,mid+1),v);
    
}

int main() {
    // freopen("input.txt","r",stdin);
    ll N,q;
    cin >> N >> q;
    for (ll i = 1; i <= N; ++i) {
        cin >> a[i];
    }
    build(1,1,N);
    while(q--) {
        ll n,u,v;
        cin >> n >> u >> v;
        if (n == 1) update(1,1,N,u,v);
        else cout << query(1,1,N,u,v) << endl;
        
    }
    return 0;
}