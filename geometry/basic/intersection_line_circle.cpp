#include <bits/stdc++.h>

using namespace std;

//circle segment circle => solve with problem

double r,a,b,c;    
const double EPS = 1e-9 + 1;

int main() {
    cin >> r >> a >> b >> c;
    double x0 = -a * c / (a * a + b * b);
    double y0 = -b * c / (a * a + b * b);
    if (c * c > r * r * (a * a + b * b) + EPS) {
        cout << "no intersection" << endl;
    }
    else if (abs(c * c - r * r * (a * a + b * b)) <= EPS) {
        cout << "one intersection" << endl;
        cout << x0 << " " << y0 << endl;
    }
    else {
        double d = r * r - c * c /  (a * a + b * b);
        double mult = sqrt(d / (a * a + b * b));
        double ax,ay,bx,by;
        ax = x0 + b * mult;
        ay = y0 - a * mult;
        bx = x0 - b * mult;
        by = y0 + a * mult;
        cout << "two intersection" << endl;
    }
    
    return 0;
}