#include <bits/stdc++.h>

using namespace std;

#define MOD 1e9 + 7
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxN = 1e5 + 1;

int N,Q;
vector <int> g[maxN];
vector <int> visited(maxN);
vector <int> a(maxN);
int prefix[maxN];

int bits[maxN];
int max_ele;
void computePrefix() {
    
    for (int i = 1; i <= N; ++i) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    max_ele = *max_element(prefix+1,prefix+N+1);
}

void update(int idx,int val) {
    while (idx != 0 && idx <= max_ele) {
        bits[idx] += val;
        idx += (idx & (-idx));
    }
}

int get(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bits[idx];
        idx -= (idx & (-idx));
    } 
    return sum;
}

int get_k(int k) {
    int res = 0;
    update(1,1);
    bits[0] = 1;
    for (int i = 1; i <= N; ++i) {
        res += get(prefix[i] - k);
        update(prefix[i],1);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    computePrefix();
    int k;
    cin >> k;
    cout << get_k(k) << endl;
    cout << "=================" << endl;
    for (int i = 1; i <= max_ele; ++i) {
        cout << bits[i] << endl;
    }
    return 0;
}

