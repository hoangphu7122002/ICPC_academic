#include <bits/stdc++.h>

using namespace std;


int main() {
    int T;
    cin >> T;
    while (T--) {
        int N,k;
        cin >> N >> k;
        vector <int> arr(N);
        for (int i = 1; i <= N; ++i) cin >> arr[i];
        deque <int> dq;
        for (int i = 1; i <= N; ++i) {
            while (dq.size() && arr[dq.back()] >= arr[i]) dq.pop_back();
            dq.push_back(i);
            if (dq.front() + k <= i) dq.pop_front();
            if (i >= k) cout << arr[dq.front()] << " ";
        }
        cout << endl;
    }
    return 0;
}