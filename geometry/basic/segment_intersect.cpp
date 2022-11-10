#include <bits/stdc++.h>

using namespace std;

const double EXP = 1e-9;

struct point {
    double x,y;
    point() {};
    point(double x, double y) : x(x), y(y) {};
    point operator-(const point& p) const{
        return point(x - p.x,y - p.y);
    }
    double cross(const point& p) const {
        return x * p.y - y * p.x;
    }
    double cross(const point& a, const point& b) const {
        return (a - *this).cross(b - *this);
    }
};

int sign(double x) {
    if (abs(x) <= EXP) return 0;
    if (x > 0) return 1;
    return -1;
}

bool inter_straight(double a, double b, double c, double d) {
    if (a > b) swap(a,b);
    if (c > d) swap(c,d);
    return max(a,c) <= max(b,d);
}

bool check_intersection(const point& a, const point& b, const point& c, const point& d) {
    if (abs(c.cross(a,d)) <= EXP && abs(c.cross(b,d)) <= EXP) return inter_straight(a.x,b.x,c.x,d.x) && inter_straight(a.y,b.y,c.y,d.y);
    return sign(a.cross(b,d)) != sign(a.cross(b,c)) &&
        sign(c.cross(a,d)) != sign(c.cross(b,d));
}

int main() {
    struct point p1{1,1};
    struct point q1{10,1};
    struct point p2{1,2};
    struct point q2{10,2};
    
    cout << check_intersection(p1,q1,p2,q2) << endl;
    
    p1 = {10, 0}, 
    q1 = {0, 10};
    p2 = {0, 0};
    q2 = {10, 10};
    
    cout << check_intersection(p1,q1,p2,q2) << endl;
    
    return 0;
}