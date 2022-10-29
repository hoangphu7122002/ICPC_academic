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
vector <int> a(maxN); //array begin
vector <int> temp(maxN);

//count inversion
int bits[maxN];

void convert() {
    for (int i = 1; i <= N; ++i) {
        temp[i] = a[i];
    }
    sort(temp.begin()+1,temp.begin()+1 + N);
    for (int i = 1; i <= N; ++i) {
        // lower_bound() Returns pointer to the first element greater than or equal to arr[i]
        
        // upper_bound() Returns pointer to the first element greater than arr[i]
        a[i] = upper_bound(temp.begin()+1,temp.begin() + N+1,a[i] - 1) - (temp.begin()+1) + 1;
    }
}
void update(int idx,int val) {
    while (idx <= N) {
        bits[idx] += val;
        idx += (idx & (-idx));
    }
}

int getSum(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bits[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}

int countInversion() {
    convert();
    int sum = 0;
    for (int i = 1; i <= N; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = N; i >= 1; i--) {
        sum += getSum(a[i] - 1);
        cout << "sum: " << getSum(a[i] - 1) << endl;
        update(a[i],1);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    cout << countInversion() << endl;
    return 0;
}