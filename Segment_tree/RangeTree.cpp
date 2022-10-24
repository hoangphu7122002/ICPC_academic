#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;
vector <int> a(maxN);
vector <int> st(4*maxN);
vector <int> lazy(4*maxN);

void down(int id) {
    st[2*id] += lazy[id];
    lazy[2*id] += lazy[id];
    
    st[2*id+1] += lazy[id];
    lazy[2*id+1] += lazy[id];
    
    lazy[id] = 0;
}

//O(NLogN)
void build(int id, int l, int r) {
    if (r < l) return;
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l +  r) / 2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    
    st[id] = max(st[2 * id],st[2 * id + 1]);
}

void update(int id,int l,int r, int u, int v, int val) {
    if (u > r || l > v) return;
    if (u <= l && r <= v) {
        st[id] += val;
        lazy[id] += val;
        return;
    }
    down(id);
    int mid = (l + r)/2;
    update(2*id,l,mid,u,v,val);
    update(2*id,mid+1,r,u,v,val);
    
    st[id]= max(st[2*id],st[2*id+1]);
}

int query2(int id,int l,int r,int u,int v) {
    if (u > r || l > v) {
        return -1;
    }
    if (u <= l && r <= v) {
        return st[id];
    }
    down(id);
    int mid = (l + r)/2;
    return max(query2(2*id,l,mid,u,v),query2(2*id,mid+1,r,u,v));
}


int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }
    build(1,1,N);

    return 0;
}