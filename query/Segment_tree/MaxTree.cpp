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
    update(2*id,l,mid,i,val);
    update(2*id,mid+1,r,i,val);
    st[id]=max(st[2*id],st[2*id+1]);
}

//O(LogN) return smallest element i => [l,r] satisfy a[i] > x
int query(int id,int l,int r,int u,int v,int x) {
    if (u > r || l > v) {
        return -1;
    }
    if (u <= l && r <= v) {
        if (st[id] <= x) return -1;
        while (l != r) {
            int mid = (l + r)/2;
            if (st[2*id] <= x) {
                l = mid + 1;
                id = 2 * id + 1;
            }
            else {
                r = mid;
                id = 2 * id;
            }
        }
        return l;
    }
    int mid = (l + r)/2;
    int lq = query(2*id,l,mid,u,v,x);
    if (lq != -1) return lq;
    return query(2*id+1,mid+1,r,u,v,x);
}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }
    build(1,1,N);
    cout << query(1,1,N,1,3,3);
    return 0;
}