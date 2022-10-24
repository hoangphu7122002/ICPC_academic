#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;
vector <int> a[maxN];
vector <int> st[4*maxN];

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
    
    merge(st[2*id].begin(),st[2*id].end(),st[2*id+1].begin(),st[2*id+1].end(),back_inserter(st[id]));
}

//O(LogN*logN)
int query(int id,int l,int r,int u,int v,int k) {
    if (u > r || l > v) {
        return 0;
    }
    if (u <= l && r <= v) {
        return upper_bound(st[id].begin() + 1,st[id].end(),k) - st[id].begin();
    }
    int mid = (l + r)/2;
    return query(2*id,l,mid,u,v,k) + query(2*id+1,mid+1,r,u,v,k);
}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int t;
        cin >> t;
        a[i].push_back(t);
    }
    build(1,1,N);
    cout << query(1,1,N,1,3,4);
    return 0;
}