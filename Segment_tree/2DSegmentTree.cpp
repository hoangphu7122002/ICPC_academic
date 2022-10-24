#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;
vector <vector<int>> a(maxN,vector<int>(maxN));
vector <vector<int>> st(4*maxN,vector<int>(4*maxN));
int M,N;

void build_y(int id_x,int l_x,int r_x,int id_y,int l_y,int r_y) {
    if (l_y == r_y) {
        if (l_x == r_x) st[id_x][id_y] = a[l_x][l_y];
        else st[id_x][id_y] = st[id_x*2][id_y] + st[id_x*2+1][id_y];
        return;
    }
    int mid_y = (l_y + r_y)/2;
    build_y(id_x,l_x,r_x,2*id_y,l_y,mid_y);
    build_y(id_x,l_x,r_x,2*id_y+1,mid_y+1,r_y);
    st[id_x][id_y] = st[id_x][id_y*2] + st[id_x][id_y*2+1];
}

void build_x(int id_x,int l_x,int r_x) {
    if (l_x != r_x) {
        int mid_x = (l_x + r_x) / 2;
        build_x(2*id_x,l_x,mid_x);
        build_x(2*id_x+1,mid_x+1,r_x);
    }
    build_y(id_x,l_x,r_x,1,1,M);
}

int sum_y(int id_x,int id_y,int tl_y,int tr_y,int l_y,int r_y) {
    if (l_y > r_y) return 0;
    if (l_y == tl_y && r_y == tr_y) return st[id_x][id_y];
    int mid_y = (tl_y + tr_y)/2;
    return sum_y(id_x,2*id_y,tl_y,mid_y,l_y,min(r_y,tr_y)) + sum_y(id_x,2*id_y+1,mid_y+1,tr_y,max(l_y,mid_y+1),r_y);
}

int sum_x(int id_x,int tl_x,int tr_x,int l_x,int r_x,int l_y,int r_y) {
    if (l_x > r_x) return 0;
    if (l_x == tl_x && r_x == tr_x) return sum_y(id_x,1,1,M,l_y,r_y);
    int mid_x = (tl_x + tr_x) / 2;
    return sum_x(2*id_x,tl_x,mid_x,l_x,min(r_x,mid_x),l_y,r_y) + sum_x(2*id_x+1,mid_x+1,tr_x,max(l_x,mid_x+1),r_x,l_y,r_y);
}

void update_y(int id_x,int l_x,int r_x,int id_y,int l_y,int r_y,int x,int y,int val) {
    if (l_y == r_y) {
        if (l_x == r_x) st[id_x][id_y] = val;
        else st[id_x][id_y] = st[id_x*2][id_y] + st[id_x*2+1][id_y];
        return;
    }
    int mid_y = (l_y + r_y)/2;
    if (y <= mid_y) update_y(id_x,l_x,r_x,2*id_y,l_y,mid_y,x,y,val);
    else update_y(id_x,l_x,r_x,2*id_y+1,mid_y+1,r_y,x,y,val);
    st[id_x][id_y] = st[id_x][id_y*2] + st[id_x][id_y*2+1];
}

void update_x(int id_x,int l_x,int r_x,int x,int y,int val) {
    if (l_x != r_x) {
        int mid_x = (l_x + r_x) / 2;
        update_x(2*id_x,l_x,mid_x,x,y,val);
        update_x(2*id_x+1,mid_x+1,r_x,x,y,val);
    }
    build_y(id_x,l_x,r_x,1,1,M);
}


int main() {
    
    return 0;
}