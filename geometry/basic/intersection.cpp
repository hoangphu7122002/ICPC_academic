#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e9;

struct point {
    double x,y;
};

struct line {
    double a,b,c;
};

point res;

double det(double a, double b, double c, double d) {
    return a * d - b * c;
}

bool intersect(line m, line n) {
    double zn = det(m.a,m.b,n.a,n.b);
    if (abs(zn) < EPS) return false;
    
    res.x = det(m.b,m.c,n.b,n.c) / zn;
    res.y = -det(m.a,m.c,n.a,n.c) / zn;
    
    return true;
}

bool parallel(line m, line n) {
    return abs(det(m.a,m.b,n.a,n.b)) < EPS;
}

bool equivalent(line m, line n) {
    return abs(det(m.a,m.b,n.a,n.b)) < EPS 
           && abs(det(m.b,m.c,n.b,n.c)) < EPS 
           && abs(det(m.a,m.c,n.a,n.c)) < EPS;
}

int main() {

    return 0;
}