#include <bits/stdc++.h>

using namespace std;

struct pt {
    double x,y;
};

int orientation(pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c, bool include_collinear) { //clockwise
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);   
}

bool ccw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o > 0 || (include_collinear && o == 0);
}

vector<pt> convex_hull(vector<pt>& a, bool include_collinear = false) {
    if (a.size() == 1) return;
    sort(a.begin(),a.end(),&cmp);
    pt p1 = a[0];
    pt p2 = a.back();
    
    vector<pt> up, down;
    up.push_back (p1);
    down.push_back (p1);
    
    for (int i = 1; i < a.size(); ++i) {
        //push up
        if (i == a.size() - 1 || cw(p1,a[i],p2,include_collinear)) {
            while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i],include_collinear))
                up.pop_back();
            up.push_back (a[i]);
        } 
        //push down
        if (i == a.size() - 1 || ccw(p1,a[i],p2,include_collinear)) {
            while (down.size()>=2 && !cw (down[down.size()-2], down[down.size()-1], a[i],include_collinear))
                down.pop_back();
            down.push_back (a[i]);
        } 
    }
    if (include_collinear && up.size() == a.size()) {
        reverse(a.begin(), a.end());
        return;
    }
    vector <pt> res;
    for (int i = 0; i < up.size(); ++i) res.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; --i) res.push_back(down[i]);
}

int main() {
    return 0;
}