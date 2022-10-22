#include <bits/stdc++.h>

using namespace std;

const int inf = 1e5 + 1;
const int maxN = 1e5 + 1;
int N, Q;
int a[maxN];
int st[4 * maxN];

void build(int id,int l,int r) {
    if (l == r) {
        a[id] = l;
        return;
    }
    int mid = l + r >> 1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    
    st[id] = min(st[2*id],st[2*id+1]);
}

void update(int id,int l,int r,int i,int val) {
    if (i < l || i > r) return;
    if (l==r) {
        st[id] = val;   
        return;
    }
    int mid = l + r >> 1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    
    st[id] = min(st[2*id],st[2*id+1]);
}

int get(int id,int l,int r,int u,int v) {
    if (l > r || r < u) return inf;
    if (l >= u && r <= v) return st[id];
    int mid = l + r >> 1;
    int get1 = get(2 * id,l,mid,u,v);
    int get2 = get(2 * id,mid+1,r,u,v);
    return min(get1,get2);
}

int main() {
    return 0;
}