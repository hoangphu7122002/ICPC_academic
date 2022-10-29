#include <bits/stdc++.h>

//dp[i] = max(d[j]) + a[i] with h[j] < h[i];

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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> a[i];
  
    return 0;
}