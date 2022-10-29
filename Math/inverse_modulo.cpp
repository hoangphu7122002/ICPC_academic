#include <bits/stdc++.h>

using namespace std;

//m la prime => tinh duoc nghich dao modulo trong toan bo [1..m-1]

const int maxN = 1e5 + 1;
int r[maxN];
int m;

int main() {
    r[1] = 1;
    for (int i = 2; i < m; ++i) {
        r[i] = (m - (m/i) * r[m%i] % m) % m;
    }    
    return 0;
}