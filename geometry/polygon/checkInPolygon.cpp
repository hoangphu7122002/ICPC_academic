#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct pt {
    ll x,y;
    pt() {};
    pt(ll x, ll y) : x(x), y(y) {};
    pt operator+(const pt &p) const {return pt(x + p.x,y + p.y);}
    pt operator-(const pt &p) const {return pt(x - p.x,y - p.y);}
    ll cross(const pt& p) const {return x * p.y - y * p.x;}
    ll dot(const pt& p) const {return x * p.x + y * p.y;}
    ll cross(const pt& a, const pt& b) const {return (a - *this).cross(b - *this);
    }
    ll dot(const pt& a, const pt& b) const {return (a - *this).dot(b - *this);}
    ll sqrLen() const {return this->dot(*this);}
};

bool lexComp(const pt& l, const pt& r) {
    return l.x < r.x || (l.x == r.x && l.y < r.y);
}

int sign(ll val) {
    return val > 0 ? 1 : (val == 0 ? 0 : -1);
}

vector<pt> seq;
vector<pt> points;
pt translation;
int n;

bool pointInTriangle(pt a, pt b, pt c, pt point) {
    ll s1 = abs(a.cross(b,c));
    ll s2 = abs(point.cross(a,b)) + abs(point.cross(b,c)) + abs(point.cross(c,a));
    return s1 == s2;
}

void prepare() {
    int pos = 0;
    for (int i = 1; i < points.size(); ++i) {
        if (lexComp(points[i],points[pos])) {
            pos = i;
        }
    }
    rotate(points.begin(),points.begin()+pos,points.end());
    for (int i = 0; i < points.size() - 1; ++i) {
        seq[i] = points[i + 1] - points[0];
    }
    translation = points[0];
}

bool pointInConvexPolygon(pt point) {
    point = point - translation;
    int n = seq.size();
    if (seq[0].cross(point) != 0 && sign(seq[0].cross(point)) != sign(seq[0].cross(seq[n-1]))) 
        return false;
    if (seq[n-1].cross(point) != 0 && sign(seq[n-1].cross(point)) != sign(seq[n-1].cross(seq[0])))
        return false;
    if (seq[0].cross(point) == 0) {
        return seq[0].sqrLen() >= point.sqrLen();
    }
    int l = 0;
    int r = n - 1;
    while (r - l > 1) {
        int mid = (r+l)>>1;
        if (seq[mid].cross(point)>=0) l = mid;
        else r = mid;
    }
    int pos = l;
    return pointInTriangle(points[pos],points[pos+1],points[0],point+translation);
}

int main() {
    return 0;
}