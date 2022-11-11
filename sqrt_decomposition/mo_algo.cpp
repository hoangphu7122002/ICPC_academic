#include <bits/stdc++.h>

using namespace std;

int block;
 
struct Query
{
    int L, R;
};

const int maxN = 1e5 + 1;
Query q[maxN];
int a[maxN];
int n,m;

bool compare(Query x, Query y) {
    if (x.L/block != y.L/block)
        return x.L/block < y.L/block;
    return x.R/block < y.R/block;
}

void queryRes() {
    block = (int)sqrt(n);
    sort(q,q+m,compare);
    int currL = 0;
    int currR = 0;
    int currSum = 0;
    
    for (int i=0; i<m; i++)
    {
        int L = q[i].L, R = q[i].R;
        while (currL < L)
        {
            currSum -= a[currL];
            currL++;
        }
        
        while (currL > L)
        {
            currSum += a[currL-1];
            currL--;
        }
        
        while (currR <= R)
        {
            currSum += a[currR];
            currR++;
        }
        
        while (currR > R+1)
        {
            currSum -= a[currR-1];
            currR--;
        }
        
        cout << L << " " << R << " " << currSum << endl;
    }
}

int main() {
    
    return 0;
}