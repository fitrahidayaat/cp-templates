#include <bits/stdc++.h>
using namespace std;
#define ll long long
void SieveOfEratosthenes(ll n) {
    vector<bool> prime(n + 1, true);
 
    for (ll p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    for (ll p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}