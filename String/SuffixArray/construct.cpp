#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 1;
const int LOGMAXN = 1e2+1;

//spare table to build LCP between prefix i and j
void process2(int M[MAXN][LOGMAXN], int A[MAXN], int N){
    int i, j;
    // Khởi tạo M với các khoảng độ dài 1
    for (i = 0; i < N; i++) M[i][0] = i;
    // Tính M với các khoảng dài 2^j
    for (j = 1; 1 << j <= N; j++)
        for (i = 0; i + (1 << j) - 1 < N; i++)
            if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
                M[i][j] = M[i][j - 1];
            else
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
}


void count_sort(vector <int>& p,vector <int>& c){
    int n = p.size();
    vector <int> cnt(n);
    vector <int> p_new(n);
    vector <int> pos(n);
    
    for (auto x : c){
        cnt[x]++;
    }
    pos[0] = 0;
    for (int i = 1; i < n; ++i){
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for (auto x : p){
        int i = c[x];
        p_new[pos[i]] = x;
        pos[i]++;
    }
    p = p_new;
}

int main(){
    string s;
    cin >> s;
    s += "$";
    int n = s.size();
    vector <int> p(n),c(n);
    vector <pair<char,int>> a(n);
    for (int i = 0; i < n; ++i) a[i] = {s[i],i};
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) p[i] = a[i].second;
    c[p[0]] = 0;
    for (int i = 1; i < n; ++i){
        if (a[i].first == a[i - 1].first)
            c[p[i]] = c[p[i - 1]];
        else c[p[i]] = c[p[i - 1]] + 1;
    }
    int k = 0;
    while ((1 << k) < n){ //k -> k + 1
        for (int i = 0; i < n; ++i){
            p[i] = (p[i] - (1 << k) + n) % n;
    }
    count_sort(p,c);
    vector <int> c_new(n);
    c_new[p[0]] = 0;
    for (int i = 1; i < n; ++i){
        pair<int,int> now = {c[p[i]],c[(p[i] + (1 << k)) % n]};
        pair<int,int> prev = {c[p[i - 1]],c[(p[i - 1] + (1 << k)) % n]};
        if (now == prev) c_new[p[i]] = c_new[p[i - 1]];
        else c_new[p[i]] = c_new[p[i - 1]] + 1;
    }
    c = c_new;
    k++;
    }
    
    //LongestCommonPrefix
    vector <int> lcp(n);
        k = 0;
        for (int i = 0; i < n - 1; ++i){
        int pi = c[i];
        int j = p[pi - 1];
        // lcp[i] = lcp(s[i..],s[j..])
        while (s[i + k] == s[j + k]) k++;
        lcp[pi] = k;
        k = max(k - 1,0);
    }
}
