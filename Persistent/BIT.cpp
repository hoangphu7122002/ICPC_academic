#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
const int maxN = 1e5 + 1;
vector <pii> BIT[maxN];

int N;

void update(int u, int val, int time) {
    while(u <= N) {
        if (BIT[u].empty()) BIT[u].push_back({time,val});
        else {
            int cur = BIT[u][BIT[u].size() - 1].second;
            BIT[u].push_back({time,cur+val});
        }
        u += (u & (-u));}
}

int get(int u, int time) {
    int res = 0;
    while (u > 0) {
        if (BIT[u].size()) {
            if (BIT[u][BIT[u].size() - 1].first <= time) {
                res += BIT[u][BIT[u].size() - 1].second;
            }
            else {
                int pos = upper_bound(BIT[u].begin(),BIT[u].end(),make_pair(time,maxN)) - BIT[u].begin() - 1;
                if (pos >= 0) res += BIT[u][pos].second;
            }
        }
        u -= (u & (-u));
    }
    return res;
}

int main() {
    
    return 0;
}