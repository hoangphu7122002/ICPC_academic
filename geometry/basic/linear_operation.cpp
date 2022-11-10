#include <bits/stdc++.h>

using namespace std;

using ftype = double;

struct point3d {
    ftype x,y,z;
    point3d() {};
    point3d(ftype x, ftype y, ftype z) : x(x), y(y), z(z) {};
    point3d& operator+=(const point3d &t) {
        x += t.x;
        y += t.y;
        z += t.z;
        return *this;
    }
    point3d& operator-=(const point3d &t) {
        x += t.x;
        y += t.y;
        z += t.z;
        return *this;
    }
    point3d& operator*=(ftype t) {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }
    point3d& operator/=(ftype t) {
        x /= t;
        y /= t;
        z /= t;
        return *this;
    }
    point3d operator+(const point3d &t) const {
        return point3d(*this) += t;
    }
    point3d operator-(const point3d &t) const {
        return point3d(*this) -= t;
    }
    point3d operator*(ftype t) const {
        return point3d(*this) *= t;
    }
    point3d operator/(ftype t) const {
        return point3d(*this) /= t;
    }
};

point3d operator*(ftype a, point3d b) {
    return b * a;
}

ftype dot(point3d a, point3d b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

ftype norm(point3d a) {
    return dot(a,a);
}

ftype abs(point3d a) {
    return sqrt(norm(a));
}

ftype proj(point3d a, point3d b) {
    return dot(a,b) / abs(b);
}

ftype angle(point3d a, point3d b) {
    return acos(dot(a,b)/(abs(a)*abs(b)));
}

//cross product
point3d cross(point3d a, point3d b) {
    return point3d(a.y * b.z - a.z * b.y,
                   a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x);
}
ftype triple(point3d a, point3d b, point3d c) {
    return dot(a, cross(b, c));
}
