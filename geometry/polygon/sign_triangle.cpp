#include <bits/stdc++.h>

using namespace std;

using ftype = double;
const double ESP = 1e-9;

struct point2d {
    ftype x,y;
    point2d() {};
    point2d(ftype x, ftype y, ftype z) : x(x), y(y) {};
    point2d& operator+=(const point2d &t) {
        x += t.x;
        y += t.y;
        return *this;
    }
    point2d& operator-=(const point2d &t) {
        x += t.x;
        y += t.y;
        return *this;
    }
    point2d& operator*=(ftype t) {
        x *= t;
        y *= t;
        return *this;
    }
    point2d& operator/=(ftype t) {
        x /= t;
        y /= t;
        return *this;
    }
    point2d operator+(const point2d &t) const {
        return point2d(*this) += t;
    }
    point2d operator-(const point2d &t) const {
        return point2d(*this) -= t;
    }
    point2d operator*(ftype t) const {
        return point2d(*this) *= t;
    }
    point2d operator/(ftype t) const {
        return point2d(*this) /= t;
    }
};

point2d operator*(ftype a, point2d b) {
    return b * a;
}

ftype dot(point2d a, point2d b) {
    return a.x * b.x + a.y * b.y;
}

ftype norm(point2d a) {
    return dot(a,a);
}

ftype abs(point2d a) {
    return sqrt(norm(a));
}

ftype proj(point2d a, point2d b) {
    return dot(a,b) / abs(b);
}

ftype angle(point2d a, point2d b) {
    return acos(dot(a,b)/(abs(a)*abs(b)));
}

//cross product
ftype cross(point2d a, point2d b) {
    return a.x * b.y - a.y * b.x;
}

//get sign_triangle
double get_sign_triangle(point2d p1, point2d p2, point2d p3) {
    return cross(p2 - p1,p3 - p2);
}

double get_triangle(point2d p1, point2d p2, point2d p3) {
    double res = get_sign_triangle(p1,p2,p3) * 1.0/2;
    if (abs(res) <= ESP) return 0;
    return res;
}

double clockwise(point2d p1, point2d p2, point2d p3) {
    return get_sign_triangle(p1,p2,p3) < 0;
}

double counter_clockwise(point2d p1, point2d p2, point2d p3) {
    return get_sign_triangle(p1,p2,p3) > 0;
}
