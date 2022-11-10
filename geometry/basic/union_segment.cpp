#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
vector <pii> points;
int N;

int union_segment() {
    vector <pair<int,bool>> x(2*N);
    int i = 0;
    for (auto ele : points) {
        x[2*i] = {ele.first,false};
        x[2*i + 1] = {ele.second,true};
        i++;
    }
    
    sort(x.begin(),x.end());
    int c = 0;
    int sum = 0;
    for (i = 0; i < 2 * N; ++i) {
        if (i > 0 && x[i].first > x[i - 1].first && c > 0) {
            sum += (x[i].first - x[i - 1].first);
        }
        if (x[i].second == true) c--;
        else c++;
    }
    return sum;
}

int main() {
    return 0;
}