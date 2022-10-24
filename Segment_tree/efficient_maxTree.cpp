#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;
vector <int> a(maxN);
vector <int> st(4*maxN);

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

void update(int id,int l,int r, int i,int val) {
    if (i < l || i >  r) return;
    if (l == r) {
        st[id] = val;
        return;
    }
    int mid = (l + r)/2;
    if (i <= mid) update(2*id,l,mid,i,val);
    else update(2*id,mid+1,r,i,val);
    st[id]=max(st[2*id],st[2*id+1]);
}

int query(int id,int l,int r,int u,int v) {
    if (u > r || l > v) {
        return -1;
    }
    if (u <= l && r <= v) return st[id];
    int mid = (l + r)/2;
    return max(query(2*id,l,mid,u,min(v,mid)),query(2*id+1,mid+1,r,max(u,mid+1),v));
    
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