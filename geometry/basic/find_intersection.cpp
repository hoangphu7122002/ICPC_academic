#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;
point l;
point r;

struct point{
    double x,y;
    point() {};
    point(double x, double y) : x(x), y(y) {};
    bool operator<(const point& p) const {
        return x < p.x - EPS || (abs(x - p.x) < EPS && y < p.y - EPS);
    }
    bool operator>(const point& p) const {
        return p < *this;
    }
};

struct line{
    double a,b,c;
    line() {};
    line(point p, point q) {
        a = p.y - q.y;
        b = q.x - p.x;
        c = - a * p.x - b * p.y;
        norm();
    }
    
    void norm() {
        double z = sqrt(a * a + b * b);
        if (abs(z) > EPS) {
            a = a/z;
            b = b/z;
            c = c/z;
        }
    }
    
    double dist(const point& p) {
        return a * p.x + b * p.y + c;
    }
};

double det(double a, double b, double c, double d) {
    return a * d - b * c;
}

bool betw(double l, double r, double x) {
    return min(l,r) <= x + EPS && x + EPS <= max(l,r);    
}

bool intersect1d(double a, double b, double c, double d) {
    if (a > b) swap(a,b);
    if (c > d) swap(c,d);
    return max(a,c) <= min(b,d) + EPS;
}

bool intersect(point a, point b, point c, point d) {
    if (!intersect1d(a.x,b.x,c.x,d.x) || !intersect1d(a.y,b.y,c.y,d.y)) {
        return false;
    }
    line m(a,b);
    line n(c,d);
    double zn = det(m.a,m.b,n.a,n.b);
    if (abs(zn) <= EPS) {
        if (abs(m.dist(c)) >= EPS || abs(n.dist(a)) >= EPS) return false;
        if (a > b) swap(a,b);
        if (c > d) swap (c,d);
        l = max(a,c);
        r = min(b,d);
    }
    l.x = r.x = det(m.b,m.c,n.b,n.c) / zn;
    l.y = r.y = -det(m.a,m.c,n.a,n.c) / zn;
    return betw(a.x,b.x,l.x) && betw(a.y,b.y,l.y)
        && betw(c.x,d.x,l.x) && betw(c.y,d.y,l.y);
}

int main() {
    return 0;
}