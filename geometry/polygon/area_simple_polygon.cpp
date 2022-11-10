#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

//Shoelace formula (O(N))
double get_area(vector<pair<double,double>>points) {
    double res = 0.0;
    for (int i = 0; i < points.size(); ++i) {
        pair<double,double> q = i ? points[i - 1] : points.back();
        res += (points[i].x - q.x) * (points[i].y + q.y);
    }
    return abs(res) / 2;
}

int main() {
    return 0;
}
