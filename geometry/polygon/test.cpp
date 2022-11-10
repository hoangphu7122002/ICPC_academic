#include <bits/stdc++.h>

using namespace std;

int main() {
    vector <int> a{1,2,3,4,5};
    rotate(a.begin(),a.begin() + 2,a.end());
    for (auto ele : a) {
        cout << ele << endl;
    }
    return 0;
}