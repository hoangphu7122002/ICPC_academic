#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6+1;

int minPrime[maxN];
bool isPrime[maxN];

//eratosthenes in segment
void segment(int L,int R) {
    vector<bool> isPrime(R - L + 1, true);  // x là số nguyên tố khi và chỉ khi isPrime[x - l] == true

    for (long long i = 2; i * i <= R; ++i) {
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
            isPrime[j - L] = false;
        }
    }
    
    if (1 >= L) {  // Xét riêng trường hợp số 1
        isPrime[1 - L] = false;
    }
    
    for (long long x = L; x <= R; ++x) {
        if (isPrime[x - L]) {
            // i là số nguyên tố
        }
    }
}

// factorial
void sieve_factorial(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (minPrime[i] == 0) { //if i is prime
            for (int j = i * i; j <= n; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
}

vector<int> factorize(int n) {
    vector<int> res;
    while (n != 1) {
        res.push_back(minPrime[n]);
        n /= minPrime[n];
    }
    return res;
}

//general
void sieve(int N) {
    for(int i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= N; ++i) {
         if(isPrime[i] == true) {
             // Mark all the multiples of i as composite numbers
             for(int j = i * i; j <= N; j += i)
                 isPrime[j] = false;
        }
    }
}

