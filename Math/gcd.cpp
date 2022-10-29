#include <bits/stdc++.h>

using namespace std;

int gcd(int A, int B) {
    if (B == 0) return A;
    else return gcd(B, A % B);
}

int d, x, y;
void extendedEuclid(int A, int B) {
    if (B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

