#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;
vector <int> arr(maxN);

int partition(int l, int r) {
    int x = arr[r]; 
    int i = l;
    for (int j = l; j <= r - 1; ++j) {
        if (arr[j] <= x) {
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[r]);
    return i;
}

int randomPartition(int l, int r)
{
    int n = r-l+1;
    int pivot = rand() % n;
    swap(arr[l + pivot], arr[r]);
    return partition(l, r);
}

int kthSmallest(int l, int r, int K) {
    if (K >= 0 && K <= r - l + 1) {
        int pos = randomPartition(l,r);
        if (pos - l == K - 1) return arr[pos];
        if (pos - l > K - 1) return kthSmallest(l,pos-1,K);
        return kthSmallest(pos+1,r,K - pos + l - 1);
    }   
    return -1;
}

int main() {
    arr = { 12, 3, 5, 7, 4, 19, 26 };
    int K = 3;
    cout << kthSmallest(0,arr.size() - 1,K);
    return 0;
}