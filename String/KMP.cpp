#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;
vector <int> T(maxN,0);
string S; //van ban
string W; //pattern can find

void create_T() {
    int pos = 2;
    int cnd = 0;
    
    T[0] = -1;
    T[1] = 0;
    
    while (pos < W.length()) {
        if (W[pos - 1] == W[cnd]) {
            T[pos] = cnd + 1;
            pos = pos + 1;
            cnd = cnd + 1;
        }
        else if (cnd > 0) {
            cnd = T[cnd];
        }
        else {
            T[pos] = 0;
            pos = pos + 1;
        }
    }
}

int KMP_Search() {
    int m = 0;
    int i = 0;
    while (m + i < S.length()) {
        if (W[i] == S[m + i]) {
            i += 1;
            if (i == W.length()) return m;
        }
        else {
            if (T[i] > -1) {
                i = T[i]; //??
                m = m + i - T[i];
            }
            else {
                i = 0;
                m = m + 1;
            }
        }
    }
    return S.length();
}

int main() {
    cin >> S >> W;
    create_T();
    cout << KMP_Search() << endl;
    return 0;
}