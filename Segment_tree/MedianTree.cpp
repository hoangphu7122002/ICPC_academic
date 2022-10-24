#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int> 

const int maxN = 1e5 + 1;
vector <pii> a(maxN);
vector <int> st[4*maxN];

//O(NLogN)
void build(int id,int l,int r) {
    if (r < l) return;
    if (l == r) {
        st[id].push_back(a[l].second);
        return;
    }
    int mid = (l + r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    
    merge(st[2*id].begin(),st[2*id].end(),st[2*id+1].begin(),st[2*id+1].end(),back_inserter(st[id]));
}

//O(log(n)*log(n))
int query(int id,int l,int r,int u,int v,int k) {
    if (l == r) return st[id][0];
    int mid = (l + r)/2;
    //<=v
    int v_query = (upper_bound(st[2*id].begin()+1,st[2*id].end(),v) - st[2*id].begin());
    //>=u
    int u_query = (lower_bound(st[2*id].begin()+1,st[2*id].end(),u) - st[2*id].begin());
    
    int M = v_query - u_query;
    if (M >= k) {
        return query(2*id,l,mid,u,v,k);
    }
    return query(2*id+1,mid+1,r,u,v,k-M);
}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int t;
        cin >> t;
        a[i] = {t,i};
    }
    sort(a.begin(),a.end());
    build(1,1,N);
    
}