#include <bits/stdc++.h>

using namespace std;

double sqr(double a) {
    return a * a;
}

struct point {
    double x,y;
    
    point operator-(point p) {
        return {x - p.x, y - p.y};
    }
};

struct circle : point {
    double r;
};

struct line {
    double a,b,c;    
};

const double EPS = 1e-9;
vector <line> ans;

void tangent (point c, double r1, double r2) {
    double r = r1 - r2;
    double z = sqr(c.x) + sqr(c.y);
    double d = z - sqr(r);
    if (d < -EPS) return;
    line l;
    l.a = (c.x * r + c.y * d) / z;
    l.b = (c.y * r - c.x * d) / z;
    l.c = r1;
    
    ans.push_back(l);
}

vector <line> tangents (circle a, circle b) {
    for (int i = -1; i <= 1; i += 2) 
        for (int j = -1; j <= 1; j += 2) tangent(b - a,a.r * i,b.r * j);    
    for (int i = 0; i < ans.size(); ++i) 
        ans[i].c -= ans[i].a * a.x + ans[i].b * a.y;
}        

int main() {
    return 0;
}