#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll maxN = 1e5 + 1;
vector <ll> a(maxN);
vector <ll> st(4*maxN);
vector <ll> lazy(4*maxN);

//O(NLogN)
void down(ll id) {
    st[2*id] += lazy[id];
    lazy[2*id] += lazy[id];
    
    st[2*id+1] += lazy[id];
    lazy[2*id+1] += lazy[id];
    
    lazy[id] = 0;
}

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

void update(ll id,ll l,ll r, ll u, ll v, ll val) {
    if (u > r || l > v) return;
    if (u <= l && r <= v) {
        st[id] += val;
        lazy[id] += val;
        return;
    }
    down(id);
    ll mid = (l + r)/2;
    update(2*id,l,mid,u,v,val);
    update(2*id+1,mid+1,r,u,v,val);
    
    st[id]= min(st[2*id],st[2*id+1]);
}

ll query2(ll id,ll l,ll r,ll u,ll v) {
    if (u > r || l > v) {
        return 1e9+1;
    }
    if (u <= l && r <= v) {
        return st[id];
    }
    down(id);
    ll mid = (l + r)/2;
    return min(query2(2*id,l,mid,u,min(v,mid)),query2(2*id+1,mid+1,r,max(u,mid+1),v));
}

int main() {
    // freopen("input.txt","r",stdin);
    ll N,Q;
    cin >> N >> Q;
    for (ll i = 1; i <= N; ++i) {
        cin >> a[i];
    }
    build(1,1,N);
    while(Q--) {
        ll que,a,b,u;
        cin >> que;
        if (que == 1){
            cin >> a >> b >> u;
            update(1,1,N,a,b,u);
            // cout << "here" << endl;
        }
        else {
            cin >> a;
            cout << query2(1,1,N,a,a) << endl;
        }
        // cout <<"crash" << endl; 
    }
    // for (ll i = 1; i <= 4*N; ++i) {
    //     cout << st[i] << " ";
    // }
    return 0;
}