#include <bits/stdc++.h>

using namespace std;

// to find distance between two polygon

struct pt{
    long long x, y;
    pt operator + (const pt & p) const {
        return pt{x + p.x, y + p.y};
    }
    pt operator - (const pt & p) const {
        return pt{x - p.x, y - p.y};
    }
    long long cross(const pt & p) const {
        return x * p.y - y * p.x;
    }
};

vector <pt> P;
vector <pt> Q;

bool complex_y(struct pt& a, struct pt& b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

void reorder(vector <pt>& points) {
    int pos = 0;
    for (int i = 1; i < points.size(); ++i) {
        if (complex_y(points[i],points[pos])) {
            pos = i;
        }
    }
    rotate(points.begin(),points.begin()+pos,points.end());
}

vector <pt> get_Minkowski() {
    reorder(P);
    reorder(Q);
    //ensure cycle
    P.push_back(P[0]);
    P.push_back(P[1]);
    Q.push_back(Q[0]);
    Q.push_back(Q[1]);
    
    int i = 0;
    int j = 0;
    vector <pt> res;
    while (i < P.size() - 2 && j < Q.size() - 2) {
        res.push_back(P[i] + Q[j]);
        int comp = (P[i+1] - P[i]).cross(Q[i+1] - Q[i]);
        if (comp >= 0) ++i;
        if (comp <= 0) ++j;
    }
    return res;
}

int main() {
    return 0;
}