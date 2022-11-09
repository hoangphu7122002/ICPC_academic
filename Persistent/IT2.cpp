#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val; Node* l; Node* r;
    Node()  {};
    Node(int val, Node* l, Node* r) : val(val) , l(l) , r(r) {};
};

const int maxN = 1e5 + 1;
int a[maxN];
Node* st[4 * maxN];
Node* version[maxN];
void build(Node* root, int l,int r) {
    if (l == r) {
        root->val = a[l];
        return;
    }
    int mid = (l + r)>>1;
    root->l = new Node(0,NULL,NULL);
    root->r = new Node(0,NULL,NULL);
    build(root->l,l,mid);
    build(root->r,mid+1,r);
    root->val = root->l->val + root->r->val;
}

int query(Node* root,int l,int r,int u,int v) {    
    if (v < l || u > r) return 0;
    if (u <= l && r <= v) {
        return root->val;
    }
    int mid=(l+r)>>1;
    return query(root->l,l,mid,u,v) + query(root->r,mid+1,r,u,v);
}

void upgrade(Node* prev, Node* cur, int l, int r, int u, int x) {
    if (u < l || u > r || l > r) return;
    if (l == r) {
        cur->val = x;
        return;
    }
    int mid=(l+r)>>1;
    if (u <= mid) {
        cur->r = prev->r;
        cur->l = new Node(0,NULL,NULL);
        upgrade(prev->l,cur->l,l,mid,u,x);
    }
    else {
        cur->l = prev->l;
        cur->r = new Node(0,NULL,NULL);
        upgrade(prev->r,cur->r,mid+1,r,u,x);
    }
    cur->val = cur->l->val + cur->r->val;
}

int main() {
    return 0;
}